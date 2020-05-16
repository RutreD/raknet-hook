#pragma once

#include <cmath>

class cVector2D {

public:

	cVector2D(float X = 0.f, float Y = 0.f);

	float fX, fY;

	auto Length() -> float;

};