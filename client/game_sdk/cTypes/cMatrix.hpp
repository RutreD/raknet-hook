#pragma once

#include "cTypes.hpp"

class cMatrix {

public:

	cVector3D		vecRight;
	unsigned long	ulFlags;
	cVector3D		vecUp;
	float			fPad_u;
	cVector3D		vecAt; 
	float			fPad_a;
	cVector3D		vecPos;
	float			fPad_p;

	cMatrix();
	cMatrix(const cMatrix &);

};