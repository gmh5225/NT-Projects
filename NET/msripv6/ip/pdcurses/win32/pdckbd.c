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
***************************************************************************
*/

#define	CURSES_LIBRARY	1
#define	INCLUDE_WINDOWS_H
#include <curses.h>

#ifdef PDCDEBUG
char *rcsid_PDCkbd  = "$Id$";
#endif

#define KEY_STATE TRUE

/*
 * These variables are used to store information about the next 
 * Input Event.
 */
static int keyCount = 0;
INPUT_RECORD save_ip;

extern HANDLE hConIn;

void win32_getch(void);

/*******************************************************************************
*	Table for key code translation of function keys in keypad mode
*	These values are for strict IBM keyboard compatibles only
*******************************************************************************/

typedef struct {
	int normal;
	int shift;
	int control;
	int alt;
	int extended;
} KPTAB;

static KPTAB kptab[] =
{
 {0,          0,          0,           0,          0           }, /* 0 */
 {0,          0,          0,           0,          0           }, /* 1 */
 {0,          0,          0,           0,          0           }, /* 2 */
 {0,          0,          0,           0,          0           }, /* 3 */
 {0,          0,          0,           0,          0           }, /* 4 */
 {0,          0,          0,           0,          0           }, /* 5 */
 {0,          0,          0,           0,          0           }, /* 6 */
 {0,          0,          0,           0,          0           }, /* 7 */
 {0x08,       0x08,       0x7F,        ALT_BKSP,   0           }, /* 8 */
 {0x09,       KEY_BTAB,   CTL_TAB,     ALT_TAB,    999         }, /* 9 */
 {0,          0,          0,           0,          0           }, /* 10 */
 {0,          0,          0,           0,          0           }, /* 11 */
 {KEY_B2,     0x35,       CTL_PAD5,    ALT_PAD5,   0           }, /* 12 */
 {0x0D,       0x0D,       CTL_ENTER,   ALT_ENTER,  1           }, /* 13 */
 {0,          0,          0,           0,          0           }, /* 14 */
 {0,          0,          0,           0,          0           }, /* 15 */
 {0,          0,          0,           0,          0           }, /* 16 */
 {0,          0,          0,           0,          0           }, /* 17 */
 {0,          0,          0,           0,          0           }, /* 18 */
 {0,          0,          0,           0,          0           }, /* 19 */
 {0,          0,          0,           0,          0           }, /* 20 */
 {0,          0,          0,           0,          0           }, /* 21 */
 {0,          0,          0,           0,          0           }, /* 22 */
 {0,          0,          0,           0,          0           }, /* 23 */
 {0,          0,          0,           0,          0           }, /* 24 */
 {0,          0,          0,           0,          0           }, /* 25 */
 {0,          0,          0,           0,          0           }, /* 26 */
 {0x1B,       0x1B,       0x1B,        ALT_ESC,    0           }, /* 27 */
 {0,          0,          0,           0,          0           }, /* 28 */
 {0,          0,          0,           0,          0           }, /* 29 */
 {0,          0,          0,           0,          0           }, /* 30 */
 {0,          0,          0,           0,          0           }, /* 31 */
 {0x20,       0x20,       0x20,        0x20,       0           }, /* 32 */
 {KEY_A3,     0x39,       CTL_PAD9,    ALT_PAD9,   3           }, /* 33 */
 {KEY_C3,     0x33,       CTL_PAD3,    ALT_PAD3,   4           }, /* 34 */
 {KEY_C1,     0x31,       CTL_PAD1,    ALT_PAD1,   5           }, /* 35 */
 {KEY_A1,     0x37,       CTL_PAD7,    ALT_PAD7,   6           }, /* 36 */
 {KEY_B1,     0x34,       CTL_PAD4,    ALT_PAD4,   7           }, /* 37 */
 {KEY_A2,     0x38,       CTL_PAD8,    ALT_PAD8,   8           }, /* 38 */
 {KEY_B3,     0x36,       CTL_PAD6,    ALT_PAD6,   9           }, /* 39 */
 {KEY_C2,     0x32,       CTL_PAD2,    ALT_PAD2,   10          }, /* 40 */
 {0,          0,          0,           0,          0           }, /* 41 */
 {0,          0,          0,           0,          0           }, /* 42 */
 {0,          0,          0,           0,          0           }, /* 43 */
 {0,          0,          0,           0,          0           }, /* 44 */
 {PAD0,       0x30,       CTL_PAD0,    ALT_PAD0,   11          }, /* 45 */
 {PADSTOP,    0x2E,       CTL_PADSTOP, ALT_PADSTOP,12          }, /* 46 */
 {0,          0,          0,           0,          0           }, /* 47 */
 {0x30,       0x29,       0,           ALT_0,      0           }, /* 48 */
 {0x31,       0x21,       0,           ALT_1,      0           }, /* 49 */
 {0x32,       0x40,       0,           ALT_2,      0           }, /* 50 */
 {0x33,       0x23,       0,           ALT_3,      0           }, /* 51 */
 {0x34,       0x24,       0,           ALT_4,      0           }, /* 52 */
 {0x35,       0x25,       0,           ALT_5,      0           }, /* 53 */
 {0x36,       0x5E,       0,           ALT_6,      0           }, /* 54 */
 {0x37,       0x26,       0,           ALT_7,      0           }, /* 55 */
 {0x38,       0x2A,       0,           ALT_8,      0           }, /* 56 */
 {0x39,       0x28,       0,           ALT_9,      0           }, /* 57 */
 {0,          0,          0,           0,          0           }, /* 58 */
 {0,          0,          0,           0,          0           }, /* 59 */
 {0,          0,          0,           0,          0           }, /* 60 */
 {0,          0,          0,           0,          0           }, /* 61 */
 {0,          0,          0,           0,          0           }, /* 62 */
 {0,          0,          0,           0,          0           }, /* 63 */
 {0,          0,          0,           0,          0           }, /* 64 */
 {0x61,       0x41,       0x01,        ALT_A,      0           }, /* 65 */
 {0x62,       0x42,       0x02,        ALT_B,      0           }, /* 66 */
 {0x63,       0x43,       0x03,        ALT_C,      0           }, /* 67 */
 {0x64,       0x44,       0x04,        ALT_D,      0           }, /* 68 */
 {0x65,       0x45,       0x05,        ALT_E,      0           }, /* 69 */
 {0x66,       0x46,       0x06,        ALT_F,      0           }, /* 70 */
 {0x67,       0x47,       0x07,        ALT_G,      0           }, /* 71 */
 {0x68,       0x48,       0x08,        ALT_H,      0           }, /* 72 */
 {0x69,       0x49,       0x09,        ALT_I,      0           }, /* 73 */
 {0x6A,       0x4A,       0x0A,        ALT_J,      0           }, /* 74 */
 {0x6B,       0x4B,       0x0B,        ALT_K,      0           }, /* 75 */
 {0x6C,       0x4C,       0x0C,        ALT_L,      0           }, /* 76 */
 {0x6D,       0x4D,       0x0D,        ALT_M,      0           }, /* 77 */
 {0x6E,       0x4E,       0x0E,        ALT_N,      0           }, /* 78 */
 {0x6F,       0x4F,       0x0F,        ALT_O,      0           }, /* 79 */
 {0x70,       0x50,       0x10,        ALT_P,      0           }, /* 80 */
 {0x71,       0x51,       0x11,        ALT_Q,      0           }, /* 81 */
 {0x72,       0x52,       0x12,        ALT_R,      0           }, /* 82 */
 {0x73,       0x53,       0x13,        ALT_S,      0           }, /* 83 */
 {0x74,       0x54,       0x14,        ALT_T,      0           }, /* 84 */
 {0x75,       0x55,       0x15,        ALT_U,      0           }, /* 85 */
 {0x76,       0x56,       0x16,        ALT_V,      0           }, /* 86 */
 {0x77,       0x57,       0x17,        ALT_W,      0           }, /* 87 */
 {0x78,       0x58,       0x18,        ALT_X,      0           }, /* 88 */
 {0x79,       0x59,       0x19,        ALT_Y,      0           }, /* 89 */
 {0x7A,       0x5A,       0x1A,        ALT_Z,      0           }, /* 90 */
 {0,          0,          0,           0,          0           }, /* 91 */
 {0,          0,          0,           0,          0           }, /* 92 */
 {0,          0,          0,           0,          0           }, /* 93 */
 {0,          0,          0,           0,          0           }, /* 94 */
 {0,          0,          0,           0,          0           }, /* 95 */
 {0x30,       0,          CTL_PAD0,    ALT_PAD0,   0           }, /* 96 */
 {0x31,       0,          CTL_PAD1,    ALT_PAD1,   0           }, /* 97 */
 {0x32,       0,          CTL_PAD2,    ALT_PAD2,   0           }, /* 98 */
 {0x33,       0,          CTL_PAD3,    ALT_PAD3,   0           }, /* 99 */
 {0x34,       0,          CTL_PAD4,    ALT_PAD4,   0           }, /* 100 */
 {0x35,       0,          CTL_PAD5,    ALT_PAD5,   0           }, /* 101 */
 {0x36,       0,          CTL_PAD6,    ALT_PAD6,   0           }, /* 102 */
 {0x37,       0,          CTL_PAD7,    ALT_PAD7,   0           }, /* 103 */
 {0x38,       0,          CTL_PAD8,    ALT_PAD8,   0           }, /* 104 */
 {0x39,       0,          CTL_PAD9,    ALT_PAD9,   0           }, /* 105 */
 {PADSTAR,    PADSTAR,    CTL_PADSTAR, ALT_PADSTAR,999         }, /* 106 */
 {PADPLUS,    PADPLUS,    CTL_PADPLUS, ALT_PADPLUS,999         }, /* 107 */
 {0,          0,          0,           0,          0           }, /* 108 */
 {PADMINUS,   PADMINUS,   CTL_PADMINUS,ALT_PADMINUS,999        }, /* 109 */
 {0x2E,       0,          CTL_PADSTOP, ALT_PADSTOP,0           }, /* 110 */
 {0,          0,          0,           0,          2           }, /* 111 */
 {KEY_F(1),   KEY_F(13),  KEY_F(25),   KEY_F(37),  0           }, /* 112 */
 {KEY_F(2),   KEY_F(14),  KEY_F(26),   KEY_F(38),  0           }, /* 113 */
 {KEY_F(3),   KEY_F(15),  KEY_F(27),   KEY_F(39),  0           }, /* 114 */
 {KEY_F(4),   KEY_F(16),  KEY_F(28),   KEY_F(40),  0           }, /* 115 */
 {KEY_F(5),   KEY_F(17),  KEY_F(29),   KEY_F(41),  0           }, /* 116 */
 {KEY_F(6),   KEY_F(18),  KEY_F(30),   KEY_F(42),  0           }, /* 117 */
 {KEY_F(7),   KEY_F(19),  KEY_F(31),   KEY_F(43),  0           }, /* 118 */
 {KEY_F(8),   KEY_F(20),  KEY_F(32),   KEY_F(44),  0           }, /* 119 */
 {KEY_F(9),   KEY_F(21),  KEY_F(33),   KEY_F(45),  0           }, /* 120 */
 {KEY_F(10),  KEY_F(22),  KEY_F(34),   KEY_F(46),  0           }, /* 121 */
 {KEY_F(11),  KEY_F(23),  KEY_F(35),   KEY_F(47),  0           }, /* 122 */
 {KEY_F(12),  KEY_F(24),  KEY_F(36),   KEY_F(48),  0           }, /* 123 */
 {0,          0,          0,           0,          0           }, /* 124 */
 {0,          0,          0,           0,          0           }, /* 125 */
 {0,          0,          0,           0,          0           }, /* 126 */
 {0,          0,          0,           0,          0           }, /* 127 */
 {0,          0,          0,           0,          0           }, /* 128 */
 {0,          0,          0,           0,          0           }, /* 129 */
 {0,          0,          0,           0,          0           }, /* 130 */
 {0,          0,          0,           0,          0           }, /* 131 */
 {0,          0,          0,           0,          0           }, /* 132 */
 {0,          0,          0,           0,          0           }, /* 133 */
 {0,          0,          0,           0,          0           }, /* 134 */
 {0,          0,          0,           0,          0           }, /* 135 */
 {0,          0,          0,           0,          0           }, /* 136 */
 {0,          0,          0,           0,          0           }, /* 137 */
 {0,          0,          0,           0,          0           }, /* 138 */
 {0,          0,          0,           0,          0           }, /* 139 */
 {0,          0,          0,           0,          0           }, /* 140 */
 {0,          0,          0,           0,          0           }, /* 141 */
 {0,          0,          0,           0,          0           }, /* 142 */
 {0,          0,          0,           0,          0           }, /* 143 */
 {0,          0,          0,           0,          0           }, /* 144 */
 {0,          0,          0,           0,          0           }, /* 145 */
 {0,          0,          0,           0,          0           }, /* 146 */
 {0,          0,          0,           0,          0           }, /* 147 */
 {0,          0,          0,           0,          0           }, /* 148 */
 {0,          0,          0,           0,          0           }, /* 149 */
 {0,          0,          0,           0,          0           }, /* 150 */
 {0,          0,          0,           0,          0           }, /* 151 */
 {0,          0,          0,           0,          0           }, /* 152 */
 {0,          0,          0,           0,          0           }, /* 153 */
 {0,          0,          0,           0,          0           }, /* 154 */
 {0,          0,          0,           0,          0           }, /* 155 */
 {0,          0,          0,           0,          0           }, /* 156 */
 {0,          0,          0,           0,          0           }, /* 157 */
 {0,          0,          0,           0,          0           }, /* 158 */
 {0,          0,          0,           0,          0           }, /* 159 */
 {0,          0,          0,           0,          0           }, /* 160 */
 {0,          0,          0,           0,          0           }, /* 161 */
 {0,          0,          0,           0,          0           }, /* 162 */
 {0,          0,          0,           0,          0           }, /* 163 */
 {0,          0,          0,           0,          0           }, /* 164 */
 {0,          0,          0,           0,          0           }, /* 165 */
 {0,          0,          0,           0,          0           }, /* 166 */
 {0,          0,          0,           0,          0           }, /* 167 */
 {0,          0,          0,           0,          0           }, /* 168 */
 {0,          0,          0,           0,          0           }, /* 169 */
 {0,          0,          0,           0,          0           }, /* 170 */
 {0,          0,          0,           0,          0           }, /* 171 */
 {0,          0,          0,           0,          0           }, /* 172 */
 {0,          0,          0,           0,          0           }, /* 173 */
 {0,          0,          0,           0,          0           }, /* 174 */
 {0,          0,          0,           0,          0           }, /* 175 */
 {0,          0,          0,           0,          0           }, /* 176 */
 {0,          0,          0,           0,          0           }, /* 177 */
 {0,          0,          0,           0,          0           }, /* 178 */
 {0,          0,          0,           0,          0           }, /* 179 */
 {0,          0,          0,           0,          0           }, /* 180 */
 {0,          0,          0,           0,          0           }, /* 181 */
 {0,          0,          0,           0,          0           }, /* 182 */
 {0,          0,          0,           0,          0           }, /* 183 */
 {0,          0,          0,           0,          0           }, /* 184 */
 {0,          0,          0,           0,          0           }, /* 185 */
 {0x3B,       0x3A,       0x3B,        ALT_SEMICOLON,0,        }, /* 186 */
 {0x3D,       0x2B,       0x3D,        ALT_EQUAL,  0           }, /* 187 */
 {0x2C,       0x3C,       0x2C,        ALT_COMMA,  0           }, /* 188 */
 {0x2D,       0x5F,       0x2D,        0x2D,       0           }, /* 189 */
 {0x2E,       0x3E,       0x2E,        ALT_STOP,   0           }, /* 190 */
 {0x2F,       0x3F,       0x2F,        ALT_FSLASH, 13          }, /* 191 */
 {0x60,       0x7E,       0x60,        ALT_BQUOTE, 0           }, /* 192 */
 {0,          0,          0,           0,          0           }, /* 193 */
 {0,          0,          0,           0,          0           }, /* 194 */
 {0,          0,          0,           0,          0           }, /* 195 */
 {0,          0,          0,           0,          0           }, /* 196 */
 {0,          0,          0,           0,          0           }, /* 197 */
 {0,          0,          0,           0,          0           }, /* 198 */
 {0,          0,          0,           0,          0           }, /* 199 */
 {0,          0,          0,           0,          0           }, /* 200 */
 {0,          0,          0,           0,          0           }, /* 201 */
 {0,          0,          0,           0,          0           }, /* 202 */
 {0,          0,          0,           0,          0           }, /* 203 */
 {0,          0,          0,           0,          0           }, /* 204 */
 {0,          0,          0,           0,          0           }, /* 205 */
 {0,          0,          0,           0,          0           }, /* 206 */
 {0,          0,          0,           0,          0           }, /* 207 */
 {0,          0,          0,           0,          0           }, /* 208 */
 {0,          0,          0,           0,          0           }, /* 209 */
 {0,          0,          0,           0,          0           }, /* 210 */
 {0,          0,          0,           0,          0           }, /* 211 */
 {0,          0,          0,           0,          0           }, /* 212 */
 {0,          0,          0,           0,          0           }, /* 213 */
 {0,          0,          0,           0,          0           }, /* 214 */
 {0,          0,          0,           0,          0           }, /* 215 */
 {0,          0,          0,           0,          0           }, /* 216 */
 {0,          0,          0,           0,          0           }, /* 217 */
 {0,          0,          0,           0,          0           }, /* 218 */
 {0x5B,       0x7B,       0x1B,        ALT_LBRACKET,0          }, /* 219 */
 {0x5C,       0x7C,       0x1C,        ALT_BSLASH, 0           }, /* 220 */
 {0x5D,       0x7D,       0x1D,        ALT_RBRACKET,0          }, /* 221 */
 {0x27,       0x22,       0x27,        ALT_FQUOTE, 0           }, /* 222 */
 {0,          0,          0,           0,          0           }, /* 223 */
 {0,          0,          0,           0,          0           }, /* 224 */
 {0,          0,          0,           0,          0           }  /* 225 */
};

static KPTAB ext_kptab[] =
{
 {0,          0,          0,           0,          }, /* MUST BE EMPTY */
 {PADENTER,   PADENTER,   CTL_PADENTER,ALT_PADENTER}, /* 13 */
 {PADSLASH,   PADSLASH,   CTL_PADSLASH,ALT_PADSLASH}, /* 111 */
 {KEY_PPAGE,  KEY_PPAGE,  CTL_PGUP,    ALT_PGUP    }, /* 33 */
 {KEY_NPAGE,  KEY_NPAGE,  CTL_PGDN,    ALT_PGDN    }, /* 34 */
 {KEY_END,    KEY_END,    CTL_END,     ALT_END     }, /* 35 */
 {KEY_HOME,   KEY_HOME,   CTL_HOME,    ALT_HOME    }, /* 36 */
 {KEY_LEFT,   KEY_LEFT,   CTL_LEFT,    ALT_LEFT    }, /* 37 */
 {KEY_UP,     KEY_UP,     CTL_UP,      ALT_UP      }, /* 38 */
 {KEY_RIGHT,  KEY_RIGHT,  CTL_RIGHT,   ALT_RIGHT   }, /* 39 */
 {KEY_DOWN,   KEY_DOWN,   CTL_DOWN,    ALT_DOWN    }, /* 40 */
 {KEY_IC,     KEY_IC,     CTL_INS,     ALT_INS     }, /* 45 */
 {KEY_DC,     KEY_DC,     CTL_DEL,     ALT_DEL     }, /* 46 */
 {PADSLASH,   PADSLASH,   CTL_PADSLASH,ALT_PADSLASH}, /* 191 */
};
 /* End of kptab[]		 */

MOUSE_STATUS Trapped_Mouse_status;

/*man-start*********************************************************************

  PDC_breakout()	- check for type-ahead

  X/Open Description:
 	The curses package does the "line-breakout optimisation" by
 	looking for type-ahead periodically while updating the screen.
 	If input is found, the current update will be postponed until
 	refresh() or doupdate() are called again.  This allows faster
 	response to commands typed in advance.  Normally, the input FILE
 	pointer passed to newterm(), or stdin in the case when initscr()
 	was called, will be used to do this type-ahead checking.  This routine
 	will do the actual check for PDcurses to see if input is pending.

  PDCurses Description:
 	This routine does what the PDcurses typeahead routine used to do.  But
 	to make that routine consistent with its System V counterpart, all it
 	does now is set whether or not typeahead checking is performed.

  X/Open Return Value:
 	The PDC_breakout() routine returns TRUE if keyboard input is pending
 	otherwise FALSE is returned.

  Portability:
 	PDCurses	bool PD_breakout( void );

**man-end**********************************************************************/

bool	PDC_breakout( void )
{
   extern	int	c_pindex;			/* putter index */
   extern	int	c_gindex;			/* getter index */
   extern	int	c_ungind;			/* wungetch() push index */

#ifdef PDCDEBUG
   if (trace_on) PDC_debug("PDC_breakout() - called\n");
#endif

   if (c_ungind)
      return (TRUE);			/* ungotten char */
   if (c_pindex > c_gindex)
      return (TRUE);			/* buffered char */
   if (SP->raw_inp)
      return((bool)PDC_check_bios_key());/* raw mode test */
   
   return((bool)PDC_check_bios_key());	/* normal mode test */
}

/*man-start*********************************************************************

  PDC_check_bios_key()	- Check BIOS key data area for input

  PDCurses Description:
 	This is a private PDCurses routine.

 	This routine will check the BIOS for any indication that
 	keystrokes are pending.

  PDCurses Return Value:
 	Returns 1 if a keyboard character is available, 0 otherwise.

  PDCurses Errors:
 	No errors are defined for this function.

  Portability:
 	PDCurses	bool	PDC_check_bios_key( void );

**man-end**********************************************************************/

bool PDC_check_bios_key(void)
{
   return(win32_kbhit(0));
}         

/*man-start*********************************************************************

  PDC_get_bios_key()	- Returns the next key available from the BIOS.

  PDCurses Description:
 	This is a private PDCurses routine.

 	Returns the next key code struck at the keyboard. If the low 8
 	bits are 0, the upper bits contain the extended character
 	code. If bit 0-7 are non-zero, the upper bits = 0.

  PDCurses Return Value:
 	This function returns OK on success and ERR on error.

  PDCurses Errors:
 	No errors are defined for this function.

  Portability:
 	PDCurses	int PDC_get_bios_key( void );

**man-end**********************************************************************/

int	PDC_get_bios_key(void)
{
 INPUT_RECORD pi;
 DWORD read;
 MOUSE_STATUS Temp_Mouse_status;
 static int last_button_no=0;
 static MOUSE_STATUS Actual_Mouse_status;
 int button_no=0;
 bool trap_mouse=FALSE;
 int idx=0;
 bool enhanced=FALSE;

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("PDC_get_bios_key() - called\n");
#endif

 while(1)
   {
    win32_getch();
   
    switch(save_ip.EventType)
      {
       case KEY_EVENT:
#if 0
            fprintf(stderr,"uChar: %d KeyCode: %d ScanCode: %d State: %x\n",
                    save_ip.Event.KeyEvent.uChar.AsciiChar,
                    save_ip.Event.KeyEvent.wVirtualKeyCode,
                    save_ip.Event.KeyEvent.wVirtualScanCode,
                    save_ip.Event.KeyEvent.dwControlKeyState);
#endif
            if (save_ip.Event.KeyEvent.uChar.AsciiChar == 0
            ||  save_ip.Event.KeyEvent.dwControlKeyState & LEFT_ALT_PRESSED
            ||  save_ip.Event.KeyEvent.dwControlKeyState & RIGHT_ALT_PRESSED
            ||  save_ip.Event.KeyEvent.dwControlKeyState & ENHANCED_KEY)
              {
               if (save_ip.Event.KeyEvent.dwControlKeyState & RIGHT_ALT_PRESSED
               &&  save_ip.Event.KeyEvent.uChar.AsciiChar != 0)
                  return(save_ip.Event.KeyEvent.uChar.AsciiChar);
               if (save_ip.Event.KeyEvent.dwControlKeyState & ENHANCED_KEY)
                 {
                  enhanced = TRUE;
                  idx = kptab[save_ip.Event.KeyEvent.wVirtualKeyCode].extended;
                 }
               else
                 {
                  enhanced = FALSE;
                  idx = save_ip.Event.KeyEvent.wVirtualKeyCode;
                 }
               if (save_ip.Event.KeyEvent.dwControlKeyState & SHIFT_PRESSED)
                  return((enhanced)?ext_kptab[idx].shift:kptab[idx].shift);
               if (save_ip.Event.KeyEvent.dwControlKeyState & LEFT_CTRL_PRESSED
               ||  save_ip.Event.KeyEvent.dwControlKeyState & RIGHT_CTRL_PRESSED)
                  return((enhanced)?ext_kptab[idx].control:kptab[idx].control);
               if (save_ip.Event.KeyEvent.dwControlKeyState & LEFT_ALT_PRESSED
               ||  save_ip.Event.KeyEvent.dwControlKeyState & RIGHT_ALT_PRESSED)
                  return((enhanced)?ext_kptab[idx].alt:kptab[idx].alt);
               return((enhanced)?ext_kptab[idx].normal:kptab[idx].normal);
              }
            else
              {
               if (kptab[save_ip.Event.KeyEvent.wVirtualKeyCode].extended == 999)
                 {
                  idx = save_ip.Event.KeyEvent.wVirtualKeyCode;
                  if (save_ip.Event.KeyEvent.dwControlKeyState & SHIFT_PRESSED)
                     return(kptab[idx].shift);
                  if (save_ip.Event.KeyEvent.dwControlKeyState & LEFT_CTRL_PRESSED
                  ||  save_ip.Event.KeyEvent.dwControlKeyState & RIGHT_CTRL_PRESSED)
                     return(kptab[idx].control);
                  if (save_ip.Event.KeyEvent.dwControlKeyState & LEFT_ALT_PRESSED
                  ||  save_ip.Event.KeyEvent.dwControlKeyState & RIGHT_ALT_PRESSED)
                     return(kptab[idx].alt);
                  return(kptab[idx].normal);
                 }
               else
                  return(save_ip.Event.KeyEvent.uChar.AsciiChar);
              }
            break;
       case MOUSE_EVENT:
            memset((char*)&Temp_Mouse_status,0,sizeof(MOUSE_STATUS));
            /* 
             * button press, release or double click ...
             */
            if (save_ip.Event.MouseEvent.dwEventFlags == 0 
            ||  save_ip.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)
              {
               /*
                * Check for Left-most button - always button 1
                */
               if (save_ip.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED
               && !(ACTUAL_BUTTON_STATUS(1) & BUTTON_RELEASED))
                 {
                  button_no = 1;
                  TEMP_BUTTON_STATUS(button_no) = (save_ip.Event.MouseEvent.dwEventFlags)?BUTTON_DOUBLE_CLICKED:BUTTON_PRESSED;
                  if (TEMP_BUTTON_STATUS(button_no) == BUTTON_PRESSED
                  && (SP->_trap_mbe) & BUTTON1_PRESSED)
                     trap_mouse = TRUE;
                  if (TEMP_BUTTON_STATUS(button_no) == BUTTON_DOUBLE_CLICKED
                  && (SP->_trap_mbe) & BUTTON1_DOUBLE_CLICKED)
                     trap_mouse = TRUE;
                  break;
                 }
               /*
                * Check for Right-most button - always button 3
                */
               if (save_ip.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED
               && !(ACTUAL_BUTTON_STATUS(3) & BUTTON_RELEASED))
                 {
                  button_no = 3;
                  TEMP_BUTTON_STATUS(button_no) = (save_ip.Event.MouseEvent.dwEventFlags)?BUTTON_DOUBLE_CLICKED:BUTTON_PRESSED;
                  if (TEMP_BUTTON_STATUS(button_no) == BUTTON_PRESSED
                  && (SP->_trap_mbe) & BUTTON3_PRESSED)
                     trap_mouse = TRUE;
                  if (TEMP_BUTTON_STATUS(button_no) == BUTTON_DOUBLE_CLICKED
                  && (SP->_trap_mbe) & BUTTON3_DOUBLE_CLICKED)
                     trap_mouse = TRUE;
                  break;
                 }
               /*
                * To get here we have a button release event or another button press
                * while a current button is pressed. The latter, we throw away. 
                * We have to use the information from the previous mouse event to 
                * determine which button was released.
                */
               if (last_button_no == 1
               && (ACTUAL_BUTTON_STATUS(1) & BUTTON_PRESSED
                   || ACTUAL_BUTTON_STATUS(1) & BUTTON_DOUBLE_CLICKED
                   || ACTUAL_MOUSE_MOVED)
               && !(save_ip.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED))
                 {
                  button_no = 1;
                  TEMP_BUTTON_STATUS(button_no) = BUTTON_RELEASED;
                  if ((SP->_trap_mbe) & BUTTON1_RELEASED)
                     trap_mouse = TRUE;
                  break;
                 }
               /*
                * Check for Right-most button - always button 3
                */
               if (last_button_no == 3
               && (ACTUAL_BUTTON_STATUS(3) & BUTTON_PRESSED
                  || ACTUAL_BUTTON_STATUS(3) & BUTTON_DOUBLE_CLICKED
                   || ACTUAL_MOUSE_MOVED)
               && !(save_ip.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED))
                 {
                  button_no = 3;
                  TEMP_BUTTON_STATUS(button_no) = BUTTON_RELEASED;
                  if ((SP->_trap_mbe) & BUTTON3_RELEASED)
                     trap_mouse = TRUE;
                  break;
                 }
               if (SP->num_mouse_buttons == 3)
                 {
                  /*
                   * Check for Middle button - button 2 only for 3 button mice
                   */
                  if (save_ip.Event.MouseEvent.dwButtonState & FROM_LEFT_2ND_BUTTON_PRESSED
                  && !(ACTUAL_BUTTON_STATUS(2) & BUTTON_RELEASED))
                    {
                     button_no = 2;
                     TEMP_BUTTON_STATUS(button_no) = (save_ip.Event.MouseEvent.dwEventFlags)?BUTTON_DOUBLE_CLICKED:BUTTON_PRESSED;
                     if (TEMP_BUTTON_STATUS(button_no) == BUTTON_PRESSED
                     && (SP->_trap_mbe) & BUTTON3_PRESSED)
                        trap_mouse = TRUE;
                     if (TEMP_BUTTON_STATUS(button_no) == BUTTON_DOUBLE_CLICKED
                     && (SP->_trap_mbe) & BUTTON3_DOUBLE_CLICKED)
                        trap_mouse = TRUE;
                     break;
                    }
                  if (last_button_no == 2
                  && (ACTUAL_BUTTON_STATUS(2) & BUTTON_PRESSED
                     || ACTUAL_BUTTON_STATUS(2) & BUTTON_DOUBLE_CLICKED
                     || ACTUAL_MOUSE_MOVED)
                  && !(save_ip.Event.MouseEvent.dwButtonState & FROM_LEFT_2ND_BUTTON_PRESSED))
                    {
                     button_no = 2;
                     TEMP_BUTTON_STATUS(button_no) = BUTTON_RELEASED;
                     if ((SP->_trap_mbe) & BUTTON2_RELEASED)
                        trap_mouse = TRUE;
                     break;
                    }
                 }
               /*
                * If we get here, then we don't know how to handle the event, so
                * dispose of it
                */
               break;
              }
            else /* button motion event */
              {
               Temp_Mouse_status.changes |= 8;
               button_no = last_button_no;
               if (button_no == 1
               &&  (SP->_trap_mbe) & BUTTON1_MOVED)
                  trap_mouse = TRUE;
               if (button_no == 2
               &&  (SP->_trap_mbe) & BUTTON2_MOVED)
                  trap_mouse = TRUE;
               if (button_no == 3
               &&  (SP->_trap_mbe) & BUTTON3_MOVED)
                  trap_mouse = TRUE;
               break;
              }
            break;
       case WINDOW_BUFFER_SIZE_EVENT:
            return(0); /* how to handle resizing ?? */
            break;
       default:
            break;
      }
    if (button_no != 0)
      {
       TEMP_MOUSE_X_POS = save_ip.Event.MouseEvent.dwMousePosition.X;
       TEMP_MOUSE_Y_POS = save_ip.Event.MouseEvent.dwMousePosition.Y;

       Temp_Mouse_status.changes |= (1 << (button_no-1));
       if (save_ip.Event.MouseEvent.dwControlKeyState & SHIFT_PRESSED)
          TEMP_BUTTON_STATUS(button_no) |= BUTTON_SHIFT;
       if (save_ip.Event.MouseEvent.dwControlKeyState & LEFT_CTRL_PRESSED)
          TEMP_BUTTON_STATUS(button_no) |= BUTTON_CONTROL;
       if (save_ip.Event.MouseEvent.dwControlKeyState & RIGHT_CTRL_PRESSED)
          TEMP_BUTTON_STATUS(button_no) |= BUTTON_CONTROL;
       if (save_ip.Event.MouseEvent.dwControlKeyState & RIGHT_ALT_PRESSED)
          TEMP_BUTTON_STATUS(button_no) |= BUTTON_ALT;
       if (save_ip.Event.MouseEvent.dwControlKeyState & LEFT_ALT_PRESSED)
          TEMP_BUTTON_STATUS(button_no) |= BUTTON_ALT;
       last_button_no = button_no;
       /*
        * We now have the current mouse status information for the last
        * Mouse event.  We need to save this in Actual_Mouse_status so
        * we can use that when comparing against the next mouse event.
        * We also need to determine if we need to set Trapped_Mouse_satus
        * based on the settings in SP->_trap_mbe.
        */
       memcpy((char*)&Actual_Mouse_status,(char*)&Temp_Mouse_status,sizeof(MOUSE_STATUS));
       if (trap_mouse)
          break;
      }
   }
 /*
  * To get here we have a mouse event that has been trapped by the
  * user. Save it in the Trapped_Mouse_status structure.
  */
 memcpy((char*)&Trapped_Mouse_status,(char*)&Temp_Mouse_status,sizeof(MOUSE_STATUS));
 return(KEY_MOUSE);
}

/*man-start*********************************************************************

  PDC_get_ctrl_break()	- return OS control break state

  PDCurses Description:
 	This is a private PDCurses routine.

 	Returns the current OS Control Break Check state.

  PDCurses Return Value:
 	DOS:
 		This function returns TRUE if the Control Break
 		Check is enabled otherwise FALSE is returned.

 	FLEXOS:
 		This function returns TRUE on if the Keyboard Mode
 		allows a break to bre reported otherwise FALSE is returned.

  PDCurses Errors:
 	No errors are defined for this function.

  Portability:
 	PDCurses	bool	PDC_get_ctrl_break( void );

**man-end**********************************************************************/

bool	PDC_get_ctrl_break(void)
{

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("PDC_get_ctrl_break() - called\n");
#endif

}

/*man-start*********************************************************************

  PDC_rawgetch()	- Returns the next uninterpreted character (if available).

  PDCurses Description:
 	Gets a character without any interpretation at all and returns
 	it. If keypad mode is active for the designated window,
 	function key translation will be performed.  Otherwise,
 	function keys are ignored.  If nodelay mode is active in the
 	window, then PDC_rawgetch() returns -1 if no character is
 	available.

 	WARNING:  It is unknown whether the FUNCTION key translation
 		  is performed at this level. --Frotz 911130 BUG

  PDCurses Return Value:
 	This function returns OK on success and ERR on error.

  PDCurses Errors:
 	No errors are defined for this function.

  Portability:
 	PDCurses	int	PDC_rawgetch( void );

**man-end**********************************************************************/

int	PDC_rawgetch(void)
{
   extern	WINDOW*	_getch_win_;

   int	c=0;
   int	oldc=0;

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("PDC_rawgetch() - called\n");
#endif

   if (_getch_win_ == (WINDOW *)NULL)   /* @@ */
      return( -1 );

   if (_getch_win_->_nodelay && !PDC_breakout()) /* @@ */
      return( -1 );

   while (1)		/* loop to get valid char */
   {
      c = PDC_get_bios_key();
      oldc = c;
      /*
       * Return the key if it is not a special key.
       */
      if (c != KEY_MOUSE
      && (c = PDC_validchar(c)) >= 0)
      {		/* get & check next char */
	 return( c );
      }
      if (_getch_win_->_use_keypad)
	 return( oldc );
   }
}

/*man-start*********************************************************************

  PDC_set_ctrl_break()	- Enables/Disables the host OS BREAK key check.

  PDCurses Description:
 	This is a private PDCurses routine.

 	Enables/Disables the host OS BREAK key check. If the supplied setting
 	is TRUE, this enables CTRL/C and CTRL/BREAK to abort the process.
 	If FALSE, CTRL/C and CTRL/BREAK are ignored.

  PDCurses Return Value:
 	This function returns OK on success and ERR on error.

  PDCurses Errors:
 	No errors are defined for this function.

  Portability:
 	PDCurses	int PDC_set_ctrl_break( bool setting );

**man-end**********************************************************************/

int	PDC_set_ctrl_break(bool setting)
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("PDC_set_ctrl_break() - called\n");
#endif

	return(OK);
}

/*man-start*********************************************************************

  PDC_sysgetch()	- Return a character using default system routines.

  PDCurses Description:
 	This is a private PDCurses function.

 	Gets a character without normal ^S, ^Q, ^P and ^C interpretation
 	and returns it.  If keypad mode is active for the designated
 	window, function key translation will be performed. Otherwise,
 	function keys are ignored. If nodelay mode is active in the
 	window, then sysgetch() returns -1 if no character is
 	available.

  PDCurses Return Value:
 	This function returns OK upon success otherwise ERR is returned.

  PDCurses Errors:
 	No errors are defined for this routine.

  Portability:
 	PDCurses	int	PDC_sysgetch( void );

**man-end**********************************************************************/

int	PDC_sysgetch(void)
{
   extern	WINDOW*	_getch_win_;

   int c=0;


#ifdef PDCDEBUG
	if (trace_on) PDC_debug("PDC_sysgetch() - called\n");
#endif

   if (_getch_win_ == (WINDOW *)NULL)  /* @@ */
      return (-1);

   if (_getch_win_->_nodelay && !PDC_breakout())
      return (-1);

   while (1)
   {
      c = PDC_get_bios_key();
      /*
       * Return the key if it is not a special key.
       */
      if ((unsigned int)c < 256)
	 return(c);
      if ((c = PDC_validchar(c)) >= 0)
      {
	 return (c);		/* get & check next char */
      }
   }
}


/*man-start*********************************************************************

  PDC_validchar()	- validate/translate passed character
  
  PDCurses Description:
  	This is a private PDCurses function.
  
  	Checks that 'c' is a valid character, and if so returns it,
  	with function key translation applied if 'w' has keypad mode
  	set.  If char is invalid, returns -1.
  
  PDCurses Return Value:
  	This function returns -1 if the passed character is invalid, or
  	the WINDOW* 'w' is NULL, or 'w's keypad is not active.
  
  	This function returns 0 under Flexos if the passed character
  	is 0x0300.  (-:Forget why.  --Frotz	911130:-)
  
  	Otherwise, this function returns the PDCurses equivalent of the
  	passed character.  See the function key and key macros in
  	<curses.h>
  
  PDCurses Errors:
  	There are no errors defined for this routine.
  
  Portability:
  	PDCurses	int	PDC_validchar( int c );

**man-end**********************************************************************/

int	PDC_validchar(int c)
{
   extern	WINDOW*	_getch_win_;

   int *scanp=NULL;

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("PDC_validchar() - called\n");
#endif

   if (_getch_win_ == (WINDOW *)NULL)
	   return (-1);	/* bad window pointer	  */

   if ((unsigned int)c < 256)	return (c);  /* normal character */
   if (!(_getch_win_->_use_keypad))	return (-1); /* skip if keys if !keypad mode */

#if 0
   /*
    * Under DOS, extended keys are in the upper byte.  Shift down for a
    * comparison.
    */
   c = (c >> 8) & 0xFF;

   scanp = kptab;
   while (*scanp > 0)	/* search for value		 */
   {			/* (stops on table entry 0x100) */
      if (*scanp++ == c)
      {
	 return (*scanp);	/* found, return it */
      }
		scanp++;
	}
	return( -1 );		/* not found, invalid */
#endif


	return(c);
}

int win32_kbhit(int timeout)
{
 INPUT_RECORD ip;
 DWORD in, read;

 if (keyCount > 0)
    return TRUE;

 if (WaitForSingleObject(hConIn, timeout) != WAIT_OBJECT_0)
 {
    return FALSE;
 }

 PeekConsoleInput(hConIn, &ip, 1, &read);
 if (read == 0)
    return(FALSE);
 ReadConsoleInput(hConIn, &ip, 1, &read);
 switch(ip.EventType)
   {
    case KEY_EVENT:
         if (ip.Event.KeyEvent.bKeyDown == FALSE)
            return(FALSE);                        /* throw away KeyUp events */
         if (ip.Event.KeyEvent.wVirtualKeyCode == 16
         ||  ip.Event.KeyEvent.wVirtualKeyCode == 17
         ||  ip.Event.KeyEvent.wVirtualKeyCode == 18
         ||  ip.Event.KeyEvent.wVirtualKeyCode == 20
         ||  ip.Event.KeyEvent.wVirtualKeyCode == 144
         ||  ip.Event.KeyEvent.wVirtualKeyCode == 145)
            return(FALSE);  /* throw away shift/alt/ctrl key only key events */
         keyCount = ip.Event.KeyEvent.wRepeatCount;
         break;
    case MOUSE_EVENT:
         if (ip.Event.MouseEvent.dwEventFlags == MS_MOUSE_MOVED
         &&  ip.Event.MouseEvent.dwButtonState == 0)
            return(FALSE);               /* throw away plain MOUSE_MOVE events */
         keyCount = 1;
         break;
    case WINDOW_BUFFER_SIZE_EVENT:
         keyCount = 1;
         break;
    default:
         keyCount = 0;
         return(FALSE);
         break;
   }
 /*
  * To get here a recognised event has occurred; save it and return TRUE
  */
 memcpy((char*)&save_ip,(char*)&ip,sizeof(INPUT_RECORD));
 return(TRUE);
}

void win32_getch(void)
{
   while (win32_kbhit(INFINITE) == FALSE)
      ;

   keyCount --;

   return;
}
