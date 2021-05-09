#pragma  once
#include <iostream>
#include <string>
#include <windows.h>
#include <tlhelp32.h>

extern HANDLE processHandle;

extern DWORD gameModule;
extern DWORD engineModule;
extern DWORD clientState;
extern bool processInit;
extern bool secondaryModuleInit;
extern bool initModule;

extern HANDLE hProcSnap;
extern PROCESSENTRY32 procEntry32;

extern HANDLE hModuleSnap;
extern MODULEENTRY32 modEntry32;

extern DWORD pID;

template <class dataType>
void writeMem(DWORD addressToWrite, dataType valToWrite)
{
	WriteProcessMemory(processHandle, (PVOID)addressToWrite, &valToWrite, sizeof(dataType), 0);
}


template <class dataType>
dataType readMem(DWORD addressToRead)
{	
	dataType addValue;

	ReadProcessMemory(processHandle, (PVOID)addressToRead, &addValue, sizeof(dataType), 0);

	return addValue;
}

extern bool getProcess(DWORD procID);

extern DWORD getModule(char* moduleName);

extern uintptr_t patternScan(char* base, size_t size, char* pattern);

extern DWORD findPattern(HANDLE processHandle, const unsigned char pattern[], const char* mask, const int offset, size_t begin);

extern std::uint32_t find(const char* proc);