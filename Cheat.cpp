#include "Cheat.h"

CPlayer_t Player;
CRadar_t Radar[32];

struct offset_t
{
	DWORD BaseAddr = 0x00A6D444;
	DWORD BaseTemp = 0;
	DWORD JumpAddr = 0x04AF046C;
	DWORD AttackAddr = 0x02EC7930;
};
offset_t Offset;

struct status_t
{
	bool Jump;
	bool Attack;
};
status_t Status;

void _CallExtern()
{
	_ReadInformations();
	_Bunnyhop();
	_Triggerbot();
	_Rapidfire();
}

void _Bunnyhop()
{
	if (GetAsyncKeyState(VK_SPACE) && Player.Flags & (FL_ONGROUND))
	{
		Status.Jump = !Status.Jump;
		_WriteMem((LPVOID)(Module.Client + Offset.JumpAddr), &Status.Jump, sizeof(bool));
		Sleep(30);
		Status.Jump = !Status.Jump;
		_WriteMem((LPVOID)(Module.Client + Offset.JumpAddr), &Status.Jump, sizeof(bool));
		Sleep(10);
	}
}

void _Triggerbot()
{
	if (GetAsyncKeyState(0x45))
	{
		//MessageBox(0, "1", "Error!", MB_OK | MB_ICONERROR);
		if (Player.CrossID > 0 && Player.CrossID < 32)
		{
			MessageBox(0, "2", "Error!", MB_OK | MB_ICONERROR);
			/*Status.Attack = !Status.Attack;
			_WriteMem((LPVOID)(Module.Client + Offset.AttackAddr), &Status.Attack, sizeof(bool));
			Sleep(30);
			Status.Attack = !Status.Attack;
			_WriteMem((LPVOID)(Module.Client + Offset.AttackAddr), &Status.Attack, sizeof(bool));
			Sleep(10);*/
		}
		else{
			printf("   - Player.CrossID: %d\n\n", Player.Team);
		}
	}
}

void _Rapidfire()
{
	if (GetAsyncKeyState(0x14))
	{
		Status.Attack = !Status.Attack;
		_WriteMem((LPVOID)(Module.Client + Offset.AttackAddr), &Status.Attack, sizeof(bool));
		Sleep(30);
		Status.Attack = !Status.Attack;
		_WriteMem((LPVOID)(Module.Client + Offset.AttackAddr), &Status.Attack, sizeof(bool));
		Sleep(10);
	}
}

void _ReadInformations()
{
	ReadProcessMemory(Process.Handle, (LPVOID)(Module.Client + Offset.BaseAddr), &Offset.BaseTemp, sizeof(DWORD), 0);
	ReadProcessMemory(Process.Handle, (LPVOID)(Offset.BaseTemp), &Player, sizeof(CPlayer_t), 0);
}

void _ReadRadarBase(int i)
{
	//Waiting

}