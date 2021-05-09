#include "include.h"

bool glowesp::glow_status = false;

void glowesp::glow(int index)
{
	if (glowesp::glow_status)
	{

		auto plr = entity::getEntityBase(index);
		if (entity::isValid(plr))
		{
			auto gObj = entity::getGlowObj();
			auto gIdx = entity::getGlowIndex(plr);

			if (entity::getEntTeam(plr) != localPlayer::getTeam()) {
				if (entity::getEntHp(plr) >= 70)
				{
					entity::glowEsp(gObj, gIdx, 99, 200, 69, 200);
				}
				if (entity::getEntHp(plr) < 70 && entity::getEntHp(plr) >= 40)
				{
					entity::glowEsp(gObj, gIdx, 255, 255, 69, 200);
				}
				if (entity::getEntHp(plr) < 40)
				{
					entity::glowEsp(gObj, gIdx, 255, 69, 69, 200);
				}
			}
		}
		
	}
}