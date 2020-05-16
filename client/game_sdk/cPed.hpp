#pragma once

#include "cTypes/cTypes.hpp"
#include "cPhysical.hpp"
#include "cObject.hpp"

enum cPedOffsets {
	getBonePosition = 0x5E4280,
	giveWeapon      = 0x5E6080,
	setAmmo			= 0x5DF290,
	isAvailable		= 0x5E0170,
	setActiveSlot   = 0x5E61F0,
	setWeapon		= 0x5E6280,
	clearWeapons	= 0x5E6320,
	getWeaponSkillI	= 0x5E6580,
	getWeaponSkillF = 0x5E3B60,
	removeWeapon	= 0x5E3990,
	grantAmmo		= 0x5DF220,
	isControlable	= 0x609590,
	cPedConstructor = 0x5E8030,
	setPlayerStats  = 0x55A070,
	getPlayerStats  = 0x558E40,
	getPlayerNumber = 0x563FA0,
	isValid			= 0x5E4220
};

class cPed : public cPhysical {

public:

	unsigned char			   __unknown_316[32];		
	unsigned char				 animation_state;
	unsigned char				__unknown_349[7];		
	cVector3D						step_pos;	
	cVector3D				 step_pos_before;		
	unsigned char			  __unknown_380[280];		
	unsigned char				CPedSound[0x100];
	unsigned char			  __unknown_916[216];		
	unsigned char					playerStatus;
	unsigned char					  jumpStatus;
	unsigned char					  __unk_flag;
	unsigned char					crouchStatus;
	unsigned long					  propirties;
	unsigned long					 propirties2;	
	unsigned long			 __unknownFlags_1144;		
	unsigned long					  ptr_stAnim;		
	void					*pPlayerData;		
	unsigned char				__unknown_1156[8];		
	void						   *pNeck;
	class cBone				   *boneHead;	
	class cBone				*boneLeftArm;		
	class cBone			   *boneRightArm;	
	class cBone			 *pboneLeftLowArm;		
	class cBone			*boneRightLowArm;	
	class cBone				*boneLeftLeg;	
	class cBone			   *boneRightLeg;		
	class cBone			 *boneLeftLowLeg;		
	class cBone			*boneRightLowLeg;		
	class cBone			*boneRightMidLeg;		
	class cBone			 *boneLeftMidLeg;	
	class cBone			 *boneLeftMidArm;		
	class cBone			*boneRightMidArm;		
	class cBone		   *boneLeftShoulder;	
	class cBone		  *boneRightShoulder;	
	class cBone				  *boneChest;		
	class cBone				  *boneMouth;		
	unsigned long						animGroup;
	unsigned char				__unknown_1240[4];		
	float						 runspeed;		
	unsigned char				   animLoopStatus;
	unsigned char			   __unknown_1249[19];		
	unsigned long					CurrentWeapon;	
	unsigned long					 muzzle_flash;		
	unsigned long						   Scores;	
	unsigned long					   ScoresType;
	unsigned long		   AlphaBlendMuzzle_flash;
	unsigned long		  AlphaBlendMuzzle_flash2;
	unsigned char				__unknown_1324[4];		
	unsigned int						state;		
	unsigned int					run_state;	
	unsigned char				__unknown_1336[8];	
	float						hitpoints;	
	float					hitpoints_max;		
	float							armor;		
	cVector3D				   reset_position;		
	float				 fCurrentRotation;		
	float				  fTargetRotation;		
	float				   fRotationSpeed;		
	float			 fRotationCalculation;		
	class CVehicle		 *pContactVehicle;		
	cVector3D			 vehicle_contact_dist;
	cVector3D		fPlaneAnglesContactEntity;
	cEntity					*item_contact;
	float					fUnknown_1416;		

	union {

		class CVehicle			 *vehicle;		
		class CAutomobile	  *automobile;		
		class CMonsterTruck       *mtruck;		
		class CTrailer           *trailer;		
		class CBike                 *bike;		
		class CQuad                 *quad;		
		class CBmx                   *bmx;		
		class CHeli                 *heli;		
		class CPlane               *plane;		
		class CBoat                 *boat;		

	};

	unsigned char				__unknown_1424[8];		
	unsigned char					   actor_lock;		
	unsigned char				__unknown_1433[7];		
	unsigned long				   turrelWeaponID;
	unsigned char			    __unknown_1808[8];		
	unsigned char					  weapon_slot;	
	unsigned char				   __unknown_1817;	
	unsigned char				     AccuracyShot;
	unsigned char				   __unknown_1819;		
	cObject					*targetObject;
	cVector3D				 fImpactPos_close;
	unsigned char					 weaponSkills;
	unsigned char					   fightStyle;
	unsigned char					  fightStyle2;
	unsigned char				   __unknown_1839;		
	unsigned long						ptr_CFire;
	unsigned char			   __unknown_1836[12];
	unsigned int				 weapon_model;		
	unsigned char			   __unknown_1860[18];	
	unsigned short							money;
	unsigned char				__unknown_1880[8];		
	unsigned long				 killedByWeaponID;
	cPed						  *killer;
	unsigned char				__unknown_1896[4];		
	cVector3D					 turrelOffset;
	float					 angleTurrelA;
	float					 angleTurrelB;
	unsigned long				  vievPosInTurrel;
	unsigned long					 ammoInTurrel;
	unsigned char			   __unknown_1928[20];		
	cPed					 *TargetedPed;
	unsigned char			   __unknown_1952[36];		

	static cPed *new_cPed(unsigned int pedType);

	auto IsDriving() -> bool;
	auto IsLeavingCar() -> bool;
	auto IsValid() -> bool;
	auto IsActorDead() -> bool;
	auto IsAvailable() -> bool;
	auto IsControlable() -> bool;
	auto IsStopped() -> bool;
	auto IsCrouch() -> bool;
	auto IsJumping() -> bool;
	auto IsModelLoaded(eModelIndex modelID) -> int;

	auto requestModelLoad(eModelIndex modelID) -> bool;
	auto loadRequestedModels() -> void;
	auto loadModel(eModelIndex modelID) -> void;
	auto getWeaponModel(int weaponId) -> eModelIndex;
	auto loadWeaponModel(int weaponId) -> void;

	auto getBonePosition(cVector3D *vecResult, const unsigned int ui32BoneID, const bool bDynamic) -> void;
	auto giveWeapon(int weaponId, int ammo) -> int;
	auto setAmmo(int weaponId, int ammo) -> void;
	auto setActiveWeaponSlot(int slotId) -> void;
	auto setWeapon(int weaponId) -> void;
	auto clearWeapons() -> void;
	auto getWeaponSkillIndex() -> unsigned char;
	auto getWeaponSkillByType(int weaponId) -> unsigned char;
	auto removeWeaponModel(int model) -> void*;
	auto grantAmmo(int weaponId, int ammo) -> int;
	auto getPlayerNumber() -> int;
	auto setPlayerStatValue(int statId, float value) -> void;
	auto getPlayerStatValue(int statId) -> float;

};