################################################################################
#
# Visual C++ NMakefile for PDCurses library - Win32 VC++ 2.0+
#
# Usage: nmake -f [path\]vcwin32.mak [DEBUG=] [target]
#
# where target can be any of:
# [all|demos|pdcurses.lib|panel.lib|testcurs.exe...]
#
################################################################################
#
# Change these for your environment...
#
################################################################################
PDCURSES_HOME	=..\..\pdcurses
CC_HOME		="c:\Program Files\DevStudio\VC"
################################################################################
# Nothing below here should required changing.
################################################################################

PDCURSES_CURSES_H		=$(PDCURSES_HOME)\curses.h
PDCURSES_CURSPRIV_H		=$(PDCURSES_HOME)\curspriv.h
PDCURSES_HEADERS		=$(PDCURSES_CURSES_H) $(PDCURSES_CURSPRIV_H)
PANEL_HEADER		=$(PDCURSES_HOME)\panel.h

CCLIBDIR		=$(CC_HOME)\lib
CCINCDIR		=$(CC_HOME)\include

srcdir		= $(PDCURSES_HOME)\pdcurses
osdir		= $(PDCURSES_HOME)\win32
pandir		= $(PDCURSES_HOME)\panel
demodir		= $(PDCURSES_HOME)\demos

CC		= cl.exe -nologo

!ifdef DEBUG
CFLAGS  = -Z7 -DPDCDEBUG
LDFLAGS = -debug -pdb:none
!else
CFLAGS  =  -O
LDFLAGS = 
!endif

CPPFLAGS	= -I$(PDCURSES_HOME) -I$(CCINCDIR)

CCFLAGS		= -c $(CFLAGS) $(CPPFLAGS)

LINK		= link.exe -nologo

CCLIBS		= user32.lib
# may need to add msvcrt.lib for VC 2.x, VC 5.0 doesn't want it
#CCLIBS		= msvcrt.lib user32.lib
STARTUP		=

LIBEXE		= lib -nologo

LIBCURSES	= pdcurses.lib
LIBPANEL	= panel.lib

PDCLIBS	= $(LIBCURSES) $(LIBPANEL)
DEMOS	=testcurs.exe newdemo.exe xmas.exe tuidemo.exe firework.exe

################################################################################
all:	$(PDCLIBS) $(DEMOS)

clean:
	-del *.obj
	-del curses.lib
	-del panel.lib
	-del *.exe

demos:	$(DEMOS)

#------------------------------------------------------------------------

LIBOBJS =     \
addch.obj     \
addchstr.obj  \
addstr.obj    \
attr.obj      \
beep.obj      \
bkgd.obj      \
border.obj    \
clear.obj     \
color.obj     \
delch.obj     \
deleteln.obj  \
getch.obj     \
getstr.obj    \
getyx.obj     \
inch.obj      \
inchstr.obj   \
initscr.obj   \
inopts.obj    \
insch.obj     \
insstr.obj    \
instr.obj     \
kernel.obj    \
mouse.obj     \
move.obj      \
outopts.obj   \
overlay.obj   \
pad.obj       \
printw.obj    \
refresh.obj   \
scanw.obj     \
scroll.obj    \
slk.obj       \
termattr.obj  \
terminfo.obj  \
touch.obj     \
util.obj      \
window.obj

PDCOBJS =     \
pdcdebug.obj  \
pdcdisp.obj   \
pdcgetsc.obj  \
pdckbd.obj    \
pdcprint.obj  \
pdcscrn.obj   \
pdcsetsc.obj  \
pdcutil.obj   \
pdcwin.obj

PANOBJS =     \
panel.obj

pdcurses.lib : $(LIBOBJS) $(PDCOBJS)
	$(LIBEXE) -out:$@ @<<
	$(LIBOBJS) $(PDCOBJS)
<<

panel.lib : $(PANOBJS)
	$(LIBEXE) -out:$@ $(PANOBJS)

addch.obj: $(srcdir)\addch.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\addch.c

addchstr.obj: $(srcdir)\addchstr.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\addchstr.c

addstr.obj: $(srcdir)\addstr.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\addstr.c

attr.obj: $(srcdir)\attr.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\attr.c

beep.obj: $(srcdir)\beep.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\beep.c

bkgd.obj: $(srcdir)\bkgd.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\bkgd.c

border.obj: $(srcdir)\border.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\border.c

clear.obj: $(srcdir)\clear.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\clear.c

color.obj: $(srcdir)\color.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\color.c

delch.obj: $(srcdir)\delch.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\delch.c

deleteln.obj: $(srcdir)\deleteln.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\deleteln.c

getch.obj: $(srcdir)\getch.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\getch.c

getstr.obj: $(srcdir)\getstr.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\getstr.c

getyx.obj: $(srcdir)\getyx.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\getyx.c

inch.obj: $(srcdir)\inch.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\inch.c

inchstr.obj: $(srcdir)\inchstr.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\inchstr.c

initscr.obj: $(srcdir)\initscr.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\initscr.c

inopts.obj: $(srcdir)\inopts.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\inopts.c

insch.obj: $(srcdir)\insch.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\insch.c

insstr.obj: $(srcdir)\insstr.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\insstr.c

instr.obj: $(srcdir)\instr.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\instr.c

kernel.obj: $(srcdir)\kernel.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\kernel.c

mouse.obj: $(srcdir)\mouse.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\mouse.c

move.obj: $(srcdir)\move.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\move.c

outopts.obj: $(srcdir)\outopts.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\outopts.c

overlay.obj: $(srcdir)\overlay.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\overlay.c

pad.obj: $(srcdir)\pad.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\pad.c

printw.obj: $(srcdir)\printw.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\printw.c

refresh.obj: $(srcdir)\refresh.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\refresh.c

scanw.obj: $(srcdir)\scanw.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\scanw.c

scroll.obj: $(srcdir)\scroll.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\scroll.c

slk.obj: $(srcdir)\slk.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\slk.c

termattr.obj: $(srcdir)\termattr.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\termattr.c

terminfo.obj: $(srcdir)\terminfo.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\terminfo.c

touch.obj: $(srcdir)\touch.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\touch.c

util.obj: $(srcdir)\util.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\util.c

window.obj: $(srcdir)\window.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\window.c


pdcdebug.obj: $(srcdir)\pdcdebug.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\pdcdebug.c

pdcdisp.obj: $(osdir)\pdcdisp.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(osdir)\pdcdisp.c

pdcgetsc.obj: $(osdir)\pdcgetsc.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(osdir)\pdcgetsc.c

pdckbd.obj: $(osdir)\pdckbd.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(osdir)\pdckbd.c

pdcprint.obj: $(osdir)\pdcprint.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(osdir)\pdcprint.c

pdcscrn.obj: $(osdir)\pdcscrn.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(osdir)\pdcscrn.c

pdcsetsc.obj: $(osdir)\pdcsetsc.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(osdir)\pdcsetsc.c

pdcutil.obj: $(srcdir)\pdcutil.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\pdcutil.c

pdcwin.obj: $(srcdir)\pdcwin.c $(PDCURSES_HEADERS)
	$(CC) $(CCFLAGS) -Fo$@ $(srcdir)\pdcwin.c

#------------------------------------------------------------------------

panel.obj: $(pandir)\panel.c $(PDCURSES_HEADERS) $(PANEL_HEADER)
	$(CC) $(CCFLAGS) -Fo$@ $(pandir)\panel.c

#------------------------------------------------------------------------

firework.exe:	firework.obj $(LIBCURSES)
	$(LINK) $(LDFLAGS) $(STARTUP) -out:$@ $*.obj $(LIBCURSES) $(CCLIBS)

newdemo.exe:	newdemo.obj $(LIBCURSES)
	$(LINK) $(LDFLAGS) $(STARTUP) -out:$@ $*.obj $(LIBCURSES) $(CCLIBS)

ptest.exe:	ptest.obj $(LIBCURSES) $(LIBPANEL)
	$(LINK) $(LDFLAGS) $(STARTUP) -out:$@ $*.obj $(LIBPANEL) $(LIBCURSES) $(CCLIBS)

testcurs.exe:	testcurs.obj $(LIBCURSES)
	$(LINK) $(LDFLAGS) $(STARTUP) -out:$@ $*.obj $(LIBCURSES) $(CCLIBS)

tuidemo.exe:	tuidemo.obj tui.obj $(LIBCURSES)
	$(LINK) $(LDFLAGS) $(STARTUP) -out:$@ tui.obj $*.obj $(LIBCURSES) $(CCLIBS)

xmas.exe:	xmas.obj $(LIBCURSES)
	$(LINK) $(LDFLAGS) $(STARTUP) -out:$@ $*.obj $(LIBCURSES) $(CCLIBS)


firework.obj: $(demodir)\firework.c $(PDCURSES_CURSES_H)
	$(CC) $(CCFLAGS) -Fo$@ $(demodir)\firework.c

newdemo.obj: $(demodir)\newdemo.c $(PDCURSES_CURSES_H)
	$(CC) $(CCFLAGS) -Fo$@ $(demodir)\newdemo.c

ptest.obj: $(demodir)\ptest.c $(PDCURSES_HOME)\panel.h $(PDCURSES_CURSES_H)
	$(CC) $(CCFLAGS) -Fo$@ $(demodir)\ptest.c

testcurs.obj: $(demodir)\testcurs.c $(PDCURSES_CURSES_H)
	$(CC) $(CCFLAGS) -Fo$@ $(demodir)\testcurs.c

tui.obj: $(demodir)\tui.c $(demodir)\tui.h $(PDCURSES_CURSES_H)
	$(CC) $(CCFLAGS) -I$(demodir) -Fo$@ $(demodir)\tui.c

tuidemo.obj: $(demodir)\tuidemo.c $(PDCURSES_CURSES_H)
	$(CC) $(CCFLAGS) -I$(demodir) -Fo$@ $(demodir)\tuidemo.c

xmas.obj: $(demodir)\xmas.c $(PDCURSES_CURSES_H)
	$(CC) $(CCFLAGS) -Fo$@ $(demodir)\xmas.c
