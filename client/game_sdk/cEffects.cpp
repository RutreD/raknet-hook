#include "cEffects.hpp"

auto cEffects::addBlood(cVector3D *vecPosition, cVector3D *vecDirection, int iCount, float fBrightness) -> void {

	unsigned long dwThis = cEffectsOffsets::pInterface;
	unsigned long dwFunc = cEffectsOffsets::addBlood;

	_asm {
		mov     ecx, dwThis
		push    fBrightness
		push    iCount
		push    vecDirection
		push    vecPosition
		call    dwFunc
	}

}

auto cEffects::addWood(cVector3D *vecPosition, cVector3D *vecDirection, int iCount, float fBrightness) -> void {
	
	unsigned long dwThis = cEffectsOffsets::pInterface;
	unsigned long dwFunc = cEffectsOffsets::addWood;

	_asm {
		mov     ecx, dwThis
		push    fBrightness
		push    iCount
		push    vecDirection
		push    vecPosition
		call    dwFunc
	}

}

auto cEffects::addTyreBurst(cVector3D *vecPosition, cVector3D *vecDirection) -> void {
	
	unsigned long dwThis = cEffectsOffsets::pInterface;
	unsigned long dwFunc = cEffectsOffsets::addTyre;

	_asm {
		mov     ecx, dwThis
		push    vecDirection
		push    vecPosition
		call    dwFunc
	}

}

auto cEffects::addBulletImpact(cVector3D *vecPosition, cVector3D *vecDirection, int iSmokeSize, int iSparkCount, float fSmokeIntensity) -> void {

	unsigned long dwThis = cEffectsOffsets::pInterface;
	unsigned long dwFunc = cEffectsOffsets::addImpact;

	_asm {
		mov     ecx, dwThis
		push    fSmokeIntensity
		push    iSparkCount
		push    iSmokeSize
		push    vecDirection
		push    vecPosition
		call    dwFunc
	}

}

auto cEffects::addPunchImpact(cVector3D *vecPosition, cVector3D *vecDirection, int i) -> void {

	unsigned long dwThis = cEffectsOffsets::pInterface;
	unsigned long dwFunc = cEffectsOffsets::addPunch;

	_asm {
		mov     ecx, dwThis
		push    i
		push    vecDirection
		push    vecPosition
		call    dwFunc
	}

}

auto cEffects::addDebris(cVector3D *vecPosition, unsigned long *rwColor, float fScale, int iCount) -> void {

	unsigned long dwThis = cEffectsOffsets::pInterface;
	unsigned long dwFunc = cEffectsOffsets::addDebris;

	_asm {
		mov     ecx, dwThis
		push    iCount
		push    fScale
		push    rwColor
		push    vecPosition
		call    dwFunc
	}

}

auto cEffects::addGlass(cVector3D *vecPosition, unsigned long *rwColor, float fScale, int iCount) -> void {

	DWORD dwThis = cEffectsOffsets::pInterface;
	DWORD dwFunc = cEffectsOffsets::addGlass;

	_asm
	{
		mov     ecx, dwThis
		push    iCount
		push    fScale
		push    rwColor
		push    vecPosition
		call    dwFunc
	}

}