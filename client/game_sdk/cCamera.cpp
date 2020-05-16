#include "cCamera.hpp"

auto cCamera::getPosition() -> cVector3D {
	return *reinterpret_cast<cVector3D *>(0xB6F338);
}

auto cCamera::getRotation() -> cVector3D {
	return *reinterpret_cast<cVector3D *>(0xB6F32C);
}

auto cCamera::getTarget() -> cVector2D {
	return { *reinterpret_cast<float *>(0xB6F258), *reinterpret_cast<float *>(0xB6F248) };
}

auto cCamera::setTarget(cVector2D vecTarget) -> void {
	*reinterpret_cast<float *>(0xB6F258) = vecTarget.fX;
	*reinterpret_cast<float *>(0xB6F248) = vecTarget.fY;
}