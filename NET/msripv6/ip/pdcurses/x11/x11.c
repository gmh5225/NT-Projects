/*
***************************************************************************
* This file comprises part of PDCurses. PDCurses is Public Domain software.
* You may use this code for whatever purposes you desire. This software
* is provided AS IS with NO WARRANTY whatsoever.
* Should this software be used in another application, an acknowledgement
* that PDCurses code is used would be appreciated, but is not mandatory.
*
* Any changes which you make to this software which may improve or enhance
* it, should be forwarded to the current maintainer for the benefit of 
* other users.
*
* The only restriction placed on this code is that no distribution of
* modified PDCurses code be made under the PDCurses name, by anyone
* other than the current maintainer.
* 
* See the file maintain.er for details of the current maintainer.
*
* This file is NOT public domain software.  It is Copyright, Mark Hessling
* 1994,1995.
***************************************************************************
*/

#if defined(XCURSES)

#define	CURSES_LIBRARY	1
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include <stdio.h>
#include <signal.h>
#include <ctype.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/socket.h>

#ifdef TIME_WITH_SYS_TIME
# include <sys/time.h>
# include <time.h>
#else
# ifdef HAVE_SYS_TIME_H
#  include <sys/time.h>
# else
#  include <time.h>
# endif
#endif

#ifdef HAVE_FCNTL_H
# include <fcntl.h>
#endif

#ifdef HAVE_ERRNO_H
# include <errno.h>
#endif

#ifdef HAVE_SYS_SELECT_H
# include <sys/select.h>   /* AIX needs this for FD_ZERO etc macros */
#endif

#include <sys/ipc.h>
#include <sys/shm.h>

#include <Intrinsic.h>
#include <StringDefs.h>
#include <Shell.h>
#include <Xaw/Box.h>
#include <keysym.h>
#include <Xatom.h>
#if defined FOREIGN
# include <Xlocale.h>
#endif

#ifdef HAVE_DECKEYSYM_H
#include <DECkeysym.h>
#endif

#ifdef HAVE_SUNKEYSYM_H
#include <Sunkeysym.h>
#endif

#include <curses.h>
#include <x11.h>

static char *XCursesClassName="XCurses";
static XtAppContext app_context;
Widget  topLevel,drawing;
static int ReceivedMapNotify=0;

Atom wm_atom[2];

#define XCURSESDISPLAY      (XtDisplay(drawing))
#define XCURSESWIN          (XtWindow(drawing))

struct XCursesKey
{
 int keycode;
 int numkeypad;
 int normal;
 int shifted;
 int control;
 int alt;
};
typedef struct XCursesKey XCURSESKEY;

XCURSESKEY XCursesKeys[] =
{
/* keycode        keypad ?       normal         shifted         control         alt*/
 {XK_Left,        FALSE,         KEY_LEFT,      KEY_SLEFT,      CTL_LEFT,       ALT_LEFT},
 {XK_Right,       FALSE,         KEY_RIGHT,     KEY_SRIGHT,     CTL_RIGHT,      ALT_RIGHT},
 {XK_Up,          FALSE,         KEY_UP,        KEY_UP,         CTL_UP,         ALT_UP},
 {XK_Down,        FALSE,         KEY_DOWN,      KEY_DOWN,       CTL_DOWN,       ALT_DOWN},
 {XK_Home,        FALSE,         KEY_HOME,      KEY_SHOME,      CTL_HOME,       ALT_HOME},
 {XK_R7,          FALSE,         KEY_HOME,      KEY_SHOME,      CTL_HOME,       ALT_HOME}, /* Sun Type 4 keyboard */
 {XK_End,         FALSE,         KEY_END,       KEY_SEND,       CTL_END,        ALT_END},
 {XK_R13,         FALSE,         KEY_END,       KEY_SEND,       CTL_END,        ALT_END},  /* Sun Type 4 keyboard */
 {XK_Prior,       FALSE,         KEY_PPAGE,     KEY_SPREVIOUS,  CTL_PGUP,       ALT_PGUP},
 {XK_R9,          FALSE,         KEY_PPAGE,     KEY_SPREVIOUS,  CTL_PGUP,       ALT_PGUP}, /* Sun Type 4 keyboard */
 {XK_Next,        FALSE,         KEY_NPAGE,     KEY_SNEXT,      CTL_PGDN,       ALT_PGDN},
 {XK_R15,         FALSE,         KEY_NPAGE,     KEY_SNEXT,      CTL_PGDN,       ALT_PGDN}, /* Sun Type 4 keyboard */
 {XK_Insert,      FALSE,         KEY_IC,        KEY_SIC,        CTL_INS,        ALT_INS},
 {XK_Delete,      FALSE,         KEY_DC,        KEY_SDC,        CTL_DEL,        ALT_DEL},
 {XK_F1,          FALSE,         KEY_F(1),      KEY_F(13),      KEY_F(25),      KEY_F(37)},
 {XK_F2,          FALSE,         KEY_F(2),      KEY_F(14),      KEY_F(26),      KEY_F(38)},
 {XK_F3,          FALSE,         KEY_F(3),      KEY_F(15),      KEY_F(27),      KEY_F(39)},
 {XK_F4,          FALSE,         KEY_F(4),      KEY_F(16),      KEY_F(28),      KEY_F(40)},
 {XK_F5,          FALSE,         KEY_F(5),      KEY_F(17),      KEY_F(29),      KEY_F(41)},
 {XK_F6,          FALSE,         KEY_F(6),      KEY_F(18),      KEY_F(30),      KEY_F(42)},
 {XK_F7,          FALSE,         KEY_F(7),      KEY_F(19),      KEY_F(31),      KEY_F(43)},
 {XK_F8,          FALSE,         KEY_F(8),      KEY_F(20),      KEY_F(32),      KEY_F(44)},
 {XK_F9,          FALSE,         KEY_F(9),      KEY_F(21),      KEY_F(33),      KEY_F(45)},
 {XK_F10,         FALSE,         KEY_F(10),     KEY_F(22),      KEY_F(34),      KEY_F(46)},
 {XK_F11,         FALSE,         KEY_F(11),     KEY_F(23),      KEY_F(35),      KEY_F(47)},
 {XK_F12,         FALSE,         KEY_F(12),     KEY_F(24),      KEY_F(36),      KEY_F(48)},
 {XK_F13,         FALSE,         KEY_F(13),     KEY_F(25),      KEY_F(37),      KEY_F(49)},
 {XK_F14,         FALSE,         KEY_F(14),     KEY_F(26),      KEY_F(38),      KEY_F(50)},
 {XK_F15,         FALSE,         KEY_F(15),     KEY_F(27),      KEY_F(39),      KEY_F(51)},
 {XK_F16,         FALSE,         KEY_F(16),     KEY_F(28),      KEY_F(40),      KEY_F(52)},
 {XK_F17,         FALSE,         KEY_F(17),     KEY_F(29),      KEY_F(41),      KEY_F(53)},
 {XK_F18,         FALSE,         KEY_F(18),     KEY_F(30),      KEY_F(42),      KEY_F(54)},
 {XK_F19,         FALSE,         KEY_F(19),     KEY_F(31),      KEY_F(43),      KEY_F(55)},
 {XK_F20,         FALSE,         KEY_F(20),     KEY_F(32),      KEY_F(44),      KEY_F(56)},
 {XK_BackSpace,   FALSE,         0x08,          0x08,           CTL_BKSP,       ALT_BKSP},
 {XK_Tab,         FALSE,         0x09,          KEY_BTAB,       CTL_TAB,        ALT_TAB},
 {XK_Select,      FALSE,         KEY_SELECT,    KEY_SELECT,     KEY_SELECT,     KEY_SELECT},
 {XK_Print,       FALSE,         KEY_PRINT,     KEY_SPRINT,     KEY_PRINT,      KEY_PRINT},
 {XK_Find,        FALSE,         KEY_FIND,      KEY_SFIND,      KEY_FIND,       KEY_FIND},
 {XK_Pause,       FALSE,         KEY_SUSPEND,   KEY_SSUSPEND,   KEY_SUSPEND,    KEY_SUSPEND},
 {XK_Clear,       FALSE,         KEY_CLEAR,     KEY_CLEAR,      KEY_CLEAR,      KEY_CLEAR},
 {XK_Cancel,      FALSE,         KEY_CANCEL,    KEY_SCANCEL,    KEY_CANCEL,     KEY_CANCEL},
 {XK_Break,       FALSE,         KEY_BREAK,     KEY_BREAK,      KEY_BREAK,      KEY_BREAK},
 {XK_Help,        FALSE,         KEY_HELP,      KEY_SHELP,      KEY_LHELP,      KEY_HELP},
 {XK_L4,          FALSE,         KEY_UNDO,      KEY_SUNDO,      KEY_UNDO,       KEY_UNDO},
 {XK_L6,          FALSE,         KEY_COPY,      KEY_SCOPY,      KEY_COPY,       KEY_COPY},
 {XK_L9,          FALSE,         KEY_FIND,      KEY_SFIND,      KEY_FIND,       KEY_FIND},
 {XK_Menu,        FALSE,         KEY_OPTIONS,   KEY_SOPTIONS,   KEY_OPTIONS,    KEY_OPTIONS},
#ifdef HAVE_SUNKEYSYM_H
 {SunXK_F36,      FALSE,         KEY_F(41),     KEY_F(43),      KEY_F(45),      KEY_F(47)},
 {SunXK_F37,      FALSE,         KEY_F(42),     KEY_F(44),      KEY_F(46),      KEY_F(48)},
#endif
#ifdef HAVE_DECKEYSYM_H
 {DXK_Remove,     FALSE,         KEY_DC,        KEY_SDC,        CTL_DEL,        ALT_DEL},
#endif
 {XK_Escape,      FALSE,         0x1B,          0x1B,           0x1B,           ALT_ESC},
 {XK_KP_Enter,    TRUE,          PADENTER,      PADENTER,       CTL_PADENTER,   ALT_PADENTER},
 {XK_KP_Add,      TRUE,          PADPLUS,       (int)'+',       CTL_PADPLUS,    ALT_PADPLUS},
 {XK_KP_Subtract, TRUE,          PADMINUS,      (int)'-',       CTL_PADMINUS,   ALT_PADMINUS},
 {XK_KP_Multiply, TRUE,          PADSTAR,       (int)'*',       CTL_PADSTAR,    ALT_PADSTAR},
 {XK_R6,          TRUE,          PADSTAR,       (int)'*',       CTL_PADSTAR,    ALT_PADSTAR}, /* Sun Type 4 keyboard */
 {XK_KP_Divide,   TRUE,          PADSLASH,      (int)'/',       CTL_PADSLASH,   ALT_PADSLASH},
 {XK_R5,          TRUE,          PADSLASH,      (int)'/',       CTL_PADSLASH,   ALT_PADSLASH},/* Sun Type 4 keyboard */
 {XK_KP_Decimal,  TRUE,          PADSTOP,       (int)'.',       CTL_PADSTOP,    ALT_PADSTOP},
 {XK_KP_0,        TRUE,          PAD0,          (int)'0',       CTL_PAD0,       ALT_PAD0},
 {XK_KP_1,        TRUE,          KEY_C1,        (int)'1',       CTL_PAD1,       ALT_PAD1},
 {XK_KP_2,        TRUE,          KEY_C2,        (int)'2',       CTL_PAD2,       ALT_PAD2},
 {XK_KP_3,        TRUE,          KEY_C3,        (int)'3',       CTL_PAD3,       ALT_PAD3},
 {XK_KP_4,        TRUE,          KEY_B1,        (int)'4',       CTL_PAD4,       ALT_PAD4},
 {XK_KP_5,        TRUE,          KEY_B2,        (int)'5',       CTL_PAD5,       ALT_PAD5},
 {XK_R11,         TRUE,          KEY_B2,        (int)'5',       CTL_PAD5,       ALT_PAD5}, /* Sun Type 4 keyboard */
 {XK_KP_6,        TRUE,          KEY_B3,        (int)'6',       CTL_PAD6,       ALT_PAD6},
 {XK_KP_7,        TRUE,          KEY_A1,        (int)'7',       CTL_PAD7,       ALT_PAD7},
 {XK_KP_8,        TRUE,          KEY_A2,        (int)'8',       CTL_PAD8,       ALT_PAD8},
 {XK_KP_9,        TRUE,          KEY_A3,        (int)'9',       CTL_PAD9,       ALT_PAD9},
/* the following added to support Sun Type 5 keyboards */
 {XK_F21,         FALSE,         KEY_SUSPEND,   KEY_SSUSPEND,   KEY_SUSPEND,    KEY_SUSPEND},
 {XK_F22,         FALSE,         KEY_PRINT,     KEY_SPRINT,     KEY_PRINT,      KEY_PRINT},
 {XK_F24,         TRUE,          PADMINUS,      (int)'-',       CTL_PADMINUS,   ALT_PADMINUS},
 {XK_F25,         TRUE,          PADSLASH,      (int)'/',       CTL_PADSLASH,   ALT_PADSLASH},/* Sun Type 4 keyboard */
 {XK_F26,         TRUE,          PADSTAR,       (int)'*',       CTL_PADSTAR,    ALT_PADSTAR}, /* Sun Type 4 keyboard */
 {XK_F27,         TRUE,          KEY_A1,        (int)'7',       CTL_PAD7,       ALT_PAD7},
 {XK_F29,         TRUE,          KEY_A3,        (int)'9',       CTL_PAD9,       ALT_PAD9},
 {XK_F31,         TRUE,          KEY_B2,        (int)'5',       CTL_PAD5,       ALT_PAD5},
 {XK_F35,         TRUE,          KEY_C3,        (int)'3',       CTL_PAD3,       ALT_PAD3},
#ifdef HAVE_XK_KP_DELETE
 {XK_KP_Delete,   TRUE,          PADSTOP,       (int)'.',       CTL_PADSTOP,    ALT_PADSTOP},
#endif
#ifdef HAVE_XK_KP_INSERT
 {XK_KP_Insert,   TRUE,          PAD0,          (int)'0',       CTL_PAD0,       ALT_PAD0},
#endif
#ifdef HAVE_XK_KP_END
 {XK_KP_End,      TRUE,          KEY_C1,        (int)'1',       CTL_PAD1,       ALT_PAD1},
#endif
#ifdef HAVE_XK_KP_DOWN
 {XK_KP_Down,     TRUE,          KEY_C2,        (int)'2',       CTL_PAD2,       ALT_PAD2},
#endif
#ifdef HAVE_XK_KP_NEXT
 {XK_KP_Next,     TRUE,          KEY_C3,        (int)'3',       CTL_PAD3,       ALT_PAD3},
#endif
#ifdef HAVE_XK_KP_LEFT
 {XK_KP_Left,     TRUE,          KEY_B1,        (int)'4',       CTL_PAD4,       ALT_PAD4},
#endif
#ifdef HAVE_XK_KP_RIGHT
 {XK_KP_Right,    TRUE,          KEY_B3,        (int)'6',       CTL_PAD6,       ALT_PAD6},
#endif
#ifdef HAVE_XK_KP_HOME
 {XK_KP_Home,     TRUE,          KEY_A1,        (int)'7',       CTL_PAD7,       ALT_PAD7},
#endif
#ifdef HAVE_XK_KP_UP
 {XK_KP_Up,       TRUE,          KEY_A2,        (int)'8',       CTL_PAD8,       ALT_PAD8},
#endif
#ifdef HAVE_XK_KP_PRIOR
 {XK_KP_Prior,    TRUE,          KEY_A3,        (int)'9',       CTL_PAD9,       ALT_PAD9},
#endif
 {0,              0,             0,             0,              0,              0},
};

#define MAX_COMPOSE_CHARS 14
#define MAX_COMPOSE_PRE 60
char *compose_chars = "`'~^,/\"AaPpSs!?0123CcRr-_<>Xx.=Yy |EeIiOoUu+NnLlgDd:*TtMmVv";
/*
   ` :    À   È   Ì   Ò   Ù   à   è   ì   ò   ù
   ' :    ´   Á   É   Í   Ó   Ú   Ý   á   é   í   ó   ú   ý   ´
   ~ :    Ã   Ñ   Õ   ã   ñ   õ
   ^ :    Â   Ê   Î   Ô   Û   â   ê   î   ô   û
   , :    ¸   Ç   ç   ¸
   / :    Ø   ø   µ   µ
   " :    ¨   Ä   Ë   Ï   Ö   Ü   ä   ë   ï   ö   ü   ÿ   ¨
   A :    Æ   À   Á   Ã   Â   Å   Å   Ã   Â   ª
   a :    æ   à   á   ã   â   å   â   ã   ª   â
   P :    Þ   ¶   ¶
   p :    þ   ¶   ¶
   S :    §   §   §   º   ª
   s :    ß   §   ª   ¹   ²   ³   º   §
   ! :    ¡   ¡
   ? :    ¿   ¿
   1 :    ¹   ½   ¼   ¹
   0 :    °   °
   2 :    ²   ²
   3 :    ³   ¾   ³
   C :    ©   Ç   ¢   ¢
   c :    ¢   ©   ç   ¢   ¢
   R :    ®
   r :    ®
   - :    ­   ±   ¬   ­   ¯   ÷
   _ :    ¯   ¯
   < :    «
   > :    «
   X :    ¤   ×
   x :    ×   ¤   ×
   . :    ·   ·   ·
   = :    ¥   ¥
   Y :    ¥   Ý   ¥
   y :    ¥   ý   ÿ   ¥   ¥
     :
   | :    ¦   ¢   ¦   Þ   þ   ¦
   E :    È   É   Ê   Ë   Ê
   e :    è   é   ê   ë   ê
   I :    Ì   Í   Î   Ï   Î
   i :    ì   í   î   ï   î
   O :    Ò   Ó   Ô   Õ   Ö   Ø   ©   ®   Õ   Ô   Å   å
   o :    °   Å   å   ¤   õ   ò   ó   ô   õ   ö   ø   ô   º
   U :    Ù   Ú   Û   Ü   Û
   u :    ù   ú   û   ü   µ   û
   + :    ±
   N :    Ñ   Ñ   ¬
   n :    ñ   ñ   ¬
   L :    £   £   £
   l :    £   £   £
   g :    ¤
   D :    °   Ð
   d :    °   ð
   : :    ÷
   * :    µ   µ
   T :    Þ
   t :    þ
   M :    ×
   m :    ×
   V :    ¦
   v :    ¦
*/
char compose_lookups[MAX_COMPOSE_PRE][MAX_COMPOSE_CHARS] =
{
/* ` */ {'A','E','I','O','U','a','e','i','o','u',000,000,000,000},
/* ' */ {' ','A','E','I','O','U','Y','a','e','i','o','u','y', 39},
/* ~ */ {'A','N','O','a','n','o',000,000,000,000,000,000,000,000},
/* ^ */ {'A','E','I','O','U','a','e','i','o','u',000,000,000,000},
/* , */ {' ','C','c',',',000,000,000,000,000,000,000,000,000,000},
/* / */ {'O','o','u','U',000,000,000,000,000,000,000,000,000,000},
/* " */ {' ','A','E','I','O','U','a','e','i','o','u','y','\"',000},
/* A */ {'E','`', 39,'~','^','"','o','*','-','>','_',000,000,000},
/* a */ {'e','`', 39,'~','^','"','o','-','_','>',000,000,000,000},
/* P */ {' ','G','!',000,000,000,000,000,000,000,000,000,000,000},
/* p */ {' ','g','!',000,000,000,000,000,000,000,000,000,000,000},
/* S */ {'S','!','O','0','A',000,000,000,000,000,000,000,000,000},
/* s */ {'s','!','a','1','2','3','0','o',000,000,000,000,000,000},
/* ! */ {' ','!',000,000,000,000,000,000,000,000,000,000,000,000},
/* ? */ {' ','?',000,000,000,000,000,000,000,000,000,000,000,000},
/* 0 */ {'^','*',000,000,000,000,000,000,000,000,000,000,000,000},
/* 1 */ {' ','2','4','^',000,000,000,000,000,000,000,000,000,000},
/* 2 */ {' ','^',000,000,000,000,000,000,000,000,000,000,000,000},
/* 3 */ {' ','4','^',000,000,000,000,000,000,000,000,000,000,000},
/* C */ {'O',',','$','|',000,000,000,000,000,000,000,000,000,000},
/* c */ {'|','o',',','/','$',000,000,000,000,000,000,000,000,000},
/* R */ {'O',000,000,000,000,000,000,000,000,000,000,000,000,000},
/* r */ {'o',000,000,000,000,000,000,000,000,000,000,000,000,000},
/* - */ {' ','+',',','-','^',':',000,000,000,000,000,000,000,000},
/* _ */ {'_','^',000,000,000,000,000,000,000,000,000,000,000,000},
/* < */ {'<',000,000,000,000,000,000,000,000,000,000,000,000,000},
/* > */ {'>',000,000,000,000,000,000,000,000,000,000,000,000,000},
/* X */ {'O','X',000,000,000,000,000,000,000,000,000,000,000,000},
/* x */ {' ','o','x',000,000,000,000,000,000,000,000,000,000,000},
/* . */ {' ','^','.',000,000,000,000,000,000,000,000,000,000,000},
/* = */ {'Y','y',000,000,000,000,000,000,000,000,000,000,000,000},
/* Y */ {'=', 39,'-',000,000,000,000,000,000,000,000,000,000,000},
/* y */ {'=', 39,'"','$','-',000,000,000,000,000,000,000,000,000},
/*   */ {' ',000,000,000,000,000,000,000,000,000,000,000,000,000},
/* | */ {' ','c','|','P','p','^',000,000,000,000,000,000,000,000},
/* E */ {'`', 39,'^','"','>',000,000,000,000,000,000,000,000,000},
/* e */ {'`', 39,'^','"','>',000,000,000,000,000,000,000,000,000},
/* I */ {'`', 39,'^','"','>',000,000,000,000,000,000,000,000,000},
/* i */ {'`', 39,'^','"','>',000,000,000,000,000,000,000,000,000},
/* O */ {'`', 39,'^','~','"','/','C','R','-','>','A','a',000,000},
/* o */ {' ','A','a','x','-','`', 39,'^','~','"','/','>','_',000},
/* U */ {'`', 39,'^','"','>',000,000,000,000,000,000,000,000,000},
/* u */ {'`', 39,'^','"',' ','>',000,000,000,000,000,000,000,000},
/* + */ {'-',000,000,000,000,000,000,000,000,000,000,000,000,000},
/* N */ {'~','-','O',000,000,000,000,000,000,000,000,000,000,000},
/* n */ {'~','-','o',000,000,000,000,000,000,000,000,000,000,000},
/* L */ {'$','=','-',000,000,000,000,000,000,000,000,000,000,000},
/* l */ {'$','=','-',000,000,000,000,000,000,000,000,000,000,000},
/* g */ {'$',000,000,000,000,000,000,000,000,000,000,000,000,000},
/* D */ {'E','-',000,000,000,000,000,000,000,000,000,000,000,000},
/* d */ {'e','-',000,000,000,000,000,000,000,000,000,000,000,000},
/* : */ {'-',000,000,000,000,000,000,000,000,000,000,000,000,000},
/* * */ {'m','M',000,000,000,000,000,000,000,000,000,000,000,000},
/* T */ {'H',000,000,000,000,000,000,000,000,000,000,000,000,000},
/* t */ {'h',000,000,000,000,000,000,000,000,000,000,000,000,000},
/* M */ {'U',000,000,000,000,000,000,000,000,000,000,000,000,000},
/* m */ {'u',000,000,000,000,000,000,000,000,000,000,000,000,000},
/* V */ {'B',000,000,000,000,000,000,000,000,000,000,000,000,000},
/* v */ {'b',000,000,000,000,000,000,000,000,000,000,000,000,000},
};

int compose_keys[MAX_COMPOSE_PRE][MAX_COMPOSE_CHARS] =
{
/* ` */ {192,200,204,210,217,224,232,236,242,249,000,000,000,000},
/* ' */ {180,193,201,205,211,218,221,225,233,237,243,250,253,180},
/* ~ */ {195,209,213,227,241,245,000,000,000,000,000,000,000,000},
/* ^ */ {194,202,206,212,219,226,234,238,244,251,000,000,000,000},
/* , */ {184,199,231,184,000,000,000,000,000,000,000,000,000,000},
/* / */ {216,248,181,181,000,000,000,000,000,000,000,000,000,000},
/* " */ {168,196,203,207,214,220,228,235,239,246,252,255,168,000},
/* A */ {198,192,193,195,194,196,197,197,195,194,170,000,000,000},
/* a */ {230,224,225,227,226,228,229,227,170,226,000,000,000,000},
/* P */ {222,182,182,000,000,000,000,000,000,000,000,000,000,000},
/* p */ {254,182,182,000,000,000,000,000,000,000,000,000,000,000},
/* S */ {167,167,167,186,170,000,000,000,000,000,000,000,000,000},
/* s */ {223,167,170,185,178,179,186,167,000,000,000,000,000,000},
/* ! */ {161,161,000,000,000,000,000,000,000,000,000,000,000,000},
/* ? */ {191,191,000,000,000,000,000,000,000,000,000,000,000,000},
/* 0 */ {176,176,000,000,000,000,000,000,000,000,000,000,000,000},
/* 1 */ {185,189,188,185,000,000,000,000,000,000,000,000,000,000},
/* 2 */ {178,178,000,000,000,000,000,000,000,000,000,000,000,000},
/* 3 */ {179,190,179,000,000,000,000,000,000,000,000,000,000,000},
/* C */ {169,199,162,162,000,000,000,000,000,000,000,000,000,000},
/* c */ {162,169,231,162,162,000,000,000,000,000,000,000,000,000},
/* R */ {174,000,000,000,000,000,000,000,000,000,000,000,000,000},
/* r */ {174,000,000,000,000,000,000,000,000,000,000,000,000,000},
/* - */ {173,177,172,173,175,247,000,000,000,000,000,000,000,000},
/* _ */ {175,175,000,000,000,000,000,000,000,000,000,000,000,000},
/* < */ {171,000,000,000,000,000,000,000,000,000,000,000,000,000},
/* > */ {187,000,000,000,000,000,000,000,000,000,000,000,000,000},
/* X */ {164,215,000,000,000,000,000,000,000,000,000,000,000,000},
/* x */ {215,164,215,000,000,000,000,000,000,000,000,000,000,000},
/* . */ {183,183,183,000,000,000,000,000,000,000,000,000,000,000},
/* = */ {165,165,000,000,000,000,000,000,000,000,000,000,000,000},
/* Y */ {165,221,165,000,000,000,000,000,000,000,000,000,000,000},
/* y */ {165,253,255,165,165,000,000,000,000,000,000,000,000,000},
/*   */ {160,000,000,000,000,000,000,000,000,000,000,000,000,000},
/* | */ {166,162,166,222,254,166,000,000,000,000,000,000,000,000},
/* E */ {200,201,202,203,202,000,000,000,000,000,000,000,000,000},
/* e */ {232,233,234,235,234,000,000,000,000,000,000,000,000,000},
/* I */ {204,205,206,207,206,000,000,000,000,000,000,000,000,000},
/* i */ {236,237,238,239,238,000,000,000,000,000,000,000,000,000},
/* O */ {210,211,212,213,214,216,169,174,213,212,197,229,000,000},
/* o */ {176,197,229,164,245,242,243,244,245,246,248,244,186,000},
/* U */ {217,218,219,220,219,000,000,000,000,000,000,000,000,000},
/* u */ {249,250,251,252,181,251,000,000,000,000,000,000,000,000},
/* + */ {177,000,000,000,000,000,000,000,000,000,000,000,000,000},
/* N */ {209,209,172,000,000,000,000,000,000,000,000,000,000,000},
/* n */ {241,241,172,000,000,000,000,000,000,000,000,000,000,000},
/* L */ {163,163,163,000,000,000,000,000,000,000,000,000,000,000},
/* l */ {163,163,163,000,000,000,000,000,000,000,000,000,000,000},
/* g */ {164,000,000,000,000,000,000,000,000,000,000,000,000,000},
/* D */ {176,208,000,000,000,000,000,000,000,000,000,000,000,000},
/* d */ {176,240,000,000,000,000,000,000,000,000,000,000,000,000},
/* : */ {247,000,000,000,000,000,000,000,000,000,000,000,000,000},
/* * */ {181,181,000,000,000,000,000,000,000,000,000,000,000,000},
/* T */ {222,000,000,000,000,000,000,000,000,000,000,000,000,000},
/* t */ {254,000,000,000,000,000,000,000,000,000,000,000,000,000},
/* M */ {215,000,000,000,000,000,000,000,000,000,000,000,000,000},
/* u */ {215,000,000,000,000,000,000,000,000,000,000,000,000,000},
/* V */ {166,000,000,000,000,000,000,000,000,000,000,000,000,000},
/* v */ {166,000,000,000,000,000,000,000,000,000,000,000,000,000},
};

KeySym compose_key=0;
int compose_mask=0;

int state_mask[8] = 
{
 ShiftMask,
 LockMask,
 ControlMask,
 Mod1Mask,
 Mod2Mask,
 Mod3Mask,
 Mod4Mask,
 Mod5Mask
};

MOUSE_STATUS Trapped_Mouse_status;

#define BITMAPDEPTH 1
#define MAX_COLORS   8
#define COLOR_CURSOR 8
#define COLOR_BORDER 9

 static int colors[MAX_COLORS+2];

 extern char *XCursesProgramName;
 static GC normal_gc,bold_gc,block_cursor_gc,rect_cursor_gc,normal_highlight_gc,bold_highlight_gc,border_gc;
 static int XCursesFontHeight,XCursesFontWidth;
 static int XCursesWindowWidth,XCursesWindowHeight;
 static int resizeXCursesWindowWidth=0,resizeXCursesWindowHeight=0;
 static int XCursesLINES=24;
 static int XCursesCOLS=80;
 static char *bitmap_file=NULL;

 static Pixmap          icon_pixmap;

 static Bool after_first_curses_request = False;

#define SHM_CURSVAR         0
#define SHM_CURSCR          1
#define SHM_CURSCR_Y        2
#define SHM_CURSCR_YY       3
#define SHM_CURSCR_FIRSTCH  4
#define SHM_CURSCR_LASTCH   5

static int shmidSP;
static int shmid_Xcurscr;
static int shmkeySP;
static int shmkey_Xcurscr;
static int otherpid;

static char global_display_name[100]; /* large enough for DISPLAY=machine */

SCREEN *XSP;
unsigned char *Xcurscr;
extern unsigned char *atrtab;

MOUSE_STATUS Mouse_status;

static int display_sockets[2];
static int display_sock;
static int exit_sock;
static int key_sockets[2];
static int key_sock;

#ifdef _HPUX_SOURCE
# define FD_SET_CAST int *
#else
# define FD_SET_CAST fd_set *
#endif
fd_set readfds;
fd_set writefds;
struct timeval socket_timeout;

#ifdef FOREIGN
 XIM Xim;
 XIC Xic;
 long im_event_mask;
 XIMStyles *im_supported_styles=NULL;
 XIMStyle my_style=0;
#endif

int XCursesProcess=1;

#ifdef HAVE_PROTO
static void get_GC(Display *,Window, GC *, XFontStruct *,int ,int, bool );
static void makeXY(int ,int ,int ,int ,int *,int *);
static int get_colors(void);
void start_event_handler(void);
int XCursesTransformLine(int ,int ,chtype ,int ,int,int,char *);
int XCursesDisplayText(chtype *, int, int, int,bool);
void XCursesDisplayScreen(bool);
void XCursesDisplayCursor( int ,int ,int ,int );
void XCursesStructureNotify(Widget,XtPointer ,XEvent *,Boolean *);
static void XCursesPasteSelection(Widget,XButtonEvent *);
static void XCursesHandleString(Widget,XEvent *,String *,Cardinal *);
static void XCursesKeyPress(Widget,XEvent *,String *,Cardinal *);
static void XCursesButton(Widget,XEvent *,String *,Cardinal *);
static void XCursesStartHighlightSelection(Widget,XButtonEvent *);
static void XCursesRequestorCallback(Widget,XtPointer,Atom *,Atom *,XtPointer,unsigned long *,int *);
static RETSIGTYPE XCursesSignalHandler(int);
static void XCursesExitXCursesProcess(int,int,char *);
#else    
static void get_GC();
static void makeXY();
static int get_colors();
void start_event_handler();
int XCursesTransformLine();
int XCursesDisplayText();
void XCursesDisplayScreen();
void XCursesDisplayCursor();
void XCursesStructureNotify();
static void XCursesHandleString();
static void XCursesKeyPress();
static void XCursesButton();
static void XCursesPasteSelection();
static void XCursesStartHighlightSelection();
static void XCursesRequestorCallback();
static RETSIGTYPE XCursesSignalHandler();
static void XCursesExitXCursesProcess();
#endif

/*  <Btn3Down>,<Btn3Up>:      XCursesStartHighlightSelection()"*/
/*  <Btn1Down>,<Btn1Up>:      XCursesButton(1) \n \*/
/*  <Btn2Down>,<Btn2Up>:      XCursesPasteSelection() \n \*/
/*  <Btn3Down>,<Btn3Up>:      XCursesButton(3)"*/
static char defaultTranslations[] =
{
 "<Key>:                    XCursesKeyPress() \n \
  <Btn1Down>:               XCursesButton() \n \
  !Ctrl <Btn2Down>:         XCursesButton() \n \
  !Shift <Btn2Down>:        XCursesButton() \n \
  !Ctrl <Btn2Up>:           XCursesButton() \n \
  !Shift <Btn2Up>:          XCursesButton() \n \
  <Btn2Down>,<Btn2Up>:      XCursesPasteSelection() \n \
  <Btn3Down>:               XCursesButton() \n \
  <Btn1Up>:                 XCursesButton() \n \
  <Btn3Up>:                 XCursesButton() \n \
  <BtnMotion>:              XCursesButton()"
};
XtTranslations XCursesTranslations;

static XtActionsRec XCursesActions[] =
{
 {"XCursesButton",                  (XtActionProc)XCursesButton},
 {"XCursesKeyPress",                (XtActionProc)XCursesKeyPress},
 {"XCursesPasteSelection",          (XtActionProc)XCursesPasteSelection},
 {"XCursesStartHighlightSelection", (XtActionProc)XCursesStartHighlightSelection},
 {"string",                         (XtActionProc)XCursesHandleString},
};

int xerror();

#ifdef HAVE_PROTO
void say(char *msg)
#else
void say(msg)
char *msg;
#endif
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:%s",(XCursesProcess)?"     X":"CURSES",msg);
#endif
}

/*********************************************************************/
/*          Shared process functions...                              */
/*********************************************************************/

/***********************************************************************/
#ifdef HAVE_PROTO
int write_socket(int sock_num,char *buf,int len)
#else
int write_socket(sock_num,buf,len)
int sock_num;
char *buf;
int len;
#endif
/***********************************************************************/
{
 int start=0,length=len,rc;
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:write_socket called: sock_num %d len %d\n",(XCursesProcess)?"     X":"CURSES",sock_num,len);
#endif
#ifdef MOUSE_DEBUG1
 if (sock_num == key_sock)
    printf("%s:write_socket(key) len: %d\n",(XCursesProcess)?"     X":"CURSES",len);
#endif
 while(1)
   {
    rc = write(sock_num,buf+start,length);
    if (rc < 0
    ||  rc == length)
       return(rc);
    length -= rc;
    start = rc;
   }
}
/***********************************************************************/
#ifdef HAVE_PROTO
int read_socket(int sock_num,char *buf,int len)
#else
int read_socket(sock_num,buf,len)
int sock_num;
char *buf;
int len;
#endif
/***********************************************************************/
{
 int start=0,length=len,rc;
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:read_socket called: sock_num %d len %d\n",(XCursesProcess)?"     X":"CURSES",sock_num,len);
#endif
 while(1)
   {
    rc = read(sock_num,buf+start,length);
#ifdef MOUSE_DEBUG1
    if (sock_num == key_sock)
       printf("%s:read_socket(key) rc %d errno %d resized: %d\n",(XCursesProcess)?"     X":"CURSES",
                                                        rc,errno,SP->resized);
#endif
    if (rc < 0
    && sock_num == key_sock
    && errno == EINTR
    && SP->resized == TRUE)
      {
#ifdef MOUSE_DEBUG1
       printf("%s:continuing\n",(XCursesProcess)?"     X":"CURSES");
#endif
       rc = 0;
       memcpy(buf,(char *)&rc,sizeof(int));
       return(0); /* must be >= 0 to avoid error */
      }
    if (rc < 0
    ||  rc == length)
       return(rc);
    length -= rc;
    start = rc;
   }
}

/*********************************************************************/
/*           Child process functions...                              */
/*********************************************************************/

/***********************************************************************/
#ifdef HAVE_PROTO
void XCursesExit(void)
#else
void XCursesExit()
#endif
/***********************************************************************/
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesExit() - called\n",(XCursesProcess)?"     X":"CURSES");
#endif
 XCursesInstruct(CURSES_EXIT);
 XCursesCleanupCursesProcess(0);
 return;
}
/***********************************************************************/
#ifdef HAVE_PROTO
void XCursesCleanupCursesProcess(int rc)
#else
void XCursesCleanupCursesProcess(rc)
int rc;
#endif
/***********************************************************************/
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesCleanupCursesProcess() - called: %d\n",(XCursesProcess)?"     X":"CURSES",rc);
#endif
 shutdown(display_sock,2);
 close(display_sock);
 shutdown(key_sock,2);
 close(key_sock);
 shmdt((char *)SP);
 shmdt((char *)Xcurscr);
 if (rc)
   _exit(rc);
 else
   return;
}
/***********************************************************************/
#ifdef HAVE_PROTO
static void XCursesExitCursesProcess(int rc,char *msg)
#else
static void XCursesExitCursesProcess(rc,msg)
int rc;
char *msg;
#endif
/***********************************************************************/
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesExitCursesProcess() - called: %d %s\n",(XCursesProcess)?"     X":"CURSES",rc,msg);
#endif
 endwin();
 XCursesCleanupCursesProcess(rc);
 return;
}
/***********************************************************************/
#ifdef HAVE_PROTO
int XCursesResizeScreen(int nlines, int ncols)
#else
int XCursesResizeScreen(nlines, ncols)
int nlines,ncols;
#endif
/***********************************************************************/
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesResizeScreen() - called: Lines: %d Cols: %d\n",(XCursesProcess)?"     X":"CURSES",nlines,ncols);
#endif
 shmdt((char *)Xcurscr);
 XCursesInstructAndWait(CURSES_RESIZE);
 if ((shmid_Xcurscr = shmget(shmkey_Xcurscr,SP->XcurscrSize+XCURSESSHMMIN,0700)) < 0)
   {
    perror("Cannot allocate shared memory for curscr");
    kill(otherpid,SIGKILL);
    return(ERR);
   }
 XCursesLINES = SP->lines;
 XCursesCOLS = SP->cols;
#ifdef PDCDEBUG
 if (trace_on) PDC_debug("%s:shmid_Xcurscr %d shmkey_Xcurscr %d SP->lines %d SP->cols %d\n",(XCursesProcess)?"     X":"CURSES",shmid_Xcurscr,shmkey_Xcurscr,SP->lines,SP->cols);
#endif
 Xcurscr = (unsigned char*)shmat(shmid_Xcurscr,0,0);
 atrtab = (unsigned char *)(Xcurscr+XCURSCR_ATRTAB_OFF);
 SP->resized=FALSE;
 return(OK);
}
/***********************************************************************/
#ifdef HAVE_PROTO
RETSIGTYPE XCursesSigwinchHandler(int signo)
#else
RETSIGTYPE XCursesSigwinchHandler(signo)
int signo;
#endif
/***********************************************************************/
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesSigwinchHandler() - called: SIGNO: %d\n",(XCursesProcess)?"     X":"CURSES",signo);
#endif
 SP->resized=TRUE;
#if !defined(SA_INTERRUPT)
 (void)signal(SIGWINCH, XCursesSigwinchHandler);
#endif
}
/***********************************************************************/
#ifdef HAVE_PROTO
int XCurses_redraw_curscr(void)
#else
int XCurses_redraw_curscr()
#endif
/***********************************************************************/
{
 int i;

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCurses_redraw_curscr() - called\n",(XCursesProcess)?"     X":"CURSES");
#endif
 for (i=0;i<curscr->_maxy;i++)
    XCurses_transform_line(curscr->_y[i],i,0,curscr->_maxx);
 return(OK);
}

/***********************************************************************/
#ifdef HAVE_PROTO
int XCurses_display_cursor(int oldrow, int oldcol, int newrow,int newcol)
#else
int XCurses_display_cursor(oldrow,oldcol,newrow,newcol)
int oldrow,oldcol,newrow,newcol;
#endif
/***********************************************************************/
{
 char buf[30];
 int idx,pos;

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCurses_display_cursor() - called: NEW row %d col %d\n",
                        (XCursesProcess)?"X":"CURSES",newrow,newcol);
#endif

 idx = CURSES_CURSOR;
 memcpy(buf,(char *)&idx,sizeof(int));
 idx = sizeof(int);
 pos = oldrow + (oldcol << 8);
 memcpy(buf+idx,(char *)&pos,sizeof(int));
 idx += sizeof(int);
 pos = newrow + (newcol << 8);
 memcpy(buf+idx,(char *)&pos,sizeof(int));
 idx += sizeof(int);

 if (write_socket(display_sock,buf,idx) < 0)
    XCursesExitCursesProcess(1,"exitting from XCurses_display_cursor");

 return(OK);
}

/***********************************************************************/
#ifdef HAVE_PROTO
int XCurses_rawgetch(void)
#else
int XCurses_rawgetch()
#endif
/***********************************************************************/
{
 int key;
 char buf[100]; /* big enough for MOUSE_STATUS struct */

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCurses_rawgetch() - called\n",(XCursesProcess)?"     X":"CURSES");
#endif
 if (read_socket(key_sock,buf,sizeof(int)) < 0)
    XCursesExitCursesProcess(2,"exitting from XCurses_rawchar"); /* what else ?? */
 memcpy((char *)&key,buf,sizeof(int));
#ifdef MOUSE_DEBUG1
 printf("%s:reading %d\n",(XCursesProcess)?"     X":"CURSES",key);
#endif
 if (key == KEY_MOUSE)
   {
    if (read_socket(key_sock,buf,sizeof(MOUSE_STATUS)) < 0)
       XCursesExitCursesProcess(2,"exitting from XCurses_rawchar"); /* what else ?? */
    memcpy((char *)&Trapped_Mouse_status,buf,sizeof(MOUSE_STATUS));
#ifdef MOUSE_DEBUG
 printf("rawgetch-x: %d y: %d Mouse status: %x\n",
                                    MOUSE_X_POS,
                                    MOUSE_Y_POS,
                                    Mouse_status.changes);
 printf("rawgetch-Button1: %x Button2: %x Button3: %x\n",
                                    BUTTON_STATUS(1),
                                    BUTTON_STATUS(2),
                                    BUTTON_STATUS(3));
#endif
   }

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCurses_rawgetch() - key %d returned\n",(XCursesProcess)?"     X":"CURSES",key);
#endif
 return(key);
}
/***********************************************************************/
#ifdef HAVE_PROTO
bool XCurses_kbhit(void)
#else
bool XCurses_kbhit()
#endif
/***********************************************************************/
{
 int s;

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCurses_kbhit() - called\n",(XCursesProcess)?"     X":"CURSES");
#endif
/*---------------------------------------------------------------------*/
/* Is something ready to be read on the socket ? Must be a key.        */
/*---------------------------------------------------------------------*/
 FD_ZERO( &readfds );
 FD_SET( key_sock, &readfds );
 if ( ( s = select ( FD_SETSIZE, (FD_SET_CAST)&readfds, NULL, NULL, &socket_timeout ) ) < 0 )
    XCursesExitCursesProcess(3,"child - exiting from XCurses_kbhit select failed");
            
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCurses_kbhit() - returning %s\n",(XCursesProcess)?"     X":"CURSES",(s == 0) ? "FALSE" : "TRUE");
#endif
 if ( s == 0 )
    return(FALSE);
 return(TRUE);
}
/***********************************************************************/
#ifdef HAVE_PROTO
int XCursesInstruct(int flag)
#else
int XCursesInstruct(flag)
int flag;
#endif
/***********************************************************************/
{
 char buf[10];

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesInstruct() - called flag %d\n",(XCursesProcess)?"     X":"CURSES",flag);
#endif
/*---------------------------------------------------------------------*/
/* Send a request to X...                                              */
/*---------------------------------------------------------------------*/
 memcpy(buf,(char *)&flag,sizeof(int));
 if (write_socket(display_sock,buf,sizeof(int)) < 0)
    XCursesExitCursesProcess(4,"exitting from XCursesInstruct");
 return(OK);
}
/***********************************************************************/
#ifdef HAVE_PROTO
int XCursesInstructAndWait(int flag)
#else
int XCursesInstructAndWait(flag)
int flag;
#endif
/***********************************************************************/
{
 int result;
 char buf[10];

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesInstructAndWait() - called\n",(XCursesProcess)?"     X":"CURSES");
#endif

/*---------------------------------------------------------------------*/
/* Tell X we want to do something...                                   */
/*---------------------------------------------------------------------*/
 XCursesInstruct(flag);
/*---------------------------------------------------------------------*/
/* ... wait for X to say the refresh has occurred.                     */
/*---------------------------------------------------------------------*/
 if (read_socket(display_sock,buf,sizeof(int)) < 0)
    XCursesExitCursesProcess(5,"exiting from XCursesInstructAndWait");
 memcpy((char *)&result,buf,sizeof(int));
 if (result != CURSES_CONTINUE)
   XCursesExitCursesProcess(6,"exitting from XCursesInstructAndWait - synchronization error");
 return(OK);
}
/***********************************************************************/
#ifdef HAVE_PROTO
int XCurses_transform_line(chtype *ch, int row, int start_col, int num_cols)
#else
int XCurses_transform_line(ch, row, start_col, num_cols)
chtype *ch;
int row,start_col,num_cols;
#endif
/***********************************************************************/
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCurses_transform_line() called: row %d start_col %d num_cols %d flag %d\n",
                        (XCursesProcess)?"X":"CURSES",row,start_col,num_cols,*(Xcurscr+XCURSCR_FLAG_OFF+row));
#endif

 while(*(Xcurscr+XCURSCR_FLAG_OFF+row))
   ; /* loop until we can write to the line */

 *(Xcurscr+XCURSCR_FLAG_OFF+row) = 1;
 memcpy(Xcurscr+XCURSCR_Y_OFF(row)+(start_col*sizeof(chtype)),ch,num_cols*sizeof(chtype));
 *(Xcurscr+XCURSCR_START_OFF+row) = start_col;
 *(Xcurscr+XCURSCR_LENGTH_OFF+row) = num_cols;
 *(Xcurscr+XCURSCR_FLAG_OFF+row) = 0;
 return(0);
}

/*********************************************************************/
/*          Parent process functions...                              */
/*********************************************************************/

/***********************************************************************/
#ifdef HAVE_PROTO
static RETSIGTYPE XCursesSignalHandler(int signo)
#else
static RETSIGTYPE XCursesSignalHandler(signo)
int signo;
#endif
/***********************************************************************/
{
 char buf[10];
 int flag = CURSES_EXIT;

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesSignalHandler() - called: %d\n",(XCursesProcess)?"     X":"CURSES",signo);
#endif
 (void)signal(signo,SIG_IGN);
/*---------------------------------------------------------------------*/
/* Send a CURSES_EXIT to myself...                                     */
/*---------------------------------------------------------------------*/
 memcpy(buf,(char *)&flag,sizeof(int));
 if (write_socket(exit_sock,buf,sizeof(int)) < 0)
    XCursesExitXCursesProcess(7,signo,"exitting from XCursesSignalHandler");
}
/***********************************************************************/
#ifdef HAVE_PROTO
static void XCursesExitXCursesProcess(int rc,int sig,char *msg)
#else
static void XCursesExitXCursesProcess(rc,sig,msg)
int rc,sig;
char *msg;
#endif
/***********************************************************************/
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesExitXCursesProcess() - called: rc:%d sig:%d %s\n",(XCursesProcess)?"     X":"CURSES",rc,sig,msg);
#endif
 shmdt((char *)SP);
 shmdt((char *)Xcurscr);
 shmctl(shmidSP,IPC_RMID,0);
 shmctl(shmid_Xcurscr,IPC_RMID,0);
 XCursesEndwin();
 shutdown(display_sock,2);
 close(display_sock);
 shutdown(exit_sock,2);
 close(exit_sock);
 shutdown(key_sock,2);
 close(key_sock);
 if (sig)
    kill(otherpid,sig); /* to kill parent process */
 _exit(rc);
}
/***********************************************************************/
#ifdef HAVE_PROTO
void XCursesDisplayScreen(bool highlight)
#else
void XCursesDisplayScreen(highlight)
bool highlight;
#endif
/***********************************************************************/
/*---------------------------------------------------------------------*/
/* This function re-draws the entire screen.                           */
/*---------------------------------------------------------------------*/
{
 int row=0;

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesDisplayScreen() - called:\n",(XCursesProcess)?"     X":"CURSES");
#endif
 for (row=0;row<XCursesLINES;row++)
   {
    while(*(Xcurscr+XCURSCR_FLAG_OFF+row))
       ; /* loop until we can write to the line */

    *(Xcurscr+XCURSCR_FLAG_OFF+row) = 1;
    XCursesDisplayText((chtype *)(Xcurscr+XCURSCR_Y_OFF(row)),row,0,COLS,highlight);
    *(Xcurscr+XCURSCR_FLAG_OFF+row) = 0;
   }
 XCursesDisplayCursor(SP->cursrow,SP->curscol,
                      SP->cursrow,SP->curscol);
 /*
  * Draw the border if required
  */
 if (XCURSESBORDERWIDTH)
    XDrawRectangle(XCURSESDISPLAY,XCURSESWIN,border_gc,
                  (XCURSESBORDERWIDTH/2),(XCURSESBORDERWIDTH/2),
                  (XCursesWindowWidth-XCURSESBORDERWIDTH),
                  (XCursesWindowHeight-XCURSESBORDERWIDTH));
 return;
}

/***********************************************************************/
#ifdef HAVE_PROTO
int XCursesRefreshScreen(void)
#else
int XCursesRefreshScreen()
#endif
/***********************************************************************/
/*---------------------------------------------------------------------*/
/* This function draws those portions of the screen that have changed. */
/*---------------------------------------------------------------------*/
{
 int row=0,start_col=0,num_cols=0;

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesRefreshScreen() - called:\n",(XCursesProcess)?"     X":"CURSES");
#endif
 for (row=0;row<XCursesLINES;row++)
   {
    num_cols = (int)*(Xcurscr+XCURSCR_LENGTH_OFF+row);
    if (num_cols != 0)
      {
       while(*(Xcurscr+XCURSCR_FLAG_OFF+row))
         ; /* loop until we can write to the line */

       *(Xcurscr+XCURSCR_FLAG_OFF+row) = 1;
       start_col = (int)*(Xcurscr+XCURSCR_START_OFF+row);
       XCursesDisplayText((chtype *)(Xcurscr+XCURSCR_Y_OFF(row)+(start_col*sizeof(chtype))),row,start_col,num_cols,FALSE);
       *(Xcurscr+XCURSCR_LENGTH_OFF+row) = 0;
       *(Xcurscr+XCURSCR_FLAG_OFF+row) = 0;
      }
   }
 XCursesDisplayCursor(SP->cursrow,SP->curscol,
                      SP->cursrow,SP->curscol);
 return(0);
}

/***********************************************************************/
#ifdef HAVE_PROTO
int XCursesDisplayText(chtype *ch, int row, int x, int num_cols, bool highlight)
#else
int XCursesDisplayText(ch, row, x, num_cols, highlight)
chtype *ch;
int row,x,num_cols;
bool highlight;
#endif
/***********************************************************************/
{
 char text[300];
 bool new_packet=FALSE;
 short fore,back;
 int original_x,pair_num,i,j;
 chtype old_attr,save_ch,attr;
 int xpos,ypos;
 GC gc;

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesDisplayText() - called: Row: %d X: %d NumCols: %d\n",(XCursesProcess)?"     X":"CURSES", row,x,num_cols);
#endif
 if (num_cols == 0)
    return(OK);

#if 0
 fprintf(stderr,"%2.2d ",x);
 for (idx=0;idx<num_cols;idx++)
   {
    save_ch = *(ch+idx);
    attr =  save_ch & A_CHARTEXT;
    old_attr = save_ch & A_ATTRIBUTES;
    fprintf(stderr,"<%c> %8.8x ",attr,old_attr);
   }
 fprintf(stderr,"\n");
#endif

 old_attr = *ch & A_ATTRIBUTES;
 save_ch = *ch;
 original_x = x;
 for (i=0,j=0; j<num_cols; x++,j++)
   {
    attr = *(ch+j) & A_ATTRIBUTES;
    if (attr != old_attr)
       new_packet = TRUE;
    if (new_packet)
      {
       if ((pair_num = PAIR_NUMBER(save_ch)) != 0)
         {
          if (pair_content(pair_num,&fore,&back) == ERR)
             return(ERR);
         }
       else
         {
          fore = COLOR_WHITE;
          back = COLOR_BLACK;
         }
       text[i] = '\0';
       if (old_attr & A_BOLD)
          gc = bold_gc;
       else
          gc = normal_gc;

       if (old_attr & A_REVERSE)
         {
          XSetForeground(XCURSESDISPLAY, gc, colors[COLOR_BLACK]);
          XSetBackground(XCURSESDISPLAY, gc, colors[COLOR_WHITE]);
         }
       else
         {
          XSetForeground(XCURSESDISPLAY, gc, colors[fore]);
          XSetBackground(XCURSESDISPLAY, gc, colors[back]);
         }

       makeXY(original_x,row,XCursesFontWidth,XCursesFontHeight,&xpos,&ypos);
       XDrawImageString(XCURSESDISPLAY,XCURSESWIN,gc,xpos,ypos,text,i);

       if (old_attr & A_UNDERLINE)
          XDrawLine(XCURSESDISPLAY,XCURSESWIN,gc,xpos,ypos+1,xpos+(XCursesFontWidth*i),ypos+1);
#ifdef PDCDEBUG
       if (trace_on)
          PDC_debug("%s:XCursesDisplayText() - row: %d col: %d num_cols: %d fore: %d back: %d text:<%s>\n",(XCursesProcess)?"     X":"CURSES",row,original_x,i,fore,back,text);
#endif

       new_packet = FALSE;
       old_attr = attr;
       original_x = x;
       i = 0;
      }
    text[i++] = *(ch+j) & A_CHARTEXT;
    save_ch = *(ch+j);
   }
 if ((pair_num = PAIR_NUMBER(save_ch)) != 0)
   {
    if (pair_content(pair_num,&fore,&back) == ERR)
       return(ERR);
   }
 else
   {
    fore = COLOR_WHITE;
    back = COLOR_BLACK;
   }
 text[i] = '\0';
 if (old_attr & A_BOLD)
    gc = bold_gc;
 else
    gc = normal_gc;

 if (old_attr & A_REVERSE)
   {
    XSetForeground(XCURSESDISPLAY, gc, colors[COLOR_BLACK]);
    XSetBackground(XCURSESDISPLAY, gc, colors[COLOR_WHITE]);
   }
 else
   {
    XSetForeground(XCURSESDISPLAY, gc, colors[fore]);
    XSetBackground(XCURSESDISPLAY, gc, colors[back]);
   }

 makeXY(original_x,row,XCursesFontWidth,XCursesFontHeight,&xpos,&ypos);
 XDrawImageString(XCURSESDISPLAY,XCURSESWIN,gc,xpos,ypos,text,i);
 if (old_attr & A_UNDERLINE)
    XDrawLine(XCURSESDISPLAY,XCURSESWIN,gc,xpos,ypos+1,xpos+(XCursesFontWidth*i),ypos+1);
#ifdef PDCDEBUG
 if (trace_on)
    PDC_debug("%s:XCursesDisplayText() (end) row: %d col: %d num_cols: %d fore: %d back: %d text:<%s>\n",(XCursesProcess)?"     X":"CURSES",row,original_x,i,fore,back,text);
#endif

 return(OK);
}
/***********************************************************************/
#ifdef HAVE_PROTO
static void get_GC(Display *display, Window win, GC *gc, XFontStruct *font_info, int fore, int back,bool highlight)
#else
static void get_GC(display,win, gc, font_info,fore,back,highlight)
Display *display;
Window win;
GC *gc;
XFontStruct *font_info;
int fore,back;
bool highlight;
#endif
/***********************************************************************/
{
 XGCValues values;

        /* Create default Graphics Context */
 *gc = XCreateGC(display,win, 0L, &values);

        /* specify font */
 XSetFont(display, *gc, font_info->fid);

        /* specify black foreground since default may be white on white */
 XSetForeground(display, *gc, colors[fore]);
 XSetBackground(display, *gc, colors[back]);
 if (highlight)
    XSetFunction(display, *gc, GXxor);
 return;
}
/***********************************************************************/
#ifdef HAVE_PROTO
static void makeXY(int x,int y,int fontwidth,int fontheight,int *xpos,int *ypos)
#else
static void makeXY(x,y,fontwidth,fontheight,xpos,ypos)
int x,y,fontwidth,fontheight,*xpos,*ypos;
#endif
/***********************************************************************/
{   
 *xpos = (x * fontwidth)+XCURSESBORDERWIDTH;
 *ypos = XCURSESNORMALFONTINFO->ascent + (y * fontheight) + XCURSESBORDERWIDTH;
 return;
}

/***********************************************************************/
#ifdef HAVE_PROTO
static int get_colors(void)
#else
static int get_colors()
#endif
/***********************************************************************/
{
#ifdef PDCDEBUG
 say("in get_colors\n");
#endif

 colors[0] = app_data.colorBlack;
 colors[1] = app_data.colorRed;
 colors[2] = app_data.colorGreen;
 colors[3] = app_data.colorYellow;
 colors[4] = app_data.colorBlue;
 colors[5] = app_data.colorMagenta;
 colors[6] = app_data.colorCyan;
 colors[7] = app_data.colorWhite;
 colors[COLOR_CURSOR] = XCURSESCURSORCOLOR;
 colors[COLOR_BORDER] = XCURSESBORDERCOLOR;
#ifdef PDCDEBUG
 say("out of get_colors\n");
#endif
 return(OK);
}

/***********************************************************************/
#ifdef HAVE_PROTO
int XCursesEndwin(void)
#else
int XCursesEndwin()
#endif
/***********************************************************************/
{

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesEndwin() - called\n",(XCursesProcess)?"     X":"CURSES");
#endif
 if (bitmap_file != NULL)
   {
    XFreePixmap(XCURSESDISPLAY,icon_pixmap);
    free(bitmap_file);
   }
 XFreeGC(XCURSESDISPLAY, normal_gc);
 XFreeGC(XCURSESDISPLAY, bold_gc);
 XFreeGC(XCURSESDISPLAY, normal_highlight_gc);
 XFreeGC(XCURSESDISPLAY, bold_highlight_gc);
 XFreeGC(XCURSESDISPLAY, block_cursor_gc);
 XFreeGC(XCURSESDISPLAY, rect_cursor_gc);
 XFreeGC(XCURSESDISPLAY, border_gc);
#ifdef FOREIGN
 XDestroyIC(Xic);
#endif
#if 0
 XCloseDisplay(XCURSESDISPLAY);
#endif
 return(0);
}
/***********************************************************************/
#ifdef HAVE_PROTO
int XCursesSendKeyToCurses(int key)
#else
int XCursesSendKeyToCurses(key)
int key;
#endif
/***********************************************************************/
{
 char buf[10];

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesSendKeyToCurses() - called: sending %d\n",(XCursesProcess)?"     X":"CURSES",key);
#endif
 memcpy(buf,(char *)&key,sizeof(int));
#ifdef MOUSE_DEBUG1
 printf("%s:writing %d\n",(XCursesProcess)?"     X":"CURSES",key);
#endif
 if (write_socket(key_sock,buf,sizeof(int)) < 0)
    XCursesExitXCursesProcess(1,SIGKILL,"exiting from XCursesSendKeyToCurses");
 return(0);
}
/***********************************************************************/
#ifdef HAVE_PROTO
void XCursesProcessRequestsFromCurses(XtPointer client_data,int *fid,XtInputId *id)
#else
void XCursesProcessRequestsFromCurses(client_data,fid,id)
XtPointer client_data;
int *fid;
XtInputId *id;
#endif
/***********************************************************************/
{
 int s,idx;
 int old_row,new_row;
 int old_x,new_x;
 int pos,num_cols;
 char buf[12]; /* big enough for 2 integers */
 unsigned char save_atrtab[MAX_ATRTAB];

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesProcessRequestFromCurses()\n",(XCursesProcess)?"     X":"CURSES");
#endif

 if (!ReceivedMapNotify)
    return;
 FD_ZERO ( &readfds );
 FD_SET ( display_sock, &readfds );

 if ( ( s = select ( FD_SETSIZE, (FD_SET_CAST)&readfds, NULL, NULL, &socket_timeout ) ) < 0 )
    XCursesExitXCursesProcess(2,SIGKILL,"exiting from XCursesProcessRequestsFromCurses - select failed");
            
 if ( s == 0 ) /* no requests pending - should never happen!*/
    return;
            
 if ( FD_ISSET ( display_sock, &readfds ) )
   {
/* read first integer to determine total message has been received */
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesProcessRequestFromCurses() - before read_socket()\n",(XCursesProcess)?"     X":"CURSES");
#endif
    if (read_socket(display_sock,buf,sizeof(int)) < 0)
       XCursesExitXCursesProcess(3,SIGKILL,"exiting from XCursesProcessRequestsFromCurses - first read");
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesProcessRequestFromCurses() - after read_socket()\n",(XCursesProcess)?"     X":"CURSES");
#endif
    memcpy((char *)&num_cols,buf,sizeof(int));
    after_first_curses_request = True;

    switch(num_cols)
      {
       case 0: break;
       case CURSES_EXIT: /* request from curses to stop */
            say("CURSES_EXIT received from child\n");
            XCursesExitXCursesProcess(0,0,"XCursesProcess requested to exit by child");
            break;
       case CURSES_BELL: /* request from curses to beep */
            say("CURSES_BELL received from child\n");
            XBell(XCURSESDISPLAY,50);
            break;
       case CURSES_CLEAR: /* request from curses to clear window */
            say("CURSES_CLEAR received from child\n");
            XClearWindow(XCURSESDISPLAY,XCURSESWIN);
            break;
       case CURSES_FLASH: /* request from curses to beep */
            say("CURSES_FLASH received from child\n");
#if 0
            XFillRectangle(XCURSESDISPLAY,XCURSESWIN,normal_highlight_gc,10,10,XCursesWindowWidth-10,XCursesWindowHeight-10);
            delay_output(50);
            XFillRectangle(XCURSESDISPLAY,XCURSESWIN,normal_highlight_gc,10,10,XCursesWindowWidth-10,XCursesWindowHeight-10);
            XCursesDisplayCursor(SP->cursrow,SP->curscol,
                                 SP->cursrow,SP->curscol);
#endif
            old_x = CURSES_CONTINUE;
            memcpy(buf,(char *)&old_x,sizeof(int));
            if (write_socket(display_sock,buf,sizeof(int)) < 0)
               XCursesExitXCursesProcess(4,SIGKILL,"exiting from XCursesProcessRequestsFromCurses");
            break;
       case CURSES_REFRESH: /* request from curses to confirm completion of display */
            say("CURSES_REFRESH received from child\n");
            XCursesRefreshScreen();
            XCursesDisplayCursor(SP->cursrow,SP->curscol,
                                 SP->cursrow,SP->curscol);
            old_x = CURSES_CONTINUE;
            memcpy(buf,(char *)&old_x,sizeof(int));
            if (write_socket(display_sock,buf,sizeof(int)) < 0)
               XCursesExitXCursesProcess(4,SIGKILL,"exiting from XCursesProcessRequestsFromCurses");
            break;
       case CURSES_CURSOR: /* display cursor */
            say("CURSES_CURSOR received from child\n");
            if (read_socket(display_sock,buf,sizeof(int)*2) < 0)
               XCursesExitXCursesProcess(5,SIGKILL,"exiting from CURSES_CURSOR XCursesProcessRequestsFromCurses");
            memcpy((char *)&pos,buf,sizeof(int));
            old_row = pos & 0xFF;
            old_x = pos >> 8;
            idx = sizeof(int);
            memcpy((char *)&pos,buf+idx,sizeof(int));
            new_row = pos & 0xFF;
            new_x = pos >> 8;
            XCursesDisplayCursor(old_row,old_x,new_row,new_x);
            break;
       case CURSES_RESIZE: /* resize window */
            after_first_curses_request = False;
            say("CURSES_RESIZE received from child\n");
            SP->lines = XCursesLINES = ((resizeXCursesWindowHeight-(2*XCURSESBORDERWIDTH)) / XCursesFontHeight);
            LINES = XCursesLINES - SP->linesrippedoff;
            SP->cols =  COLS  = XCursesCOLS = ((resizeXCursesWindowWidth-(2*XCURSESBORDERWIDTH)) / XCursesFontWidth);
            XCursesWindowWidth = resizeXCursesWindowWidth;
            XCursesWindowHeight = resizeXCursesWindowHeight;
            /*
             * Draw the border if required
             */
            if (XCURSESBORDERWIDTH)
              XDrawRectangle(XCURSESDISPLAY,XCURSESWIN,border_gc,
                            (XCURSESBORDERWIDTH/2),(XCURSESBORDERWIDTH/2),
                            (XCursesWindowWidth-XCURSESBORDERWIDTH),
                            (XCursesWindowHeight-XCURSESBORDERWIDTH));
/*
 * detach and drop the current shared memory segment and create and attach
 * to a new segment.
 */
            memcpy(save_atrtab,atrtab,sizeof(save_atrtab));
            SP->XcurscrSize = XCURSCR_SIZE;
            shmdt((char *)Xcurscr);
            shmctl(shmid_Xcurscr,IPC_RMID,0);
            if ((shmid_Xcurscr = shmget(shmkey_Xcurscr,SP->XcurscrSize+XCURSESSHMMIN,0700|IPC_CREAT)) < 0)
              {
               perror("Cannot allocate shared memory for curscr");
               XCursesExitXCursesProcess(4,SIGKILL,"exiting from XCursesProcessRequestsFromCurses");
              }
            Xcurscr = (unsigned char*)shmat(shmid_Xcurscr,0,0);
            memset(Xcurscr, 0, SP->XcurscrSize); 
            atrtab = (unsigned char *)(Xcurscr+XCURSCR_ATRTAB_OFF);
            memcpy(atrtab,save_atrtab,sizeof(save_atrtab));

            old_x = CURSES_CONTINUE;
            memcpy(buf,(char *)&old_x,sizeof(int));
            if (write_socket(display_sock,buf,sizeof(int)) < 0)
               XCursesExitXCursesProcess(4,SIGKILL,"exiting from XCursesProcessRequestsFromCurses");
            break;
       default:
#ifdef PDCDEBUG
            if (trace_on) PDC_debug("%s:Unknown request %d\n",(XCursesProcess)?"     X":"CURSES",num_cols);
#endif
            break;
      }
   }
 return;
}

/***********************************************************************/
#ifdef HAVE_PROTO
void XCursesDisplayCursor(int old_row,int old_x,int new_row,int new_x)
#else
void XCursesDisplayCursor(old_row,old_x,new_row,new_x)
int old_row,old_x,new_row,new_x;
#endif
/***********************************************************************/
{
 int xpos,ypos,i;
 char buf[2];
 chtype *ch;

#ifdef PDCDEBUG
 if (trace_on) PDC_debug("%s:XCursesDisplayCursor() - draw char at row: %d col %d\n",(XCursesProcess)?"     X":"CURSES",old_row,old_x);
#endif

/*
 * If the cursor position is outside the boundary of the screen, ignore
 * request.
 */
 if (old_row >= XCursesLINES
 ||  old_x >= COLS
 ||  new_row >= XCursesLINES
 ||  new_x >= COLS)
    return;

 /* display the character at the current cursor position */
#ifdef PDCDEBUG
 if (trace_on) PDC_debug("%s:XCursesDisplayCursor() - draw char at row: %d col %d\n",(XCursesProcess)?"     X":"CURSES",old_row,old_x);
#endif
 XCursesDisplayText((chtype *)(Xcurscr+(XCURSCR_Y_OFF(old_row)+(old_x*sizeof(chtype)))),old_row,old_x,1,FALSE);
 /* display the cursor at the new cursor position */

 switch(SP->visibility)
   {
    case 0: /* cursor not displayed, no more to do */
         break;
    case 1:
          makeXY(new_x,new_row,XCursesFontWidth,XCursesFontHeight,&xpos,&ypos);
          for (i=0;i<XCURSESNORMALFONTINFO->descent+2;i++)
             XDrawLine(XCURSESDISPLAY,XCURSESWIN,rect_cursor_gc,(xpos),(ypos-2+i),(xpos+XCursesFontWidth),(ypos-2+i));
#ifdef PDCDEBUG
         if (trace_on) PDC_debug("%s:XCursesDisplayCursor() - draw line at row %d col %d\n",(XCursesProcess)?"     X":"CURSES",new_row,new_x);
#endif
         break;
    default:
         makeXY(new_x,new_row,XCursesFontWidth,XCursesFontHeight,&xpos,&ypos);
         ch = (chtype *)(Xcurscr+XCURSCR_Y_OFF(new_row)+(new_x*sizeof(chtype)));
         buf[0] =  (char)(*ch & A_CHARTEXT);
         buf[1] = '\0';
         XSetForeground(XCURSESDISPLAY, block_cursor_gc, colors[COLOR_BLACK]); /* use original foreground colour ? */
         XDrawImageString(XCURSESDISPLAY,XCURSESWIN,block_cursor_gc,xpos,ypos,buf,1);
#ifdef PDCDEBUG
         if (trace_on) PDC_debug("%s:XCursesDisplayCursor() - draw cursor at row: %d col %d char <%s>\n",(XCursesProcess)?"     X":"CURSES",new_row,new_x,buf);
#endif
         break;
   }
 return;
}
/***********************************************************************/
#ifdef HAVE_PROTO
void XCursesGetIcon(void)
#else
void XCursesGetIcon()
#endif
/***********************************************************************/
{
 XIconSize *icon_size;
 int size_count=0;
 Status rc=0;
 unsigned char *bitmap_bits=NULL;
 unsigned int icon_bitmap_width=0,icon_bitmap_height=0;
 unsigned int file_bitmap_width=0,file_bitmap_height=0;
 int max_height=0,max_width=0;
 int x_hot=0,y_hot=0;
 int i;

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesGetIcon\n",(XCursesProcess)?"     X":"CURSES");
#endif
 icon_size = XAllocIconSize();
 rc = XGetIconSizes(XtDisplay(topLevel),
                    RootWindowOfScreen(XtScreen(topLevel)),
                    &icon_size,
                    &size_count);
 if (rc  /* if the WM can advise on icon sizes... */
 &&  size_count)
   {
#ifdef PDCDEBUG
    if (trace_on) PDC_debug("%s:size_count: %d rc: %d\n",(XCursesProcess)?"     X":"CURSES",size_count,rc);
#endif
    for (i=0;i<size_count;i++)
       {
        if (icon_size[i].max_width > max_width)
           max_width = icon_size[i].max_width;
        if (icon_size[i].max_height > max_height)
           max_height = icon_size[i].max_height;
#ifdef PDCDEBUG
        if (trace_on) PDC_debug("%s:min: %d %d\n",(XCursesProcess)?"     X":"CURSES",icon_size[i].min_width,icon_size[i].min_height);
        if (trace_on) PDC_debug("%s:max: %d %d\n",(XCursesProcess)?"     X":"CURSES",icon_size[i].max_width,icon_size[i].max_height);
        if (trace_on) PDC_debug("%s:inc: %d %d\n",(XCursesProcess)?"     X":"CURSES",icon_size[i].width_inc,icon_size[i].height_inc);
#endif
       }
    if (max_width >= BIG_ICON_WIDTH
    &&  max_height >= BIG_ICON_HEIGHT)
      {
       icon_bitmap_width = BIG_ICON_WIDTH;
       icon_bitmap_height = BIG_ICON_HEIGHT;
       bitmap_bits = (unsigned char *)big_icon_bitmap_bits;
      }
    else
      {
       icon_bitmap_width = LITTLE_ICON_WIDTH;
       icon_bitmap_height = LITTLE_ICON_HEIGHT;
       bitmap_bits = (unsigned char *)little_icon_bitmap_bits;
      }
   }
 else  /* WM won't tell us what icon size to use, so use small icon :-( */
   {
    icon_bitmap_width = LITTLE_ICON_WIDTH;
    icon_bitmap_height = LITTLE_ICON_HEIGHT;
    bitmap_bits = (unsigned char *)little_icon_bitmap_bits;
   }
 XFree((char *)icon_size);

 if (strcmp(XCURSESBITMAPFILE,"") != 0) /* supplied bitmap */
   {
    rc = XReadBitmapFile(XtDisplay(topLevel),
                         RootWindowOfScreen(XtScreen(topLevel)),
                         (char *)XCURSESBITMAPFILE,
                         &file_bitmap_width,
                         &file_bitmap_height,
                         &icon_pixmap,
                         &x_hot,
                         &y_hot);
    switch(rc)
      {
       case BitmapOpenFailed:
            fprintf(stderr,"bitmap file %s: not found\n",XCURSESBITMAPFILE);
            break;
       case BitmapFileInvalid:
            fprintf(stderr,"bitmap file %s: contents invalid\n",XCURSESBITMAPFILE);
            break;
       default:
            return;
            break;
      }
   }
 icon_pixmap = XCreateBitmapFromData(XtDisplay(topLevel),
                                     RootWindowOfScreen(XtScreen(topLevel)),
                                     (char *)bitmap_bits,
                                     icon_bitmap_width, 
                                     icon_bitmap_height);
 return;
}
/***********************************************************************/
#ifdef HAVE_PROTO
void XCursesExpose(Widget w,XtPointer client_data,XEvent *event,Boolean *continue_to_dispatch)
#else
void XCursesExpose(w,client_data,event,continue_to_dispatch)
Widget w;
XtPointer client_data;
XEvent *event;
Boolean *continue_to_dispatch;
#endif
/***********************************************************************/
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesExpose called\n",(XCursesProcess)?"     X":"CURSES");
#endif

#if 0
/* get all other Expose events on the queue */
  while (XCheckTypedEvent(display, Expose, &event))
#endif
 if (event->xexpose.count != 0) /* ignore all Exposes except last */
    return;

#if 0
 XCursesDisplayScreen(FALSE);
/*
 * Can we here determine largest rectangle to refresh based on all outstanding
 * expose events?
 */
/*
 * should refresh that portion of the screen now exposed - in XCursesProcess
 * using event.x, event.y, event.width, event.height to determine row/col
 * to refresh. Call XCursesDisplayText() to do the refresh.
 */
 if (after_first_curses_request
 &&  after_first_expose_event)
   {
    XCursesRefreshScreen();
    XCursesDisplayCursor(SP->cursrow,SP->curscol,
                        SP->cursrow,SP->curscol);
   }
 after_first_expose_event = True;
#else
 if (after_first_curses_request
 &&  ReceivedMapNotify)
     XCursesDisplayScreen(FALSE);
#endif
 return;
}
/***********************************************************************/
#ifdef HAVE_PROTO
void XCursesStructureNotify(Widget w,XtPointer client_data,XEvent *event,Boolean *continue_to_dispatch)
#else
void XCursesStructureNotify(w,client_data,event,continue_to_dispatch)
Widget w;
XtPointer client_data;
XEvent *event;
Boolean *continue_to_dispatch;
#endif
/***********************************************************************/
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesStructureNotify called\n",(XCursesProcess)?"     X":"CURSES");
#endif
 switch(event->type)
   {
    case ConfigureNotify:
#ifdef PDCDEBUG
         say("ConfigureNotify received\n");
#endif
    /* window has been resized, change width and
     * height to send to place_text and place_graphics
     * in next Expose */
    /* also will  need to kill (SIGWINCH) curses process if screen
     * size changes
     */
         resizeXCursesWindowWidth = (event->xconfigure.width);
         resizeXCursesWindowHeight = (event->xconfigure.height);
         after_first_curses_request = False;
#ifdef SIGWINCH
         kill(otherpid,SIGWINCH);
#endif
         break;
    case MapNotify:
#ifdef PDCDEBUG
         say("MapNotify received\n");
#endif
         ReceivedMapNotify=1;
         /*
          * Draw the window border
          */
         if (XCURSESBORDERWIDTH)
            XDrawRectangle(XCURSESDISPLAY,XCURSESWIN,border_gc,
                          (XCURSESBORDERWIDTH/2),(XCURSESBORDERWIDTH/2),
                          (XCursesWindowWidth-XCURSESBORDERWIDTH),
                          (XCursesWindowHeight-XCURSESBORDERWIDTH));
         break;
    default:
#ifdef PDCDEBUG
         if (trace_on) PDC_debug("%s:XCursesStructureNotify - unknown event %d\n",(XCursesProcess)?"     X":"CURSES",event->type);
#endif
         break;
   }
 return;
}
/***********************************************************************/
#ifdef HAVE_PROTO
void XCursesNonmaskable(Widget w,XtPointer client_data,XEvent *event,Boolean *continue_to_dispatch)
#else
void XCursesNonmaskable(w,client_data,event,continue_to_dispatch)
Widget w;
XtPointer client_data;
XEvent *event;
Boolean *continue_to_dispatch;
#endif
/***********************************************************************/
{
 XClientMessageEvent *client_event=(XClientMessageEvent *)event;

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesNonmaskable called: otherpid %d\n",(XCursesProcess)?"     X":"CURSES",otherpid);
#endif
 switch(event->type)
   {
    case ClientMessage:
#ifdef PDCDEBUG
         say("ClientMessage received\n");
#endif
         if ((Atom)client_event->data.s[0] == wm_atom[0]
         ||  (Atom)client_event->data.s[0] == wm_atom[1])
            XCursesExitXCursesProcess(0,SIGKILL,"");
         break;
    default:
#ifdef PDCDEBUG
         if (trace_on) PDC_debug("%s:XCursesNonmaskable - unknown event %d\n",(XCursesProcess)?"     X":"CURSES",event->type);
#endif
         break;
   }
 return;
}
/***********************************************************************/
#ifdef HAVE_PROTO
static void XCursesButton(Widget w,XEvent *event, String *params, Cardinal *nparams)
#else
static void XCursesButton(w,event,params,nparams)
Widget w;
XEvent *event;
String *params;
Cardinal *nparams;
#endif
/***********************************************************************/
{
 int button_no=0;
 static int last_button_no;
 static Time last_button_press_time=0;
 MOUSE_STATUS save_mouse_status;
 bool send_key=TRUE;
 char buf[100]; /* for MOUSE_STATUS struct */

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesButton called\n",(XCursesProcess)?"     X":"CURSES");
#endif

 save_mouse_status=Mouse_status;
 button_no = event->xbutton.button;
/*---------------------------------------------------------------------*/
/* It appears that under X11R6 (at least on Linux), that an event_type */
/* of ButtonMotion does not include the mouse button in the event. The */
/* following code is designed to cater for this situation.             */
/*---------------------------------------------------------------------*/
 if (button_no == 0)
    button_no = last_button_no;
 last_button_no = button_no;

 Mouse_status.changes = 0;
 switch(event->type)
   {
    case ButtonPress:
#ifdef MOUSE_DEBUG
       printf("\nButtonPress\n");
#endif
         if ((event->xbutton.time - last_button_press_time) < XCURSESDOUBLECLICKPERIOD)
           {
            MOUSE_X_POS = save_mouse_status.x;
            MOUSE_Y_POS = save_mouse_status.y;
            BUTTON_STATUS(button_no) = BUTTON_DOUBLE_CLICKED;
            if (!(SP->_trap_mbe & BUTTON1_DOUBLE_CLICKED)
            &&  button_no == 1)
               send_key = FALSE;
            if (!(SP->_trap_mbe & BUTTON2_DOUBLE_CLICKED)
            &&  button_no == 2)
               send_key = FALSE;
            if (!(SP->_trap_mbe & BUTTON3_DOUBLE_CLICKED)
            &&  button_no == 3)
               send_key = FALSE;
           }
         else
           {
            MOUSE_X_POS = (event->xbutton.x-XCURSESBORDERWIDTH) / XCursesFontWidth;
            MOUSE_Y_POS = (event->xbutton.y-XCURSESBORDERWIDTH) / XCursesFontHeight;
            BUTTON_STATUS(button_no) = BUTTON_PRESSED;
            if (!(SP->_trap_mbe & BUTTON1_PRESSED)
            &&  button_no == 1)
               send_key = FALSE;
            if (!(SP->_trap_mbe & BUTTON2_PRESSED)
            &&  button_no == 2)
               send_key = FALSE;
            if (!(SP->_trap_mbe & BUTTON3_PRESSED)
            &&  button_no == 3)
               send_key = FALSE;
           }
         last_button_press_time = event->xbutton.time;
         break;
    case MotionNotify:
#ifdef MOUSE_DEBUG
       printf("\nMotionNotify: y: %d x: %d Width: %d Height: %d\n",event->xbutton.y,
                event->xbutton.x,
                XCursesFontWidth,
                XCursesFontHeight);
#endif
         /*
          * Throw away mouse movements if they are in the same character position
          * as the last mouse event, or if we are currently in the middle of
          * a double click event.
          */
         MOUSE_X_POS = (event->xbutton.x-XCURSESBORDERWIDTH) / XCursesFontWidth;
         MOUSE_Y_POS = (event->xbutton.y-XCURSESBORDERWIDTH) / XCursesFontHeight;
         if ((MOUSE_X_POS == save_mouse_status.x
           &&  MOUSE_Y_POS == save_mouse_status.y)
         ||  save_mouse_status.button[button_no-1] == BUTTON_DOUBLE_CLICKED)
           {
            send_key = FALSE;
            break;
           }
         MOUSE_X_POS = (event->xbutton.x-XCURSESBORDERWIDTH) / XCursesFontWidth;
         MOUSE_Y_POS = (event->xbutton.y-XCURSESBORDERWIDTH) / XCursesFontHeight;
         Mouse_status.changes |= 8;
            if (!(SP->_trap_mbe & BUTTON1_MOVED)
            &&  button_no == 1)
               send_key = FALSE;
            if (!(SP->_trap_mbe & BUTTON2_MOVED)
            &&  button_no == 2)
               send_key = FALSE;
            if (!(SP->_trap_mbe & BUTTON3_MOVED)
            &&  button_no == 3)
               send_key = FALSE;
         break;
    case ButtonRelease:
#ifdef MOUSE_DEBUG
       printf("\nButtonRelease\n");
#endif
         MOUSE_X_POS = (event->xbutton.x-XCURSESBORDERWIDTH) / XCursesFontWidth;
         MOUSE_Y_POS = (event->xbutton.y-XCURSESBORDERWIDTH) / XCursesFontHeight;
         BUTTON_STATUS(button_no) = BUTTON_RELEASED;
            if (!(SP->_trap_mbe & BUTTON1_RELEASED)
            &&  button_no == 1)
               send_key = FALSE;
            if (!(SP->_trap_mbe & BUTTON2_RELEASED)
            &&  button_no == 2)
               send_key = FALSE;
            if (!(SP->_trap_mbe & BUTTON3_RELEASED)
            &&  button_no == 3)
               send_key = FALSE;
         break;
   }
/*
 *---------------------------------------------------------------------
 * Set up the mouse status fields in preparation for sending...
 *---------------------------------------------------------------------
 */
 Mouse_status.changes |= (1 << (button_no-1));
 if (event->xbutton.state & ShiftMask)
    BUTTON_STATUS(button_no) |= BUTTON_SHIFT;
 if (event->xbutton.state & ControlMask)
    BUTTON_STATUS(button_no) |= BUTTON_CONTROL;
 if (event->xbutton.state & Mod1Mask)
    BUTTON_STATUS(button_no) |= BUTTON_ALT;
/*
 *---------------------------------------------------------------------
 * If we are ignoring the event, or the mouse position is outside the
 * bounds of the screen (because of the border), return here...
 *---------------------------------------------------------------------
 */
 if (!send_key
 ||  MOUSE_X_POS < 0
 ||  MOUSE_X_POS >= XCursesCOLS
 ||  MOUSE_Y_POS < 0
 ||  MOUSE_Y_POS >= XCursesLINES)
   return;

#ifdef MOUSE_DEBUG
 printf("Button: %d x: %d y: %d Button status: %x Mouse status: %x\n",button_no,
                                    MOUSE_X_POS,
                                    MOUSE_Y_POS,
                                    BUTTON_STATUS(button_no),
                                    Mouse_status.changes);
 printf("Send: %d Button1: %x Button2: %x Button3: %x\n",send_key,
                                    BUTTON_STATUS(1),
                                    BUTTON_STATUS(2),
                                    BUTTON_STATUS(3));
#endif
/*---------------------------------------------------------------------*/
/* Send the KEY_MOUSE to curses program...                             */
/*---------------------------------------------------------------------*/
 XCursesSendKeyToCurses(KEY_MOUSE);
 memcpy(buf,(char *)&Mouse_status,sizeof(MOUSE_STATUS));
#ifdef MOUSE_DEBUG1
    printf("%s:writing mouse stuff\n",(XCursesProcess)?"     X":"CURSES");
#endif
 (void)write_socket(key_sock,buf,sizeof(MOUSE_STATUS));
 return;
}
/***********************************************************************/
#ifdef HAVE_PROTO
static int XCursesSetupCurses(void)
#else
static int XCursesSetupCurses()
#endif
/***********************************************************************/
{
 char wait_buf[5];
 int wait_value;
#if defined(SA_INTERRUPT)
 struct sigaction sigact;
#endif

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesSetupCurses called\n",(XCursesProcess)?"     X":"CURSES");
#endif
 close ( display_sockets[1] );
 close ( key_sockets[1] );
 display_sock = display_sockets[0];
 key_sock = key_sockets[0];
 FD_ZERO ( &readfds );
 FD_ZERO ( &writefds );
 read_socket(display_sock,wait_buf,sizeof(int));
 memcpy((char *)&wait_value,wait_buf,sizeof(int));
 if (wait_value != CURSES_CHILD)
    return(ERR);
/*---------------------------------------------------------------------*/
/* Set LINES and COLS now so that the size of the                      */
/*---------------------------------------------------------------------*/
 if ((shmidSP = shmget(shmkeySP,sizeof(SCREEN)+XCURSESSHMMIN,0700)) < 0)
   {
    perror("Cannot allocate shared memory for SCREEN");
    kill(otherpid,SIGKILL);
    return(ERR);
   }
 SP = (SCREEN*)shmat(shmidSP,0,0);
 XCursesLINES = SP->lines;
 LINES = XCursesLINES - SP->linesrippedoff;
 XCursesCOLS = COLS = SP->cols;
 if ((shmid_Xcurscr = shmget(shmkey_Xcurscr,SP->XcurscrSize+XCURSESSHMMIN,0700)) < 0)
   {
    perror("Cannot allocate shared memory for curscr");
    kill(otherpid,SIGKILL);
    return(ERR);
   }
#ifdef PDCDEBUG
 if (trace_on) PDC_debug("%s:shmid_Xcurscr %d shmkey_Xcurscr %d LINES %d COLS %d\n",(XCursesProcess)?"     X":"CURSES",shmid_Xcurscr,shmkey_Xcurscr,LINES,COLS);
#endif
 Xcurscr = (unsigned char *)shmat(shmid_Xcurscr,0,0);
 atrtab = (unsigned char *)(Xcurscr+XCURSCR_ATRTAB_OFF);
 PDC_init_atrtab();
#ifdef PDCDEBUG
 say ("cursesprocess exiting from Xinitscr\n");
#endif
/*---------------------------------------------------------------------*/
/* Always trap SIGWINCH if the C library supports SIGWINCH...          */
/*---------------------------------------------------------------------*/
#ifdef SIGWINCH
# if defined(SA_INTERRUPT)
 sigact.sa_handler = XCursesSigwinchHandler;
 sigact.sa_flags = SA_INTERRUPT;
 sigact.sa_mask = 0;
 (void)sigaction(SIGWINCH, &sigact, NULL );
# else
 (void)signal(SIGWINCH, XCursesSigwinchHandler );
# endif
#endif
 return(OK);
}
/***********************************************************************/
#ifdef HAVE_PROTO
static int XCursesSetupX(char *display_name)
#else
static int XCursesSetupX(display_name)
char *display_name;
#endif
/***********************************************************************/
{
 XColor pointerforecolor,pointerbackcolor;
 XrmValue rmfrom,rmto;
 char wait_buf[5];
 int wait_value=0,i=0;
 int minwidth=0,minheight=0;
/*
 * The following kludge is to force XtVaAppInitialize() to recognize the
 * name of the program.  Without it, a default value of "main" is used.
 */
 int argc=1;
 char *argv[2];

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesSetupX called\n",(XCursesProcess)?"     X":"CURSES");
#endif
 argv[0] = XCursesProgramName;
 argv[1] = NULL;

/*---------------------------------------------------------------------*/
/* Keep open the 'write' end of the socket so the XCurses process can  */
/* send a CURSES_EXIT to itself from within the signal handler...      */
/*---------------------------------------------------------------------*/
#if 0
 close ( display_sockets[0] );
#else
 exit_sock = display_sockets[0];
#endif
 display_sock = display_sockets[1];
 close ( key_sockets[0] );
 key_sock = key_sockets[1];
/*---------------------------------------------------------------------*/
/* Trap all signals when XCurses is the child process...               */
/*---------------------------------------------------------------------*/
 for (i=0;i<NSIG;i++)
    (void)signal(i,XCursesSignalHandler);
/*---------------------------------------------------------------------*/
/* Start defining X Toolkit things...                                  */
/*---------------------------------------------------------------------*/
#if XtSpecificationRelease > 4
 XtSetLanguageProc(NULL, (XtLanguageProc)NULL,NULL);
#endif
/*---------------------------------------------------------------------*/
/* If a DISPLAY value has been supplied, set the env variable DISPLAY. */
/*---------------------------------------------------------------------*/
 if (display_name)
   {
    strcpy(global_display_name,"DISPLAY=");
    strcat(global_display_name,display_name);
    putenv(global_display_name);
   }
/*---------------------------------------------------------------------*/
/* Exit if no DISPLAY variable set...                                  */
/*---------------------------------------------------------------------*/
 if (getenv("DISPLAY") == NULL)
   {
    fprintf(stderr,"Error: no DISPLAY variable set\n");
    kill(otherpid,SIGKILL);
    return(ERR);
   }
/*---------------------------------------------------------------------*/
/* Initialise the top level widget...                                  */
/*---------------------------------------------------------------------*/
 topLevel = XtVaAppInitialize(&app_context,XCursesClassName,NULL,0,&argc,argv,NULL,
/*
                              XtNinput, (XtArgVal)True,
                              XtNtitle,XCursesProgramName,
                              XtNname,"xcurses",
*/
                              NULL);
 XtVaGetApplicationResources(topLevel,&app_data,app_resources,XtNumber(app_resources),NULL);
/* check application resource values here... */

 XCursesFontWidth = XCURSESNORMALFONTINFO->max_bounds.rbearing - XCURSESNORMALFONTINFO->min_bounds.lbearing;
 XCursesFontHeight = XCURSESNORMALFONTINFO->max_bounds.ascent + XCURSESNORMALFONTINFO->max_bounds.descent;
/*---------------------------------------------------------------------*/
/* Check that the bold font and normal fonts are the same size...      */
/*---------------------------------------------------------------------*/
 if (XCursesFontWidth != XCURSESBOLDFONTINFO->max_bounds.rbearing - XCURSESBOLDFONTINFO->min_bounds.lbearing
 ||  XCursesFontHeight != XCURSESBOLDFONTINFO->max_bounds.ascent + XCURSESBOLDFONTINFO->max_bounds.descent)
   {
    fprintf(stderr,"Error: normal font and bold font are different sizes\n");
    fprintf(stderr,"\tNormal\tBold\n");
    fprintf(stderr,"Width :\t%d\t%d\n",XCursesFontWidth,XCURSESBOLDFONTINFO->max_bounds.rbearing - XCURSESBOLDFONTINFO->min_bounds.lbearing);
    fprintf(stderr,"Height:\t%d\t%d\n",XCursesFontHeight,XCURSESBOLDFONTINFO->max_bounds.ascent + XCURSESBOLDFONTINFO->max_bounds.descent);
    kill(otherpid,SIGKILL);
    return(ERR);
   }
/*---------------------------------------------------------------------*/
/* Calculate size of display window...                                 */
/*---------------------------------------------------------------------*/
 XCursesCOLS = XCURSESCOLS;
 XCursesLINES = XCURSESLINES;
 XCursesWindowWidth = (XCursesFontWidth * XCursesCOLS) + (2 * XCURSESBORDERWIDTH);
 XCursesWindowHeight = (XCursesFontHeight * XCursesLINES) + (2 * XCURSESBORDERWIDTH);
 minwidth = (XCursesFontWidth*2)+(XCURSESBORDERWIDTH*2);
 minheight = (XCursesFontHeight*2)+(XCURSESBORDERWIDTH*2);
/*---------------------------------------------------------------------*/
/* Set up the icon for the application. The default is an internal one */
/* for XCurses. Then set various application level resources...        */
/*---------------------------------------------------------------------*/
 XCursesGetIcon();

 XtVaSetValues(topLevel,
                        XtNwidthInc,XCursesFontWidth,
                        XtNheightInc,XCursesFontHeight,
                        XtNminWidth,minwidth,
                        XtNminHeight,minheight,
                        XtNiconPixmap,icon_pixmap,
                        NULL);
/*---------------------------------------------------------------------*/
/* Create a BOX widget in which to draw..                              */
/*---------------------------------------------------------------------*/
 drawing = XtVaCreateManagedWidget(XCursesProgramName,boxWidgetClass,topLevel,
                                   XtNwidth,XCursesWindowWidth,
                                   XtNheight,XCursesWindowHeight,
                                   NULL);
/*
 XtVaSetValues(drawing,
                                   XtNwidth,XCursesWindowWidth,
                                   XtNheight,XCursesWindowHeight,
                              XtNwidthInc,XCursesFontWidth,
                              XtNheightInc,XCursesFontHeight,
                              XtNminWidth,XCursesFontWidth*2,
                              XtNminHeight,XCursesFontHeight*2,
                        XtNborderWidth,20,
               NULL);
*/
/*---------------------------------------------------------------------*/
/* Process any default translations...                                 */
/*---------------------------------------------------------------------*/
 XCursesTranslations = XtParseTranslationTable(defaultTranslations);
 XtAugmentTranslations(drawing,XCursesTranslations);
 XtAppAddActions(app_context,XCursesActions,XtNumber(XCursesActions));
/*---------------------------------------------------------------------*/
/* Process the supplied colors...                                      */
/*---------------------------------------------------------------------*/
 if (get_colors() == ERR)
   {
    kill(otherpid,SIGKILL);
    return(ERR);
   }
/*---------------------------------------------------------------------*/
/* Now have LINES and COLS. Set these in the shared SP so the    */
/* curses program can find them...                                     */
/*---------------------------------------------------------------------*/
 LINES = XCursesLINES;
 COLS = XCursesCOLS;
 if ((shmidSP = shmget(shmkeySP,sizeof(SCREEN)+XCURSESSHMMIN,0700|IPC_CREAT)) < 0)
   {
    perror("Cannot allocate shared memory for SCREEN");
    kill(otherpid,SIGKILL);
    return(ERR);
   }
 SP = (SCREEN*)shmat(shmidSP,0,0);
 memset(SP, 0, sizeof(SCREEN));
 SP->XcurscrSize = XCURSCR_SIZE;
 SP->lines = XCursesLINES;
 SP->cols = XCursesCOLS;
#ifdef PDCDEBUG
 if (trace_on) PDC_debug("%s:SHM size for curscr %d\n",(XCursesProcess)?"     X":"CURSES",SP->XcurscrSize);
#endif
 if ((shmid_Xcurscr = shmget(shmkey_Xcurscr,SP->XcurscrSize+XCURSESSHMMIN,0700|IPC_CREAT)) < 0)
   {
    perror("Cannot allocate shared memory for curscr");
    kill(otherpid,SIGKILL);
    shmdt((char *)SP);
    shmctl(shmidSP,IPC_RMID,0);
    return(ERR);
   }
 Xcurscr = (unsigned char *)shmat(shmid_Xcurscr,0,0);
 memset(Xcurscr, 0, SP->XcurscrSize); 
 atrtab = (unsigned char *)(Xcurscr+XCURSCR_ATRTAB_OFF);
 PDC_init_atrtab();
#ifdef PDCDEBUG
 if (trace_on) PDC_debug("%s:shmid_Xcurscr %d shmkey_Xcurscr %d LINES %d COLS %d\n",(XCursesProcess)?"     X":"CURSES",shmid_Xcurscr,shmkey_Xcurscr,LINES,COLS);
#endif
/*---------------------------------------------------------------------*/
/* Add Event handlers to the drawing widget...                         */
/*---------------------------------------------------------------------*/
 XtAddEventHandler(drawing,ExposureMask,False,XCursesExpose,NULL);
/* XtAddEventHandler(drawing,KeyPressMask|KeyReleaseMask,False,XCursesKeyPressKeyRelease,NULL); */
/* XtAddEventHandler(drawing,ButtonPressMask|ButtonReleaseMask,False,XCursesButtonPressButtonRelease,NULL);*/
 XtAddEventHandler(drawing,StructureNotifyMask,False,XCursesStructureNotify,NULL);
#if 0
 XtAddEventHandler(drawing,0,True,XCursesNonmaskable,NULL);
#endif
 XtAddEventHandler(topLevel,0,True,XCursesNonmaskable,NULL);
/*---------------------------------------------------------------------*/
/* Add input handler form display_sock (requests from curses program)  */
/*---------------------------------------------------------------------*/
 XtAppAddInput(app_context,display_sock,(XtPointer)XtInputReadMask,XCursesProcessRequestsFromCurses,NULL);
/*---------------------------------------------------------------------*/
/* Leave telling the curses process that it can start to here so that  */
/* when the curses process makes a request, the Xcurses process can    */
/* service the request...                                              */
/*---------------------------------------------------------------------*/
 wait_value = CURSES_CHILD;
 memcpy(wait_buf,(char *)&wait_value,sizeof(int));
 (void)write_socket(display_sock,wait_buf,sizeof(int));
/*---------------------------------------------------------------------*/
/* Realize the widget...                                               */
/*---------------------------------------------------------------------*/
 XtRealizeWidget(topLevel);
/*---------------------------------------------------------------------*/
/* Handle trapping of the WM_DELETE_WINDOW property...                 */
/*---------------------------------------------------------------------*/
 wm_atom[0] = XInternAtom(XtDisplay(topLevel),"WM_DELETE_WINDOW",False);
 wm_atom[1] = XInternAtom(XtDisplay(topLevel),"WM_SAVE_YOURSELF",False);
/* (void)XSetWMProtocols(XtDisplay(topLevel),RootWindowOfScreen(XtScreen(topLevel)),&wm_delete_window_atom,1);*/
/* (void)XSetWMProtocols(XtDisplay(topLevel),XCURSESWIN,&wm_delete_window_atom,1);*/
 (void)XSetWMProtocols(XtDisplay(topLevel),XtWindow(topLevel),wm_atom,2);
/*---------------------------------------------------------------------*/
/* Create the Graphics Context for drawing. This MUST be done AFTER the*/
/* associated widget has been realized...                              */
/*---------------------------------------------------------------------*/
#ifdef PDCDEBUG
  say("before get_GC\n");
#endif
 get_GC(XCURSESDISPLAY,XCURSESWIN,&normal_gc,XCURSESNORMALFONTINFO,COLOR_WHITE,COLOR_BLACK,FALSE);
 get_GC(XCURSESDISPLAY,XCURSESWIN,&bold_gc,XCURSESBOLDFONTINFO,COLOR_WHITE,COLOR_BLACK,FALSE);
 get_GC(XCURSESDISPLAY,XCURSESWIN,&normal_highlight_gc,XCURSESNORMALFONTINFO,COLOR_WHITE,COLOR_BLACK,TRUE);
 get_GC(XCURSESDISPLAY,XCURSESWIN,&bold_highlight_gc,XCURSESBOLDFONTINFO,COLOR_WHITE,COLOR_BLACK,TRUE);
 get_GC(XCURSESDISPLAY,XCURSESWIN,&block_cursor_gc,XCURSESNORMALFONTINFO,COLOR_BLACK,COLOR_CURSOR,FALSE);
 get_GC(XCURSESDISPLAY,XCURSESWIN,&rect_cursor_gc,XCURSESNORMALFONTINFO,COLOR_CURSOR,COLOR_BLACK,FALSE);
 get_GC(XCURSESDISPLAY,XCURSESWIN,&border_gc,XCURSESNORMALFONTINFO,COLOR_BORDER,COLOR_BLACK,FALSE);
/*
 XSetLineAttributes(XCURSESDISPLAY,normal_gc,2,LineSolid,CapButt,JoinMiter);
 XSetLineAttributes(XCURSESDISPLAY,bold_gc,2,LineSolid,CapButt,JoinMiter);
*/
 XSetLineAttributes(XCURSESDISPLAY,rect_cursor_gc,2,LineSolid,CapButt,JoinMiter);
 XSetLineAttributes(XCURSESDISPLAY,border_gc,XCURSESBORDERWIDTH,LineSolid,CapButt,JoinMiter);
/*---------------------------------------------------------------------*/
/* Set the cursor for the application...                               */
/*---------------------------------------------------------------------*/
 XDefineCursor(XCURSESDISPLAY,XCURSESWIN,XCURSESPOINTER);
 rmfrom.size = sizeof(Pixel);
 rmto.size = sizeof(XColor);
#if XtSpecificationRelease > 4
 rmto.addr = (XPointer)&pointerforecolor;
 rmfrom.addr = (XPointer)&(XCURSESPOINTERFORECOLOR);
 XtConvertAndStore(drawing,XtRPixel,&rmfrom,XtRColor,&rmto);
#else
 rmto.addr = (char *)&pointerforecolor;
 rmfrom.addr = (char *)&(XCURSESPOINTERFORECOLOR);
 XtConvert(drawing,XtRPixel,&rmfrom,XtRColor,&rmto);
#endif
 rmfrom.size = sizeof(Pixel);
 rmto.size = sizeof(XColor);
#if XtSpecificationRelease > 4
 rmfrom.addr = (XPointer)&(XCURSESPOINTERBACKCOLOR);
 rmto.addr = (XPointer)&pointerbackcolor;
 XtConvertAndStore(drawing,XtRPixel,&rmfrom,XtRColor,&rmto);
#else
 rmfrom.addr = (char *)&(XCURSESPOINTERBACKCOLOR);
 rmto.addr = (char *)&pointerbackcolor;
 XtConvert(drawing,XtRPixel,&rmfrom,XtRColor,&rmto);
#endif
 XRecolorCursor(XCURSESDISPLAY,XCURSESPOINTER,&pointerforecolor,&pointerbackcolor);
/*---------------------------------------------------------------------*/
/* Convert the supplied compose key to a Keysym...                     */
/*---------------------------------------------------------------------*/
 compose_key = XStringToKeysym(XCURSESCOMPOSEKEY);
 if (compose_key
 &&  IsModifierKey(compose_key))
   {
    register int i=0,j=0;
    KeyCode *kcp;
    XModifierKeymap *map;
    KeyCode compose_keycode=XKeysymToKeycode(XCURSESDISPLAY,compose_key);
    map = XGetModifierMapping(XCURSESDISPLAY);
    kcp = map->modifiermap;
    for (i=0;i<8;i++)
      {
       for (j=0;j<map->max_keypermod;j++,kcp++)
         {
          if (!*kcp)
             continue;
          if (compose_keycode == *kcp)
            {
             compose_mask = state_mask[i];
             break;
            }
         }
       if (compose_mask)
          break;
      }
    XFreeModifiermap(map);
   }
/* fprintf(stderr,"COMPOSE KEY: %d %s STATE: %d\n",compose_key,XCURSESCOMPOSEKEY,compose_mask);*/

#ifdef FOREIGN
 sleep(20);
 if ((Xim = XOpenIM(XCURSESDISPLAY,NULL,NULL,NULL)) == NULL)
   {
    perror("Cannot open Input Method");
    kill(otherpid,SIGKILL);
    shmdt((char *)SP);
    shmdt((char *)Xcurscr);
    shmctl(shmidSP,IPC_RMID,0);
    shmctl(shmid_Xcurscr,IPC_RMID,0);
    return(ERR);
   }
 XGetIMValues(Xim,XNQueryInputStyle, &im_supported_styles, NULL);
 my_style = XIMPreeditNone|XIMStatusNone;
/* call XtCvtStringToFontSet ??? */
 if ((Xic = XCreateIC(Xim, XNInputStyle, my_style,
/*

*/
                      NULL)) == NULL)
   {
    perror("ERROR: Cannot create input context");
    kill(otherpid,SIGKILL);
    shmdt((char *)SP);
    shmdt((char *)Xcurscr);
    shmctl(shmidSP,IPC_RMID,0);
    shmctl(shmid_Xcurscr,IPC_RMID,0);
    return(ERR);
   }
 XFree(im_supported_styles);
 XGetICValues(Xic, XNFilterEvents, &im_event_mask, NULL);
 XtAddEventHandler(drawing,im_event_mask,False,NULL,NULL);
 XSetICFocus(Xic);
#endif
/*---------------------------------------------------------------------*/
/* Wait for events...                                                  */
/*---------------------------------------------------------------------*/
 XtAppMainLoop(app_context);
 return(OK); /* won't get here */
}
/***********************************************************************/
#ifdef HAVE_PROTO
int XCursesInitscr(char *display_name)
#else
int XCursesInitscr(display_name)
char *display_name;
#endif
/***********************************************************************/
{
 int pid,rc;

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesInitscr() - called\n",(XCursesProcess)?"     X":"CURSES");
#endif

#if defined FOREIGN
 if (setlocale(LC_ALL, "") == NULL)
   {
    fprintf(stderr, "ERROR: cannot set locale\n");
    return(ERR);
   }
 if (!XSupportsLocale())
   {
    fprintf(stderr, "ERROR: X does not support locale\n");
    return(ERR);
   }
 if (XSetLocaleModifiers("") == NULL)
    fprintf(stderr, "WARNING: Cannot set locale modifiers\n");
#endif

 shmkeySP = getpid();
 memset ( &socket_timeout, '\0', sizeof ( socket_timeout ) );
            
 if ( socketpair ( AF_UNIX, SOCK_STREAM, 0, display_sockets ) < 0 )
   {
    fprintf(stderr, "ERROR: cannot create display socketpair\n");
    return(ERR);
    }
            
 if ( socketpair ( AF_UNIX, SOCK_STREAM, 0, key_sockets ) < 0 )
   {
    fprintf(stderr, "ERROR: cannot create key socketpair\n");
    return(ERR);
    }

 pid = fork();
 switch(pid)
   {
   case (-1):
         fprintf(stderr,"ERROR: cannot fork()\n");
         return(ERR);
         break;
    case 0: /* child */
         shmkey_Xcurscr = getpid();
#ifdef XISPARENT
         XCursesProcess=0;
         rc = XCursesSetupCurses();
#else
         XCursesProcess=1;
         otherpid = getppid();
         rc = XCursesSetupX(display_name);
#endif
         break;
    default: /* parent */
         shmkey_Xcurscr = pid;
#ifdef XISPARENT
         XCursesProcess=1;
         otherpid = pid;
         rc = XCursesSetupX(display_name);
#else
         XCursesProcess=0;
         rc = XCursesSetupCurses();
#endif
         break;
   }
 return(rc);
}
/***********************************************************************/
#ifdef HAVE_PROTO
static void XCursesKeyPress(Widget w,XEvent *event, String *params, Cardinal *nparams)
#else
static void XCursesKeyPress(w,event,params,nparams)
Widget w;
XEvent *event;
String *params;
Cardinal *nparams;
#endif
/***********************************************************************/
{
#define STATE_NORMAL   0
#define STATE_COMPOSE  1
#define STATE_CHAR     2
#ifdef FOREIGN
 wchar_t buffer[120];
#else
 char buffer[120];
#endif
 int buflen=40;
 int count,key,i;
 KeySym keysym;
 XComposeStatus compose;
 static int compose_state=STATE_NORMAL;
 static int compose_index=0;
 int save_visibility=0;
 int char_idx=0;
 int xpos,ypos;
#ifdef FOREIGN
 Status status;
#endif

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesKeyPress called\n",(XCursesProcess)?"     X":"CURSES");
#endif

 if (event->type == KeyRelease) /* ignore KeyRelease for now... */
    return;
 buffer[0] = '\0';
#ifdef FOREIGN
 count = XwcLookupString(Xic,&(event->xkey),buffer,buflen,&keysym, &status);
 switch(status)
   {
    case XLookupNone:
         fprintf(stderr,"XLookupNone status\n");
         break;
    case XLookupKeySym:
         fprintf(stderr,"XLookupKeySym status\n");
         break;
    case XLookupBoth:
         fprintf(stderr,"XLookupBoth status\n");
         break;
    case XLookupChars:
         fprintf(stderr,"XLookupChars status\n");
         break;
   }
#else
 count = XLookupString(&(event->xkey),buffer,buflen,&keysym, &compose);
#endif

/* translate keysym into curses key code */
#ifdef PDCDEBUG
 PDC_debug("%s:Key mask: %x\n",(XCursesProcess)?"     X":"CURSES",event->xkey.state);
 key = 0;
 for (key=0;key<4;key++)
   PDC_debug("%s:Keysym %x %d\n",(XCursesProcess)?"     X":"CURSES",XKeycodeToKeysym(XCURSESDISPLAY,event->xkey.keycode,key),key);
#endif

/* fprintf(stderr,"KEY: %d %s\n",keysym,XKeysymToString(keysym));*/
 key = 0;
 /*
  * Check if the key just pressed is the user-specified compose key
  * If it is, set the compose state and exit.
  */
 if (keysym == compose_key)
   {
/*    fprintf(stderr,"Compose key pressed\n");*/
    /*
     * Change the shape of the cursor to an outline rectangle
     * to indicate we are in "compose" status
     */
    save_visibility = SP->visibility;
    SP->visibility = 0;
    XCursesDisplayCursor(SP->cursrow,SP->curscol,
                         SP->cursrow,SP->curscol);
    SP->visibility = save_visibility;;
    makeXY(SP->curscol,SP->cursrow,XCursesFontWidth,XCursesFontHeight,&xpos,&ypos);
    XDrawRectangle(XCURSESDISPLAY,XCURSESWIN,rect_cursor_gc,(xpos+1),(ypos-XCursesFontHeight+(XCURSESNORMALFONTINFO->descent)+1),(XCursesFontWidth-2),(XCursesFontHeight-2));
/*    fprintf(stderr,"Descent:%d Ascent:%d\n",XCURSESNORMALFONTINFO->descent,XCURSESNORMALFONTINFO->ascent);*/
    compose_state = STATE_COMPOSE;
    return;
   }
 /*
  * If the key just pressed is just a modifier, ignore it.
  */
 if (IsModifierKey(keysym))
    return;
 switch(compose_state)
   {
    case STATE_COMPOSE:
         if (event->xkey.state & compose_mask)
           {
/* fprintf(stderr,"STATE_COMPOSE: char has compose_mask\n");*/
            compose_state = STATE_NORMAL;
            XCursesDisplayCursor(SP->cursrow,SP->curscol,
                                 SP->cursrow,SP->curscol);
            break;
           }
         if (buffer[0] != 0
         && count == 1)
             key = (int)buffer[0];
/*         fprintf(stderr,"STATE_COMPOSE: state %x %x\n",event->xkey.state,compose_mask);*/
         compose_index = (-1);
         for (i=0;i<(int)strlen(compose_chars);i++)
           {
            if ((int)compose_chars[i] == key)
              {
               compose_index = i;
               break;
              }
           }
/*         fprintf(stderr,"STATE_COMPOSE: %d - compose_index\n",compose_index);*/
         if (compose_index == (-1))
           {
            compose_state = STATE_NORMAL;
            compose_index = 0;
            XCursesDisplayCursor(SP->cursrow,SP->curscol,
                                 SP->cursrow,SP->curscol);
            break;
           }
         compose_state = STATE_CHAR;
         return;
         break;
    case STATE_CHAR:
         if (event->xkey.state & compose_mask)
           {
/* fprintf(stderr,"STATE_COMPOSE: char has compose_state\n");*/
            compose_state = STATE_NORMAL;
            XCursesDisplayCursor(SP->cursrow,SP->curscol,
                                 SP->cursrow,SP->curscol);
            break;
           }
         if (buffer[0] != 0
         && count == 1)
             key = (int)buffer[0];
         char_idx = (-1);
/*         fprintf(stderr,"STATE_CHAR: %d - compose_index\n",compose_index);*/
         for (i=0;i<MAX_COMPOSE_CHARS;i++)
           {
            if (compose_lookups[compose_index][i] == key)
              {
               char_idx = i;
               break;
              }
           }
  /*       fprintf(stderr,"STATE_CHAR: compose_index: %d char_idx: %d\n",compose_index,char_idx);*/
         if (char_idx == (-1))
           {
            compose_state = STATE_NORMAL;
            compose_index = 0;
            XCursesDisplayCursor(SP->cursrow,SP->curscol,
                                 SP->cursrow,SP->curscol);
            break;
           }
/*         fprintf(stderr,"STATE_CHAR: %d %c - key\n",compose_keys[compose_index][char_idx],compose_keys[compose_index][char_idx]);*/
         XCursesSendKeyToCurses(compose_keys[compose_index][char_idx]);
         compose_state = STATE_NORMAL;
         compose_index = 0;
         XCursesDisplayCursor(SP->cursrow,SP->curscol,
                              SP->cursrow,SP->curscol);
         return;
         break;
    default:
         break;
   }
 /*
  * To get here we are procesing "normal" keys
  */
#ifdef PDCDEBUG
 if (trace_on) PDC_debug("%s:Keysym %x %d\n",(XCursesProcess)?"     X":"CURSES",XKeycodeToKeysym(XCURSESDISPLAY,event->xkey.keycode,key),key);
#endif
 for (i=0;XCursesKeys[i].keycode != 0;i++)
   {
    if (XCursesKeys[i].keycode == keysym)
      {
#ifdef PDCDEBUG
       if (trace_on) PDC_debug("%s:State %x\n",(XCursesProcess)?"     X":"CURSES",event->xkey.state);
#endif
       if (XCursesKeys[i].numkeypad)
         {
          if (event->xkey.state & Mod2Mask  /* 0x10: usually, numlock modifier */
          ||  event->xkey.state & ShiftMask) /* or 0x01: shift modifier */
            {
             key = XCursesKeys[i].shifted;
             break;
            }
         }
       if (event->xkey.state & ShiftMask)  /* 0x01: shift modifier */
         {
          key = XCursesKeys[i].shifted;
          break;
         }
       if (event->xkey.state & ControlMask)  /* 0x04: control modifier */
         {
          key = XCursesKeys[i].control;
          break;
         }
       if (event->xkey.state & Mod1Mask)  /* 0x08: usually, alt modifier */
         {
          key = XCursesKeys[i].alt;
          break;
         }
/*---------------------------------------------------------------------*/
/* To get here, we ignore all other modifiers.                         */
/*---------------------------------------------------------------------*/
       key = XCursesKeys[i].normal;
       break;
      }
   }
 if (key == 0
 && buffer[0] != 0
 && count == 1)
    key = (int)buffer[0];
#ifdef PDCDEBUG
 if (trace_on) PDC_debug("%s:Key: %s pressed - %x Mod: %x\n",(XCursesProcess)?"     X":"CURSES",XKeysymToString(keysym),key,event->xkey.state);
#endif
/*---------------------------------------------------------------------*/
/* Handle ALT letters and numbers...                                   */
/*---------------------------------------------------------------------*/
 if (event->xkey.state == Mod1Mask)
   {
    if (key >= (int)'A'
    &&  key <= (int)'Z')
       key = ALT_A + (key - (int)('A'));
    if (key >= (int)'a'
    &&  key <= (int)'z')
       key = ALT_A + (key - (int)('a'));
    if (key >= (int)'0'
    &&  key <= (int)'9')
       key = ALT_0 + (key - (int)('0'));
   }
/*---------------------------------------------------------------------*/
/* After all that, send the key back to the application if is NOT zero.*/
/*---------------------------------------------------------------------*/
 if (key)
    XCursesSendKeyToCurses(key);
 return;
}
/***********************************************************************/
#ifdef HAVE_PROTO
static void XCursesHandleString(Widget w, XEvent *event, String *params, Cardinal *nparams)
#else
static void XCursesHandleString(w, event, params, nparams)
Widget w;
XEvent *event;
String *params;
Cardinal *nparams;
#endif
/***********************************************************************/
{
 register int i=0;
 unsigned char *ptr=NULL;

 if (*nparams != 1) 
    return;

 if ((*params)[0] == '0' 
 && (*params)[1] == 'x' 
 && (*params)[2] != '\0') 
   {
    unsigned char c;
    int total=0;
    char *p;
    for (p = *params+2; (c = *p); p++) 
      {
       total *= 16;
       if (isupper(c)) c = tolower(c);
       if (c >= '0' && c <= '9')
          total += c - '0';
       else 
          if (c >= 'a' && c <= 'f')
             total += c - 'a' + 10;
          else 
             break;
      }
    if (c == '\0')
       XCursesSendKeyToCurses(total);
   }
 else
   {
    ptr = (unsigned char *)*params;
    for (i=0;i<(int)strlen((char *)ptr);i++)
      {
       XCursesSendKeyToCurses((int)*(ptr+i));
      }
   }
 return;
}
/***********************************************************************/
#ifdef HAVE_PROTO
static void XCursesPasteSelection(Widget w,XButtonEvent *button_event)
#else
static void XCursesPasteSelection(w,button_event)
Widget w;
XButtonEvent *button_event;
#endif
/***********************************************************************/
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesPasteSelection() - called\n",(XCursesProcess)?"     X":"CURSES");
#endif
 XtGetSelectionValue(w,XA_PRIMARY,XA_STRING,XCursesRequestorCallback,(XtPointer)button_event,button_event->time);
 return;
}
/***********************************************************************/
#ifdef HAVE_PROTO
static void XCursesStartHighlightSelection(Widget w,XButtonEvent *button_event)
#else
static void XCursesStartHighlightSelection(w,button_event)
Widget w;
XButtonEvent *button_event;
#endif
/***********************************************************************/
{
 int row=SP->cursrow;
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesStartHighlightSelection() - called\n",(XCursesProcess)?"     X":"CURSES");
#endif

#if 0
 XCursesDisplayText((chtype *)(Xcurscr+XCURSCR_Y_OFF(row)+(0*sizeof(chtype))),row,0,COLS,TRUE);
 XCursesDisplayText((chtype *)(Xcurscr+XCURSCR_Y_OFF(row+1)+(0*sizeof(chtype))),row+1,0,COLS,TRUE);
 XCursesDisplayText((chtype *)(Xcurscr+XCURSCR_Y_OFF(row)+(0*sizeof(chtype))),row,0,COLS,TRUE);
 XCursesDisplayText((chtype *)(Xcurscr+XCURSCR_Y_OFF(row+1)+(0*sizeof(chtype))),row+1,0,COLS,TRUE);
 XFillRectangle(XCURSESDISPLAY,XCURSESWIN,normal_highlight_gc,10,10,50,50);
#endif
 XFillRectangle(XCURSESDISPLAY,XCURSESWIN,normal_highlight_gc,10,10,50,50);
 XCursesDisplayText((chtype *)(Xcurscr+XCURSCR_Y_OFF(row)+(0*sizeof(chtype))),row,0,COLS,TRUE);
 XCursesDisplayText((chtype *)(Xcurscr+XCURSCR_Y_OFF(row+1)+(0*sizeof(chtype))),row+1,0,COLS,TRUE);


 return;
}
/***********************************************************************/
#ifdef HAVE_PROTO
static void XCursesRequestorCallback(Widget w,XtPointer data, Atom *selection, 
                                     Atom *type, XtPointer value, 
                                     unsigned long *length, int *format)
#else
static void XCursesRequestorCallback(w,data,selection,type,value,length,format)
Widget w;
XtPointer data;
Atom *selection;
Atom *type;
XtPointer value;
unsigned long *length;
int *format;
#endif
/***********************************************************************/
{
int i=0,key=0;
char *string=(char *)value;

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:XCursesRequestorCallback() - called\n",(XCursesProcess)?"     X":"CURSES");
#endif

 if ((value == NULL) && (*length == 0))
    return;

 for (i=0;i<(*length);i++)
   {
    key = (int)(*(string+i));
    if (key == 10) /* new line - convert to ^M */
       key = 13;
    XCursesSendKeyToCurses(key);
   }
 return;
}

#if 0
/***********************************************************************/
#ifdef HAVE_PROTO
static Boolean convert_proc(Widget w,Atom *selection, Atom *target, 
                            Atom *type_return, XtPointer *value_return,
                            unsigned long *length_return, int *format_return)
#else
static Boolean convert_proc(w,selection,target,type_return,value_return,
                            length_return,format_return)
Widget w;
Atom *selection;
Atom *target;
Atom *type_return;
XtPointer *value_return;
unsigned long *length_return; 
int *format_return;
#endif
/***********************************************************************/
{

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("%s:convert_proc() - called\n",(XCursesProcess)?"     X":"CURSES");
#endif

 XtGetSelectionValue(w,XA_PRIMARY,XA_STRING,XCursesRequestorCallback,event,event->time);
 return;
}
#endif

/***********************************************************************/
#ifdef HAVE_PROTO
int XCurses_get_rows(void)
#else
int XCurses_get_rows()
#endif
/***********************************************************************/
{
 return(XCursesLINES);
}
/***********************************************************************/
#ifdef HAVE_PROTO
int XCurses_get_cols(void)
#else
int XCurses_get_cols()
#endif
/***********************************************************************/
{
 return(XCursesCOLS);
}
#endif
