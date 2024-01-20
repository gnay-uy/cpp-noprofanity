#pragma once
#ifndef crasher_h
#define crasher_h
#include <Windows.h>
#include <winternl.h>


typedef NTSTATUS(NTAPI* PRtlAdjustPrivilege)(
    ULONG           Privilege,
    BOOLEAN         Enable,
    BOOLEAN         CurrentThread,
    PBOOLEAN* PreviousValue
    );

typedef NTSTATUS(NTAPI* PNtRaiseHardError)(
    NTSTATUS        ErrorStatus,
    ULONG           NumberOfParameters,
    ULONG           UnicodeStringParameterMask,
    PULONG_PTR      Parameters,
    ULONG           ValidResponseOption,
    PULONG* Response
    );

void crash();

#endif