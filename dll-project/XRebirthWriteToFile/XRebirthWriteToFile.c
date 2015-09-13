// XRebirthWriteToFile.cpp : Definiert die exportierten Funktionen für die DLL-Anwendung.
//

#include "stdafx.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <wchar.h>

__declspec(dllexport) void __fastcall fnTestDll(unsigned int money)
{
	FILE* file;
	fopen_s(&file, "C:\\Users\\trampi\\Desktop\\temp\\temp_rebirth.txt", "w+");
	fprintf(file, "%u", money);
	fclose(file);
	return;
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
	)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
