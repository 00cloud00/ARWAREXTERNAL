#include "include.h"

bool norecoil::norecoil_status = false;

D3DXVECTOR3 NewViewAngles;
D3DXVECTOR3 OldAimPunch;

void norecoil::rcs()
{
	if (norecoil::norecoil_status)
	{
		if (localPlayer::getShotsFired() > 1) {
			NewViewAngles.x = ((localPlayer::getLocalViewAngles().x + OldAimPunch.x) - (localPlayer::getLocalPunchAngles().x * 2.f)); 
			NewViewAngles.y = ((localPlayer::getLocalViewAngles().y + OldAimPunch.y) - (localPlayer::getLocalPunchAngles().y * 2.f));


			while (NewViewAngles.y > 180)
				NewViewAngles.y -= 360;

			while (NewViewAngles.y < -180)
				NewViewAngles.y += 360;

			if (NewViewAngles.x > 89.0f)
				NewViewAngles.x = 89.0f;

			if (NewViewAngles.x < -89.0f)
				NewViewAngles.x = -89.0f;

			OldAimPunch.x = localPlayer::getLocalPunchAngles().x * 2.f;
			OldAimPunch.y = localPlayer::getLocalPunchAngles().y * 2.f;

			localPlayer::setLocalViewAngles(NewViewAngles);
		}
		else
		{
			OldAimPunch.x = OldAimPunch.y = 0;
		}
	}
	
}