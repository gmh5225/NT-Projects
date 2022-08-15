@echo off
if not exist build\* mkdir build
if not exist build\intel\* mkdir build\intel
if not exist build\intel\mt_obj\* mkdir build\intel\mt_obj
if not exist build\intel\mt_obj\cpp_obj\* mkdir build\intel\mt_obj\cpp_obj
if not exist build\intel\mt_obj\pure_obj\* mkdir build\intel\mt_obj\pure_obj
echo.
echo # *** These are the compiler switches for the MT model (LIBCMT.LIB):
echo #
echo # CL = -c -nologo -Zlp8 -W3 -WX -GFy -DWIND32 -GS -Zc:wchar_t \
echo # -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x0400 -D_WIN32_WINDOWS=0x400 -D-DNOSERVICE -Fdbuild\intel\libcmt.pdb \
echo # -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT
echo #
echo # ML = -c -nologo -coff -Cx -Zm -DQUIET -D?QUIET -Di386 -D_WIN32 -DWIN32 \
echo # -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT
echo.
cd .
set CL=-c -nologo -Zlp8 -W3 -WX -GFy -DWIND32 -GS -Zc:wchar_t -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x0400 -D_WIN32_WINDOWS=0x400 -D-DNOSERVICE -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -Fdbuild\intel\libcmt.pdb
set ML=-c -nologo -coff -Cx -Zm -DQUIET -D?QUIET -Di386 -D_WIN32 -DWIN32 -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT
"C:\Program Files (x86)\Microsoft Visual Studio 8\VC\BIN\nmake.exe" -nologo -i -f makefile.sub DIR=. CPUDIR=intel  WINHEAP=YES RTC=YES  BLD_REL_NO_DBINFO=  BLD_MODEL=mt OBJDIR=build\intel\mt_obj  CPP_OBJDIR=build\intel\mt_obj\cpp_obj  PURE_OBJDIR=build\intel\mt_obj\pure_obj  TARGET_CPU=i386 HOST_CPU=i386  MT_LIB_DIR=mt_lib  VCTOOLSINC="C:\Program Files (x86)\Microsoft Visual Studio 8\VC\PlatformSDK\include"  PRE_BLD=0 POST_BLD=1
cd .
echo.
echo # *** These are the compiler switches for the MT model (LIBCPMT.LIB):
echo #
echo # CL = -c -nologo -Zlp8 -W3 -WX -GFy -DWIND32 -GS -Zc:wchar_t \
echo # -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x0400 -D_WIN32_WINDOWS=0x400 -D-DNOSERVICE -Fdbuild\intel\libcpmt.pdb \
echo # -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT
echo #
echo # ML = -c -nologo -coff -Cx -Zm -DQUIET -D?QUIET -Di386 -D_WIN32 -DWIN32 \
echo # -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT
echo.
cd .
set CL=-c -nologo -Zlp8 -W3 -WX -GFy -DWIND32 -GS -Zc:wchar_t -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x0400 -D_WIN32_WINDOWS=0x400 -D-DNOSERVICE -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -Fdbuild\intel\libcpmt.pdb
set ML=-c -nologo -coff -Cx -Zm -DQUIET -D?QUIET -Di386 -D_WIN32 -DWIN32 -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT
"C:\Program Files (x86)\Microsoft Visual Studio 8\VC\BIN\nmake.exe" -nologo -i -f makefile.sub DIR=. CPUDIR=intel  WINHEAP=YES RTC=YES  BLD_REL_NO_DBINFO=  BLD_MODEL=mt OBJDIR=build\intel\mt_obj  CPP_OBJDIR=build\intel\mt_obj\cpp_obj  TARGET_CPU=i386 HOST_CPU=i386  MT_LIB_DIR=mt_lib  VCTOOLSINC="C:\Program Files (x86)\Microsoft Visual Studio 8\VC\PlatformSDK\include"  PRE_BLD=0 POST_BLD=1 _stdcpp_
cd .
if not exist build\intel\dll_obj\* mkdir build\intel\dll_obj
if not exist build\intel\dll_obj\pure_obj\* mkdir build\intel\dll_obj\pure_obj
if not exist build\intel\dll_obj\clr_obj\* mkdir build\intel\dll_obj\clr_obj
if not exist build\intel\dll_obj\cpp_obj\* mkdir build\intel\dll_obj\cpp_obj
echo.
echo # *** These are the compiler switches for the DLL model (MSVCRT.LIB):
echo #
echo # CL = -c -nologo -Zlp8 -W3 -WX -GFy -DWIND32 -GS -Zc:wchar_t \
echo # -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x0400 -D_WIN32_WINDOWS=0x400 -D-DNOSERVICE -Fdbuild\intel\_sample_.pdb \
echo # -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -DCRTDLL
echo #
echo # ML = -c -nologo -coff -Cx -Zm -DQUIET -D?QUIET -Di386 -D_WIN32 -DWIN32 \
echo # -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -DCRTDLL
echo.
cd .
set CL=-c -nologo -Zlp8 -W3 -WX -GFy -DWIND32 -GS -Zc:wchar_t -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x0400 -D_WIN32_WINDOWS=0x400 -D-DNOSERVICE -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -DCRTDLL -Fdbuild\intel\_sample_.pdb
set ML=-c -nologo -coff -Cx -Zm -DQUIET -D?QUIET -Di386 -D_WIN32 -DWIN32 -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -DCRTDLL
"C:\Program Files (x86)\Microsoft Visual Studio 8\VC\BIN\nmake.exe" -nologo -i -f makefile.sub DIR=. CPUDIR=intel  WINHEAP=YES RTC=YES  BLD_REL_NO_DBINFO=  BLD_MODEL=dll BLD_DLL=1 OBJDIR=build\intel\dll_obj  CPP_OBJDIR=build\intel\dll_obj\cpp_obj  PURE_OBJDIR=build\intel\dll_obj\pure_obj  CLR_OBJDIR=build\intel\dll_obj\clr_obj  TARGET_CPU=i386 HOST_CPU=i386  VCTOOLSINC="C:\Program Files (x86)\Microsoft Visual Studio 8\VC\PlatformSDK\include"  PRE_BLD=0 POST_BLD=1
cd .
echo.
echo # *** These are the compiler switches for the DLL model (MSVCMRT.LIB):
echo #
echo # CL = -c -nologo -Zlp8 -W3 -WX -GFy -DWIND32 -GS -Zc:wchar_t \
echo # -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x0400 -D_WIN32_WINDOWS=0x400 -D-DNOSERVICE -Fdbuild\intel\_sample_.pdb \
echo # -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -D_DLL -DMRTDLL
echo #
echo # ML = -c -nologo -coff -Cx -Zm -DQUIET -D?QUIET -Di386 -D_WIN32 -DWIN32 \
echo # -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -D_DLL -DMRTDLL
echo.
cd .
set CL=-c -nologo -Zlp8 -W3 -WX -GFy -DWIND32 -GS -Zc:wchar_t -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x0400 -D_WIN32_WINDOWS=0x400 -D-DNOSERVICE -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -D_DLL -DMRTDLL -Fdbuild\intel\sample_m.pdb
set ML=-c -nologo -coff -Cx -Zm -DQUIET -D?QUIET -Di386 -D_WIN32 -DWIN32 -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -D_DLL -DMRTDLL
"C:\Program Files (x86)\Microsoft Visual Studio 8\VC\BIN\nmake.exe" -nologo -i -f makefile.sub DIR=. CPUDIR=intel  WINHEAP=YES RTC=YES  BLD_REL_NO_DBINFO=  BLD_MODEL=dll BLD_DLL=1 OBJDIR=build\intel\dll_obj  CPP_OBJDIR=build\intel\dll_obj\cpp_obj  PURE_OBJDIR=build\intel\dll_obj\pure_obj  CLR_OBJDIR=build\intel\dll_obj\clr_obj  TARGET_CPU=i386 HOST_CPU=i386  VCTOOLSINC="C:\Program Files (x86)\Microsoft Visual Studio 8\VC\PlatformSDK\include"  PURE_OBJ_DIR=pure_obj CLR_OBJ_DIR=clr_obj  PRE_BLD=0 POST_BLD=1 _mix_ _pure_
cd .
echo.
echo # *** These are the compiler switches for the DLL model (MSVCPRT.LIB):
echo #
echo # CL = -c -nologo -Zlp8 -W3 -WX -GFy -DWIND32 -GS -Zc:wchar_t \
echo # -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x0400 -D_WIN32_WINDOWS=0x400 -D-DNOSERVICE -Fdbuild\intel\sample_p.pdb \
echo # -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -D_DLL -DCRTDLL2
echo #
echo # ML = -c -nologo -coff -Cx -Zm -DQUIET -D?QUIET -Di386 -D_WIN32 -DWIN32 \
echo # -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -D_DLL -DCRTDLL2
echo.
cd .
set CL=-c -nologo -Zlp8 -W3 -WX -GFy -DWIND32 -GS -Zc:wchar_t -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x0400 -D_WIN32_WINDOWS=0x400 -D-DNOSERVICE -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -D_DLL -DCRTDLL2 -Fdbuild\intel\sample_p.pdb
set ML=-c -nologo -coff -Cx -Zm -DQUIET -D?QUIET -Di386 -D_WIN32 -DWIN32 -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -D_DLL -DCRTDLL2
"C:\Program Files (x86)\Microsoft Visual Studio 8\VC\BIN\nmake.exe" -nologo -i -f makefile.sub DIR=. CPUDIR=intel  WINHEAP=YES RTC=YES  BLD_REL_NO_DBINFO=  BLD_MODEL=dll BLD_DLL=1 OBJDIR=build\intel\dll_obj  CPP_OBJDIR=build\intel\dll_obj\cpp_obj  TARGET_CPU=i386 HOST_CPU=i386  VCTOOLSINC="C:\Program Files (x86)\Microsoft Visual Studio 8\VC\PlatformSDK\include"  PRE_BLD=0 POST_BLD=1 _stdcpp_
cd .
if not exist build\intel\xmt_obj\* mkdir build\intel\xmt_obj
if not exist build\intel\xmt_obj\cpp_obj\* mkdir build\intel\xmt_obj\cpp_obj
if not exist build\intel\xmt_obj\pure_obj\* mkdir build\intel\xmt_obj\pure_obj
echo.
echo # *** These are the compiler switches for the XMT model (LIBCMTD.LIB):
echo #
echo # CL = -c -nologo -Zlp8 -W3 -WX -GFy -DWIND32 -GS -Zc:wchar_t \
echo # -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x0400 -D_WIN32_WINDOWS=0x400 -D-DNOSERVICE -Fdbuild\intel\libcmtd.pdb \
echo # -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT
echo #
echo # ML = -c -nologo -coff -Cx -Zm -DQUIET -D?QUIET -Di386 -D_WIN32 -DWIN32 \
echo # -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT
echo.
cd .
set CL=-c -nologo -Zlp8 -W3 -WX -GFy -DWIND32 -GS -Zc:wchar_t -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x0400 -D_WIN32_WINDOWS=0x400 -D-DNOSERVICE -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -Fdbuild\intel\libcmtd.pdb
set ML=-c -nologo -coff -Cx -Zm -DQUIET -D?QUIET -Di386 -D_WIN32 -DWIN32 -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT
"C:\Program Files (x86)\Microsoft Visual Studio 8\VC\BIN\nmake.exe" -nologo -i -f makefile.sub DIR=. CPUDIR=intel  WINHEAP=YES RTC=YES  BLD_REL_NO_DBINFO=  BLD_MODEL=xmt BLD_DBG=1 OBJDIR=build\intel\xmt_obj  CPP_OBJDIR=build\intel\xmt_obj\cpp_obj  PURE_OBJDIR=build\intel\xmt_obj\pure_obj  TARGET_CPU=i386 HOST_CPU=i386  VCTOOLSINC="C:\Program Files (x86)\Microsoft Visual Studio 8\VC\PlatformSDK\include"  PRE_BLD=0 POST_BLD=1
cd .
echo.
echo # *** These are the compiler switches for the XMT model (LIBCPMTD.LIB):
echo #
echo # CL = -c -nologo -Zlp8 -W3 -WX -GFy -DWIND32 -GS -Zc:wchar_t \
echo # -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x0400 -D_WIN32_WINDOWS=0x400 -D-DNOSERVICE -Fdbuild\intel\libcpmtd.pdb \
echo # -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT
echo #
echo # ML = -c -nologo -coff -Cx -Zm -DQUIET -D?QUIET -Di386 -D_WIN32 -DWIN32 \
echo # -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT
echo.
cd .
set CL=-c -nologo -Zlp8 -W3 -WX -GFy -DWIND32 -GS -Zc:wchar_t -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x0400 -D_WIN32_WINDOWS=0x400 -D-DNOSERVICE -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -Fdbuild\intel\libcpmtd.pdb
set ML=-c -nologo -coff -Cx -Zm -DQUIET -D?QUIET -Di386 -D_WIN32 -DWIN32 -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT
"C:\Program Files (x86)\Microsoft Visual Studio 8\VC\BIN\nmake.exe" -nologo -i -f makefile.sub DIR=. CPUDIR=intel  WINHEAP=YES RTC=YES  BLD_REL_NO_DBINFO=  BLD_MODEL=xmt BLD_DBG=1 OBJDIR=build\intel\xmt_obj  CPP_OBJDIR=build\intel\xmt_obj\cpp_obj  TARGET_CPU=i386 HOST_CPU=i386  VCTOOLSINC="C:\Program Files (x86)\Microsoft Visual Studio 8\VC\PlatformSDK\include"  PRE_BLD=0 POST_BLD=1 _stdcpp_
cd .
if not exist build\intel\xdll_obj\* mkdir build\intel\xdll_obj
if not exist build\intel\xdll_obj\pure_obj\* mkdir build\intel\xdll_obj\pure_obj
if not exist build\intel\xdll_obj\clr_obj\* mkdir build\intel\xdll_obj\clr_obj
if not exist build\intel\xdll_obj\cpp_obj\* mkdir build\intel\xdll_obj\cpp_obj
echo.
echo # *** These are the compiler switches for the XDLL model (MSVCRTD.LIB):
echo #
echo # CL = -c -nologo -Zlp8 -W3 -WX -GFy -DWIND32 -GS -Zc:wchar_t \
echo # -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x0400 -D_WIN32_WINDOWS=0x400 -D-DNOSERVICE -Fdbuild\intel\_sampld_.pdb \
echo # -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -DCRTDLL
echo #
echo # ML = -c -nologo -coff -Cx -Zm -DQUIET -D?QUIET -Di386 -D_WIN32 -DWIN32 \
echo # -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -DCRTDLL
echo.
cd .
set CL=-c -nologo -Zlp8 -W3 -WX -GFy -DWIND32 -GS -Zc:wchar_t -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x0400 -D_WIN32_WINDOWS=0x400 -D-DNOSERVICE -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -DCRTDLL -Fdbuild\intel\_sampld_.pdb
set ML=-c -nologo -coff -Cx -Zm -DQUIET -D?QUIET -Di386 -D_WIN32 -DWIN32 -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -DCRTDLL
"C:\Program Files (x86)\Microsoft Visual Studio 8\VC\BIN\nmake.exe" -nologo -i -f makefile.sub DIR=. CPUDIR=intel  WINHEAP=YES RTC=YES  BLD_REL_NO_DBINFO=  BLD_MODEL=xdll BLD_DLL=1 BLD_DBG=1 OBJDIR=build\intel\xdll_obj  CPP_OBJDIR=build\intel\xdll_obj\cpp_obj  PURE_OBJDIR=build\intel\xdll_obj\pure_obj  CLR_OBJDIR=build\intel\xdll_obj\clr_obj  TARGET_CPU=i386 HOST_CPU=i386  VCTOOLSINC="C:\Program Files (x86)\Microsoft Visual Studio 8\VC\PlatformSDK\include"  PRE_BLD=0 POST_BLD=1
cd .
echo.
echo # *** These are the compiler switches for the DLL model (MSVCMRTD.LIB):
echo #
echo # CL = -c -nologo -Zlp8 -W3 -WX -GFy -DWIND32 -GS -Zc:wchar_t \
echo # -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x0400 -D_WIN32_WINDOWS=0x400 -D-DNOSERVICE -Fdbuild\intel\_sample_.pdb \
echo # -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -D_DLL -DMRTDLL
echo #
echo # ML = -c -nologo -coff -Cx -Zm -DQUIET -D?QUIET -Di386 -D_WIN32 -DWIN32 \
echo # -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -D_DLL -DMRTDLL
echo.
cd .
set CL=-c -nologo -Zlp8 -W3 -WX -GFy -DWIND32 -GS -Zc:wchar_t -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x0400 -D_WIN32_WINDOWS=0x400 -D-DNOSERVICE -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -D_DLL -DMRTDLL -Fdbuild\intel\sampld_m.pdb
set ML=-c -nologo -coff -Cx -Zm -DQUIET -D?QUIET -Di386 -D_WIN32 -DWIN32 -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -D_DLL -DMRTDLL
"C:\Program Files (x86)\Microsoft Visual Studio 8\VC\BIN\nmake.exe" -nologo -i -f makefile.sub DIR=. CPUDIR=intel  WINHEAP=YES RTC=YES  BLD_REL_NO_DBINFO=  BLD_MODEL=xdll BLD_DLL=1 BLD_DBG=1 OBJDIR=build\intel\xdll_obj  CPP_OBJDIR=build\intel\xdll_obj\cpp_obj  PURE_OBJDIR=build\intel\xdll_obj\pure_obj  CLR_OBJDIR=build\intel\xdll_obj\clr_obj  TARGET_CPU=i386 HOST_CPU=i386  VCTOOLSINC="C:\Program Files (x86)\Microsoft Visual Studio 8\VC\PlatformSDK\include"  PURE_OBJ_DIR=pure_obj CLR_OBJ_DIR=clr_obj  PRE_BLD=0 POST_BLD=1 _mix_ _pure_
cd .
echo.
echo # *** These are the compiler switches for the XDLL model (MSVCPRTD.LIB):
echo #
echo # CL = -c -nologo -Zlp8 -W3 -WX -GFy -DWIND32 -GS -Zc:wchar_t \
echo # -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x0400 -D_WIN32_WINDOWS=0x400 -D-DNOSERVICE -Fdbuild\intel\sampld_p.pdb \
echo # -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -D_DLL -DCRTDLL2
echo #
echo # ML = -c -nologo -coff -Cx -Zm -DQUIET -D?QUIET -Di386 -D_WIN32 -DWIN32 \
echo # -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -D_DLL -DCRTDLL2
echo.
cd .
set CL=-c -nologo -Zlp8 -W3 -WX -GFy -DWIND32 -GS -Zc:wchar_t -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x0400 -D_WIN32_WINDOWS=0x400 -D-DNOSERVICE -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -D_DLL -DCRTDLL2 -Fdbuild\intel\sampld_p.pdb
set ML=-c -nologo -coff -Cx -Zm -DQUIET -D?QUIET -Di386 -D_WIN32 -DWIN32 -D_MBCS -D_MB_MAP_DIRECT -D_CRTBLD -D_FN_WIDE -DWINHEAP -D_RTC -D_MT -D_DLL -DCRTDLL2
"C:\Program Files (x86)\Microsoft Visual Studio 8\VC\BIN\nmake.exe" -nologo -i -f makefile.sub DIR=. CPUDIR=intel  WINHEAP=YES RTC=YES  BLD_REL_NO_DBINFO=  BLD_MODEL=xdll BLD_DLL=1 BLD_DBG=1 OBJDIR=build\intel\xdll_obj  CPP_OBJDIR=build\intel\xdll_obj\cpp_obj  TARGET_CPU=i386 HOST_CPU=i386  VCTOOLSINC="C:\Program Files (x86)\Microsoft Visual Studio 8\VC\PlatformSDK\include"  PRE_BLD=0 POST_BLD=1 _stdcpp_
cd .
