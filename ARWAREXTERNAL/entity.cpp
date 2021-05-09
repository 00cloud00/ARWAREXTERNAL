#include "include.h"

DWORD entity::getEntityBase(int index)
{
	return readMem<DWORD>(gameModule + hazedumper::signatures::dwEntityList + (index * 0x10));
}

int	entity::getEntHp(DWORD playerBase)
{
	return readMem<int>(playerBase + hazedumper::netvars::m_iHealth);
}

bool entity::isAlive(DWORD playerBase)
{
	if (getEntHp(playerBase) > 0 && getEntHp(playerBase) <= 100)
		return true;
	return false;
}

int	entity::getEntTeam(DWORD playerBase)
{
	return readMem<int>(playerBase + hazedumper::netvars::m_iTeamNum);
}

int entity::getGlowIndex(DWORD playerBase)
{
	return readMem<int>(playerBase + hazedumper::netvars::m_iGlowIndex);
}

DWORD entity::getGlowObj()
{
	return readMem<DWORD>(gameModule + hazedumper::signatures::dwGlowObjectManager);
}

bool entity::isValid(DWORD playerBase)
{
	auto dormant = readMem<bool>(playerBase + hazedumper::signatures::m_bDormant);
	if ((entity::isAlive(playerBase) && entity::getEntTeam(playerBase) != 0) && !dormant)
		return true;
	return false;
}

void entity::glowEsp(DWORD glowObj, int glowInd, float r, float g, float b, float a)
{
	writeMem<float>((glowObj + ((glowInd * 0x38) + 0x4)), r / 255);
	writeMem<float>((glowObj + ((glowInd * 0x38) + 0x8)), g / 255);
	writeMem<float>((glowObj + ((glowInd * 0x38) + 0xC)), b / 255);
	writeMem<float>((glowObj + ((glowInd * 0x38) + 0x10)), a / 255);
	writeMem<bool>((glowObj + ((glowInd * 0x38) + 0x24)), true);
	writeMem<bool>((glowObj + ((glowInd * 0x38) + 0x25)), false);
}

bool entity::getSpotted(DWORD base)
{
	return readMem<bool>(base + hazedumper::netvars::m_bSpotted);
}

void entity::setSpotted(DWORD base, bool val)
{
	writeMem<bool>(base + hazedumper::netvars::m_bSpotted, val);
}

bool entity::getEntImmunity(DWORD base)
{
	return readMem<bool>(base + hazedumper::netvars::m_bGunGameImmunity);
}

DWORD entity::getEntBoneMatrix(DWORD base)
{
	return readMem<DWORD>(base + hazedumper::netvars::m_dwBoneMatrix);
}

//https://www.unknowncheats.me/forum/counterstrike-global-offensive/283460-bone-pos-externally.html (usando solo un call a readmem)
D3DXVECTOR3	entity::getEntBonePos(DWORD base, int boneID) 
{
	Matrix3x4_t boneMatrix = readMem<Matrix3x4_t>(entity::getEntBoneMatrix(base) + boneID * 0x30);

	return{
		boneMatrix.Matrix[0][3],
		boneMatrix.Matrix[1][3],
		boneMatrix.Matrix[2][3]
	};
}

D3DXVECTOR3	entity::getEntPos(DWORD base)
{
	return readMem<D3DXVECTOR3>(base + hazedumper::netvars::m_vecOrigin);
}

D3DXVECTOR3 entity::getEntEyePos(DWORD playerBase)
{
	return ((entity::getEntPos(playerBase)) + (readMem<D3DXVECTOR3>(playerBase + hazedumper::netvars::m_vecViewOffset)));
}
