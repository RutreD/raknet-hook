#pragma once

#include <cmath>

class cVector3D {

public:

	cVector3D(float X = 0.f, float Y = 0.f, float Z = 0.f);

	float fX, fY, fZ;

	auto Length() -> float;

};
