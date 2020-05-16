#pragma once

#include "cTypes/cTypes.hpp"

#include "cPed.hpp"
#include "cVehicle.hpp"
#include "cCamera.hpp"
#include "cEffects.hpp"

class cGame {

public: 

	auto getCamera() -> cCamera*;
	auto getEffects() -> cEffects*;
	auto getPed(unsigned long address) -> cPed*;
	auto getEntity(unsigned long address) -> cEntity*;
	auto getPhysical(unsigned long address) -> cPhysical*;
	auto getPlaceable(unsigned long address) -> cPlaceable*;
	auto getVehicle(unsigned long address) -> cVehicle*;
	auto getObject(unsigned long address) -> cObject*;

private:

	cCamera		*pCamera	= new cCamera();
	cEffects	*pEffects	= new cEffects();

};
