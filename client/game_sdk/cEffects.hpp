#pragma once

#include "cTypes/cTypes.hpp"
#include "cEntity.hpp"

enum cEffectsOffsets {
	pInterface = 0xA9AE00,
	addBlood   = 0x49EB00,
	addWood	   = 0x49EE10,
	addTyre	   = 0x49F300,
	addImpact  = 0x49F3D0,
	addPunch   = 0x49F670,
	addDebris  = 0x49F750,
	addGlass   = 0x49F970
};

class cEffects {

public:
	
	auto addBlood(cVector3D *vecPosition, cVector3D *vecDirection, int iCount, float fBrightness) -> void;
	auto addWood(cVector3D *vecPosition, cVector3D *vecDirection, int iCount, float fBrightness) -> void;
	auto addTyreBurst(cVector3D *vecPosition, cVector3D *vecDirection) -> void;
	auto addBulletImpact(cVector3D *vecPosition, cVector3D *vecDirection, int iSmokeSize, int iSparkCount, float fSmokeIntensity) -> void;
	auto addPunchImpact(cVector3D *vecPosition, cVector3D *vecDirection, int i) -> void;
	auto addDebris(cVector3D *vecPosition, unsigned long *rwColor, float fScale, int iCount) -> void;
	auto addGlass(cVector3D *vecPosition, unsigned long *rwColor, float fScale, int iCount) -> void;

};