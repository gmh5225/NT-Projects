#
# Makefile for use with Microsoft Visual C++
#
CPP = cl.exe
RSC = rc.exe
LINK = link.exe
COMPRESS = compress.exe

!ifdef DEBUG
CPPFLAGS = -nologo -Od -Zi -Yd -GX -MTd -DWIN32 -DMSRIPv6 -I. -I..\..\..\msripv6\inc -I$(NTMAKEENV)
LINKFLAGS = -nologo -release -libpath:..\..\..\msripv6\wship6\obj\i386\checked
!else
CPPFLAGS = -nologo -Oityb1 -GX -MT -DWIN32 -DMSRIPv6 -I. -I..\..\..\msripv6\inc -I$(NTMAKEENV)
LINKFLAGS = -nologo -release -libpath:..\..\..\msripv6\wship6\obj\i386\free
!endif

LIBS = user32.lib gdi32.lib advapi32.lib shell32.lib wsock32.lib wship6.lib

OBJS = cgi.obj\
       date.obj\
       debug.obj\
       error.obj\
       fnord.obj\
       fnordsrv.obj\
       httpdir.obj\
       httplog.obj\
       httpmap.obj\
       httpmime.obj\
       httpreq.obj\
       httpsend.obj\
       httpsrv.obj\
       imagemap.obj\
       isapi.obj\
       netio.obj\
       parse.obj\
       profile.obj\
       registry.obj\
       tray.obj\
       users.obj\
       wincgi.obj

fnord: fnord.exe

fnordnt: fnordnt.exe

all: fnord.exe

fnord.exe : $(OBJS) fnord.res
  $(LINK) $(LINKFLAGS) -subsystem:windows @<<
  $(OBJS) fnord.res -out:fnord.exe $(LIBS)
<<

fnordnt.exe : $(OBJS) fnord.res
  $(LINK) $(LINKFLAGS) -subsystem:console @<<
  $(OBJS) fnord.res -out:fnordnt.exe $(LIBS)
<<

netio.obj: netio.cpp build.h error.h debug.h netio.h

httplog.obj: httplog.cpp build.h error.h debug.h parse.h registry.h

registry.obj: registry.cpp build.h error.h debug.h parse.h netio.h registry.h

date.obj: date.cpp build.h error.h debug.h date.h

httpmime.obj: httpmime.cpp build.h error.h debug.h parse.h httpmime.h

error.obj: error.cpp build.h error.h debug.h

httpreq.obj: httpreq.cpp build.h error.h debug.h parse.h date.h netio.h\
	registry.h users.h tray.h httpmime.h httplog.h httpreq.h httpsrv.h\
	httpmap.h httpsend.h httpdir.h imagemap.h cgi.h isapi.h

fnordsrv.obj: fnordsrv.cpp build.h error.h debug.h fnord.h

fnord.obj: fnord.cpp

fnord.res: fnord.rc fnord1.ico tray.ico
  $(RSC) fnord.rc

clean:
  -del *.res
  -del *.obj

kit:
  -$(COMPRESS) fnord.exe ..\..\Install\fnord.ex_
  -$(COMPRESS) fnordnt.exe ..\..\Install\fnordnt.ex_
  -$(COMPRESS) ..\Control\fnordctl.exe ..\..\Install\fnordctl.ex_
