#include "cPhysical.hpp"

auto cPhysical::getSpeed() -> float {
	return speed.Length();
}

auto cPhysical::setSpeed(cVector3D vecSpeed) -> void {
	speed.fX = vecSpeed.fX;
	speed.fY = vecSpeed.fY;
	speed.fZ = vecSpeed.fZ;
}

auto cPhysical::applyMoveForce(cVector3D vecForce) -> void {
	reinterpret_cast<void(__thiscall *)(class cPhysical *pThis, class cVector3D vecForce)>(cPhysicalOffsets::applyMoveForce)(this, vecForce);
}

auto cPhysical::applyGravityForce(cVector3D a, cVector3D b, char a4) -> void {
	reinterpret_cast<void(__thiscall *)(class cPhysical *pThis, class cVector3D a, class cVector3D b, char a4)>(cPhysicalOffsets::applyMoveForce)(this, a, b, a4);
}