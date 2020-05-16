#include "cEntity.hpp"

auto cEntity::Teleport(cVector3D vecPos, bool lockRotate) -> void {
	Teleport(vecPos.fX, vecPos.fY, vecPos.fZ, lockRotate);
}

auto cEntity::IsPed() -> bool {
	return modelID <= 311;
}

auto cEntity::IsVehicle() -> bool {
	return (modelID >= 400 && modelID <= 611);
}

auto cEntity::IsOnScreen() -> bool {
	return this->bOffscreen ^ true;
}

auto cEntity::IsUnderWater() -> bool {
	return this->bUnderwater;
}

auto cEntity::IsVisible() -> bool {
	return this->bIsVisible;
}

auto cEntity::SetVisible(bool bVisible) -> void {
	this->bIsVisible = bVisible;
}

auto cEntity::IsUsesCollision() -> bool {
	return this->bUsesCollision;
}

auto cEntity::SetUsesCollision(bool bCollision) -> void {
	this->bUsesCollision = bCollision;
}