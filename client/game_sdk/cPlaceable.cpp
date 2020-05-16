#include "cPlaceable.hpp"

auto cPlaceable::setPosition(cVector3D vecPosition) -> void {
	pMatrix->vecPos = vecPosition;
}

auto cPlaceable::getPosition() -> cVector3D {
	return pMatrix->vecPos;
}

auto cPlaceable::setRotation(cVector3D vecRotation) -> void {
	reinterpret_cast<float(__thiscall *)(class cPlaceable *pThis, float fX, float fY, float fZ)>(cPlaceableOffsets::setRotation)(this, vecRotation.fX, vecRotation.fY, vecRotation.fZ);
}

auto cPlaceable::getRotation() -> long double {
	return reinterpret_cast<long double(__thiscall *)(class cPlaceable *pThis)>(cPlaceableOffsets::getRotation)(this);
}