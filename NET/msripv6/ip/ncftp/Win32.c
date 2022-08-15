#include "Win32.h"
#include <dos.h>
#include <stdio.h>
#include <string.H>
#include <time.h>
#ifdef __BORLANDC__
#   include <dir.h>
#endif
#include <io.h>
#include "util.h"

#include "xfer.h"


/* we need the real ones here */

#undef socket
#undef accept
#undef bind
#undef send
#undef recv
#undef listen
#undef connect
#undef getsockname
#undef setsockopt
#undef closesocket


#ifdef __BORLANDC__
char *getpass(char *);
#endif

char TitleBarLocation[128] = "";
char TitleBarFileStatus[128] = "";
char TitleBarNormal[128] = "NcFTP 2.4.2b1/Win32";

#define MAX_ASCII 100

int Gettimeofday(struct timeval *timenow)
{
	time_t t;

	t = clock();

	timenow->tv_usec = t;
	timenow->tv_sec = t / CLK_TCK;

	return 0;
}

char *getwd(char *cwd)
{
   char *returnValue = getcwd(cwd, 64);

   while (strchr(cwd, '\\') != NULL)
      *strchr(cwd, '\\') = '/';

   return returnValue;
}

/* Empty Stubs */

#undef sleep
int sleep(int timetosleep)
{
   return 0;
}

void Echo(FILE *fp, int on)
{
}

int fork(void)
{
   return 0;
}

void GetPass(char *promptstr, char *answer, size_t siz)
{
#ifdef __BORLANDC__
  strcpy(answer, getpass(promptstr));
#else
  size_t i = 0;
  cputs(promptstr);
  while (siz-- != 0) {
	answer[i] = _getch();		/* NOT the curses version! */
	switch (answer[i]) {
	case '\0':
		answer[i] = _getch();	/* NOT the curses version! */
	default:
		cputs("*");
		++i;
		break;
	case '\r':
	case '\n':
		answer[i] = '\0';
		return;
	}
  }
#endif
}

int alarm(int variable)
{
   return 0;
}


#undef pclose
int PClose(FILE *closeFile)
{
   _pclose(closeFile);
   SetConsoleTitle(TitleBarLocation);
}


#define STRING_SIZE 10240

char *filename_completion_function (char *string, int newSet)
{
#ifdef __BORLANDC__
   static struct ffblk fileInfo;
   
   char *ptr;
   
   char pattern[128];

   if (newSet == 0)
   {
      strcpy(pattern, string);
      strcat(pattern, "*");

      if (findfirst(pattern, &fileInfo, FA_DIREC))
         return NULL;
   }
   else
   {
      if (findnext(&fileInfo))
         return NULL;
   }
   ptr = (char *)malloc(strlen(fileInfo.ff_name) + 1);
   strcpy(ptr, fileInfo.ff_name);
   
   if (fileInfo.ff_attrib & FA_DIREC)
   {
      strcat(ptr, "/");
   }

   strlwr(ptr);

   return ptr;
#else
#ifdef _MSC_VER		/* Microsoft compilers */
   static struct _finddata_t fileInfo;
   static long find_handle = -1;
   char *ptr;
   char pattern[128];

   if (newSet == 0 || find_handle == -1) {
      strcpy(pattern, string);
      strcat(pattern, "*");

      if (find_handle != -1)
	 _findclose(find_handle);
      if ((find_handle = _findfirst(pattern, &fileInfo)) == -1)
         return NULL;
   }
   else if (_findnext(find_handle, &fileInfo)) {
      _findclose(find_handle);
      find_handle = -1;
      return NULL;
   }
   ptr = (char *)malloc(strlen(fileInfo.name) + 2);
   strcpy(ptr, fileInfo.name);
   
   if (fileInfo.attrib & _A_SUBDIR)
      strcat(ptr, "/");

   strlwr(ptr);
   return ptr;
#endif
#endif
}

int DoWin32Console(XferSpecPtr xp)
{
  char buffer[128];

  sprintf(TitleBarFileStatus, 
          "%s %s",
          NETREADING(xp) ? "Receiving" : "Sending",
          xp->remoteFileName);
  if (xp->frac != 0.0)
  {
     /*      perc = (int) (100.0 * xp->frac); */
     sprintf(buffer, ":%3d%%",(int) (100 * xp->frac));
     strcat(TitleBarFileStatus, buffer);
  }
  if (xp->remoteFileName != NULL)
     SetConsoleTitle(TitleBarFileStatus);
}

#ifdef __BORLANDC__
#define OPEN_SOCK(x)	_open_osfhandle(x,O_RDWR|O_BINARY)
#else
#define OPEN_SOCK(x)	_open_osfhandle(x,_O_RDWR|_O_BINARY)
#endif
#define TO_SOCK(x)	_get_osfhandle(x)
#define SOCK_TEST(x, y)	if((x) == (y)) errno = WSAGetLastError()
#define SOCK_TEST_ERROR(x) SOCK_TEST(x, SOCKET_ERROR)

SOCKET
w32_socket(int af, int type, int protocol)
{
    SOCKET s;
    if((s = socket(af, type, protocol)) == INVALID_SOCKET)
	errno = WSAGetLastError();
    else
	s = OPEN_SOCK(s);
    return s;
}

SOCKET
w32_accept(SOCKET s, struct sockaddr *addr, int *addrlen)
{
    SOCKET r;
    SOCK_TEST((r = accept(TO_SOCK(s), addr, addrlen)), INVALID_SOCKET);
    return OPEN_SOCK(r);
}

int
w32_bind(SOCKET s, const struct sockaddr *addr, int addrlen)
{
    int r;
    SOCK_TEST_ERROR(r = bind(TO_SOCK(s), addr, addrlen));
    return r;
}

int
w32_connect(SOCKET s, const struct sockaddr *addr, int addrlen)
{
    int r;
    SOCK_TEST_ERROR(r = connect(TO_SOCK(s), addr, addrlen));
    return r;
}

int
w32_getsockname(SOCKET s, struct sockaddr *addr, int *addrlen)
{
    int r;
    SOCK_TEST_ERROR(r = getsockname(TO_SOCK(s), addr, addrlen));
    return r;
}

int
w32_setsockopt(SOCKET s, int level, int optname, const char *optval, int optlen)
{
    int r;
    SOCK_TEST_ERROR(r = setsockopt(TO_SOCK(s), level, optname, optval, optlen));
    return r;
}

int
w32_send(SOCKET s, const char *buf, int len, int flags)
{
    int r;
    SOCK_TEST_ERROR(r = send(TO_SOCK(s), buf, len, flags));
    return r;
}

int
w32_recv(SOCKET s, char *buf, int len, int flags)
{
    int r;
    SOCK_TEST_ERROR(r = recv(TO_SOCK(s), buf, len, flags));
    return r;
}

int
w32_listen(SOCKET s, int backlog)
{
    int r;
    SOCK_TEST_ERROR(r = listen(TO_SOCK(s), backlog));
    return r;
}

int
w32_closesocket(SOCKET s)
{
    return closesocket(TO_SOCK(s));
}

