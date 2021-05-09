#pragma once

#include <windows.h>
#include <d3dx9.h>

namespace localPlayer
{
	extern DWORD			localPlayerAddress;
	extern DWORD			getLocal();
	extern int				getFlags();
	extern D3DXVECTOR3		getVelocity();
	extern void				initLocal();
	extern int				getFlashDur();
	extern int				getTeam();
	extern D3DXVECTOR3		getLocalViewAngles();					
	extern void				setLocalViewAngles(D3DXVECTOR3 angles);
	extern D3DXVECTOR3		getLocalPunchAngles();
	extern D3DXMATRIX		getLocalViewMatrix();
	extern int				getShotsFired();
	extern int				getLocalCrosshair();
	extern D3DXVECTOR3		getLocalPos();
	extern D3DXVECTOR3		getLocalEyePos();
	extern int				getLocalCrossID();
	extern bool				isScoped();
}
