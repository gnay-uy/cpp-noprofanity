#include <Windows.h>
#include <winternl.h>
#include <iostream>

#include "crasher.h"

void crash()
{
    HMODULE hNTDLL = GetModuleHandleA("NTDLL");

    if (hNTDLL == nullptr) {
        return;
    }

    FARPROC pRtlAdjustPrivilege = GetProcAddress(hNTDLL, "RtlAdjustPrivilege");
    FARPROC pNtRaiseHardError = GetProcAddress(hNTDLL, "NtRaiseHardError");

    auto RtlAdjustPrivilege = (PRtlAdjustPrivilege)pRtlAdjustPrivilege;
    auto NtRaiseHardError = (PNtRaiseHardError)pNtRaiseHardError;

    PBOOLEAN prevValue;
    PULONG res;

    RtlAdjustPrivilege(19, TRUE, FALSE, &prevValue);
    NtRaiseHardError((NTSTATUS)0xDEADBEEF, 0, 0, nullptr, 6, &res);

    FreeModule(hNTDLL);
}