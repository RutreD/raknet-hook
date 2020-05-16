#include "cPed.hpp"

auto cPed::new_cPed(unsigned int pedType) -> cPed* {

	unsigned char *_this = new unsigned char[sizeof(cPed)];
	reinterpret_cast<bool(__thiscall *)(void *pThis, unsigned int type)>(cPedOffsets::cPedConstructor)(_this, pedType);
	
	return reinterpret_cast<cPed *>(_this);

}

auto cPed::IsDriving() -> bool {
	return state == 50;
}

auto cPed::IsLeavingCar() -> bool {
	if (IsDriving()) return false;
	return state == 0;
}

auto cPed::IsValid() -> bool {
	return reinterpret_cast<bool(__thiscall *)(class cPed *pThis)>(cPedOffsets::isValid)(this);
}

auto cPed::IsActorDead() -> bool {
	return (state == 55 || state == 63 || hitpoints == 0.f);
}

auto cPed::IsAvailable() -> bool {
	return reinterpret_cast<bool(__thiscall *)(class cPed *pThis)>(cPedOffsets::isAvailable)(this);
}

auto cPed::IsControlable() -> bool {
	return reinterpret_cast<bool(__thiscall *)(class cPed *pThis)>(cPedOffsets::isControlable)(this);
}

auto cPed::IsStopped() -> bool {
	return (getSpeed() < 0.0001f);
}

auto cPed::IsCrouch() -> bool {
	return (crouchStatus == 132);
}

auto cPed::IsJumping() -> bool {
	return (animation_state == 0 || jumpStatus == 34 || jumpStatus == 36);
}

auto cPed::getBonePosition(cVector3D *vecResult, const unsigned int ui32BoneID, const bool bDynamic) -> void {
	reinterpret_cast<void(__thiscall *)(class cPed *pThis, class cVector3D *vecResult, unsigned __int32 ui32BoneID, bool bDynamic)>(cPedOffsets::getBonePosition)(this, vecResult, ui32BoneID, bDynamic);
}

auto cPed::IsModelLoaded(eModelIndex modelID) -> int {
	int *ModelsLoadStateArray = reinterpret_cast<int*>(0x8E4CD0);
	return ModelsLoadStateArray[5 * modelID];
}

auto cPed::requestModelLoad(eModelIndex modelID) -> bool {

	if (IsModelLoaded(modelID))
		return false;

	reinterpret_cast<void(__cdecl *)(int modelId, int a2)>(0x4087E0)(modelID, 2);

	return true;

}

auto cPed::loadRequestedModels() -> void {
	reinterpret_cast<void(__cdecl *)(int a1)>(0x40EA10)(0);
}

auto cPed::loadModel(eModelIndex modelID) -> void {
	if (requestModelLoad(modelID))
		loadRequestedModels();
}

auto cPed::getWeaponModel(int weaponId) -> eModelIndex {
	if (weaponId == 1)
		return weapon_BrassKnuckles;
	else if (weaponId >= 2 && weaponId <= 8)
		return eModelIndex(weaponId + 331);
	else if (weaponId == 9)
		return weapon_Chainsaw;
	else if (weaponId >= 22 && weaponId <= 29)
		return eModelIndex(weaponId + 324);
	else if (weaponId == 32)
		return weapon_Tech9;
	else if (weaponId >= 30 && weaponId <= 31)
		return eModelIndex(weaponId + 325);
	else if (weaponId >= 33 && weaponId <= 38)
		return eModelIndex(weaponId + 324);
	else if (weaponId >= 16 && weaponId <= 18)
		return eModelIndex(weaponId + 326);
	else if (weaponId == 39)
		return weapon_RemoteExplosives;
	else if (weaponId >= 41 && weaponId <= 43)
		return eModelIndex(weaponId + 324);
	else if (weaponId >= 10 && weaponId <= 15)
		return eModelIndex(weaponId + 311);
	else if (weaponId >= 44 && weaponId <= 45)
		return eModelIndex(weaponId + 324);
	else if (weaponId == 46)
		return weapon_Parachute;
	else if (weaponId == 40)
		return weapon_Detonator;
	return eModelIndex(-1);
}

auto cPed::loadWeaponModel(int weaponId) -> void {
	loadModel(getWeaponModel(weaponId));
}

auto cPed::giveWeapon(int weaponId, int ammo) -> int {
	loadWeaponModel(weaponId);
	return reinterpret_cast<int(__thiscall *)(class cPed *pThis, int weapId, int ammo, int unk)>(cPedOffsets::giveWeapon)(this, weaponId, ammo, 0);
}

auto cPed::setAmmo(int weaponId, int ammo) -> void {
	reinterpret_cast<void(__thiscall *)(class cPed *pThis, int weaponId, int ammo)>(cPedOffsets::setAmmo)(this, weaponId, ammo);
}

auto cPed::setActiveWeaponSlot(int slotId) -> void {
	reinterpret_cast<void(__thiscall *)(class cPed *pThis, int slotId)>(cPedOffsets::setActiveSlot)(this, slotId);
}

auto cPed::setWeapon(int weaponId) -> void {
	reinterpret_cast<unsigned(__thiscall *)(class cPed *pThis, int weaponId)>(cPedOffsets::setWeapon)(this, weaponId);
}

auto cPed::clearWeapons() -> void {
	reinterpret_cast<void(__thiscall *)(class cPed *pThis)>(cPedOffsets::clearWeapons)(this);
}

auto cPed::getWeaponSkillIndex() -> unsigned char {
	return reinterpret_cast<unsigned char(__thiscall *)(class cPed *pThis)>(cPedOffsets::getWeaponSkillI)(this);
}

auto cPed::getWeaponSkillByType(int weaponId) -> unsigned char {
	return reinterpret_cast<unsigned char(__thiscall *)(class cPed *pThis, int weaponId)>(cPedOffsets::getWeaponSkillF)(this, weaponId);
}

auto cPed::removeWeaponModel(int model) -> void* {
	return reinterpret_cast<void*(__thiscall *)(class cPed *pThis, int model) > (cPedOffsets::removeWeapon)(this, model);
}

auto cPed::grantAmmo(int weaponId, int ammo) -> int {
	return reinterpret_cast<int(__thiscall *)(class cPed *pThis, int weaponId, int ammo)>(cPedOffsets::grantAmmo)(this, weaponId, ammo);
}

auto cPed::getPlayerNumber() -> int {
	return reinterpret_cast<int(__cdecl *)(class cPed *pThis)>(cPedOffsets::getPlayerNumber)(this);
}

auto cPed::setPlayerStatValue(int statId, float value) -> void {
	reinterpret_cast<void(__cdecl *)(int statId, float value)>(cPedOffsets::setPlayerStats)(statId, value);
}

auto cPed::getPlayerStatValue(int statId) -> float {
	return reinterpret_cast<float(__cdecl *)(unsigned short statId)>(cPedOffsets::getPlayerStats)(statId);
}
