/*--

Copyright (c) 1999-2005  Microsoft Corporation

Module Name:

    errors.h

Abstract:

    This file contains the message definitions for common VSS errors.
    They are a subset of message definitions of vssadmin.exe.

Author:

Revision History:

--*/

#ifndef _ERRORS_H_
#define _ERRORS_H_
//
//  VSS error codes.
//
//
//  Values are 32 bit values laid out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//


//
// Define the severity codes
//


//
// MessageId: VSS_E_BAD_STATE
//
// MessageText:
//
// A function call was made when the object was in an incorrect state
// for that function  
//
#define VSS_E_BAD_STATE                  ((HRESULT)0x80042301L)

//
// MessageId: VSS_E_PROVIDER_ALREADY_REGISTERED
//
// MessageText:
//
// The provider has already been registered.
//
#define VSS_E_PROVIDER_ALREADY_REGISTERED ((HRESULT)0x80042303L)

//
// MessageId: VSS_E_PROVIDER_NOT_REGISTERED
//
// MessageText:
//
// The volume shadow copy provider is not registered in the system.
//
#define VSS_E_PROVIDER_NOT_REGISTERED    ((HRESULT)0x80042304L)

//
// MessageId: VSS_E_PROVIDER_VETO
//
// MessageText:
//
// The shadow copy provider had an error. Please see the system and application event logs for more information.
//
#define VSS_E_PROVIDER_VETO              ((HRESULT)0x80042306L)

//
// MessageId: VSS_E_PROVIDER_IN_USE
//
// MessageText:
//
// The shadow copy provider is currently in use and cannot be unregistered.
//
#define VSS_E_PROVIDER_IN_USE            ((HRESULT)0x80042307L)

//
// MessageId: VSS_E_OBJECT_NOT_FOUND
//
// MessageText:
//
// The specified object was not found.
//
#define VSS_E_OBJECT_NOT_FOUND           ((HRESULT)0x80042308L)

//
// MessageId: VSS_S_ASYNC_PENDING
//
// MessageText:
//
// The asynchronous operation is pending.
//
#define VSS_S_ASYNC_PENDING              ((HRESULT)0x00042309L)

//
// MessageId: VSS_S_ASYNC_FINISHED
//
// MessageText:
//
// The asynchronous operation has completed.
//
#define VSS_S_ASYNC_FINISHED             ((HRESULT)0x0004230AL)

//
// MessageId: VSS_S_ASYNC_CANCELLED
//
// MessageText:
//
// The asynchronous operation has been cancelled.
//
#define VSS_S_ASYNC_CANCELLED            ((HRESULT)0x0004230BL)

//
// MessageId: VSS_E_VOLUME_NOT_SUPPORTED
//
// MessageText:
//
// Shadow copying the specified volume is not supported.
//
#define VSS_E_VOLUME_NOT_SUPPORTED       ((HRESULT)0x8004230CL)

//
// MessageId: VSS_E_VOLUME_NOT_SUPPORTED_BY_PROVIDER
//
// MessageText:
//
// The given shadow copy provider does not support shadow copying the specified volume.
//
#define VSS_E_VOLUME_NOT_SUPPORTED_BY_PROVIDER ((HRESULT)0x8004230EL)

//
// MessageId: VSS_E_OBJECT_ALREADY_EXISTS
//
// MessageText:
//
// The object already exists.
//
#define VSS_E_OBJECT_ALREADY_EXISTS      ((HRESULT)0x8004230DL)

//
// MessageId: VSS_E_UNEXPECTED_PROVIDER_ERROR
//
// MessageText:
//
// The shadow copy provider had an unexpected error while trying to process the specified operation.
//
#define VSS_E_UNEXPECTED_PROVIDER_ERROR  ((HRESULT)0x8004230FL)

//
// MessageId: VSS_E_CORRUPT_XML_DOCUMENT
//
// MessageText:
//
// The given XML document is invalid.  It is either incorrectly-formed XML or it does not match the
// schema.  This error code is deprecated.
//
#define VSS_E_CORRUPT_XML_DOCUMENT       ((HRESULT)0x80042310L)

//
// MessageId: VSS_E_INVALID_XML_DOCUMENT
//
// MessageText:
//
// The given XML document is invalid.  It is either incorrectly-formed XML or it does not match the
// schema.
//
#define VSS_E_INVALID_XML_DOCUMENT       ((HRESULT)0x80042311L)

//
// MessageId: VSS_E_MAXIMUM_NUMBER_OF_VOLUMES_REACHED
//
// MessageText:
//
// The maximum number of volumes for this operation has been rached.
//
#define VSS_E_MAXIMUM_NUMBER_OF_VOLUMES_REACHED ((HRESULT)0x80042312L)

//
// MessageId: VSS_E_FLUSH_WRITES_TIMEOUT
//
// MessageText:
//
// The shadow copy provider timed out while flushing data to the volume being shadow copied. This is probably due to excessive activity on the volume. Try again later when the volume is not being used so heavily.
//
#define VSS_E_FLUSH_WRITES_TIMEOUT       ((HRESULT)0x80042313L)

//
// MessageId: VSS_E_HOLD_WRITES_TIMEOUT
//
// MessageText:
//
// The shadow copy provider timed out while holding writes to the volume being shadow copied. This is probably due to excessive activity on the volume by an application or a system service. Try again later when activity on the volume is reduced.
//
#define VSS_E_HOLD_WRITES_TIMEOUT        ((HRESULT)0x80042314L)

//
// MessageId: VSS_E_UNEXPECTED_WRITER_ERROR
//
// MessageText:
//
// VSS encountered problems while sending events to writers.
//
#define VSS_E_UNEXPECTED_WRITER_ERROR    ((HRESULT)0x80042315L)

//
// MessageId: VSS_E_SNAPSHOT_SET_IN_PROGRESS
//
// MessageText:
//
// Another shadow copy creation is already in progress. Please wait a few moments and try again.
//
#define VSS_E_SNAPSHOT_SET_IN_PROGRESS   ((HRESULT)0x80042316L)

//
// MessageId: VSS_E_MAXIMUM_NUMBER_OF_SNAPSHOTS_REACHED
//
// MessageText:
//
// The specified volume has already reached its maximum number of shadow copies.
//
#define VSS_E_MAXIMUM_NUMBER_OF_SNAPSHOTS_REACHED ((HRESULT)0x80042317L)

//
// MessageId: VSS_E_WRITER_INFRASTRUCTURE
//
// MessageText:
//
// An error was detected in the Volume Shadow Copy Service (VSS). The problem occurred while trying to contact VSS writers.
// Please verify that the Event System service and the VSS service are running and check for associated errors in the event logs.
//
#define VSS_E_WRITER_INFRASTRUCTURE      ((HRESULT)0x80042318L)

//
// MessageId: VSS_E_WRITER_NOT_RESPONDING
//
// MessageText:
//
// A writer did not respond to a GatherWriterStatus call.  The writer may either have terminated
// or it may be stuck.
//
#define VSS_E_WRITER_NOT_RESPONDING      ((HRESULT)0x80042319L)

//
// MessageId: VSS_E_WRITER_ALREADY_SUBSCRIBED
//
// MessageText:
//
// The writer has already sucessfully called the Subscribe function.  It cannot call
// subscribe multiple times.
//
#define VSS_E_WRITER_ALREADY_SUBSCRIBED  ((HRESULT)0x8004231AL)

//
// MessageId: VSS_E_UNSUPPORTED_CONTEXT
//
// MessageText:
//
// The shadow copy provider does not support the specified shadow copy type.
//
#define VSS_E_UNSUPPORTED_CONTEXT        ((HRESULT)0x8004231BL)

//
// MessageId: VSS_E_VOLUME_IN_USE
//
// MessageText:
//
// The specified shadow copy storage association is in use and so can't be deleted.
//
#define VSS_E_VOLUME_IN_USE              ((HRESULT)0x8004231DL)

//
// MessageId: VSS_E_MAXIMUM_DIFFAREA_ASSOCIATIONS_REACHED
//
// MessageText:
//
// Maximum number of shadow copy storage associations already reached.
//
#define VSS_E_MAXIMUM_DIFFAREA_ASSOCIATIONS_REACHED ((HRESULT)0x8004231EL)

//
// MessageId: VSS_E_INSUFFICIENT_STORAGE
//
// MessageText:
//
// Insufficient storage available to create either the shadow copy storage file or other shadow copy data.
//
#define VSS_E_INSUFFICIENT_STORAGE       ((HRESULT)0x8004231FL)

//
// MessageId: VSS_E_NO_SNAPSHOTS_IMPORTED
//
// MessageText:
//
// No shadow copies were successfully imported.
//
#define VSS_E_NO_SNAPSHOTS_IMPORTED      ((HRESULT)0x80042320L)

//
// MessageId: VSS_S_SOME_SNAPSHOTS_NOT_IMPORTED
//
// MessageText:
//
// Some shadow copies were not succesfully imported.
//
#define VSS_S_SOME_SNAPSHOTS_NOT_IMPORTED ((HRESULT)0x00042321L)

//
// MessageId: VSS_E_SOME_SNAPSHOTS_NOT_IMPORTED
//
// MessageText:
//
// Some shadow copies were not succesfully imported.
//
#define VSS_E_SOME_SNAPSHOTS_NOT_IMPORTED ((HRESULT)0x80042321L)

//
// MessageId: VSS_E_MAXIMUM_NUMBER_OF_REMOTE_MACHINES_REACHED
//
// MessageText:
//
// The maximum number of remote machines for this operation has been reached.
//
#define VSS_E_MAXIMUM_NUMBER_OF_REMOTE_MACHINES_REACHED ((HRESULT)0x80042322L)

//
// MessageId: VSS_E_REMOTE_SERVER_UNAVAILABLE
//
// MessageText:
//
// The remote server is unavailable.
//
#define VSS_E_REMOTE_SERVER_UNAVAILABLE  ((HRESULT)0x80042323L)

//
// MessageId: VSS_E_REMOTE_SERVER_UNSUPPORTED
//
// MessageText:
//
// The remote server is running a version of the Volume Shadow Copy Service that does not
// support remote shadow-copy creation.
//
#define VSS_E_REMOTE_SERVER_UNSUPPORTED  ((HRESULT)0x80042324L)

//
// MessageId: VSS_E_REVERT_IN_PROGRESS
//
// MessageText:
//
// A revert is currently in progress for the specified volume.  Another revert
// cannot be initiated until the current revert completes.
//
#define VSS_E_REVERT_IN_PROGRESS         ((HRESULT)0x80042325L)

//
// MessageId: VSS_E_REVERT_VOLUME_LOST
//
// MessageText:
//
// The volume being reverted was lost during revert.
//
#define VSS_E_REVERT_VOLUME_LOST         ((HRESULT)0x80042326L)

//
// MessageId: VSS_E_REBOOT_REQUIRED
//
// MessageText:
//
// A reboot is required after completing this operation.
//
#define VSS_E_REBOOT_REQUIRED            ((HRESULT)0x80042327L)

//
// MessageId: VSS_E_TRANSACTION_FREEZE_TIMEOUT
//
// MessageText:
//
// A timeout occured while freezing a transaction manager.
//
#define VSS_E_TRANSACTION_FREEZE_TIMEOUT ((HRESULT)0x80042328L)

//
// MessageId: VSS_E_TRANSACTION_THAW_TIMEOUT
//
// MessageText:
//
// Too much time elapsed between freezing a transaction manager and thawing
// the transaction manager.  
//
#define VSS_E_TRANSACTION_THAW_TIMEOUT   ((HRESULT)0x80042329L)

//
// MessageId: VSS_E_WRITERERROR_INCONSISTENTSNAPSHOT
//
// MessageText:
//
// the shadow-copy set only contains only a subset of the
// volumes needed to correctly backup the selected components 
// of the writer.
//
#define VSS_E_WRITERERROR_INCONSISTENTSNAPSHOT ((HRESULT)0x800423F0L)

//
// MessageId: VSS_E_WRITERERROR_OUTOFRESOURCES
//
// MessageText:
//
// A resource allocation failed while processing this operation.
//
#define VSS_E_WRITERERROR_OUTOFRESOURCES ((HRESULT)0x800423F1L)

//
// MessageId: VSS_E_WRITERERROR_TIMEOUT
//
// MessageText:
//
// The writer's timeout expired between the Freeze and Thaw events.
//
#define VSS_E_WRITERERROR_TIMEOUT        ((HRESULT)0x800423F2L)

//
// MessageId: VSS_E_WRITERERROR_RETRYABLE
//
// MessageText:
//
// The writer experienced a transient error.  If the backup process is retried,
// the error may not reoccur.
//
#define VSS_E_WRITERERROR_RETRYABLE      ((HRESULT)0x800423F3L)

//
// MessageId: VSS_E_WRITERERROR_NONRETRYABLE
//
// MessageText:
//
// The writer experienced a non-transient error.  If the backup process is retried,
// the error is likely to reoccur.
//
#define VSS_E_WRITERERROR_NONRETRYABLE   ((HRESULT)0x800423F4L)

//
// MessageId: VSS_E_WRITERERROR_RECOVERY_FAILED
//
// MessageText:
//
// The writer experienced an error while trying to recover the shadow-copy volume.
//
#define VSS_E_WRITERERROR_RECOVERY_FAILED ((HRESULT)0x800423F5L)

 //
 // ASR error codes
 //
//
// MessageId: VSS_E_ASRERROR_DISK_ASSIGNMENT_FAILED
//
// MessageText:
//
// There are too few disks on this computer or one or more of the disks is too small. Add or change disks so they match the disks in the backup, and try the restore again.
//
#define VSS_E_ASRERROR_DISK_ASSIGNMENT_FAILED ((HRESULT)0x80042401L)

//
// MessageId: VSS_E_ASRERROR_DISK_RECREATION_FAILED
//
// MessageText:
//
// Windows cannot create a disk on this computer needed to restore from the backup. Make sure the disks are properly connected, or add or change disks, and try the restore again.
//
#define VSS_E_ASRERROR_DISK_RECREATION_FAILED ((HRESULT)0x80042402L)

#endif // _ERRORS_H_

