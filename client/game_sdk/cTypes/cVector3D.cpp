#include "cVector3D.hpp"

cVector3D::cVector3D(float X, float Y, float Z) {

	fX = X;
	fY = Y;
	fZ = Z;

}

auto cVector3D::Length() -> float {
	return sqrtf(powf(fX, 2) + powf(fY, 2) + powf(fZ, 2));
}