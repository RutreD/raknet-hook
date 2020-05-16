#pragma once

#include "cTypes/cTypes.hpp"
#include "cPhysical.hpp"

enum cObjectOffsets {
	setTargatable = 0x59F300,
	isTargatable  = 0x59F320,
	isDamaged     = 0x46A2F0
};

class cObject : public cPhysical {

public:

	unsigned char			   __unknown_312[8];		
	unsigned long						  flags;
	unsigned char				   EffectDamage;
	unsigned char			   __unknown_325[3];
	unsigned char				DamagByWeaponID;
	unsigned char			  __unknown_327[11];
	float					  hitpoints;
	float						   size;
	unsigned long				ptr_CObjectInfo;

	auto setTargatable(bool bTargatable) -> int;
	auto IsTargatable() -> bool;
	auto IsDamaged() -> bool;

};