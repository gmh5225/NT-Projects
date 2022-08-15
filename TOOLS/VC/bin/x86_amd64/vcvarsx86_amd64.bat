@SET VSINSTALLDIR=C:\Program Files (x86)\Microsoft Visual Studio 8
@SET VCINSTALLDIR=C:\Program Files (x86)\Microsoft Visual Studio 8\VC
@SET FrameworkDir=C:\WINDOWS\Microsoft.NET\Framework
@SET FrameworkVersion=v2.0.50727
@SET FrameworkSDKDir=C:\Program Files (x86)\Microsoft Visual Studio 8\SDK\v2.0
@if "%VSINSTALLDIR%"=="" goto error_no_VSINSTALLDIR
@if "%VCINSTALLDIR%"=="" goto error_no_VCINSTALLDIR

@echo Setting environment for using Microsoft Visual Studio 2005 x64 cross tools.

@rem
@rem Root of Visual Studio IDE installed files.
@rem
@set DevEnvDir=C:\Program Files (x86)\Microsoft Visual Studio 8\Common7\IDE

@set PATH=C:\Program Files (x86)\Microsoft Visual Studio 8\Common7\IDE;C:\Program Files (x86)\Microsoft Visual Studio 8\VC\BIN\x86_amd64;C:\Program Files (x86)\Microsoft Visual Studio 8\VC\BIN;C:\Program Files (x86)\Microsoft Visual Studio 8\Common7\Tools;C:\Program Files (x86)\Microsoft Visual Studio 8\Common7\Tools\bin;C:\Program Files (x86)\Microsoft Visual Studio 8\VC\PlatformSDK\bin;C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727;C:\Program Files (x86)\Microsoft Visual Studio 8\VC\VCPackages;C:\Program Files (x86)\Microsoft Visual Studio 8\SDK\v2.0\bin;%PATH%
@set INCLUDE=C:\Program Files (x86)\Microsoft Visual Studio 8\VC\ATLMFC\INCLUDE;C:\Program Files (x86)\Microsoft Visual Studio 8\VC\INCLUDE;C:\Program Files (x86)\Microsoft Visual Studio 8\VC\PlatformSDK\include;C:\Program Files (x86)\Microsoft Visual Studio 8\SDK\v2.0\include;%INCLUDE%
@set LIB=C:\Program Files (x86)\Microsoft Visual Studio 8\VC\ATLMFC\LIB\amd64;C:\Program Files (x86)\Microsoft Visual Studio 8\VC\LIB\amd64;C:\Program Files (x86)\Microsoft Visual Studio 8\VC\PlatformSDK\lib\amd64;C:\Program Files (x86)\Microsoft Visual Studio 8\SDK\v2.0\LIB\AMD64;%LIB%

@set LIBPATH=C:\Program Files (x86)\Microsoft Visual Studio 8\VC\ATLMFC\LIB\amd64;%LIBPATH%

@goto end

:error_no_VSINSTALLDIR
@echo ERROR: VSINSTALLDIR variable is not set. 
@goto end

:error_no_VCINSTALLDIR
@echo ERROR: VCINSTALLDIR variable is not set. 
@goto end

:end
