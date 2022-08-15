#
# Borland C++ IDE generated makefile
#
.AUTODEPEND


#
# Borland C++ tools
#
IMPLIB  = Implib
BCC32   = Bcc32 +BccW32.cfg 
TLINK32 = TLink32
TLIB    = TLib
BRC32   = Brc32
TASM32  = Tasm32
#
# IDE macros
#


#
# Options
#
IDE_LFLAGS32 =  -LC:\BC45\LIB
IDE_RFLAGS32 = 
LLATW32_fnorddexe =  -Tpe -aa -c
RLATW32_fnorddexe =  -w32
BLATW32_fnorddexe = 
CNIEAT_fnorddexe = -IC:\BC45\INCLUDE -D
LNIEAT_fnorddexe = -x
LEAT_fnorddexe = $(LLATW32_fnorddexe)
REAT_fnorddexe = $(RLATW32_fnorddexe)
BEAT_fnorddexe = $(BLATW32_fnorddexe)

#
# Dependency List
#
Dep_fnord = \
   fnord.exe

fnord : BccW32.cfg $(Dep_fnord)
  echo MakeNode 

Dep_fnorddexe = \
   netio.obj\
   log.obj\
   registry.obj\
   date.obj\
   mime.obj\
   error.obj\
   httpreq.obj\
   server.obj\
   fnord.obj\
   fnord.res

fnord.exe : $(Dep_fnorddexe)
  $(TLINK32) @&&|
 /v $(IDE_LFLAGS32) $(LEAT_fnorddexe) $(LNIEAT_fnorddexe) +
C:\BC45\LIB\c0w32.obj+
netio.obj+
log.obj+
registry.obj+
date.obj+
mime.obj+
error.obj+
httpreq.obj+
server.obj+
fnord.obj
$<,$*
C:\BC45\LIB\import32.lib+
C:\BC45\LIB\cw32mt.lib

|
   $(BRC32) fnord.res $<

Dep_netiodobj = \
   netio.h

netio.obj : $(Dep_netiodobj)
  $(BCC32) -c @&&|
 $(CEAT_fnorddexe) $(CNIEAT_fnorddexe) -o$@ netio.cpp
|

Dep_logdobj = \
   log.h

log.obj : $(Dep_logdobj)
  $(BCC32) -c @&&|
 $(CEAT_fnorddexe) $(CNIEAT_fnorddexe) -o$@ log.cpp
|

Dep_registrydobj = \
   registry.h

registry.obj : $(Dep_registrydobj)
  $(BCC32) -c @&&|
 $(CEAT_fnorddexe) $(CNIEAT_fnorddexe) -o$@ registry.cpp
|

Dep_datedobj = \
   date.h

date.obj : $(Dep_datedobj)
  $(BCC32) -c @&&|
 $(CEAT_fnorddexe) $(CNIEAT_fnorddexe) -o$@ date.cpp
|

Dep_mimedobj = \
   mime.h

mime.obj : $(Dep_mimedobj)
  $(BCC32) -c @&&|
 $(CEAT_fnorddexe) $(CNIEAT_fnorddexe) -o$@ mime.cpp
|

Dep_errordobj = \
   error.h

error.obj : $(Dep_errordobj)
  $(BCC32) -c @&&|
 $(CEAT_fnorddexe) $(CNIEAT_fnorddexe) -o$@ error.cpp
|

Dep_httpreqdobj = \
   httpreq.h

httpreq.obj : $(Dep_httpreqdobj)
  $(BCC32) -c @&&|
 $(CEAT_fnorddexe) $(CNIEAT_fnorddexe) -o$@ httpreq.cpp
|

Dep_serverdobj = \
   server.h

server.obj : $(Dep_serverdobj)
  $(BCC32) -c @&&|
 $(CEAT_fnorddexe) $(CNIEAT_fnorddexe) -o$@ server.cpp
|

fnord.obj :  fnord.cpp
  $(BCC32) -c @&&|
 $(CEAT_fnorddexe) $(CNIEAT_fnorddexe) -o$@ fnord.cpp
|

fnord.res :  fnord.rc
  $(BRC32) $(IDE_RFLAGS32) $(REAT_fnorddexe) $(CNIEAT_fnorddexe) -R -FO$@ fnord.rc

# Compiler configuration file
BccW32.cfg : 
   Copy &&|
-R
-v
-vi
-H
-H=httpd.csm
-d
-v-
-R-
-k-
-4
-a2
-Og
-Z-
-O
-Oe
-Ol
-Ob
-OW
-Om
-Op
-Oi
-Ov
-K-
-p-
-Ot
-Oa
-f-
-ff-
-WM
-W
| $@


