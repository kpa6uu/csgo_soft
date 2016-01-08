 #ifndef CHEAT
#define CHEAT

#include "Main.h"

#define FL_ONGROUND (1 << 0)

class Vec3
{
public:
	float x, y, z;
	Vec3(){};

	Vec3(float x, float y, float z)
	{
		this->x;
		this->y;
		this->z;
	}
};

struct CPlayer_t
{
	char _0x0000[240];
	__int32 Team; //0x00F0 
	char _0x00F4[8];
	__int32 Health; //0x00FC 
	BYTE Flags; //0x0100 
	char _0x0101[1075];
	Vec3 Origin; //0x0534 
	char _0x0540[7728];
	__int32 CrossID; //0x2370 
};
extern CPlayer_t Player;

struct CRadar_t
{

};
extern CRadar_t Radar[32];

void _CallExtern();
void _Bunnyhop();
void _Triggerbot();
void _ReadInformations();
void _Rapidfire();

#endif