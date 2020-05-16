#pragma once

#include "cTypes/cTypes.hpp"

class cCamera {

public:

	auto getPosition() -> cVector3D;
	auto getRotation() -> cVector3D;

	auto getTarget() -> cVector2D;
	auto setTarget(cVector2D vecTarget) -> void;

};