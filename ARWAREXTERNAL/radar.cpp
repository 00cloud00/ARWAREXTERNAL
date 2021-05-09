#include "include.h"

bool radar::radar_status = false;

void radar::show(int index)
{
	if (radar::radar_status)
	{		
		DWORD base = entity::getEntityBase(index);
		if (entity::getEntTeam(base) != localPlayer::getTeam() && !entity::getSpotted(base))
		{
			writeMem<bool>(base + hazedumper::netvars::m_bSpotted, true);
		}
		
	}
}