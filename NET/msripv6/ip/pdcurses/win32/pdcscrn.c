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
char *rcsid_PDCscrn  = "$Id$";
#endif

HANDLE hConOut = INVALID_HANDLE_VALUE;
HANDLE hConIn = INVALID_HANDLE_VALUE;

#ifndef DONT_RESTORE_SCREEN
static HANDLE hConOutSaved = INVALID_HANDLE_VALUE;
#endif

/*man-start*********************************************************************

  PDC_scr_close()	- Internal low-level binding to close the physical screen

  PDCurses Description:
 	This function provides a low-level binding for the Flexos
 	platform which must close the screen before writing to it.
 	This is a nop for the DOS platform.

 	This function is provided in order to reset the FlexOS 16 bit
 	character set for input rather than the limited input
 	character set associated with the VT52.

  PDCurses Return Value:
 	This function returns OK on success, otherwise an ERR is returned.

  PDCurses Errors:
 	The DOS platform will never fail.  The Flexos platform may fail
 	depending on the ability to close the current virtual console in
 	8 (as opposed to 16) bit mode.

  Portability:
 	PDCurses	int	PDC_scr_close( void );

**man-end**********************************************************************/

int	PDC_scr_close(void)
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("PDC_scr_close() - called\n");
#endif
#ifndef DONT_RESTORE_SCREEN
        if (hConOutSaved == INVALID_HANDLE_VALUE)
                return( OK );
        SetConsoleActiveScreenBuffer(hConOutSaved);
        (void) CloseHandle(hConOut);
        hConOut = hConOutSaved;
	hConOutSaved = INVALID_HANDLE_VALUE;
#endif
	return( OK );
}

/*man-start*********************************************************************

  PDC_scrn_modes_equal()	- Decide if two screen modes are equal

  PDCurses Description:
 	Mainly required for OS/2. It decides if two screen modes
        (VIOMODEINFO structure) are equal. Under DOS it just compares
        two integers

  PDCurses Return Value:
 	This function returns TRUE if equal else FALSe.

  PDCurses Errors:
 	No errors are defined for this function.

  Portability:
 	PDCurses	int PDC_scrn_modes_equal( int mode1, int mode2 );
 	OS2 PDCurses	int PDC_scrn_modes_equal( VIOMODEINFO mode1, VIOMODEINFO mode2 );

**man-end**********************************************************************/

bool	PDC_scrn_modes_equal(int mode1, int mode2)
{
#ifdef PDCDEBUG
   if (trace_on) PDC_debug("PDC_scrn_modes_equal() - called\n");
#endif
   return (mode1 == mode2);
}

/*man-start*********************************************************************

  PDC_scr_open()	- Internal low-level binding to open the physical screen

  PDCurses Description:
 	This function provides a low-level binding for the Flexos
 	platform which must open the screen before writing to it.

 	This function is provided in order to access the FlexOS 16 bit
 	character set for input rather than the limited input
 	character set associated with the VT52.

  PDCurses Return Value:
 	This function returns OK on success, otherwise an ERR is returned.

  PDCurses Errors:
 	The DOS platform will never fail.  The Flexos platform may fail
 	depending on the ability to open the current virtual console in
 	8 (as opposed to 16) bit mode.

  Portability:
 	PDCurses	int	PDC_scr_open( SCREEN* internal, bool echo );

**man-end**********************************************************************/

int	PDC_scr_open(SCREEN *internal, bool echo)
{
 DWORD numbuttons=0;

#ifdef PDCDEBUG
   if (trace_on) PDC_debug("PDC_scr_open() - called\n");
#endif

	hConOut = GetStdHandle(STD_OUTPUT_HANDLE);
	hConIn = GetStdHandle(STD_INPUT_HANDLE);

#ifndef DONT_RESTORE_SCREEN
	/* do this only when we haven't already */
	if (hConOutSaved == INVALID_HANDLE_VALUE) {
	    COORD size;
	    CONSOLE_SCREEN_BUFFER_INFO scr;

	    hConOutSaved = hConOut;
	    GetConsoleScreenBufferInfo(hConOutSaved, &scr);

	    /*
	     * Create our own screen buffer, so that we
	     * may restore the original when done.
	     */
	    hConOut = CreateConsoleScreenBuffer(
		GENERIC_WRITE | GENERIC_READ,
		FILE_SHARE_WRITE | FILE_SHARE_READ,
		(LPSECURITY_ATTRIBUTES) NULL,
		CONSOLE_TEXTMODE_BUFFER,
		(LPVOID) NULL);
	    size.X = scr.srWindow.Right - scr.srWindow.Left + 1;
	    size.Y = scr.srWindow.Bottom - scr.srWindow.Top + 1;
	    SetConsoleScreenBufferSize(hConOut, size);
	    SetConsoleActiveScreenBuffer(hConOut);
	}
#endif
	SetConsoleMode(hConIn, ENABLE_PROCESSED_INPUT |
			       ENABLE_MOUSE_INPUT |
			       ENABLE_WINDOW_INPUT);

	FlushConsoleInputBuffer(hConIn);

	GetNumberOfConsoleMouseButtons((LPDWORD)&numbuttons);
	internal->num_mouse_buttons = (int)numbuttons;

	PDC_get_cursor_pos(&internal->cursrow, &internal->curscol);
	internal->direct_video	= TRUE; /* Assume that we can      */
	internal->autocr	= TRUE;		/* lf -> crlf by default     */
	internal->raw_out	= FALSE;	/* tty I/O modes	     */
	internal->raw_inp	= FALSE;	/* tty I/O modes	     */
	internal->cbreak	= TRUE;
	internal->echo	= echo;
	/* under System V Curses, typeahead checking is enabled by default */
	internal->refrbrk	= TRUE;	/* allow premature end of refresh*/
	internal->video_seg	= 0xb000;	/* Base screen segment addr   */
	internal->video_ofs	= 0x0;		/* Base screen segment ofs    */
	internal->video_page	= 0;		/* Current Video Page	      */
	internal->visible_cursor= TRUE;	/* Assume that it is visible  */
	internal->cursor	= PDC_get_cursor_mode();

	internal->adapter	= PDC_query_adapter_type();
	internal->scrnmode	= PDC_get_scrn_mode();

	internal->lines	= PDC_get_rows();
	internal->cols	= PDC_get_columns();

	internal->audible	= TRUE;
	internal->visibility	= 1;
	internal->orig_cursor = internal->cursor;
	internal->orgcbr = PDC_get_ctrl_break();
	internal->blank = ' ';
	internal->resized = FALSE;
	internal->shell = FALSE;
	internal->_trap_mbe = 0L;
	internal->_map_mbe_to_key = 0L;
	internal->linesrippedoff = 0;
	internal->linesrippedoffontop = 0;
	internal->delaytenths = 0;

	return( OK );
}

/*man-start*********************************************************************

  PDC_resize_screen()	- Internal low-level function to resize screen

  PDCurses Description:
 	This function provides a means for the application program to
 	resize the overall dimensions of the screen.  Under DOS and OS/2
 	the application can tell PDCurses what size to make the screen;
 	under X11, resizing is done by the user and this function simply
 	adjusts its internal structures to fit the new size.

  PDCurses Return Value:
 	This function returns OK on success, otherwise an ERR is returned.

  PDCurses Errors:

  Portability:
 	PDCurses	int	PDC_resize_screen( int, int );

**man-end**********************************************************************/

/***********************************************************************/
#ifdef HAVE_PROTO
int	PDC_resize_screen(int nlines, int ncols)
#else
int	PDC_resize_screen(nlines, ncols)
int nlines,ncols;
#endif
/***********************************************************************/
{
	int rc=OK;

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("PDC_resize_screen() - called. Lines: %d Cols: %d\n",nlines,ncols);
#endif

	return ( rc );
}
