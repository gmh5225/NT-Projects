/*
Copyright (C) 1996

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

The author can be contacted via Email at bmorin@wpi.edu
*/
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include "build.h"
#include "error.h"
#include "debug.h"
#pragma hdrstop
#include "fnord.h"

#ifdef BUILD_SRV

//Private Constants
//Command String Constants
#define SRV_CMD_HELP      "HELP"
#define SRV_CMD_INSTALL   "INSTALL"
#define SRV_CMD_UNINSTALL "UNINSTALL"
#define SRV_CMD_STATUS    "STATUS"
#define SRV_CMD_START     "START"
#define SRV_CMD_STOP      "STOP"
#define SRV_CMD_DEBUG     "DEBUG"

//Private Vars
static SERVICE_STATUS_HANDLE    SrvStatusHnd;
static SERVICE_STATUS           SrvStatus;

//Private Functions
void SrvCmdDisplayHelp();
void SrvCmdDebug();
void SrvCmdInstall(char *ServiceExePath);
void SrvCmdUninstall();
void SrvCmdStatus();
void SrvCmdStart();
void SrvCmdStop();

void WINAPI ServiceCtrlHandler(DWORD CtrlCode);
void WINAPI ServiceMain(DWORD argc, LPTSTR *argv);

void SetSrvState(DWORD State, DWORD Error);

void SrvGetServiceType(DWORD Type, char *Str );
void SrvGetState(DWORD State, char *Str );
void SrvGetControls( DWORD Control, char *Str );

//Public Functions
/******************************************************************************/
void SrvProcessCommand(int argc, char *argv[]) {

   if ((argc > 1) && (strcmpi(argv[1], SRV_CMD_HELP) == 0)) {
      SrvCmdDisplayHelp();
      }
   else if ((argc > 1) && (strcmpi(argv[1], SRV_CMD_DEBUG) == 0)) {
      SrvCmdDebug();
      }
   else if ((argc > 1) && (strcmpi(argv[1], SRV_CMD_INSTALL) == 0)) {
      SrvCmdInstall(argv[0]);
      }
   else if ((argc > 1) && (strcmpi(argv[1], SRV_CMD_UNINSTALL) == 0)) {
      SrvCmdUninstall();
      }
   else if ((argc > 1) && (strcmpi(argv[1], SRV_CMD_STATUS) == 0)) {
      SrvCmdStatus();
      }
   else if ((argc > 1) && (strcmpi(argv[1], SRV_CMD_START) == 0)) {
      SrvCmdStart();
      }
   else if ((argc > 1) && (strcmpi(argv[1], SRV_CMD_STOP) == 0)) {
      SrvCmdStop();
      }
   else {
      SERVICE_TABLE_ENTRY   ServiceTable[] = {
         { "fnord", ServiceMain },
         { NULL, NULL}
         };
      if (!StartServiceCtrlDispatcher(ServiceTable)) {
         printf("Error in call to StartServiceCtrlDispatcher()");
         }
      }
   }
/******************************************************************************/
//Private Functions
/******************************************************************************/
void SrvCmdDisplayHelp() {
   printf("Commands: \n");
   printf("\n");
   printf("INSTALL   install service\n");
   printf("UNINSTALL uninstall service\n");
   printf("STATUS    show status of service\n");
   printf("START     start service\n");
   printf("STOP      stop service\n");
   printf("DEBUG     start as debug-process\n");
   }
/******************************************************************************/
void SrvCmdDebug() {
   //Call WinMain
   WinMain( GetModuleHandle(NULL), 0, NULL, 0 );
	}
/******************************************************************************/
void SrvCmdInstall(char *ServiceExePath) {
   SC_HANDLE SCHnd;
   SC_HANDLE SrvHnd;

   //Open the Service Control Manager
   SCHnd = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
   if (!SCHnd) {
      printf("Failure to open service control manager\n");
      return;
      }

   printf("Installing service file %s\n", ServiceExePath);

   //Create a service
   SrvHnd = CreateService(
      SCHnd,
      "fnord",   //Internal name
      "Fnord",   //Name to display
      SERVICE_ALL_ACCESS,
      SERVICE_WIN32_OWN_PROCESS | SERVICE_INTERACTIVE_PROCESS,
      SERVICE_AUTO_START,
      SERVICE_ERROR_NORMAL,
      ServiceExePath,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL);

   if (!SrvHnd) {
      printf("Failure to create new service\n");
      return;
      }
   else {
      printf("fnord service installed\n");
      }

   //Cleanup
   CloseServiceHandle(SrvHnd);
   CloseServiceHandle(SCHnd);
	}
/******************************************************************************/
void SrvCmdUninstall() {
   SC_HANDLE SCHnd;
   SC_HANDLE SrvHnd;

   //Open the Service Control Manager
   SCHnd = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
   if (!SCHnd) {
      printf("Failure to open service control manager\n");
      return;
      }

   SrvHnd = OpenService(SCHnd, "fnord", SERVICE_ALL_ACCESS | DELETE);
   if (!SrvHnd) {
      printf("Failure to open fnord service\n");
      return;
      }

   //Stop the service if it's running
   SERVICE_STATUS SrvStatus;

   if (!QueryServiceStatus(SrvHnd, &SrvStatus)) {
      printf("Failure to in call to QueryServiceStatus\n");
      return;
      }
   if (SrvStatus.dwCurrentState != SERVICE_STOPPED) {
      printf("Stopping fnord service\n");

      if (!ControlService(SrvHnd, SERVICE_CONTROL_STOP, &SrvStatus)) {
         printf("Failure to stop service\n");
         return;
         }

      //Give it a chance to shutdown
      int i;
      for (i=0; i<4; i++) {
         Sleep(500);
         printf(".");
         }
      printf("\n");
      }

   //Remove the service
   if (!DeleteService(SrvHnd)) {
      printf("Failure to remove fnord service\n");
      }
   else {
      printf("fnord service removed\n");
      }

   //Cleanup
   CloseServiceHandle(SrvHnd);
   CloseServiceHandle(SCHnd);
   }
/******************************************************************************/
void SrvCmdStatus() {
   char Str[100];
   SC_HANDLE SCHnd;
   SC_HANDLE SrvHnd;
   SERVICE_STATUS SrvStatus;

   //Open the Service Control Manager
   SCHnd = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
   if (!SCHnd) {
      printf("Failure to open service control manager\n");
      return;
      }

   SrvHnd = OpenService(SCHnd, "fnord", SERVICE_ALL_ACCESS | DELETE);
   if (!SrvHnd) {
      printf("Failure to open fnord service\n");
      return;
      }

   if (!QueryServiceStatus(SrvHnd, &SrvStatus)) {
      printf("Failure to in call to QueryServiceStatus\n");
      return;
      }

   SrvGetServiceType( SrvStatus.dwServiceType, Str );
   printf("ServiceType            : %d\t(%s)\n", SrvStatus.dwServiceType, Str );
   SrvGetState( SrvStatus.dwCurrentState, Str );
   printf("CurrentState           : %d\t(%s)\n", SrvStatus.dwCurrentState, Str );
   SrvGetControls( SrvStatus.dwControlsAccepted, Str );
   printf("ControlsAccepted       : %d\t(%s)\n", SrvStatus.dwControlsAccepted, Str );
   printf("Win32ExitCode          : %d\n", SrvStatus.dwWin32ExitCode);
   printf("ServiceSpecificExitCode: %d\n", SrvStatus.dwServiceSpecificExitCode);
   printf("CheckPoint             : %d\n", SrvStatus.dwCheckPoint);
   printf("WaitHint               : %d\n", SrvStatus.dwWaitHint);

   //Cleanup
   CloseServiceHandle(SrvHnd);
   CloseServiceHandle(SCHnd);
   }
/******************************************************************************/
void SrvCmdStart() {
   SC_HANDLE SCHnd;
   SC_HANDLE SrvHnd;

   //Open the Service Control Manager
   SCHnd = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
   if (!SCHnd) {
      printf("Failure to open service control manager\n");
      return;
      }

   SrvHnd = OpenService(SCHnd, "fnord", SERVICE_ALL_ACCESS | DELETE);
   if (!SrvHnd) {
      printf("Failure to open fnord service\n");
      return;
      }


   if (!StartService(SrvHnd, 0, NULL)) {
      printf("Failure to start service\n");
      return;
      }

   //Cleanup
   CloseServiceHandle(SrvHnd);
   CloseServiceHandle(SCHnd);
   }
/******************************************************************************/
void SrvCmdStop() {
   SC_HANDLE SCHnd;
   SC_HANDLE SrvHnd;

   //Open the Service Control Manager
   SCHnd = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
   if (!SCHnd) {
      printf("Failure to open service control manager\n");
      return;
      }

   SrvHnd = OpenService(SCHnd, "fnord", SERVICE_ALL_ACCESS | DELETE);
   if (!SrvHnd) {
      printf("Failure to open fnord service\n");
      return;
      }

   //Stop the service if it's running
   SERVICE_STATUS SrvStatus;

   if (!QueryServiceStatus(SrvHnd, &SrvStatus)) {
      printf("Failure to in call to QueryServiceStatus\n");
      return;
      }
   if (SrvStatus.dwCurrentState != SERVICE_STOPPED) {
      printf("Stopping fnord service\n");

      if (!ControlService(SrvHnd, SERVICE_CONTROL_STOP, &SrvStatus)) {
         printf("Failure to stop service\n");
         return;
         }
      }

   //Cleanup
   CloseServiceHandle(SrvHnd);
   CloseServiceHandle(SCHnd);
   }
/******************************************************************************/
void WINAPI ServiceCtrlHandler(DWORD CtrlCode) {

   switch(CtrlCode) {
      case SERVICE_CONTROL_SHUTDOWN:
      case SERVICE_CONTROL_STOP:
         SetSrvState(SERVICE_STOP_PENDING, 0);

         // Shutdown
         SendMessage( GetFnordMainWindow(), WM_DESTROY, 0, 0 );
         break;

      case SERVICE_CONTROL_INTERROGATE:
      default:
         SetServiceStatus( SrvStatusHnd, &SrvStatus);
         break;
      }
   }
/******************************************************************************/
void WINAPI ServiceMain(DWORD /*argc*/, LPTSTR * /*argv*/) {
   SrvStatusHnd = RegisterServiceCtrlHandler("fnord",  ServiceCtrlHandler);
   if( !SrvStatusHnd ) {
      printf("Failure to register fnord service control handler. error=%d", GetLastError());
      return;
      }

   //Service Status
   SrvStatus.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
   SrvStatus.dwCurrentState = SERVICE_START_PENDING;
   SrvStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN;
   SrvStatus.dwWin32ExitCode = NO_ERROR;
   SrvStatus.dwServiceSpecificExitCode = 0;
   SrvStatus.dwCheckPoint = 0;
   SrvStatus.dwWaitHint = 10000;
   SetServiceStatus( SrvStatusHnd, &SrvStatus );

   SetSrvState(SERVICE_RUNNING, 0);

   //Call WinMain
   WinMain( GetModuleHandle(NULL), 0, NULL, 0 );

   SetSrvState(SERVICE_STOPPED, 0);

   return;
   }
/******************************************************************************/
void SetSrvState(DWORD State, DWORD Error) {
   SrvStatus.dwCurrentState = State;

   if (Error == 0) {
      SrvStatus.dwWin32ExitCode = NO_ERROR;
      SrvStatus.dwServiceSpecificExitCode = 0;
      }
   else {
      SrvStatus.dwWin32ExitCode = ERROR_SERVICE_SPECIFIC_ERROR;
      SrvStatus.dwServiceSpecificExitCode = Error;
      }

   SetServiceStatus(SrvStatusHnd, &SrvStatus);
   }
/******************************************************************************/
void SrvGetServiceType(DWORD Type, char *Str ) {
   switch(Type) {
      case SERVICE_WIN32_OWN_PROCESS:
         strcpy( Str, "SERVICE_WIN32_OWN_PROCESS" );
         break;
      case SERVICE_WIN32_SHARE_PROCESS:
         strcpy( Str, "SERVICE_WIN32_SHARE_PROCESS" );
         break;
      case SERVICE_KERNEL_DRIVER:
         strcpy( Str, "SERVICE_KERNEL_DRIVER" );
         break;
      case SERVICE_FILE_SYSTEM_DRIVER:
         strcpy( Str, "SERVICE_FILE_SYSTEM_DRIVER" );
         break;
      default:
         strcpy( Str, "unknown" );
         break;
      }
   }
/******************************************************************************/
void SrvGetState(DWORD State, char *Str ) {

   switch(State) {
      case SERVICE_STOPPED:
         strcpy( Str, "Service STOPPED" );
         break;
      case SERVICE_START_PENDING:
         strcpy( Str, "Service STARTING" );
         break;
      case SERVICE_STOP_PENDING:
         strcpy( Str, "Service working on STOP" );
         break;
      case SERVICE_RUNNING:
         strcpy( Str, "Service RUNNING" );
         break;
      case SERVICE_CONTINUE_PENDING:
         strcpy( Str, "Service working on CONTINUE" );
         break;
      case SERVICE_PAUSE_PENDING:
         strcpy( Str, "Service working on PAUSE");
         break;
      case SERVICE_PAUSED:
         strcpy( Str, "Service PAUSING");
         break;
      default:
         strcpy( Str, "Unknown" );
         break;
      }
   }
/******************************************************************************/
void SrvGetControls( DWORD Control, char *Str ) {

   strcpy( Str, "SERVICE_ACCEPT:" );
   if( Control & (SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_PAUSE_CONTINUE |
      SERVICE_ACCEPT_SHUTDOWN ) ) {

      if( Control & SERVICE_ACCEPT_STOP )
         strcat( Str, " STOP" );
      if( Control & SERVICE_ACCEPT_PAUSE_CONTINUE )
         strcat( Str, " PAUSE/CONT" );
      if( Control & SERVICE_ACCEPT_SHUTDOWN )
         strcat( Str, " SHUTDOWN" );
      }
   else {
      strcat( Str, "None " );
      }
   }
/******************************************************************************/
#endif
