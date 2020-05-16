#include "cVehicle.hpp"

auto cVehicle::getHitpoints() -> float {
	return this->hitpoints;
}

auto cVehicle::setHitpoints(float fHealth) -> void {
	this->hitpoints = fHealth;
}

auto cVehicle::repairCar() -> void {
	fix();
	setHitpoints(1000.f);
}

auto cVehicle::isBoat() -> bool {
	return reinterpret_cast<bool(__cdecl *)(int modelId)>(cVehicleOffsets::isBoat)(modelID);
}

auto cVehicle::isCar() -> bool {
	return reinterpret_cast<bool(__cdecl *)(int modelId)>(cVehicleOffsets::isCar)(modelID);
}

auto cVehicle::isTrain() -> bool {
	return reinterpret_cast<bool(__cdecl *)(int modelId)>(cVehicleOffsets::isTrain)(modelID);
}

auto cVehicle::isHeli() -> bool {
	return reinterpret_cast<bool(__cdecl *)(int modelId)>(cVehicleOffsets::isHeli)(modelID);
}

auto cVehicle::isPlane() -> bool {
	return reinterpret_cast<bool(__cdecl *)(int modelId)>(cVehicleOffsets::isPlane)(modelID);
}

auto cVehicle::isBike() -> bool {
	return reinterpret_cast<bool(__cdecl *)(int modelId)>(cVehicleOffsets::isBike)(modelID);
}

auto cVehicle::isFakePlane() -> bool {
	return reinterpret_cast<bool(__cdecl *)(int modelId)>(cVehicleOffsets::isFake)(modelID);
}

auto cVehicle::isMonsterTruck() -> bool {
	return reinterpret_cast<bool(__cdecl *)(int modelId)>(cVehicleOffsets::isMonster)(modelID);
}

auto cVehicle::isQuadBike() -> bool {
	return reinterpret_cast<bool(__cdecl *)(int modelId)>(cVehicleOffsets::isQuad)(modelID);
}

auto cVehicle::isBMX() -> bool {
	return reinterpret_cast<bool(__cdecl *)(int modelId)>(cVehicleOffsets::isBMX)(modelID);
}

auto cVehicle::isTrailer() -> bool {
	return reinterpret_cast<bool(__cdecl *)(int modelId)>(cVehicleOffsets::isTrailer)(modelID);
}

auto cVehicle::lockVehicle() -> bool {
	return reinterpret_cast<bool(__thiscall *)(class cVehicle *pThis)>(cVehicleOffsets::lockVehicle)(this);
}

auto cVehicle::setAngularVelocity(cVector3D angularVelocity) -> float {
	return reinterpret_cast<float(__thiscall *)(class cVehicle *pThis, float X, float Y, float Z)>(cVehicleOffsets::lockVehicle)(this, angularVelocity.fX, angularVelocity.fY, angularVelocity.fZ);
}