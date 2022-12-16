//#include<iostream>

//#include<stdio.h>
#include <locale.h>
#include <stdio.h>
#include <Windows.h>
#include <io.h>
//using namespace std;

typedef long NTSTATUS;

#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)


typedef struct _IO_STATUS_BLOCK {
	union {
		NTSTATUS Status;
		PVOID    Pointer;
	};

	ULONG_PTR Information;
} IO_STATUS_BLOCK, * PIO_STATUS_BLOCK;


typedef struct _OBJECT_NAME_INFORMATION {
	ULONG FileNameLength;
	WCHAR FileName[1];
} OBJECT_NAME_INFORMATION, * POBJECT_NAME_INFORMATION;

typedef NTSTATUS(NTAPI* NTQUERYINFORMATIONFILE)(
	IN  HANDLE                 FileHandle,
	OUT PIO_STATUS_BLOCK       IoStatusBlock,
	OUT PVOID                  FileInformation,
	IN  DWORD                  Length,
	IN  int FileInformationClass
	);

NTQUERYINFORMATIONFILE NtQueryInformationFile = NULL;

int main(int argc, char* argv[]) {
	setlocale(0, "chs");

	NTSTATUS status = -1;
	HMODULE hNtdll = NULL;
	HANDLE hFile = INVALID_HANDLE_VALUE;
	IO_STATUS_BLOCK IoStatus = { 0 };
	POBJECT_NAME_INFORMATION pfni = NULL;
	size_t allocSize = 0;

	hNtdll = LoadLibrary(L"ntdll.dll");
	NtQueryInformationFile = (NTQUERYINFORMATIONFILE)GetProcAddress(hNtdll, "NtQueryInformationFile");

	hFile = (HANDLE)_get_osfhandle(_fileno(stdin));
	if (hFile != INVALID_HANDLE_VALUE) {
		allocSize = sizeof(OBJECT_NAME_INFORMATION) + MAX_PATH * sizeof(WCHAR);
		pfni = (POBJECT_NAME_INFORMATION)malloc(allocSize);
		if (pfni != NULL) {
			RtlZeroMemory(pfni, allocSize);
			status = NtQueryInformationFile(hFile, &IoStatus, pfni, allocSize, 9);
			if (NT_SUCCESS(status))
				wprintf(L"ÎÄ¼þÃû: %s\n", pfni->FileName);
			free(pfni);
		}

		CloseHandle(hFile);
	}

	FreeLibrary(hNtdll);

	return 0;
}