#include "cVector2D.hpp"

cVector2D::cVector2D(float X, float Y) {

	fX = X;
	fY = Y;

}

auto cVector2D::Length() -> float {
	return sqrtf(powf(fX, 2) + powf(fY, 2));
}