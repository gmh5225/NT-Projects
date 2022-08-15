#ifndef __REAL_H
#define __REAL_H

#ifdef MSRIPv6
#include <winsock2.h>
#include <ws2ip6.h>
#endif

/* #include <winsock.h> */
#include <stdio.h>
#include <fcntl.h>
#include <windows.h>
#include <stdarg.h>
#include <io.h>
#include <curses.h>

/* #include "Xfer.h" */

extern char TitleBarLocation[128];
extern char TitleBarFileStatus[128];
extern char TitleBarNormal[128];

#define PORT_VERSION "2.4.2 - Win32 Beta1"


#ifdef __BORLANDC__
#define S_IRGRP 0
#define S_IROTH 0
#include <process.h>
#endif

#ifndef WIN32
#  define WIN32
#endif

#define DM 242
#define IP 244

#define WILL 251
#define WONT 252
#define DO 253
#define DONT 254
#define IAC 255

#define ENETDOWN WSAENETDOWN
#define ENETUNREACH WSAENETUNREACH
#define ECONNABORTED WSAECONNABORTED
#define ETIMEDOUT WSAETIMEDOUT
#define ECONNREFUSED WSAECONNREFUSED
#define EHOSTDOWN WSAEHOSTDOWN

int Gettimeofday(struct timeval *timenow);
int alarm(int time);

#define bcopy(s,d,l) memcpy((d),(s),(l))
#define bzero(cp,l) memset((cp),0,(l))

#endif

#ifndef __FAKE_H
#define __FAKE_H
#include <time.h>
#ifdef MSRIPv6
#ifndef _WINSOCKAPI_
#include <winsock2.h>
#include <ws2ip6.h>
#endif
#else
#include <winsock.h>
#endif

#ifdef __BORLANDC__
#include <mem.h>
#endif

#define GETPASS

#define System "WIN32"

#define TYPE_A 'A'
#define TYPE_I 'I'
#define TYPE_E 'E'
#define TYPE_L 'L'


#define COMPLETE 2 /* Working */
#define CONTINUE 3 /* Working */
#define PRELIM   1 /* Not Sure Yet */

#define SIGQUIT 1
#define SIGPIPE 2
#define SIGALRM 3

#define popen _popen
#define pclose _pclose

#define TRANSIENT 5

int fork(void);

int Getpass(char *something);

#define getppid getpid

int PClose(FILE *closeFile);

/* Added for Local Command Line Completion */
char *filename_completion_function (char *string, int newSet);

/*int DoWin32Console(XferSpecPtr xp);*/

SOCKET w32_socket(int af, int type, int protocol);
SOCKET w32_accept(SOCKET s, struct sockaddr *addr, int *addrlen);
int w32_bind(SOCKET s, const struct sockaddr *addr, int addrlen);
int w32_connect(SOCKET s, const struct sockaddr *addr, int addrlen);
int w32_send(SOCKET s, const char *buf, int len, int flags);
int w32_recv(SOCKET s, char *buf, int len, int flags);
int w32_listen(SOCKET s, int backlog);
int w32_getsockname(SOCKET s, struct sockaddr *addr, int *addrlen);
int w32_setsockopt(SOCKET s, int level, int optname, const char *optval, int optlen);
int w32_closesocket(SOCKET s);

#define socket w32_socket
#define accept w32_accept
#define bind   w32_bind
#define send   w32_send
#define recv   w32_recv
#define listen   w32_listen
#define connect w32_connect
#define getsockname w32_getsockname
#define setsockopt  w32_setsockopt
#define closesocket w32_closesocket

#endif



