#pragma once

#include <Windows.h>
#include <iostream>
#include <d3dx9.h>
#include <stdint.h>

#include "cVector2D.hpp"
#include "cVector3D.hpp"
#include "cMatrix.hpp"
#include "eModelIndex.hpp"
#include "cRect.hpp"
#include "cDetachable.hpp"

enum {
	ACTOR_SELF					= -1,
	VEHICLE_SELF				= -1,
	ACTOR_ALIVE					= 0x01,
	ACTOR_NOT_SAME_VEHICLE		= 0x02,
	VEHICLE_ALIVE				= 0x01,
	VEHICLE_EMPTY				= 0x02,
	VEHICLE_OCCUAPIED			= 0x04,
	VEHICLE_NOTBURNING			= 0x08,
	ACTOR_STATE_DRIVING			= 50,
	ACTOR_STATE_DYING			= 54,
	ACTOR_STATE_DEAD			= 55,
	ACTOR_MSTATE_STILL			= 1,
	ACTOR_MSTATE_RUN			= 6,
	ACTOR_MSTATE_RUN_FAST		= 7,
	VEHICLE_FLAGS_INVULNERABLE	= (4 | 8 | 16 | 128),
	ACTOR_FLAGS_INVULNERABLE	= (4 | 8 | 64 | 128),
	VEHICLE_TYPE_CAR			= 0,
	VEHICLE_TYPE_BOAT			= 5,
	VEHICLE_TYPE_TRAIN			= 6,
	VEHICLE_TYPE_BIKE			= 9
};

enum eClientVehicleType
{
	CLIENTVEHICLE_NONE,
	CLIENTVEHICLE_CAR,
	CLIENTVEHICLE_BOAT,
	CLIENTVEHICLE_TRAIN,
	CLIENTVEHICLE_HELI,
	CLIENTVEHICLE_PLANE,
	CLIENTVEHICLE_BIKE,
	CLIENTVEHICLE_MONSTERTRUCK,
	CLIENTVEHICLE_QUADBIKE,
	CLIENTVEHICLE_BMX,
	CLIENTVEHICLE_TRAILER
};


enum eCheatStates
{
	CHEAT_STATE_NONE,
	CHEAT_STATE_ACTOR,
	CHEAT_STATE_VEHICLE
};

enum {
	VEHICLEUPGRADE_NITRO_5X		= 1008,
	VEHICLEUPGRADE_NITRO_2X		= 1009,
	VEHICLEUPGRADE_NITRO_10X	= 1010,
	VEHICLEUPGRADE_HYDRAULICS	= 1087,
	VEHICLE_MAX_PASSENGERS		= 9,
};

#pragma pack(push, 1)

typedef struct _VECTOR
{
	float	X, Y, Z;
} VECTOR, *PVECTOR;

typedef struct _MATRIX4X4
{
	VECTOR	right;
	unsigned long	flags;
	VECTOR	up;
	float	pad_u;
	VECTOR	at; 
	float	pad_a;
	VECTOR	pos;
	float	pad_p;
} MATRIX4X4, *PMATRIX4X4;

struct detachable
{
	float	position[3];
	unsigned char __unknown_12[4];
	float	vector[3];
	unsigned char __unknown_28[16];
};

struct weapon
{
	unsigned int	id;
	unsigned int	state;
	int32_t		ammo_clip;
	int32_t		ammo;
	unsigned int	__unknown_count;
	unsigned int	__goggle;	
	unsigned int	__unknown;
};

struct object_base
{
	void	*vtbl;
	float					coords[3];		
	union
	{
		float			m_heading;	
		void			*m_CMatrixPre;		
		float			*preMatrix;				
		MATRIX4X4		*preMatrixStruct;		
	};
	union
	{
		void			*m_CMatrix;				
		float			*matrix;				
		MATRIX4X4		*matrixStruct;			
	};

	void				*m_pRwObject;				

	unsigned long	bUsesCollision : 1;			
	unsigned long	bCollisionProcessed : 1;	
	unsigned long	bIsStatic : 1;			
	unsigned long	bHasContacted : 1;	
	unsigned long	bIsStuck : 1;			
	unsigned long	bIsInSafePosition : 1;	
	unsigned long	bWasPostponed : 1;		
	unsigned long	bIsVisible : 1;			
	unsigned long	bIsBIGBuilding : 1;		
	unsigned long	bRenderDamaged : 1;		
	unsigned long	bStreamingDontDelete : 1;	
	unsigned long	bRemoveFromWorld : 1;		
	unsigned long	bHasHitWall : 1;			
	unsigned long	bImBeingRendered : 1;		
	unsigned long	bDrawLast : 1;			
	unsigned long	bDistanceFade : 1;	
	unsigned long	bDontCastShadowsOn : 1; 
	unsigned long	bOffscreen : 1;			
	unsigned long	bIsStaticWaitingForCollision : 1;	
	unsigned long	bDontStream : 1;			
	unsigned long	bUnderwater : 1;		
	unsigned long	bHasPreRenderEffects : 1;
	unsigned long	bIsTempBuilding : 1;		
	unsigned long	bDontUpdateHierarchy : 1;	
	unsigned long	bHasRoadsignText : 1;		
	unsigned long	bDisplayedSuperLowLOD : 1;
	unsigned long	bIsProcObject : 1;			
	unsigned long	bBackfaceCulled : 1;		
	unsigned long	bLightObject : 1;		
	unsigned long	bUnimportantStream : 1;		
	unsigned long	bTunnel : 1;			
	unsigned long	bTunnelTransition : 1;	

	unsigned char			wSeedColFlags;		
	unsigned char			wSeedVisibleFlags;		
	unsigned short		model_alt_id;		
	unsigned char			__unknown_36[4];	

	unsigned int		*m_pLastRenderedLink;
	unsigned short		timer;			
	unsigned char			m_iplIndex;		
	unsigned char			interior_id;
	unsigned char			__unknown_48[6];	

	unsigned char			nType : 3;			
	unsigned char			nStatus : 5;		

	unsigned char			__unknown_56[8];	
	unsigned char			quantumPhysics;		
	unsigned char			nImmunities;			
	unsigned char			__unknown_66;			
};

struct actor_info
{
	struct object_base	base;				
	unsigned char				flags;				
	unsigned char				__unknown_67[1];	
	union	
	{
		float	speed[3];
		struct
		{
			D3DXVECTOR3 m_SpeedD3DVec;
		};
	};
	float				spin[3];			
	float				speed_rammed[3];	
	float				spin_rammed[3];		
	unsigned char				__unknown_116[60];	
	void				*__unknown_176;		
	void				*__unknown_180;		

	unsigned long				collision_flags;	
	void				*last_touched_object;	
	void				*last_collided_object;	
	unsigned char				__unknown_196[16];		
	float				speed_z;			
	float				collision_time_216; 
	void				*collision_current_obj;		
	unsigned char				collision_something[12];	
	float				collision_last_coord[3];	

	unsigned char				__unknown_248[100];
	unsigned char				animation_state;			
	unsigned char				__unknown_349[7];			
	float				step_pos[3];		
	float				step_pos_before[3]; 
	unsigned char				__unknown_380[752]; 

	unsigned char			pedFlags[16];			
	void *pPedIntelligence; 
	void  *pPlayerData; 

	unsigned char				__unknown_1156[8]; 

	void				*pNeck;			
	void				*pHead;				
	void				*pLeftArm;			
	void				*pRightArm;			
	void				*pLeftLowArm;	
	void				*pRightLowArm;	
	void				*pLeftLeg;			
	void				*pRightLeg;		
	void				*pLeftLowLeg;		
	void				*pRightLowLeg;		
	void				*pRightMidLeg;		
	void				*pLeftMidLeg;	
	void				*pLeftMidArm;		
	void				*pRightMidArm;	
	void				*pLeftShoulder;		
	void				*pRightShoulder;	
	void				*pChest;			
	void				*pMouth;		

	unsigned char				runningStyle;		
	unsigned char				__unknown_1237[7];
	float				runspeed;		
	unsigned char				__unknown_1248[36];
	unsigned short			muzzle_flash;		
	unsigned char				__unknown_1286[6];	

	unsigned char				pedIK[32];	
	unsigned char				__unknown_1324[4];	

	unsigned int			state;	
	unsigned int			mstate; 
	unsigned char				__unknown_1336[8];	
	float				hitpoints;		
	float				hitpoints_max;		
	float				armor;
	unsigned char				__unknown_1356[12];	

	float				fCurrentRotation;		
	float				fTargetRotation;	
	float				fRotationSpeed;			
	float				fRotationCalculation;	

	union
	{
		void	*pContactEntity;	
		struct vehicle_info *vehicle_contact;	
	};

	float	vehicle_contact_dist[3];			
	float	fPlaneAnglesContactEntity[3];	
	void	*item_contact;						
	float	fUnknown_1416;					

	union
	{
		struct vehicle_info *vehicle;
	};

	unsigned char				__unknown_1424[8];	
	unsigned char				actor_lock;		
	unsigned char				__unknown_1433[7];	
	struct weapon		weapon[13];			
	unsigned char				__unknown_1804[12];
	unsigned char				weapon_slot;	
	unsigned char				__unknown_1817[3];	
	void				*ptr_autoAimTarget;	
	float				fImpactPos_close[3];
	unsigned char				__unknown_1836[20]; 
	unsigned int			weapon_model;		
	unsigned char				__unknown_1860[28]; 
	unsigned int			weapon_hit_type;	
	struct actor_info	*weapon_hit_by;	
	unsigned char				__unknown_1889[92]; 
};	

struct vehicle_info
{
	struct object_base			base;
	unsigned char						flags;			
	unsigned char						__unknown_67;	
	float						speed[3];
	float						spin[3];
	float						speed_rammed[3];	
	float						spin_rammed[3];		

	unsigned char						__unknown_116[20];

	unsigned char						__unknown_136[4];	
	float						mass;	
	float						turn_mass;	
	float						grip_div;	
	float						mass_to_grip_mult;		
	float						fTurnMass;				
	float						grip_level_norm;		
	float						center_of_mass[3];		
	void						*__unknown_176;			
	void						*__unknown_180;		

	unsigned long						collision_flags;		
	void						*last_touched_object;	
	void						*last_collided_object;	
	unsigned char						__unknown_196[20];	
	float						collision_something;	
	void						*collision_current_obj;

	unsigned char						__unknown_224[12];		
	float						collision_position[3];
	unsigned char						__unknown_248[68];	
	void						*__unknown_316;			
	unsigned char						__unknown_320[157];
	unsigned char						in_vehicle;			
	unsigned char						__unknown_478[422];

	void						*pHandlingData;		
	struct physicalFlyParams	*pFlyData;			
	unsigned char						__unknown_908[96];	
	unsigned int					hFlagsLocal;		
	unsigned char						__unknown_1008[56];
	unsigned char						m_nVehicleFlags[8];
	unsigned int					m_TimeOfCreation;	

	unsigned char						color[4];			
	unsigned char						modding[2];			
	unsigned short				UpgradeModelID[15];	
	float						wheel_size;		
	unsigned short				CarAlarmState;		
	unsigned short				ForcedRandomSeed;
	struct actor_info			*passengers[9];		

	unsigned char				m_nNumPassengers;	
	unsigned char				m_nNumGettingIn;	
	unsigned char				m_nGettingInFlags;	
	unsigned char				m_nGettingOutFlags; 
	unsigned char				m_nMaxPassengers;	
	unsigned char				m_windowsOpenFlags; 
	char						m_nNitroBoosts;		
	char						m_nSpecialColModel; 
	unsigned long						*pEntityWeAreOnForVisibilityCheck;	
	unsigned long						*m_pFire;			

	float						steer_angles[2];	
	float						gas_pedal;			
	float						break_pedal;		

	unsigned char				VehicleCreatedBy;	 
	short						ExtendedRemovalRange;

	unsigned char						__unknown_1191;

	unsigned char				car_bomb : 3;		
	unsigned char				OverrideLights : 2; 
	unsigned char				WinchType : 2;		

	unsigned char						__unknown_1193;

	unsigned char				m_GunsCycleIndex : 2;		
	unsigned char				m_OrdnanceCycleIndex : 2;

	unsigned char				nUsedForCover;			
	unsigned char				AmmoInClip;			
	unsigned char				PacMansCollected;
	unsigned char				PedsPositionForRoadBlock;
	unsigned char				NumPedsForRoadBlock;

	float						nBodyDirtLevel;			

	unsigned char				m_nCurrentGear;			
	float						m_fGearChangeCount;		
	float						m_fWheelSpinForAudio;
	unsigned char						__unknown_1213[3];		

	float						hitpoints;			
	void						*pulling_truck;		
	struct vehicle_info			*trailer;		
	unsigned char						__unknown_1228[44]; 
	unsigned int					door_status;		
	unsigned char						__unknown_1276[148];	
	unsigned char						vehicle_type;			
	unsigned char						__unknown_1425[19];		

	union
	{
		struct
		{
			float	m_fTrainSpeed;			
			float	m_fTrainRailDistance;	
			float	m_fDistanceToNextCarriage;		
		};
		struct
		{
			unsigned char boat_sound_level;				
			unsigned char car_tire_status[4];				
			unsigned char door_damage_status[6];		
		};
	};

	unsigned char		lights_status_frontLeft : 1;
	unsigned char		__unknown_lights_status_2 : 1;
	unsigned char		lights_status_frontRight : 1;
	unsigned char		__unknown_lights_status_4 : 3;
	unsigned char		lights_status_rear : 1;

	unsigned char				__unknown_1457[3];		

	unsigned char		car_status_left : 4;	
	unsigned char		car_status_right : 4;
	unsigned char				car_bumper_status;			
	unsigned char		car_windshield_status : 4;
	unsigned char		car_bumper_status_front : 4;
	unsigned char				car_bumper_status_rear;

	unsigned char				m_trainFlags[4];			
	unsigned char				__unknown_1468[8];		
	float				doorHood_dist;			
	unsigned char				__unknown_1480[4];		
	float				doorHood_dist_two;		
	unsigned char				__unknown_1488[4];			
	struct vehicle_info *m_train_next_carriage;		
	unsigned char				__unknown_1496[4];			
	float				doorTrunk_dist;			
	unsigned char				__unknown_1504[4];		
	float				doorTrunk_dist_two;		
	unsigned char				__unknown_1512[12];			
	float				doorOne_dist;				
	unsigned char				__unknown_1528[4];			
	union
	{
		struct detachable	detachable_bike1[1];	
		struct
		{
			float	doorOne_dist_two;			
			unsigned char __unknown_1536[12];			
			float	doorTwo_dist;				
			unsigned char __unknown_1552[4];			
			float	doorTwo_dist_two;			
			unsigned char __unknown_1560[12];			
			float	doorThree_dist;				
			unsigned char __unknown_1576[4];			
			float	doorThree_dist_two;			
			unsigned char __unknown_1584[12];			
			float	doorFour_dist;				
			unsigned char __unknown_1600[6];			
			float	doorFour_dist_two;			
		};
	};
	unsigned char				__unknown_1610[18];		
	unsigned char				bike_tire_status[2];	
	unsigned char				__unknown_1630[2];		

	struct detachable	detachable_bike2[4];	
	unsigned char				__unknown_1808[8];		
	float				fPos_FireCarLadder[3];	
	struct detachable	detachable_car[4];		
	unsigned char				__unknown_2004[12];		
	float				suspension[4];			
	unsigned char				__unknown_2032[244];	
	float				burn_timer;				
	unsigned char				__unknown_2280[100];	
	float				fCannonAimX_Y[2];		
	unsigned char				__unknown_2388[48];		
	float				fHeliDistanceToGround;	
	unsigned char				__unknown_2440[24];		
	float				fHeliMainRotorDistance;	
	float				fHeliSecRotorDistance;	
	unsigned char				__unknown_2472[88];		
	unsigned char				SmokeTrailEnabled;		
	unsigned char				__unknown_2561[23];		

};

struct object_info
{
	struct object_base	base;
	unsigned char				__unknown_66;			
	unsigned char				flags;	
	unsigned char				__unknown_68[7];	
	float				physical_height;	
	unsigned char				__unknown_79[173];	
	struct actor_info	*actor; 
	unsigned char				__unknown_256[8];	
	float				height_to_actor;	
	unsigned char				__unknown_268[4];	
	float				pitch;	
	float				roll;	
	unsigned char				__unknown_280[68];	
	float				scale;	
	unsigned char				__unknown_352[59];	
};

struct physicalFlyParams
{
	float	__itsNull;	
	float	heightIncreaseRel[2];	
	float	circleAround;			
	float	changeDir;		
	float	changeDir_side; 
	float	roll_lr;		
	float	__unknown_28;	
	float	pitch;			
	float	__unknown_36;	
	float	_multPitch;		
	float	finalPitch_;
	float	_unknownMultipliers_isOne[2];	
	float	_orientationMultiplier;			
	float	_SpeedMultiplier_isOne;		
	float	pitchMultiplier;	
	float	rollMultiplier;		
	float	circleMultiplier;	
};

struct checkpoint
{
	unsigned int	__unknown1;		
	unsigned int	counter;		
	unsigned int	color;			
	unsigned int	__unknown2;		
	float		position[3];
	float		rotation[3];	
	float		zero_point_two;
	float		radius;			
	unsigned int	__unknown3;		
	unsigned int	__unknown4;		
};

struct vehicle_state
{
	float					matrix[16];
	float					speed[3];
	float					spin[3];
	struct vehicle_state	*trailer;
	struct vehicle_info		*trailerPtr;
};

#pragma pack(pop)