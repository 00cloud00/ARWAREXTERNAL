#include "include.h"

bool triggerbot::triggerbot_status = false;
int weaponID;
float inaccuracy;

int distance(D3DXVECTOR3 a, D3DXVECTOR3 b) {
	double distance;

	distance = sqrt(((int)a.x - (int)b.x) * ((int)a.x - (int)b.x) +
		((int)a.y - (int)b.y) * ((int)a.y - (int)b.y) +
		((int)a.z - (int)b.z) * ((int)a.z - (int)b.z));

	return (int)abs(round(distance));
}

void getWeapon()
{
	int weapon = readMem<int>(localPlayer::getLocal() + hazedumper::netvars::m_hActiveWeapon);
	//between weaponchange it doesn't work
	int weaponEntity = readMem<int>(gameModule + hazedumper::signatures::dwEntityList + ((weapon & 0xFFF) - 1) * 0x10);

	if (weaponEntity != NULL) {
		weaponID = readMem<int>(weaponEntity + hazedumper::netvars::m_iItemDefinitionIndex);	
		inaccuracy = readMem<float>(weaponEntity + hazedumper::netvars::m_fAccuracyPenalty);		
	}
}

void triggerbot::trigger()
{	
	if (triggerbot::triggerbot_status)
	{
		bool isScoped = readMem<bool>(localPlayer::getLocal() + hazedumper::netvars::m_bIsScoped);
		auto xhair = localPlayer::getLocalCrossID();
		if (xhair > -1) {
			auto inCross = entity::getEntityBase(xhair - 1); //entity
			getWeapon();
			if (entity::getEntTeam(inCross) != localPlayer::getTeam()) {
				if (weaponID == 40 || weaponID == 9 || weaponID == 11 || weaponID == 38)
				{
					float vel = readMem<float>(localPlayer::localPlayerAddress + hazedumper::netvars::m_vecVelocity);
					if (isScoped)
					{
						if ((vel > 0.1 || vel < -0.000984192) && localPlayer::getFlags() != FL_ON_GROUND_CROUCHED)
							return;

						Sleep(10);
						mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
						Sleep(25);
						mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
					}
				}
				else if (weaponID == 31) //zeusbot
				{
					if (distance(localPlayer::getLocalPos(), entity::getEntPos(inCross)) <= 150)
					{
						mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, NULL, NULL);
						Sleep(5);
						mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL);

					}

				}
				else if (weaponID == 42) //knifebot
				{
					if (distance(localPlayer::getLocalPos(), entity::getEntPos(inCross)) <= 82)
					{
						if (entity::getEntHp(inCross) <= 50 && distance(localPlayer::getLocalPos(), entity::getEntPos(inCross)) <= 70)
						{
							mouse_event(MOUSEEVENTF_RIGHTDOWN, NULL, NULL, NULL, NULL);
							Sleep(5);
							mouse_event(MOUSEEVENTF_RIGHTUP, NULL, NULL, NULL, NULL);
						}
						else {
							mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, NULL, NULL);
							Sleep(5);
							mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL);
						}
					}

				}
				else if (weaponID == 64)
				{
					Sleep(0);
					mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
					Sleep(1000);
					mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				
				}
				else if(inaccuracy < 0.025){
					Sleep(25);
					mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
					Sleep(25);
					mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

				}
			}
		}
	}
}