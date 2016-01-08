#include "Main.h"

int main()
{
	SetConsoleTitle("Gerkings - CSGO - 0.0.1");
	printf("\n   [+] Gerkings - CSGO 0.0.1\n\n");

	printf("   - Init process...\n\n");
	_GetProcess();

	while (true)
	{
		Sleep(1);
		_CallExtern();
	}
}