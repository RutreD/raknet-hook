#include "cObject.hpp"

auto cObject::setTargatable(bool bTargatable) -> int {
	return reinterpret_cast<int(__thiscall *)(class cObject *pThis, unsigned char ucTargatable)>(cObjectOffsets::setTargatable)(this, bTargatable);
}

auto cObject::IsTargatable() -> bool {
	return reinterpret_cast<int(__thiscall *)(class cObject *pThis)>(cObjectOffsets::isTargatable)(this);
}

auto cObject::IsDamaged() -> bool {
	return reinterpret_cast<int(__thiscall *)(class cObject *pThis)>(cObjectOffsets::isDamaged)(this);
}