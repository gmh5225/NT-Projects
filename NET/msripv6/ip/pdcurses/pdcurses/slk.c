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
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <curses.h>

/* undefine any macros for functions defined in this module */
#undef	slk_init
#undef	slk_set
#undef	slk_refresh
#undef	slk_noutrefresh
#undef	slk_label
#undef	slk_clear
#undef	slk_restore
#undef	slk_touch
#undef	slk_attron
#undef	slk_attrset
#undef	slk_attroff

/* undefine any macros for functions called by this module if in debug mode */
#ifdef PDCDEBUG
#endif

#ifdef PDCDEBUG
char *rcsid_slk  = "$Id$";
#endif

/*man-start*********************************************************************

  Name:                                                          slk

  Synopsis:

  	int slk_init(int fmt);
  	int slk_set(int labnum, char *label, int fmt);
  	int slk_refresh(void);
  	int slk_noutrefresh(void);
  	char *slk_label(int labnum);
  	int slk_clear(void);
  	int slk_restore(void);
  	int slk_touch(void);
  	int slk_attron(attr_t attrs);
  	int slk_attrset(attr_t attrs);
  	int slk_attroff(attr_t attrs);

  X/Open Description:
 	These functions manipulate the current attributes of the named
 	window.  These attributes can be any combination of A_STANDOUT,
 	A_REVERSE, A_BOLD, A_DIM, A_BLINK, A_UNDERLINE.

 	NOTE:	attroff(), attron(), attrset(), standend(), standout(),
 		wstandend(), and wstandout() are defined as macros.

  PDCurses Description:
 	System V compatible color support is included.
 	See <curses.h> for further details.

  X/Open Return Value:
 	All functions return OK on success and ERR on error.

  X/Open Errors:
 	It is an error to call this function with a NULL window pointer.

  Portability                             X/Open    BSD    SYS V
                                          Dec '88
      slk_init                              Y        -       Y
      slk_set                               Y        -       Y
      slk_refresh                           Y        -       Y
      slk_noutrefresh                       Y        -       Y
      slk_label                             Y        -       Y
      slk_clear                             Y        -       Y
      slk_restore                           Y        -       Y
      slk_touch                             Y        -       Y
      slk_attron                            Y        -       Y
      slk_attrset                           Y        -       Y
      slk_attroff

**man-end**********************************************************************/

/***********************************************************************/
#ifdef HAVE_PROTO
int	PDC_CDECL	slk_init(int fmt)
#else
int	PDC_CDECL	slk_init(fmt)
int fmt;
#endif
/***********************************************************************/
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("slk_init() - called\n");
#endif
/****************** this does nothing at the moment ***************/
	return( OK );
}
/***********************************************************************/
#ifdef HAVE_PROTO
int	PDC_CDECL	slk_set(int labnum, char *lab, int fmt)
#else
int	PDC_CDECL	slk_set(labnum, lab, fmt)
int labnum;
char *lab;
int fmt;
#endif
/***********************************************************************/
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("slk_set() - called\n");
#endif
/****************** this does nothing at the moment ***************/
	return( OK );
}
/***********************************************************************/
#ifdef HAVE_PROTO
int	PDC_CDECL	slk_refresh(void)
#else
int	PDC_CDECL	slk_refresh()
#endif
/***********************************************************************/
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("slk_refresh() - called\n");
#endif
/****************** this does nothing at the moment ***************/
	return( OK );
}
/***********************************************************************/
#ifdef HAVE_PROTO
int	PDC_CDECL	slk_noutrefresh(void)
#else
int	PDC_CDECL	slk_noutrefresh()
#endif
/***********************************************************************/
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("slk_noutrefresh() - called\n");
#endif
/****************** this does nothing at the moment ***************/
	return( OK );
}
/***********************************************************************/
#ifdef HAVE_PROTO
char*	PDC_CDECL	slk_label(int labnum)
#else
char*	PDC_CDECL	slk_label(labnum)
int labnum;
#endif
/***********************************************************************/
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("slk_label() - called\n");
#endif
/****************** this does nothing at the moment ***************/
	return(NULL);
}
/***********************************************************************/
#ifdef HAVE_PROTO
int	PDC_CDECL	slk_clear(void)
#else
int	PDC_CDECL	slk_clear()
#endif
/***********************************************************************/
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("slk_clear() - called\n");
#endif
/****************** this does nothing at the moment ***************/
	return( OK );
}
/***********************************************************************/
#ifdef HAVE_PROTO
int	PDC_CDECL	slk_restore(void)
#else
int	PDC_CDECL	slk_restore()
#endif
/***********************************************************************/
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("slk_restore() - called\n");
#endif
/****************** this does nothing at the moment ***************/
	return( OK );
}
/***********************************************************************/
#ifdef HAVE_PROTO
int	PDC_CDECL	slk_touch(void)
#else
int	PDC_CDECL	slk_touch()
#endif
/***********************************************************************/
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("slk_touch() - called\n");
#endif
/****************** this does nothing at the moment ***************/
	return( OK );
}
/***********************************************************************/
#ifdef HAVE_PROTO
int	PDC_CDECL	slk_attron(attr_t attrs)
#else
int	PDC_CDECL	slk_attron(attrs)
attr_t attrs;
#endif
/***********************************************************************/
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("slk_attron() - called\n");
#endif
/****************** this does nothing at the moment ***************/
	return( OK );
}
/***********************************************************************/
#ifdef HAVE_PROTO
int	PDC_CDECL	slk_attroff(attr_t attrs)
#else
int	PDC_CDECL	slk_attroff(attrs)
attr_t attrs;
#endif
/***********************************************************************/
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("slk_attroff() - called\n");
#endif
/****************** this does nothing at the moment ***************/
	return( OK );
}
/***********************************************************************/
#ifdef HAVE_PROTO
int	PDC_CDECL	slk_attrset(attr_t attrs)
#else
int	PDC_CDECL	slk_attrset(attrs)
attr_t attrs;
#endif
/***********************************************************************/
{
#ifdef PDCDEBUG
	if (trace_on) PDC_debug("slk_attrset() - called\n");
#endif
/****************** this does nothing at the moment ***************/
	return( OK );
}
