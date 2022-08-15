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
#include <string.h>
#define	CURSES_LIBRARY	1
#define	INCLUDE_WINDOWS_H
#include <curses.h>

#ifdef HAVE_MEMORY_H
# include <memory.h>
#endif

extern HANDLE hConOut;

#ifdef PDCDEBUG
char *rcsid_PDCdisp  = "$Id$";
#endif

/*man-start*********************************************************************

  PDC_clr_update()	- Updates the screen with a full redraw.

  PDCurses Description:
 	Updates the screen by clearing it and then redraw it in its
 	entirety. If SP->refrbrk is TRUE, and there is pending
 	input characters, the update will be prematurely terminated.

  PDCurses Return Value:
 	This routine returns ERR if it is unable to accomplish it's task.
 	This return value is ONLY under FLEXOS.

 	The return value OK is returned if there were no errors.

  PDCurses Errors:
 	No errors are defined for this function.

  Portability:
 	PDCurses	int PDC_clr_update( WINDOW* s );

**man-end**********************************************************************

/***********************************************************************/
int	PDC_clr_update(WINDOW *s)
/***********************************************************************/
{
   register int	i=0,j=0;
   WINDOW *w = NULL;
   unsigned short *ch;
   bool rc=FALSE;


   extern unsigned char atrtab[MAX_ATRTAB];


   unsigned short temp_line[256];
   unsigned short chr;

#ifdef PDCDEBUG
   if (trace_on) PDC_debug("PDC_clr_update() - called\n");
#endif

   w = curscr;
   if (w == (WINDOW *)NULL)
      return( ERR );
/* if (SP->full_redraw)
	PDC_clr_scrn(s); *//* clear physical screen */

   s->_clear = FALSE;
   for (i = 0; i < LINES; i++)	/* update physical screen */
   {
      if (s != w)
	 memcpy(w->_y[i], s->_y[i], COLS * sizeof(chtype));

      ch = temp_line;

      for (j=0;j<COLS;j++)          /* for each chtype in the line... */
      {
	 chr = (unsigned short)(s->_y[i][j] & A_CHARTEXT);
	 temp_line[j] = chtype_attr(s->_y[i][j]) | chr;
      }

      if (SP->direct_video)
      {
	 CHAR_INFO buffer[128];
	 COORD bufSize, bufPos;
	 SMALL_RECT sr;

	 bufPos.X = bufPos.Y = 0;
	 
	 bufSize.X = COLS;
	 bufSize.Y = 1;

	 sr.Top = i;
	 sr.Bottom = i;
	
	 sr.Left = 0;
	 sr.Right = COLS - 1;

	 for (j = 0; j < COLS; j++)
	 {
	    buffer[j].Char.AsciiChar = (ch[j] & 0x00FF);
	    buffer[j].Attributes = (ch[j] & 0xFF00) >> 8 ;
#ifdef HIDE_ATTR
	    buffer[j].Attributes =  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
#endif
	 }

	 WriteConsoleOutput(hConOut, buffer, bufSize, bufPos, &sr);
      }
      else
      {
	 for (j = 0; j < COLS; j++)
	 {
	    PDC_gotoxy(i, j);
	    PDC_putc( (*ch & A_CHARTEXT), (*ch & A_ATTRIBUTES) >> 8 );
	    ch++;
	 }
      }

      if (SP->refrbrk && (SP->cbreak || SP->raw_inp)) 
      {
	 rc = PDC_breakout();
	 if(rc) 
	    break;
      }

   }
   return( OK );
}

/*man-start*********************************************************************

  PDC_cursor_on()	- Turns on the hardware cursor.

  PDCurses Description:
 	Turns on the hardware curses, it does nothing if it is already on.

  PDCurses Return Value:
 	Returns OK upon success, ERR upon failure.

  Portability:
 	PDCurses	int PDC_cursor_on( void );

**man-end**********************************************************************/

/***********************************************************************/
int	PDC_cursor_on(void)
/***********************************************************************/
{
CONSOLE_CURSOR_INFO cci;

#ifdef PDCDEBUG
   if (trace_on) PDC_debug("PDC_cursor_on() - called\n");
#endif

	if (!SP->visible_cursor)
	{
		SP->visible_cursor = TRUE;
		GetConsoleCursorInfo(hConOut,&cci);
		cci.bVisible = TRUE;
		SetConsoleCursorInfo(hConOut,&cci);
	}
	return( OK );
}

/*man-start*********************************************************************

  PDC_cursor_off()	- Turns off the hardware cursor.

  PDCurses Description:
 	Turns off the hardware curses, it does nothing if it is already off.

  PDCurses Return Value:
 	Returns OK upon success, ERR upon failure.

  PDCurses Errors:
 	ERR will be returned (in the case of FLEXOS) if the hardware cursor
 	can not be disabled.

  Portability:
 	PDCurses	int PDC_cursor_off( void );

**man-end**********************************************************************/

/***********************************************************************/
int	PDC_cursor_off(void)
/***********************************************************************/
{
CONSOLE_CURSOR_INFO cci;

#ifdef PDCDEBUG
   if (trace_on) PDC_debug("PDC_cursor_off() - called\n");
#endif
   
	if (SP->visible_cursor)
	{
		SP->visible_cursor = FALSE;
		GetConsoleCursorInfo(hConOut,&cci);
		cci.bVisible = FALSE;
		SetConsoleCursorInfo(hConOut,&cci);
	}

	return( OK );
}

/*man-start*********************************************************************

  PDC_fix_cursor()	- Fix the cursor start and stop scan lines (if necessary)

  PDCurses Description:
 	This is a private PDCurses routine.

 	This routine will fix the cursor shape for certain video adapters.
 	Normally, the values used are correct, but some adapters choke.
 	The most noticable choke is on a monochrome adapter.  The "correct"
 	scan lines will result in the cursor being set in the middle of the
 	character cell, rather than at the bottom.

 	The passed flag indicates whether the cursor is visible or not.

 	This only applies to the DOS platform.

  PDCurses Return Value:
 	This function returns OK on success and ERR on error.

  PDCurses Errors:
 	No errors are defined for this function.

  Portability:
 	PDCurses	int PDC_fix_cursor( int flag );

**man-end**********************************************************************/

/***********************************************************************/
int	PDC_fix_cursor(int flag)
/***********************************************************************/
{
	return(OK);
}

/*man-start*********************************************************************

  PDC_gotoxy()	- position hardware cursor at (x, y)

  PDCurses Description:
	This is a private PDCurses routine.

 	Moves the physical cursor to the desired address on the
 	screen. We don't optimize here -- on a PC, it takes more time
 	to optimize than to do things directly.

  PDCurses Return Value:
 	This function returns OK on success and ERR on error.

  PDCurses Errors:
 	No errors are defined for this function.

  Portability:
 	PDCurses	int PDC_gotoxy( int row, int col );

**man-end**********************************************************************/

/***********************************************************************/
int	PDC_gotoxy(int row, int col)
/***********************************************************************/
{
   COORD coord;

#ifdef PDCDEBUG
   if (trace_on) PDC_debug("PDC_gotoxy() - called: row %d col %d\n",row,col);
#endif

	if ((SP->cursrow == row) && (SP->curscol == col))
	return( OK );

	coord.X = col;
	coord.Y = row;

	SetConsoleCursorPosition(hConOut, coord);
	return(OK);
}

/*man-start*********************************************************************

  PDC_putc()	- Output a character in the current attribute.

  PDCurses Description:
 	This is a private PDCurses routine.

 	Outputs character 'chr' to screen in tty fashion. If a colour
 	mode is active, the character is written with colour 'colour'.

  PDCurses Return Value:
 	This function returns OK on success and ERR on error.

  PDCurses Errors:
 	No errors are defined for this function.

  Portability:
 	PDCurses	int PDC_putc( chtype character, chtype color );

**man-end**********************************************************************/

/***********************************************************************/
int	PDC_putc( chtype character, chtype color )
/***********************************************************************/
{
	int curRow, curCol;
	WORD buffer[2];
	COORD coord;
	DWORD written;

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("PDC_putc() - called:char=%c attrib=0x%x color=0x%x\n",character & A_CHARTEXT,character & A_ATTRIBUTES,color);
#endif

	buffer[0] = color;
	PDC_get_cursor_pos (&curRow, &curCol);
	coord.X = curCol;
	coord.Y = curRow;
//   WriteConsoleOutputAttribute(hConOut, &buffer, 1, coord, &written);

	buffer[0] = character;
	WriteConsoleOutputCharacter(hConOut, &buffer[0], 1, coord, &written);
       
   return (OK);
}

/*man-start*********************************************************************

  PDC_putctty()	- Output a character and attribute in TTY fashion.

  PDCurses Description:
 	This is a private PDCurses routine.

 	Outputs character 'chr' to screen in tty fashion. If a colour
 	mode is active, the character is written with colour 'colour'.

 	This function moves the physical cursor after writing so the
 	screen will scroll if necessary.

  PDCurses Return Value:
 	This function returns OK on success and ERR on error.

  PDCurses Errors:
 	No errors are defined for this function.

  Portability:
 	PDCurses	int PDC_putctty( chtype character, chtype color );

**man-end**********************************************************************/

/***********************************************************************/
int	PDC_putctty( chtype character, chtype color )
/***********************************************************************/
{
   int curRow=0, curCol=0;
   WORD buffer;
   COORD coord;
   DWORD written;


#ifdef PDCDEBUG
	if (trace_on) PDC_debug("PDC_putctty() - called\n");
#endif

   buffer = color; 
   PDC_get_cursor_pos (&curRow, &curCol);
   coord.X = curCol;
   coord.Y = curRow;
//   WriteConsoleOutputAttribute(hConOut, &buffer, 1, coord, &written);
       
   buffer = character; 
	WriteConsoleOutputCharacter(hConOut, &buffer, 1, coord, &written);
       
   return (OK);
}

/*man-start*********************************************************************

  PDC_scroll()	- low level screen scroll

  PDCurses Description:
 	Scrolls a window in the current page up or down. Urow, lcol,
 	lrow, rcol are the window coordinates.	Lines is the number of
 	lines to scroll. If 0, clears the window, if < 0 scrolls down,
 	if > 0 scrolls up.  Blanks areas that are left, and sets
 	character attributes to attr. If in a colour graphics mode,
 	fills them with the colour 'attr' instead.

  PDCurses Return Value:
 	The PDC_scroll() function returns OK on success otherwise ERR is returned.

  PDCurses Errors:
 	An error will only be returned on the Flexos platform if s_copy()
 	fails.

  Portability:
 	PDCurses	int PDC_scroll( int urow, int lcol, int rcol,
 				     int nlines, chtype attr );

**man-end**********************************************************************/

/***********************************************************************/
int	PDC_scroll(int urow, int lcol, int lrow, int rcol, int nlines, chtype attr)
/***********************************************************************/
{
	extern unsigned	char atrtab[MAX_ATRTAB];
	int	phys_attr=chtype_attr(attr);

#ifdef PDCDEBUG
	if (trace_on) PDC_debug("PDC_scroll() - called: urow %d lcol %d lrow %d rcol %d nlines %d\n",urow,lcol,lrow,rcol,nlines);
#endif

	return( OK );
}

/*man-start*********************************************************************

  PDC_transform_line()	- display a physical line of the screen

  PDCurses Description:
 	This is a private PDCurses function.

 	Updates the given physical line to look like the corresponding
 	line in _curscr.

  PDCurses Return Value:
 	This routine returns TRUE if a premature refresh end
 	is allowed, and there is an input character pending.  Otherwise,
 	FALSE is returned.

  PDCurses Errors:
 	No errors are defined for this routine.

  Portability:
 	PDCurses	bool	PDC_transform_line( int lineno );

**man-end**********************************************************************/

/***********************************************************************/
bool	PDC_transform_line(register int lineno)
/***********************************************************************/
{

   int	x=0;
   int	endx=0;
   int	len=0;
	register chtype *srcp;
	extern unsigned	char atrtab[MAX_ATRTAB];

	unsigned short temp_line[256]={0};
	unsigned short chr=0;
	unsigned short*	ch=NULL;

	register int j=0;
   bool rc=FALSE;


#ifdef PDCDEBUG
	if (trace_on) PDC_debug("PDC_transform_line() - called\n");
#endif

   if (curscr == (WINDOW *)NULL)
      return( FALSE );

   x = curscr->_firstch[lineno];
   endx = curscr->_lastch[lineno];
	srcp = curscr->_y[lineno] + x;
   len = endx-x+1;
   
   ch = temp_line; /* now have ch pointing to area to contain real attributes. MH-920715 */

/* replace the attribute part of the chtype with the actual colour value */
/* replacing the number that points to the actual colour value.          */

   for (j=0;j<len;j++)          /* for each chtype in the line... */
   {
      chr = *(srcp+j) & A_CHARTEXT;
      temp_line[j] = chtype_attr(*(srcp+j)) | chr;
   }

	if (SP->direct_video)
	{
	 CHAR_INFO ci[128];
	 COORD bufSize, bufPos;
	 SMALL_RECT sr;

	 bufPos.X = bufPos.Y = 0;

	 bufSize.X = (endx - x) + 1;
	 bufSize.Y = 1;

	 sr.Top = lineno;
	 sr.Bottom = lineno;

	 sr.Left = x;
	 sr.Right = endx;

	 for (j = 0; j < (endx - x) + 1; j++)
	 {
		 ci[j].Char.AsciiChar = (ch[j] & 0x00FF);
		 ci[j].Attributes = (ch[j] & 0xFF00) >> 8 ;
#ifdef HIDE_ATTR
	    ci[j].Attributes =  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
#endif
	 }

	 WriteConsoleOutput(hConOut, ci, bufSize, bufPos, &sr);
	}
	else
	{
		PDC_gotoxy(lineno,x);
		for (; x <= endx; x++)
		{
	 PDC_putc( (*ch & A_CHARTEXT),(*ch & A_ATTRIBUTES) );
	 ch++;
      }

      
   }
   curscr->_firstch[lineno] = _NO_CHANGE;
   curscr->_lastch[lineno] = _NO_CHANGE;
   
   if (SP->refrbrk && (SP->cbreak || SP->raw_inp)) 
   {
      rc = PDC_breakout();
      if(rc) 
	 return(TRUE);
   }
   return(FALSE);
}

