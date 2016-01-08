#include "Functions.h"

process_t Process;
module_t Module;

void _GetProcess()
{
	Process.Window = FindWindow(0, "Counter-Strike: Global Offensive");
	GetWindowThreadProcessId(Process.Window, &Process.ID);
	Process.Handle = OpenProcess(PROCESS_ALL_ACCESS, 0, Process.ID);

	if (Process.Window)
	{
		if (Process.Handle)
		{
			Module.Client = _GetModule("client.dll");
			printf("   - Client Module: 0x%X\n\n", Module.Client);
		}
	}
	else
	{
		MessageBox(0, "Make sure your Counter-Strike: Global Offsenive is running!", "Error!", MB_OK | MB_ICONERROR);
		exit(1);
	}
}

DWORD _GetModule(char * szModuleName)
{
	HANDLE hSnap;
	MODULEENTRY32 Module;

	DWORD Output;

	hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, Process.ID);

	if (Module32First(hSnap, &Module))
	{
		while (Module32Next(hSnap, &Module))
		{
			if (lstrcmpi(Module.szModule, szModuleName) == false)
			{
				Output = (DWORD)Module.modBaseAddr;
				break;
			}
		}
	}
	return Output;
}

void _WriteMem(LPVOID addr, LPVOID buffer, DWORD size)
{
	WriteProcessMemory(Process.Handle, addr, buffer, size, 0);
}