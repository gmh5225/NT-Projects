/* FTP.c */

#include "Sys.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <arpa/telnet.h>
#include <netdb.h>
#include <errno.h>
#ifdef HAVE_NET_ERRNO_H
#	include <net/errno.h>
#endif
#include <setjmp.h>
#include <ctype.h>

#include "Util.h"
#include "FTP.h"
#include "RCmd.h"

#ifdef HAVE_LIBTERMNET
#	ifdef HAVE_TERMNET_H
#		include <termnet.h>
#	else
#		ifdef HAVE_TERM_TERMNET_H
#			include <term/termnet.h>
#		endif
#	endif
#endif

#ifdef HAVE_LIBSOCKS5
#	define SOCKS 5
#	include <socks.h>
#else
#	ifdef HAVE_LIBSOCKS
#		define accept		Raccept
#		define connect		Rconnect
#		define getsockname	Rgetsockname
#		define listen		Rlisten
#	endif
#endif


/* The control stream we read responses to commands from. */
FILE *gControlIn = NULL;

/* The control stream we write our request to. */
FILE *gControlOut = NULL;

/* The actual socket for the data streams. */
int gDataSocket = kClosedFileDescriptor;

int gDataSocketAccepted = kClosedFileDescriptor;

/* Port number we're FTP'ing to. */
unsigned int gFTPPort = kPortUnset;

/* Flag indicating whether we are connected to a remote host. */
int gConnected = 0;

/* Method we would rather to specify where to send data to our local
 * host, either Passive (PASV) or SendPort (PORT).  If you choose
 * Passive FTP, you can attempt to use SendPort if the PASV command
 * fails, since all FTP implementations must support PORT.
 */
#ifndef FTP_DATA_PORT_MODE
int gPreferredDataPortMode = kSendPortMode;
#else
int gPreferredDataPortMode = FTP_DATA_PORT_MODE;
#endif

/* Method we actually ended up using on the current data transfer,
 * PORT or PASV.
 */
int gDataPortMode;

/* We keep track of whether we can even attempt to use Passive FTP.
 * After we find out the remote server doesn't support it, we won't
 * keep asking every time we want to do a transfer.
 */
int gHasPASV;

/* Need to special case if trying to read the startup message from the
 * server, so our command handler won't jump to the wrong spot if
 * the server hangs up at that point.
 */
int gReadingStartup = 0;

int gRemoteServerType;

/* Transfer mode.  We support only stream mode and block mode. */
int gMode;

HangupProc gHangupProc;

/* Network addresses of the sockets we use. */
#ifdef MSRIPv6
struct sockaddr_in6 gServerCtrlAddr;
struct sockaddr_in6 gServerDataAddr;
struct sockaddr_in6 gOurClientCtrlAddr;
struct sockaddr_in6 gOurClientDataAddr;
#else
struct sockaddr_in gServerCtrlAddr;
struct sockaddr_in gServerDataAddr;
struct sockaddr_in gOurClientCtrlAddr;
struct sockaddr_in gOurClientDataAddr;
#endif

/* Real name (not alias) registered to the host we're connected to. */
string gActualHostName;

/* Internet Protocol address of host we're connected to, as a string. */
#ifdef MSRIPv6
char gIPStr[40];
#else
char gIPStr[32];
#endif

extern int gDoneApplication;

/*
 * Some declare these with int's, others (hpux...) with size_t.
 *
extern int gethostname(char *, int), getdomainname(char *, int);
 *
 */

#ifdef MSRIPv6
struct hostent *GetHostEntry(char *host, struct in6_addr *ip_address);
#else
struct hostent *GetHostEntry(char *host, struct in_addr *ip_address);
#endif

void InitDefaultFTPPort(void)
{
#ifdef FTP_PORT
	/* If FTP_PORT is defined, we use a different port number by default
	 * than the one supplied in the servent structure.
	 */
	gFTPPort = FTP_PORT;
#else
	struct servent *ftp;	
	
	if ((ftp = getservbyname("ftp", "tcp")) == NULL)
		gFTPPort = (unsigned int) kDefaultFTPPort;
	else
		gFTPPort = (unsigned int) ntohs(ftp->s_port);
#endif	/* FTP_PORT */
#ifdef HAVE_LIBSOCKS
	SOCKSinit("ncftp");
#endif
}	/* InitDefaultFTPPort */




void MyInetAddr(char *dst, size_t siz, char **src, int i)
{
#ifdef MSRIPv6
	struct in6_addr *ia;
	char *cp;
	
	Strncpy(dst, "???", siz);
	if (src != (char **) 0) {
		ia = (struct in6_addr *) src[i];
		cp = inet6_ntoa(ia);
#else
	struct in_addr *ia;
	char *cp;
	
	Strncpy(dst, "???", siz);
	if (src != (char **) 0) {
		ia = (struct in_addr *) src[i];
		cp = inet_ntoa(*ia);
#endif
		if ((cp != (char *) 0) && (cp != (char *) -1))
			Strncpy(dst, cp, siz);
	}
}	/* MyInetAddr */




/* On entry, you should have 'host' be set to a symbolic name (like
 * cse.unl.edu), or set to a numeric address (like 129.93.3.1).
 * If the function fails, it will return NULL, but if the host was
 * a numeric style address, you'll have the ip_address to fall back on.
 */
#ifdef MSRIPv6
struct hostent *GetHostEntry(char *host, struct in6_addr *ip_address)
{
	struct in6_addr ip;
	struct hostent *hp;
	
    ZERO(ip);

	/* See if the host was given in the numerical format, like "fe80::1"
	 * If it was, inet6_addr will convert that to a 128-bit binary value;
	 * it not, inet6_addr will return (-1).
	 */
    if (inet6_addr(host, &ip)) {
		hp = getipnodebyaddr((char *) &ip, (int) sizeof(ip), AF_INET6, NULL);
	} else {
		/* Not numerical, so it must be a hostname, like ftp.wustl.edu.
         * Really should switch this to use getaddrinfo so that
         * scoped addresses work properly. */
		hp = getipnodebyname(host, AF_INET6, 0, NULL);
		if (hp != NULL)
			ip = * (struct in6_addr *) hp->h_addr_list;
	}
	if (ip_address != NULL)
		*ip_address = ip;
	return (hp);
}	/* GetHostEntry */
#else
struct hostent *GetHostEntry(char *host, struct in_addr *ip_address)
{
	struct in_addr ip;
	struct hostent *hp;
	
	/* See if the host was given in the dotted IP format, like "36.44.0.2."
	 * If it was, inet_addr will convert that to a 32-bit binary value;
	 * it not, inet_addr will return (-1L).
	 */
	ip.s_addr = inet_addr(host);
	if (ip.s_addr != INADDR_NONE) {
		hp = gethostbyaddr((char *) &ip, (int) sizeof(ip), AF_INET);
	} else {
		/* No IP address, so it must be a hostname, like ftp.wustl.edu. */
		hp = gethostbyname(host);
		if (hp != NULL)
			ip = * (struct in_addr *) hp->h_addr_list;
	}
	if (ip_address != NULL)
		*ip_address = ip;
	return (hp);
}	/* GetHostEntry */
#endif



/* Makes every effort to return a fully qualified domain name. */
int GetOurHostName(char *host, size_t siz)
{
#ifdef HOSTNAME
	/* You can hardcode in the name if this routine doesn't work
	 * the way you want it to.
	 */
	Strncpy(host, HOSTNAME, siz);
#else
	struct hostent *hp;
	int result;
	char **curAlias;
	char nodeName[64], domain[64], tmpdomain[64];
	char *cp;
	size_t nodeNameLen;

	host[0] = '\0';
	result = gethostname(host, (int) siz);
	if ((result < 0) || (host[0] == '\0')) {
#if 0
		(void) fprintf(stderr,
"Could not determine the hostname. Re-compile with HOSTNAME defined\n\
to be the full name of your hostname, i.e. -DHOSTNAME=\\\"cse.unl.edu\\\".\n");
			Exit(kExitBadHostName);
#endif
		Strncpy(host, "hostname.unknown.com", siz);
		return(6);
	}

	if (strchr(host, '.') != NULL) {
		/* gethostname returned full name (like "cse.unl.edu"), instead
		 * of just the node name (like "cse").
		 */
		return (1);
	}
	
	hp = GetHostEntry(host, NULL);
	if (hp != NULL) {
		/* Maybe the host entry has the full name. */
		Strncpy(host, (char *) hp->h_name, siz);
		if (strchr((char *) hp->h_name, '.') != NULL) {
			/* The 'name' field for the host entry had full name. */
#ifdef MSRIPv6
            freehostent(hp);
#endif
			return (2);
		}

		/* Now try the list of aliases, to see if any of those look real. */
		STRNCPY(nodeName, host);
		nodeNameLen = strlen(nodeName);
		for (curAlias = hp->h_aliases; *curAlias != NULL; curAlias++) {
			/* See if this name is longer than the node name;  we assume
			 * longer == more detailed.
			 */
			if (strlen(*curAlias) > nodeNameLen) {
				/* We will use this one if it looks like this name is
				 * a superset of the nodename;  so if it contains the
				 * nodename, assume that this will work.
				 */
				if (strstr(*curAlias, nodeName) != NULL)
					Strncpy(host, *curAlias, siz);
			}
		}
		
		/* See if the final thing we decided on in the host entry
		 * looks complete.
		 */
#ifdef MSRIPv6
        freehostent(hp);
#endif
		if (strchr(host, '.') != NULL)
			return (3);
	}

	/* Otherwise, we just have the node name.  See if we can get the
	 * domain name ourselves.
	 * 
	 * It'd be so much simpler if you would just define DOMAINNAME
	 * and get it over with!
	 */
#ifdef DOMAINNAME
	(void) STRNCPY(domain, DOMAINNAME);
#else
	domain[0] = '\0';
#	ifdef HAVE_GETDOMAINNAME
	/* getdomainname() returns just the domain name, without a
	 * preceding period.  For example, on "cse.unl.edu", it would
	 * return "unl.edu".
	 *
	 * SunOS note: getdomainname will return an empty string if
	 * this machine isn't on NIS.
	 */
	if (getdomainname(domain, (int) sizeof(domain)) < 0)
		DebugMsg("getdomainname failed.\n");
	if (domain[0] == '\0')
		DebugMsg("getdomainname did not return anything.\n");
	else {
/*
 * local domain names
 *
 * These can now be determined from the domainname system call.
 * The first component of the NIS domain name is stripped off unless
 * it begins with a dot or a plus sign.
 */
		if (domain[0] == '+')
			domain[0] = '.';
#		ifdef NIS_GETDOMAINNAME
		if (domain[0] != '.') {
			/* Strip off first component. */
			cp = strchr(domain, '.');
			if (cp != NULL) {
				STRNCPY(tmpdomain, cp + 1);
				STRNCPY(domain, tmpdomain);
			}
		}
#		else
#		ifdef DNS_GETDOMAINNAME
		/* Don't do anything, since it should have reutrned the
		 * whole domain we want.
		 */
#		else
		{
			int dots;

			for (dots = 0, cp = domain; *cp; cp++)
				if (*cp == '.')
					++dots;

			/* You didn't say if you were running NIS, so only assume a
			 * NIS domain if there are three components or more (i.e.
			 * getdomainname returned something like aaa.bbb.ccc), which
			 * would have two dots or more.  Otherwise, it would be an
			 * error to strip off "unl." from "unl.edu" if there were
			 * only two components returned.
			 */
			if ((dots > 1) && (domain[0] != '.')) {
			 	/* Strip off first component. */
				cp = strchr(domain, '.');
				if (cp != NULL) {
					STRNCPY(tmpdomain, cp + 1);
					STRNCPY(domain, tmpdomain);
				}
			}
		}
#		endif	/* DNS_GETDOMAINNAME */
#		endif	/* NIS_GETDOMAINNAME */
	}
#	endif	/* HAVE_GETDOMAINNAME */
#endif	/* DOMAINNAME */

	if (domain[0] != '\0') {
		/* Supposedly, it's legal for getdomainname() to return one with
		 * a period at the end.
		 */
		cp = domain + strlen(domain) - 1;
		if (*cp == '.')
			*cp = '\0';
		if (domain[0] != '.')
			(void) Strncat(host, ".", siz);
		(void) Strncat(host, domain, siz);
		return(4);
	} else {
		Strncpy(host, "hostname.unknown.com", siz);
#if 0
		fprintf(stderr,
"WARNING: could not determine full host name (have: '%s').\n\
The program should be re-compiled with DOMAINNAME defined to be the\n\
domain name, i.e. -DDOMAINNAME=\\\"unl.edu\\\"\n\n",
			host);
#endif
	}
	return(5);
#endif	/* !HOSTNAME */
}	/* GetOurHostName */




void CloseControlConnection(void)
{
	/* This will close each file, if it was open. */
	if (CloseFile(&gControlIn))
		DebugMsg("Closed control connection.\n");
	CloseFile(&gControlOut);
	gConnected = 0;
}	/* CloseControlConnection */



static
#ifdef MSRIPv6
int GetSocketAddress(int sockfd, struct sockaddr_in6 *saddr)
{
	int len = (int) sizeof (struct sockaddr_in6);
#else
int GetSocketAddress(int sockfd, struct sockaddr_in *saddr)
{
	int len = (int) sizeof (struct sockaddr_in);
#endif
	int result = 0;

	if (getsockname(sockfd, (struct sockaddr *)saddr, &len) < 0) {
		Error(kDoPerror, "Could not get socket name.\n");
		result = -1;
	}
	return (result);
}	/* GetSocketAddress */




void SetLinger(int sockfd)
{
#ifdef SO_LINGER
	struct linger li;

	li.l_onoff = 1;
	li.l_linger = 120;	/* 2 minutes, but system ignores field. */

	/* Have the system make an effort to deliver any unsent data,
	 * even after we close the connection.
	 */
	if (setsockopt(sockfd, SOL_SOCKET, SO_LINGER, (char *) &li, (int) sizeof(li)) < 0)
		DebugMsg("Note: Linger mode could not be enabled.\n");
#endif	/* SO_LINGER */
}	/* SetLinger */




void SetTypeOfService(int sockfd, int tosType)
{
#ifdef IP_TOS
	/* Specify to the router what type of connection this is, so it
	 * can prioritize packets.
	 */
	if (setsockopt(sockfd, IPPROTO_IP, IP_TOS, (char *) &tosType, (int) sizeof(tosType)) < 0)
		DebugMsg("Note: Type-of-service could not be set.\n");
#endif	/* IP_TOS */
}	/* SetTypeOfService */




void SetInlineOutOfBandData(int sockfd)
{
#ifdef SO_OOBINLINE
	int on = 1;

	if (setsockopt(sockfd, SOL_SOCKET, SO_OOBINLINE, (char *) &on, (int) sizeof(on)) < 0)
		DebugMsg("Note: May not be able to handle out-of-band data.");
#endif /* SO_OOBINLINE */
}	/* SetInlineOutOfBandData */




int OpenControlConnection(char *host, unsigned int port)
{
#ifdef MSRIPv6
	struct in6_addr ip_address;
#else
	struct in_addr ip_address;
#endif
	int err = 0;
	int result;
	int sockfd = -1, sock2fd = -1;
	ResponsePtr rp;
	char **curaddr;
	struct hostent *hp;

	/* Since we're the client, we just have to get a socket() and
	 * connect() it.
	 */
	ZERO(gServerCtrlAddr);

	/* Default transfer mode is stream mode. */
	gMode = 'S';

	/* Don't know what type of server it is yet. */
	gRemoteServerType = kUnknownFTPd;

	/* Assume it's a fatal error, unless we say otherwise. */
	result = kConnectErrFatal;

	/* Make sure we use network byte-order. */
	port = (unsigned int) htons((unsigned short) port);

#ifdef MSRIPv6
	gServerCtrlAddr.sin6_port = port;
#else
	gServerCtrlAddr.sin_port = port;
#endif

	hp = GetHostEntry(host, &ip_address);

	if (hp == NULL) {
		/* Okay, no host entry, but maybe we have a numeric address
		 * in ip_address we can try.
		 */
#ifdef MSRIPv6
		if (IN6_IS_ADDR_UNSPECIFIED(&ip_address)) {
			Error(kDontPerror, "%s: Unknown host.\n", host);
			return (result);
		}
		gServerCtrlAddr.sin6_family = AF_INET6;
		gServerCtrlAddr.sin6_addr = ip_address;
	} else {
		gServerCtrlAddr.sin6_family = hp->h_addrtype;
		/* We'll fill in the rest of the structure below. */
	}
	
	if ((sockfd = socket(gServerCtrlAddr.sin6_family, SOCK_STREAM, 0)) < 0) {
		Error(kDoPerror, "Could not get a socket.\n");
        if (hp != NULL) freehostent(hp);
		return (result);
	}
#else
		if (ip_address.s_addr == INADDR_NONE) {
			Error(kDontPerror, "%s: Unknown host.\n", host);
			return (result);
		}
		gServerCtrlAddr.sin_family = AF_INET;
		gServerCtrlAddr.sin_addr.s_addr = ip_address.s_addr;
	} else {
		gServerCtrlAddr.sin_family = hp->h_addrtype;
		/* We'll fill in the rest of the structure below. */
	}
	
	if ((sockfd = socket(gServerCtrlAddr.sin_family, SOCK_STREAM, 0)) < 0) {
		Error(kDoPerror, "Could not get a socket.\n");
		return (result);
	}
#endif

	/* Okay, we have a socket, now try to connect it to a remote
	 * address.  If we didn't get a host entry, we will only have
	 * one thing to try (ip_address);  if we do have one, we can try
	 * every address in the list from the host entry.
	 */

	if (hp == NULL) {
		/* Since we're given a single raw address, and not a host entry,
		 * we can only try this one address and not any other addresses
		 * that could be present for a site with a host entry.
		 */
		err = connect(sockfd, (struct sockaddr *) &gServerCtrlAddr,
			      (int) sizeof (gServerCtrlAddr));
	} else {
		/* We can try each address in the list.  We'll quit when we
		 * run out of addresses to try or get a successful connection.
		 */
		for (curaddr = hp->h_addr_list; *curaddr != NULL; curaddr++) {
			/* This could overwrite the address field in the structure,
			 * but this is okay because the structure has a junk field
			 * just for this purpose.
			 */
#ifdef MSRIPv6
			memcpy(&gServerCtrlAddr.sin6_addr, *curaddr, (size_t) hp->h_length);
#else
			memcpy(&gServerCtrlAddr.sin_addr, *curaddr, (size_t) hp->h_length);
#endif
			err = connect(sockfd, (struct sockaddr *) &gServerCtrlAddr,
				      (int) sizeof (gServerCtrlAddr));
			if (err == 0)
				break;
		}
	}
	
	if (err < 0) {
		/* Could not connect.  Close up shop and go home. */

		/* If possible, tell the caller if they should bother
		 * calling back later.
		 */
		switch (errno) {
			case ENETDOWN:
			case ENETUNREACH:
			case ECONNABORTED:
			case ETIMEDOUT:
			case ECONNREFUSED:
			case EHOSTDOWN:
				result = kConnectErrReTryable;
				/*FALLTHROUGH*/
			default:
				Error(kDoPerror, "Could not connect to %s.\n", host);
		}
		goto fatal;
	}

	/* Get our end of the socket address for later use. */
	if (GetSocketAddress(sockfd, &gOurClientCtrlAddr) < 0)
		goto fatal;

	/* We want Out-of-band data to appear in the regular stream,
	 * since we can handle TELNET.
	 */
	SetInlineOutOfBandData(sockfd);
	
#if defined(IP_TOS) && defined(IPTOS_LOWDELAY)
	/* Control connection is somewhat interactive, so quick response
	 * is desired.
	 */
	SetTypeOfService(sockfd, IPTOS_LOWDELAY);
#endif

	if ((sock2fd = dup(sockfd)) < 0) {
		Error(kDoPerror, "Could not duplicate a file descriptor.\n");
		goto fatal;
	}

	/* Now setup the FILE pointers for use with the Std I/O library
	 * routines.
	 */
	if ((gControlIn = fdopen(sockfd, "r")) == NULL) {
		Error(kDoPerror, "Could not fdopen.\n");
		goto fatal;
	}

	if ((gControlOut = fdopen(sock2fd, "w")) == NULL) {
		Error(kDoPerror, "Could not fdopen.\n");
		CloseFile(&gControlIn);
		sockfd = kClosedFileDescriptor;
		goto fatal;
	}

	/* We'll be reading and writing lines, so use line buffering.  This
	 * is necessary since the stdio library will use full buffering
	 * for all streams not associated with the tty.
	 */
#ifdef HAVE_SETLINEBUF
	setlinebuf(gControlIn);
	setlinebuf(gControlOut);
#else
	(void) SETVBUF(gControlIn, NULL, _IOLBF, (size_t) BUFSIZ);
	(void) SETVBUF(gControlOut, NULL, _IOLBF, (size_t) BUFSIZ);
#endif

#ifdef MSRIPv6
	(void) STRNCPY(gIPStr, inet6_ntoa(&gServerCtrlAddr.sin6_addr));
#else
	(void) STRNCPY(gIPStr, inet_ntoa(gServerCtrlAddr.sin_addr));
#endif
	if ((hp == NULL) || (hp->h_name == NULL))
		(void) STRNCPY(gActualHostName, host);
	else
		(void) STRNCPY(gActualHostName, (char *) hp->h_name);

#ifdef MSRIPv6
    if (hp != NULL) freehostent(hp);
#endif

	/* Read the startup message from the server. */	
	rp = InitResponse();
	gReadingStartup = 1;
	if (GetResponse(rp) == 5) {
		/* They probably hung up on us right away.  That's too bad,
		 * but we can tell the caller that they can call back later
		 * and try again.
		 */
		gReadingStartup = 0;
		result = kConnectErrReTryable;
		if (CloseFile(&gControlIn))
			DebugMsg("Closed control connection.\n");
		CloseFile(&gControlOut);
		sockfd = kClosedFileDescriptor;
		sock2fd = kClosedFileDescriptor;
		DoneWithResponse(rp);
		goto fatal;
	}
	if ((rp != NULL) && (rp->msg.first != NULL)) {
		if (strstr(rp->msg.first->line, "Version wu-") != NULL) {
			gRemoteServerType = kWuFTPd;
			DebugMsg("Remote server is running wu-ftpd.\n");
		} else if (STRNEQ("NcFTPd", rp->msg.first->line, 6)) {
			gRemoteServerType = kNcFTPd;
			DebugMsg("Remote server is running NcFTPd!\n");
		}
	}
	gReadingStartup = 0;
	DoneWithResponse(rp);

	gHasPASV = 1;		/* Assume we have it, until proven otherwise. */
	gConnected = 1;

	return (kConnectNoErr);
	
fatal:
#ifdef MSRIPv6
    if (hp != NULL) freehostent(hp);
#endif
#ifdef WIN32
        closesocket(sockfd);
#else   
	if (sockfd > 0)
		close(sockfd);
#endif 
	if (sock2fd > 0)
		close(sock2fd);
	return (result);
}	/* OpenControlConnection */




void CloseDataConnection(int mustClose)
{
	/* Don't need to close if in block mode. */
	if ((mustClose == 0) && (gMode == 'B')) {
		DebugMsg("Leaving data connection open.\n");
		return;
	}
	gDataSocketAccepted = kClosedFileDescriptor;
	if (gDataSocket != kClosedFileDescriptor) {
#ifdef WIN32
		closesocket(gDataSocket);
#else
		close(gDataSocket);
#endif
		gDataSocket = kClosedFileDescriptor;
		DebugMsg("Closed data connection.\n");
	} else {
		DebugMsg("Data connection was already closed.\n");
	}
}	/* CloseDataConnection */




int SetStartOffset(long restartPt)
{
	if (restartPt != SZ(0)) {
		if (RCmd(kDefaultResponse, "REST %lu", (unsigned long) restartPt) == 3) {
			DebugMsg("Starting at %lu bytes.\n", (unsigned long) restartPt);
		} else {
			DebugMsg("Could not start at %lu bytes.\n", (unsigned long) restartPt);
			return (-1);
		}
	}
	return (0);
}	/* SetStartOffset */



static
#ifdef MSRIPv6
int SendPort(struct sockaddr_in6 *saddr)
{
	char *a, *p;
	int result;
	ResponsePtr rp;

	rp = InitResponse();

	/* Need to tell the other side which host (the address) and
	 * which process (port) on that host to send data to.
	 */
	RCmd(rp, "LPRT %u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,"
         "%u,%u,%u",
         6, 16,
         saddr->sin6_addr.s6_bytes[0],
         saddr->sin6_addr.s6_bytes[1],
         saddr->sin6_addr.s6_bytes[2],
         saddr->sin6_addr.s6_bytes[3],
         saddr->sin6_addr.s6_bytes[4],
         saddr->sin6_addr.s6_bytes[5],
         saddr->sin6_addr.s6_bytes[6],
         saddr->sin6_addr.s6_bytes[7],
         saddr->sin6_addr.s6_bytes[8],
         saddr->sin6_addr.s6_bytes[9],
         saddr->sin6_addr.s6_bytes[10],
         saddr->sin6_addr.s6_bytes[11],
         saddr->sin6_addr.s6_bytes[12],
         saddr->sin6_addr.s6_bytes[13],
         saddr->sin6_addr.s6_bytes[14],
         saddr->sin6_addr.s6_bytes[15],
         2,
         HIBYTE(ntohs(saddr->sin6_port)),
         LOBYTE(ntohs(saddr->sin6_port)));
	
	/* A 500'ish response code means the LPRT command failed. */
	result = ((rp->codeType == 5) ? (-1) : 0);
	DoneWithResponse(rp);
	return (result);
}	/* SendPort */
#else
int SendPort(struct sockaddr_in *saddr)
{
	char *a, *p;
	int result;
	ResponsePtr rp;

	rp = InitResponse();

	/* These will point to data in network byte order. */
	a = (char *) &saddr->sin_addr;
	p = (char *) &saddr->sin_port;
#define UC(x) (int) (((int) x) & 0xff)

	/* Need to tell the other side which host (the address) and
	 * which process (port) on that host to send data to.
	 */
	RCmd(rp, "PORT %d,%d,%d,%d,%d,%d",
		UC(a[0]), UC(a[1]), UC(a[2]), UC(a[3]), UC(p[0]), UC(p[1]));
	
	/* A 500'ish response code means the PORT command failed. */
	result = ((rp->codeType == 5) ? (-1) : 0);
	DoneWithResponse(rp);
	return (result);
}	/* SendPort */
#endif




static
#ifdef MSRIPv6
int Passive(struct sockaddr_in6 *saddr, int *weird)
{
	ResponsePtr rp;
	int i[21], j;
	char *cp;
	int result;

	result = -1;
	rp = InitResponse();
	RCmd(rp, "LPSV");
	if (rp->codeType != 2) {
		/* Didn't understand or didn't want passive port selection. */
		goto done;
	}

	/* The other side returns a specification in the form of
	 * an integer for the address family, followed by an integer denoting
     * the host address length (in integers), followed by the host address
     * in the form of one integer per byte, followed by an integer denoting
     * the port address length (in integers), followed by the port address
	 * in the form of one integer per byte.
     *
     * For IPv6, the address familty should be 6, the host address length
     * should be 16, and the port address length should be 2.
	 *
	 * It should give us something like:
	 * "Entering Long Passive Mode (6,16,254,128,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,3,233)",
	 * so look for digits with sscanf() starting 29 characters down the string.
	 */
	for (cp = rp->msg.first->line; ; cp++) {
		if (*cp == '\0') {
			DebugMsg("Cannot parse LPSV response: %s\n", rp->msg.first->line);
			goto done;
		}
		if (isdigit(*cp))
			break;
	}

	if (sscanf(cp, "%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,"
               "%u,%u,%u", &i[0], &i[1], &i[2], &i[3], &i[4], &i[5], &i[6],
               &i[7], &i[8], &i[9], &i[10], &i[11], &i[12], &i[13], &i[14],
               &i[15], &i[16], &i[17], &i[18], &i[19], &i[20]) != 21) {
		DebugMsg("Cannot parse LPSV response: %s\n", rp->msg.first->line);
		goto done;
	}

    if (i[0] != 6 || i[1] != 16 || i[18] !=2) {
        DebugMsg("LPSV response appears to not be an IPv6 address: %s\n",
                 rp->msg.first->line);
        goto done;
    }

	for (j = 0, *weird = 0; j < 21; j++) {
		/* Some ftp servers return bogus port octets, such as
		 * boombox.micro.umn.edu.  Let the caller know if we got a
		 * weird looking octet.
		 */
		if ((i[j] < 0) || (i[j] > 255))
			*weird = *weird + 1;

        if (j >= 2 && j <= 17)
            saddr->sin6_addr.s6_bytes[j - 2] = (unsigned char) (i[j] & 0xff);
	}

    saddr->sin6_port = htons((unsigned short)
                             (((i[19] & 0xff) << 8) | (i[20] & 0xff)));

	result = 0;
done:
	DoneWithResponse(rp);
	return (result);
}	/* Passive */
#else
int Passive(struct sockaddr_in *saddr, int *weird)
{
	ResponsePtr rp;
	int i[6], j;
	unsigned char n[6];
	char *cp;
	int result;

	result = -1;
	rp = InitResponse();
	RCmd(rp, "PASV");
	if (rp->codeType != 2) {
		/* Didn't understand or didn't want passive port selection. */
		goto done;
	}

	/* The other side returns a specification in the form of
	 * an internet address as the first four integers (each
	 * integer stands for 8-bits of the real 32-bit address),
	 * and two more integers for the port (16-bit port).
	 *
	 * It should give us something like:
	 * "Entering Passive Mode (129,93,33,1,10,187)", so look for
	 * digits with sscanf() starting 24 characters down the string.
	 */
	for (cp = rp->msg.first->line; ; cp++) {
		if (*cp == '\0') {
			DebugMsg("Cannot parse PASV response: %s\n", rp->msg.first->line);
			goto done;
		}
		if (isdigit(*cp))
			break;
	}

	if (sscanf(cp, "%d,%d,%d,%d,%d,%d",
			&i[0], &i[1], &i[2], &i[3], &i[4], &i[5]) != 6) {
		DebugMsg("Cannot parse PASV response: %s\n", rp->msg.first->line);
		goto done;
	}

	for (j=0, *weird = 0; j<6; j++) {
		/* Some ftp servers return bogus port octets, such as
		 * boombox.micro.umn.edu.  Let the caller know if we got a
		 * weird looking octet.
		 */
		if ((i[j] < 0) || (i[j] > 255))
			*weird = *weird + 1;
		n[j] = (unsigned char) (i[j] & 0xff);
	}

	memcpy(&saddr->sin_addr, &n[0], (size_t) 4);
	memcpy(&saddr->sin_port, &n[4], (size_t) 2);

	result = 0;
done:
	DoneWithResponse(rp);
	return (result);
}	/* Passive */
#endif




int OpenDataConnection(int mode)
{
	int dataSocket;
	int weirdPort;

	/* Before we can transfer any data, and before we even ask the
	 * remote server to start transferring via RETR/NLST/etc, we have
	 * to setup the connection.
	 */
	if ((gMode == 'B') && (gDataSocket != kClosedFileDescriptor)) {
		/* Re-use existing connection. */
		return (0);
	}
tryPort2:
#ifdef MSRIPv6
	dataSocket = socket(AF_INET6, SOCK_STREAM, 0);
#else
	dataSocket = socket(AF_INET, SOCK_STREAM, 0);
#endif
	if (dataSocket < 0) {
		Error(kDoPerror, "Could not get a data socket.\n");
		return (-1);
	}

	if ((gHasPASV == 0) || (mode == kSendPortMode)) {
tryPort:
#ifdef MSRIPv6
		gOurClientDataAddr = gOurClientCtrlAddr;
		gOurClientDataAddr.sin6_family = AF_INET6;
		/* bind will assign us an unused port, typically between 1024-5000. */ 
		gOurClientDataAddr.sin6_port = 0;
#else
		gOurClientDataAddr.sin_family = AF_INET;
		gOurClientDataAddr = gOurClientCtrlAddr;
		/* bind will assign us an unused port, typically between 1024-5000. */ 
		gOurClientDataAddr.sin_port = 0;
#endif		
#ifdef HAVE_LIBSOCKS
		if (Rbind(dataSocket, (struct sockaddr *) &gOurClientDataAddr,
			(int) sizeof (gOurClientDataAddr),
#ifdef MSRIPv6
			gServerCtrlAddr.sin6_addr.s6_addr) < 0) 
#else
			gServerCtrlAddr.sin_addr.s_addr) < 0) 
#endif
#else
		if (bind(dataSocket, (struct sockaddr *) &gOurClientDataAddr,
			(int) sizeof (gOurClientDataAddr)) < 0) 
#endif
		{
			Error(kDoPerror, "Could not bind the data socket.\n");
#ifdef MSRIPv6
			EPrintF("You probably need to install the updated "
                    "version of msafd.dll.\nSee \"FIXES FOR NT 4.0\" in the "
                    "MSRIPv6 readme.txt file.  Or, as a \npossible "
                    "workaround, you can try passive mode (via \"set "
                    "ftp-mode passive\")\nwith those servers that "
                    "support it.\n");
#endif
			goto bad;
		}
	
		/* Need to do this so we can figure out which port the system
		 * gave to us.
		 */
		if (GetSocketAddress(dataSocket, &gOurClientDataAddr) < 0)
			goto bad;
	
		if (listen(dataSocket, 1) < 0) {
			Error(kDoPerror, "listen failed.\n");
			goto bad;
		}
	
		if (SendPort(&gOurClientDataAddr) < 0)
			goto bad;
	
		gDataPortMode = kSendPortMode;
	} else {
		/* Passive mode.  Let the other side decide where to send. */
		
#ifdef MSRIPv6
		gOurClientDataAddr.sin6_family = AF_INET6;
#else
		gOurClientDataAddr.sin_family = AF_INET;
#endif
		gOurClientDataAddr = gOurClientCtrlAddr;

		if ((!gHasPASV) || (Passive(&gOurClientDataAddr, &weirdPort) < 0)) {
			Error(kDontPerror, "Passive mode refused.\n");
			gHasPASV = 0;
			
			/* We can try using regular PORT commands, which are required
			 * by all FTP protocol compliant programs, if you said so.
			 *
			 * We don't do this automatically, because if your host
			 * is running a firewall you (probably) do not want SendPort
			 * FTP for security reasons.
			 */
			if (mode == kFallBackToSendPortMode)
				goto tryPort;
			goto bad;
		}
		if (connect(dataSocket, (struct sockaddr *) &gOurClientDataAddr,
			(int) sizeof(gOurClientDataAddr)) < 0 ) {
			if ((weirdPort > 0) && (errno == ECONNREFUSED)) {
				EPrintF("Server sent back a bogus port number.\nI will fall back to PORT instead of PASV mode.\n");
				if (mode == kFallBackToSendPortMode) {
					close(dataSocket);
					gHasPASV = 0;
					goto tryPort2;
				}
				goto bad;
			}
			Error(kDoPerror, "connect failed.\n");
			goto bad;
		}

		gDataPortMode = kPassiveMode;
	}

	SetLinger(dataSocket);
	
#if defined(IP_TOS) && defined(IPTOS_THROUGHPUT)
	/* Data connection is a non-interactive data stream, so
	 * high throughput is desired, at the expense of low
	 * response time.
	 */
	SetTypeOfService(dataSocket, IPTOS_THROUGHPUT);
#endif

	gDataSocket = dataSocket;
	return (0);
bad:
	(void) close(dataSocket);
	return (-1);
}	/* OpenDataConnection */




int AcceptDataConnection(void)
{
	int newSocket;
	int len;

	if ((gMode == 'B') && (gDataSocketAccepted != kClosedFileDescriptor)) {
		/* Re-use existing connection. */
		return 0;
	}

	/* If we did a PORT, we have some things to finish up.
	 * If we did a PASV, we're ready to go.
	 */
	if (gDataPortMode == kSendPortMode) {
		/* Accept will give us back the server's data address;  at the
		 * moment we don't do anything with it though.
		 */
		len = (int) sizeof(gServerDataAddr);
		newSocket = accept(gDataSocket, (struct sockaddr *) &gServerDataAddr, &len);
	
#ifdef WIN32
		(void) closesocket(gDataSocket);
#else
		(void) close(gDataSocket);
#endif
		if (newSocket < 0) {
			Error(kDoPerror, "Could not accept a data connection.\n");
			gDataSocket = kClosedFileDescriptor;
			gDataSocketAccepted = kClosedFileDescriptor;
			return (-1);
		}
		
		gDataSocket = newSocket;
		gDataSocketAccepted = newSocket;
	}

	return (0);
}	/* AcceptDataConnection */



/* Kind of silly, but I wanted to keep this module as self-contained
 * as possible.
 */
void SetPostHangupOnServerProc(HangupProc proc)
{
	gHangupProc = proc;
}	/* SetPostHangupOnServerProc */




void HangupOnServer(void)
{
	int wasConn;

	wasConn = gConnected;

	/* Since we want to close both sides of the connection for each
	 * socket, we can just have them closed with close() instead of
	 * using shutdown().
	 */
	if (wasConn != 0) {
			CloseControlConnection();
			CloseDataConnection(1);
			if (gHangupProc != (HangupProc)0)
				(*gHangupProc)();
	}
}	/* HangupOnServer */




void SendTelnetInterrupt(void)
{
	unsigned char msg[4];

	/* 1. User system inserts the Telnet "Interrupt Process" (IP) signal
	 *    in the Telnet stream.
	 */
	msg[0] = (unsigned char) IAC;
	msg[1] = (unsigned char) IP;

	/* 2. User system sends the Telnet "Sync" signal. */
	msg[2] = (unsigned char) IAC;
	msg[3] = (unsigned char) DM;

	if (send(fileno(gControlOut), (char *) msg, 3, 0) != 3)
		Error(kDoPerror, "Could not send a telnet interrupt(a).\n");
	if (send(fileno(gControlOut), (char *) msg + 3, 1, MSG_OOB) != 1)
		Error(kDoPerror, "Could not send a telnet interrupt(b).\n");
}	/* SendTelnetInterrupt */

/* eof FTP.c */
