#pragma once

#include "cTypes/cTypes.hpp"
#include "cEntity.hpp"

enum cPhysicalOffsets {
	applyMoveForce		= 0x542A07,
	applyGravityForce	= 0x542B50
};

class cPhysical : public cEntity {

public:

	union {

		struct {

			union {

				struct {

					unsigned char __unk1_nImmunities : 1;
					unsigned char       bUsesGravity : 1;
					unsigned char __unk3_nImmunities : 1;
					unsigned char __unk4_nImmunities : 1; 
					unsigned char __unk5_nImmunities : 1;
					unsigned char __unk6_nImmunities : 1;
					unsigned char __unk7_nImmunities : 1;
					unsigned char __unk8_nImmunities : 1;

				};

				unsigned char			nImmunities;	

			};

			union {

				struct {

					unsigned char __unk1__unknown_66 : 1;
					unsigned char			bIsOnPlace : 1;
					unsigned char __unk3__unknown_66 : 1;
					unsigned char __unk4__unknown_66 : 1;
					unsigned char __unk5__unknown_66 : 1;
					unsigned char				 bLock : 1;
					unsigned char __unk7__unknown_66 : 1;
					unsigned char __unk8__unknown_66 : 1;

				};

				unsigned char		   __unknown_66;

			};

			union {

				struct {

					unsigned char            soft : 1;
					unsigned char       pedFreeze : 1;
					unsigned char    bullet_proof : 1;
					unsigned char      fire_proof : 1;
					unsigned char collision_proof : 1;
					unsigned char     melee_proof : 1;
					unsigned char     __unk7_flag : 1;
					unsigned char explosion_proof : 1;

				};

				unsigned char			  flags;	

			};

			union {

				struct {

					unsigned char __unk1__unknown_68 : 1;
					unsigned char __unk2__unknown_68 : 1;
					unsigned char __unk3__unknown_68 : 1;
					unsigned char __unk4__unknown_68 : 1;
					unsigned char __unk5__unknown_68 : 1;
					unsigned char __unk6__unknown_68 : 1;
					unsigned char __unk7__unknown_68 : 1;
					unsigned char __unk8__unknown_68 : 1;

				};

				unsigned char		   __unknown_68;		

			};

		};

		uint32_t			immunities;	

	};

	cVector3D					speed;
	cVector3D					spin;
	cVector3D					speed_rammed;
	cVector3D					spin_rammed;
	unsigned char				__unknown_116[24];		
	float						mass;
	float						massWhenTurning;
	float						gripDivider;
	float						massToGrip;
	float						Elasticity;
	float						Buoyancy;
	cVector3D					massCenter;
	void						*__unknown_176;			
	void						*__unknown_180;		
	unsigned char				__unknown_184;
	unsigned short				collisionCount;
	unsigned char				__unknown_187;
	cPhysical					*last_collided_object;
	cPhysical					*last_collided_object2;
	cPhysical					*last_collided_object3;
	cPhysical					*last_collided_object4;
	cPhysical					*last_collided_object5;
	cPhysical					*last_collided_object6;
	float						speed_z;		
	float						damageValue;		
	cPhysical					*damagedBy;		
	cVector3D					collided_pos_local;
	cVector3D					collided_pos;
	unsigned short				collided_part;
	cPhysical					*attachedSubject;
	cVector3D					target_pos;
	cVector3D					target_angle;
	unsigned char				__unknown_280[16];
	cPhysical					*collide_ignored;
	float						lightLevel;
	unsigned int				__unknown_304;
	unsigned int				*CShadowData;

	virtual int processEntityCollision(cEntity *pEntity, char *pColPoint) = 0;

	auto getSpeed() -> float;
	auto setSpeed(cVector3D vecSpeed) -> void;
	auto applyMoveForce(cVector3D vecForce) -> void;
	auto applyGravityForce(cVector3D a, cVector3D b, char a4) -> void;

};