#ifndef FUNCTIONS
#define FUNCTIONS

#include "Main.h"

struct process_t
{
	HWND Window;
	DWORD ID;
	HANDLE Handle;
};
extern process_t Process;

struct module_t
{
	DWORD Client;
};
extern module_t Module;

void _GetProcess();
DWORD _GetModule(char * szModuleName);
void _WriteMem(LPVOID addr, LPVOID buffer, DWORD size);

#endif