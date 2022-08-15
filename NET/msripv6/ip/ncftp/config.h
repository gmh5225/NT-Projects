/* Config.h.in.  Generated automatically from configure.in by autoheader.  */


/* Don't define HOSTNAME or DOMAINNAME unless you have to.  After compiling,
 * a test run of the program will tell you if it couldn't determine these
 * itself.  If the test run looks normal (i.e. doesn't mention this stuff)
 * you're okay.
 */

/* #define HOSTNAME "cse.unl.edu" */

/* #define DOMAINNAME "unl.edu" */

/* If you're using the program as an FTP program in an enviroment where
 * you almost always need to open with a user name and password, you
 * might consider turning off anonymous by default.
 *
 * Note:  this won't override whatever is in your ~/.ncftp/prefs.
 * When you run the program the first time, that file is created, so
 * changing this may not seem to work until you edit your prefs.
 */ 
#define UOPEN 0					/* No anon ftp by default? */

/* After compiling the program, you may decide that the curses stuff
 * doesn't perform well.  (It works great on some systems, awful on others).
 * If visual mode doesn't do a good job, you can have visual mode off
 * by default.
 *
 * Note:  this won't override whatever is in your ~/.ncftp/prefs.
 * When you run the program the first time, that file is created, so
 * changing this may not seem to work until you edit your prefs.
 */
#define VISUAL 1

/* Keep user logs by default? */
#define USERLOG 1

/* Default progress meter (0..4) */
#define PROGRESS 2




/* Define to empty if the keyword does not work.  */
#undef const

/* Define if the `getpgrp' function takes no argument.  */
#undef GETPGRP_VOID

/* Define if you have the strftime function.  */
#define HAVE_STRFTIME

/* Define if the setvbuf function takes the buffering type as its second
   argument and the buffer pointer as the third, as on System V
   before release 3.  */
#undef SETVBUF_REVERSED

/* Define to `unsigned' if <sys/types.h> doesn't define.  */
#undef size_t

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if you can safely include both <sys/time.h> and <time.h>.  */
#undef TIME_WITH_SYS_TIME

#ifdef WIN32
#define MORE "more"

#define ZCAT "zcat"

#define GZCAT "zcat"

#define UNAME "Windows95"

#define LS "ls"
#else
#define MORE "/bin/more"

#define ZCAT "/bin/zcat"

#define GZCAT "/bin/zcat"

#define UNAME "Linux Redwing 1.2.13 #6 Thu Sep 7 22:06:08 CDT 1995 i586"

#define LS "/bin/ls"
#endif

#define HAVE_LIBCURSES
#undef HAVE_LIBNCURSES
#undef HAVE_LIBREADLINE
#undef HAVE_LIBTERMCAP

/* This can be one of kSendPortMode (0), kPassiveMode (1) or
 * kFallBackToSendPortMode (2).
 *
 * Example: #define FTP_DATA_PORT_MODE 2
 */
#undef FTP_DATA_PORT_MODE

#undef HAVE_MAXX
#define HAVE__MAXX 1

/* Define to 1 if ANSI function prototypes are usable.  */
#define PROTOTYPES 1

/* Define if you have the beep function.  */
#define HAVE_BEEP

/* Define if you have the curs_set function.  */
#define HAVE_CURS_SET 1

/* Define if you have the fcntl function.  */
#define HAVE_FCNTL 1

/* Define if you have the filename_completion_function function.  */
 #define HAVE_FILENAME_COMPLETION_FUNCTION

/* Define if you have the flock function.  */
#define HAVE_FLOCK 1

/* Define if you have the getcwd function.  */
#undef HAVE_GETCWD

/* Define if you have the getdomainname function.  */
#undef HAVE_GETDOMAINNAME

/* Define if you have the getmaxyx function.  */
#undef HAVE_GETMAXYX

/* Define if you have the getwd function.  */
#define HAVE_GETWD 1

/* Define if you have the memmove function.  */
#define HAVE_MEMMOVE 1

/* Define if you have the mktime function.  */
#define HAVE_MKTIME 1

/* Define if you have the notimeout function.  */
#define HAVE_NOTIMEOUT 1

/* Define if you have the remove function.  */
#define HAVE_REMOVE

/* Define if you have the setlinebuf function.  */
#undef HAVE_SETLINEBUF

/* Define if you have the strcasecmp function.  */
#undef HAVE_STRCASECMP

/* Define if you have the strerror function.  */
#define HAVE_STRERROR 1

/* Define if you have the symlink function.  */
#undef HAVE_SYMLINK

/* Define if you have the tcgetpgrp function.  */
#undef HAVE_TCGETPGRP

/* Define if you have the unlink function.  */
#define HAVE_UNLINK 1

/* Define if you have the <curses.h> header file.  */
#define HAVE_CURSES_H 1

/* Define if you have the <cursesX.h> header file.  */
#undef HAVE_CURSESX_H

/* Define if you have the <fcntl.h> header file.  */
#define HAVE_FCNTL_H

/* Define if you have the <limits.h> header file.  */
#define HAVE_LIMITS_H 1

/* Define if you have the <memory.h> header file.  */
#define HAVE_MEMORY_H 1

/* Define if you have the <ncurses.h> header file.  */
#undef HAVE_NCURSES_H

/* Define if you have the <net/errno.h> header file.  */
#undef HAVE_NET_ERRNO_H

/* Define if you have the <readline/history.h> header file.  */
#undef HAVE_READLINE_HISTORY_H

/* Define if you have the <sgtty.h> header file.  */
#undef HAVE_SGTTY_H

/* Define if you have the <stdarg.h> header file.  */
#define HAVE_STDARG_H 1

/* Define if you have the <string.h> header file.  */
#define HAVE_STRING_H 1

/* Define if you have the <sys/bsdtypes.h> header file.  */
#undef HAVE_SYS_BSDTYPES_H

/* Define if you have the <sys/file.h> header file.  */
#define HAVE_SYS_FILE_H 1

/* Define if you have the <sys/ioctl.h> header file.  */
#define HAVE_SYS_IOCTL_H 1

/* Define if you have the <sys/time.h> header file.  */
#undef HAVE_SYS_TIME_H

/* Define if you have the <term/termnet.h> header file.  */
#undef HAVE_TERM_TERMNET_H

/* Define if you have the <termio.h> header file.  */
#undef HAVE_TERMIO_H

/* Define if you have the <termios.h> header file.  */
#undef HAVE_TERMIOS_H

/* Define if you have the <termnet.h> header file.  */
#undef HAVE_TERMNET_H

/* Define if you have the <unistd.h> header file.  */
#undef HAVE_UNISTD_H

/* Define if you have the <utime.h> header file.  */
#define HAVE_UTIME_H

/* Define if you have the c_s library (-lc_s).  */
#undef HAVE_LIBC_S

/* Define if you have the com_err library (-lcom_err).  */
#undef HAVE_LIBCOM_ERR

/* Define if you have the crypto library (-lcrypto).  */
#undef HAVE_LIBCRYPTO

/* Define if you have the db library (-ldb).  */
#undef HAVE_LIBDB

/* Define if you have the getline library (-lgetline).  */
#undef HAVE_LIBGETLINE

/* Define if you have the gssapi_krb5 library (-lgssapi_krb5).  */
#undef HAVE_LIBGSSAPI_KRB5

/* Define if you have the inet library (-linet).  */
#undef HAVE_LIBINET

/* Define if you have the isode library (-lisode).  */
#undef HAVE_LIBISODE

/* Define if you have the krb5 library (-lkrb5).  */
#undef HAVE_LIBKRB5

/* Define if you have the posix library (-lposix).  */
#undef HAVE_LIBPOSIX

/* Define if you have the resolv library (-lresolv).  */
#undef HAVE_LIBRESOLV

/* Define if you have the socket library (-lsocket).  */
#undef HAVE_LIBSOCKET

/* Define if you have the socks library (-lsocks).  */
#undef HAVE_LIBSOCKS

/* Define if you have the socks5 library (-lsocks5).  */
#undef HAVE_LIBSOCKS5

/* Define if you have the termnet library (-ltermnet).  */
#undef HAVE_LIBTERMNET
