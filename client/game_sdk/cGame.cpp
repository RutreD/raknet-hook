#include "cGame.hpp"

auto cGame::getCamera() -> cCamera* {
	return pCamera;
}

auto cGame::getEffects() -> cEffects* {
	return pEffects;
}

auto cGame::getPed(unsigned long address) -> cPed* {
	return reinterpret_cast<cPed *>(*reinterpret_cast<unsigned long *>(address));
}

auto cGame::getEntity(unsigned long address) -> cEntity* {
	return reinterpret_cast<cEntity *>(*reinterpret_cast<unsigned long *>(address));
}

auto cGame::getPhysical(unsigned long address) -> cPhysical* {
	return reinterpret_cast<cPhysical *>(*reinterpret_cast<unsigned long *>(address));
}

auto cGame::getPlaceable(unsigned long address) -> cPlaceable* {
	return reinterpret_cast<cPlaceable *>(*reinterpret_cast<unsigned long *>(address));
}

auto cGame::getVehicle(unsigned long address) -> cVehicle* {
	return reinterpret_cast<cVehicle *>(*reinterpret_cast<unsigned long *>(address));
}

auto cGame::getObject(unsigned long address) -> cObject* {
	return reinterpret_cast<cObject *>(*reinterpret_cast<unsigned long *>(address));
}