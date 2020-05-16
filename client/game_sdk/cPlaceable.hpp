#pragma once

#include "cTypes/cTypes.hpp"

enum cPlaceableOffsets {
	setRotation = 0x439A80,
	getRotation = 0x441DB0
};

class cPlaceable {

public:

	virtual ~cPlaceable() = 0;

	cVector3D	vecPosition;
	float		fAngle;
	cMatrix		*pMatrix;

	auto setPosition(cVector3D vecPosition) -> void;
	auto getPosition() -> cVector3D;

	auto setRotation(cVector3D vecRotation) -> void;
	auto getRotation() -> long double;

};
