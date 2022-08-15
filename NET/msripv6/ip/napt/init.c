// -*- mode: C++; tab-width: 4; indent-tabs-mode: nil -*- (for GNU Emacs)
//
// Copyright (c) 1985-2000 Microsoft Corporation
//
// This file is part of the Microsoft Research IPv6 Network Protocol Stack.
// You should have received a copy of the Microsoft End-User License Agreement
// for this software along with this release; see the file "license.txt".
// If not, please see http://www.research.microsoft.com/msripv6/license.htm,
// or write to Microsoft Research, One Microsoft Way, Redmond, WA 98052-6399.
//


#include "oscfg.h"
#include "ndis.h"
#include "naptdef.h"
#include "ntddnapt.h"

NTSTATUS
CreateClose(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp);

NTSTATUS
DeviceControl(PDEVICE_OBJECT DeviceObject, PIRP Irp);

extern void LanLoadProtocol(void);
extern void LanUnloadProtocol(void);
extern void NaptStart(void);
extern void NaptStop(void);

extern NTSTATUS
NaptDispatchDeviceControl(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);

//
// If the compiler can handle it, save space by making various
// routines disposable or pageable.
//
#ifdef ALLOC_PRAGMA
#pragma alloc_text( init, DriverEntry )
#pragma alloc_text( page, DriverUnload )
#endif //ALLOC_PRAGMA


//* DriverEntry
//
//  Main initialization routine for the Napt driver.
//  This is the driver entry point, called by the system upon loading us.
//
//  Note that this code assumes that there is only one instance of the
//  translator running on the system at any one time.
//
NTSTATUS  // Returns: final status from the initialization operation.
DriverEntry(
    IN PDRIVER_OBJECT  DriverObject,  // Napt driver object.
    IN PUNICODE_STRING RegistryPath)  // Path to our info in the registry.
{
    NTSTATUS Status;
    PDEVICE_OBJECT DevObj;
    UNICODE_STRING DeviceName;
    UNICODE_STRING LinkName;

    KdPrint(("Napt DriverEntry: Loading Napt\n"));

    //
    // Hang onto this so we can call DriverUnload ourselves.
    //
    NaptDriverObject = DriverObject;

    //
    // Initialize the driver object.
    //
    DriverObject->DriverUnload = DriverUnload;
    DriverObject->MajorFunction[IRP_MJ_CREATE] = CreateClose;
    DriverObject->MajorFunction[IRP_MJ_CLOSE] = CreateClose;
    DriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = DeviceControl;

    //
    // Create a device object for this device...
    //
    RtlInitUnicodeString(&DeviceName, DD_NAPT_DEVICE_NAME);
    Status = IoCreateDevice(DriverObject, 0, &DeviceName, FILE_DEVICE_NETWORK,
                            0, FALSE, &DevObj);
    if (!NT_SUCCESS(Status)) {
        KdPrint(("Napt DriverEntry: "
                 "Failed to create device object %ws, Status %lx\n",
                 DD_NAPT_DEVICE_NAME, Status));
        return Status;
    }

    // "There can be only one."
    ASSERT(DriverObject->DeviceObject == DevObj);
    ASSERT(DevObj->NextDevice == NULL);

    // Initialize the device object.
    DevObj->Flags |= DO_DIRECT_IO;
  
    //
    // Create a Win32-accessible link for the device.
    // This will allow Windows programs to make IOCTLs.
    //
    RtlInitUnicodeString(&LinkName, WIN_NAPT_LINK_NAME);
    Status = IoCreateSymbolicLink(&LinkName, &DeviceName);
    if (!NT_SUCCESS(Status)) {
        KdPrint(("Napt DriverEntry: IoCreateSymbolicLink failed\n"));
        IoDeleteDevice(DevObj);
        return Status;
    }

    // Create protocol bindings.
    LanLoadProtocol();

    // Start the translator.
    NaptStart();

    return STATUS_SUCCESS;
}


//* DriverUnload
//
//  Routine we registered (in DriverEntry) with the I/O Manager.
//  This is called by the system when it is unloading us.
//
VOID
DriverUnload(
    IN PDRIVER_OBJECT DriverObject)  // Napt driver object.
{
    UNICODE_STRING LinkName;

    //
    // If we've already shut ourselves down for some reason
    // (like the IPv6 stack going away), then just return now.
    //
    if (NaptUnloading == TRUE)
        return;

    //
    // Mark ourselves as going away.
    //
    NaptUnloading = TRUE;

    KdPrint(("Napt DriverUnload: Unloading Napt\n"));

    //
    // Remove the Win32-accessible symbolic link.
    //
    RtlInitUnicodeString(&LinkName, WIN_NAPT_LINK_NAME);
    (void) IoDeleteSymbolicLink(&LinkName);

    //
    // Delete the Napt device object.
    //
    IoDeleteDevice(DriverObject->DeviceObject);

    // Now unload the protocol bindings.
    LanUnloadProtocol();

    // Stop the translator.
    NaptStop();
}


//* CreateClose
//
//  This routine services open commands.  It establishes
//  the driver's existance by returning status success.
//
NTSTATUS
CreateClose(
    PDEVICE_OBJECT DeviceObject,  // Context for the activity.
    PIRP Irp)                     // The device control argument block.
{
    UNREFERENCED_PARAMETER(DeviceObject);

    Irp->IoStatus.Status = STATUS_SUCCESS;
    IoCompleteRequest(Irp, IO_NO_INCREMENT);

    return STATUS_SUCCESS;
}


//* DeviceControl
//
NTSTATUS
DeviceControl(
    PDEVICE_OBJECT DeviceObject,  // Context for the activity.
    PIRP Irp)                     // The device control argument block.
{
    PIO_STACK_LOCATION irpSp;

    UNREFERENCED_PARAMETER(DeviceObject);
    PAGED_CODE();

    irpSp = IoGetCurrentIrpStackLocation(Irp);

    return NaptDispatchDeviceControl(Irp, irpSp);
}
