// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <Winternl.h>

#pragma comment(lib, "ntdll")


int main()
{
    UNICODE_STRING str;
    NTSTATUS status;
    WCHAR filepath[100] = L"\\CLFS\\??\\\\C:\\Windows\\Temp\\CLFS_test";
    RtlInitUnicodeString(&str, filepath);
    OBJECT_ATTRIBUTES obj;
    IO_STATUS_BLOCK isb;
    TCHAR buff2[0x0001000] = {};
    InitializeObjectAttributes(&obj, &str,OBJ_CASE_INSENSITIVE, NULL, NULL);

    HANDLE h;
    status = NtCreateFile(&h, SYNCHRONIZE | GENERIC_READ, &obj, &isb, 0, 0x0000080, 0x0000007, FILE_OPEN_IF, 0x0000020, 0x0000000, 0);
    if (!NT_SUCCESS(status)) {
        printf("%s", "erro");
    }
    status = ReadFile(h, buff2, 0x0001000, 0, NULL);
    if (!NT_SUCCESS(status)) {
        printf("%s", "erroz");
    }
}

