REM
REM This is where you add your private build environment settings.
REM Usually, this only consists of your favorite editor settings.
REM
REM If you want source depot to use your editor for change pages (notepad is
REM the default), set the SDEDITOR macro to your editor name.
REM
REM You may have to add some entries to the path to find your editor.
REM
REM Note: Whatever you add to the path will have NO effect on the build
REM       tools used when you call nmake or build in a razzle window.
REM
REM If you're tempted to put other stuff here to significantly modify the
REM build environment, first look at the what razzle does already.
REM
REM     razzle help
REM 
REM from a build window will show the current available options.
REM Hopefully your requirement is already there.
REM
REM When you're done editing this file, save it and exit.  Then at
REM your earliest convience, add
REM      D:\NT\WRK-V1.2\developer\JonathanMoore\setenv.cmd
REM to source control.
REM
REM If you have multiple machines, add another COMPUTERNAME test as below
REM
if "%COMPUTERNAME%" == "MICROSOFT" goto DoMICROSOFT
REM
echo %COMPUTERNAME% is unknown - Please update %INIT%\setenv.cmd
goto :eof
REM
:DoMICROSOFT
REM
REM *** Add your private environment settings for computer: MICROSOFT here ***
REM path=%path%;<**Your path here**> 
REM set SDEDITOR=<**Your editor name here**> 
REM
goto :eof
