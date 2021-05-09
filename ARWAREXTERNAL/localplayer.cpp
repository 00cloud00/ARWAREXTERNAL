#include "include.h"

DWORD localPlayer::localPlayerAddress = 0;

void localPlayer::initLocal() {

	localPlayer::localPlayerAddress = readMem<DWORD>(gameModule + hazedumper::signatures::dwLocalPlayer);
}

DWORD localPlayer::getLocal() {
	return localPlayer::localPlayerAddress;
}

int localPlayer::getFlags() {

	return readMem<int>(localPlayer::getLocal() + hazedumper::netvars::m_fFlags);
}

D3DXVECTOR3 localPlayer::getVelocity()
{
	return readMem<D3DXVECTOR3>(localPlayer::getLocal() + hazedumper::netvars::m_vecVelocity);
}

int localPlayer::getFlashDur() {
	return readMem<int>(localPlayer::getLocal() + hazedumper::netvars::m_flFlashDuration);
}


int localPlayer::getTeam() {

	return readMem<int>(localPlayer::getLocal() + hazedumper::netvars::m_iTeamNum);

}

void localPlayer::setLocalViewAngles(D3DXVECTOR3 angles)
{
	writeMem<D3DXVECTOR3>(clientState + hazedumper::signatures::dwClientState_ViewAngles, angles);
}

D3DXVECTOR3 localPlayer::getLocalPunchAngles()
{
	return readMem<D3DXVECTOR3>(localPlayer::getLocal() + hazedumper::netvars::m_aimPunchAngle);
}

D3DXMATRIX	localPlayer::getLocalViewMatrix()
{
	return readMem<D3DXMATRIX>(gameModule + hazedumper::signatures::dwViewMatrix);
}

int localPlayer::getShotsFired() {
	return readMem<int>(localPlayer::getLocal() + hazedumper::netvars::m_iShotsFired);
}

D3DXVECTOR3 localPlayer::getLocalViewAngles()
{
	return readMem<D3DXVECTOR3>(clientState + hazedumper::signatures::dwClientState_ViewAngles);
}

int localPlayer::getLocalCrosshair()
{
	auto temp = readMem<int>(localPlayer::getLocal() + hazedumper::netvars::m_iCrosshairId);
	if (temp <= 0 || temp > 32)
		return -1;
	return temp;
}

D3DXVECTOR3 localPlayer::getLocalPos()
{
	return readMem<D3DXVECTOR3>(localPlayer::getLocal() + hazedumper::netvars::m_vecOrigin);
}

int localPlayer::getLocalCrossID()
{
	auto temp = readMem<int>(localPlayer::getLocal() + hazedumper::netvars::m_iCrosshairId);
	if (temp <= 0 || temp > 32)
		return -1;
	return temp;
}

D3DXVECTOR3 localPlayer::getLocalEyePos()
{
	return ((localPlayer::getLocalPos()) + (readMem<D3DXVECTOR3>(localPlayer::getLocal() + hazedumper::netvars::m_vecViewOffset)));
}
