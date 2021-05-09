#include "include.h"

bool bhop::bhop_status = false;

void bhop::bhop()
{
	if (bhop::bhop_status)
	{
		float vel = readMem<float>(localPlayer::localPlayerAddress + hazedumper::netvars::m_vecVelocity);
		if (localPlayer::getFlags() == FL_ON_GROUND && GetAsyncKeyState(VK_SPACE) && (vel > 0.1 || vel < -0.000984192))
		{
			writeMem<int>(gameModule + hazedumper::signatures::dwForceJump, 1);
			Sleep(35);
			writeMem<int>(gameModule + hazedumper::signatures::dwForceJump, 0);
		}
	}
}