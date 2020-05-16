#include "cMatrix.hpp"

cMatrix::cMatrix() {

	vecUp		= { 1.f, 0.f, 0.f };
	vecRight	= { 0.f, 1.f, 0.f };
	vecAt		= { 0.f, 0.f, 1.f };
	vecPos		= { 0.f, 0.f, 0.f };

	ulFlags		= 0;
	fPad_u		= 0.f;
	fPad_p		= 0.f;
	fPad_a		= 0.f;

}

cMatrix::cMatrix(const cMatrix &mat) {

	vecUp		= mat.vecUp;
	vecRight	= mat.vecRight;
	vecAt		= mat.vecAt;
	vecPos		= mat.vecPos;

	ulFlags		= 0;
	fPad_u		= 0.f;
	fPad_p		= 0.f;
	fPad_a		= 0.f;

}
