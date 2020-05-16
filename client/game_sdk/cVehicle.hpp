#pragma once

#include "cTypes/cTypes.hpp"
#include "cPed.hpp"

enum cVehicleOffsets {
	isBoat		= 0x4C5A70,
	isCar		= 0x4C5AA0,
	isTrain		= 0x4C5AD0,
	isHeli		= 0x4C5B00,
	isPlane		= 0x4C5B30,
	isBike		= 0x4C5B60,
	isFake		= 0x4C5B90,
	isMonster	= 0x4C5BC0,
	isQuad		= 0x4C5BF0,
	isBMX		= 0x4C5C20,
	isTrailer	= 0x4C5C50,
	lockVehicle = 0x5433B0,
	setVelocity = 0x45AFB0
};

class cVehicle : public cPhysical {

public:

	void						*__unknown_316;		
	unsigned char						__unknown_320[157];	
	unsigned char						in_vehicle;			
	unsigned char						__unknown_478[422];

	void						*pHandlingData;		
	class physicalFlyParams	*pFlyData;			
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

	class cPed					*driver;
	class cPed					*passenger_FrontRight; 
	class cPed					*passenger_RearLeft; 
	class cPed					*passenger_RearRight; 
	class cPed					*passengers_additional[5];

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
	class vehicle_info			*trailer;			
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
	class vehicle_info *m_train_next_carriage;	
	unsigned char				__unknown_1496[4];			
	float				doorTrunk_dist;			
	unsigned char				__unknown_1504[4];			
	float				doorTrunk_dist_two;			
	unsigned char				__unknown_1512[12];	
	float				doorOne_dist;				
	unsigned char				__unknown_1528[4];			
	union
	{
		struct cDetachable *detachable_bike1[1];	
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

	struct cDetachable	detachable_bike2[4];	
	unsigned char				__unknown_1808[8];	
	float				fPos_FireCarLadder[3];
	struct cDetachable	detachable_car[4];	
	unsigned char				__unknown_2004[12];		
	float				suspension[4];			
	unsigned char				__unknown_2032[92];	
	float				fHeliRotorSpeed;	
	unsigned char				__unknown_2128[84];	
	float			   fNitroValue;			
	unsigned char				__unknown_2216[60];	
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

	virtual void _processControlCollisionCheck(char a1) = 0;
	virtual void _processControlInputs(bool a2) = 0;
	virtual void getComponentWorldPosition(int id, cVector3D *pos) = 0;
	virtual bool isComponentPresent(int id) = 0;
	virtual bool _openDoor(int a2, int a3, int a4, float a5, char a6) = 0;
	virtual void _processOpenDoor(int a2, float a3, float a4, float a5, float a6) = 0;
	virtual long double getDoorAngleOpenRatio(int id) = 0;
	virtual void _getDoorAngleOpenRatio(int id) = 0;
	virtual bool isDoorReady(int id) = 0;
	virtual bool _isDoorReady(int id) = 0;
	virtual bool isDoorFullyOpen(int id) = 0;
	virtual bool _isDoorFullyOpen(int id) = 0;
	virtual bool isDoorClosed(int id) = 0;
	virtual bool _isDoorClosed(int id) = 0;
	virtual bool isDoorMissing(int id) = 0;
	virtual bool _isDoorMissing(int id) = 0;
	virtual bool isOpenTopCar() = 0;
	virtual void _removeRefsToVehicle(int a1) = 0;
	virtual void _blowUpCar(int frame, bool a2) = 0;
	virtual void _blowUpCarCutSceneNoExtras(int a1, int a2, int a3, int a4) = 0;
	virtual bool _setUpWheelColModel(int a1) = 0;
	virtual bool _burstTyre(unsigned char nWheel, bool state) = 0;
	virtual bool __isRoomForPedToLeaveCar() = 0;
	virtual void _processDrivingAnims(class CPed* ped, bool a3) = 0;
	virtual char* getRideAnimData() = 0;
	virtual void setupSuspensionLines() = 0;
	virtual cVector3D* _addMovingCollisionSpeed(cVector3D *a2, cVector3D *a3) = 0;
	virtual void fix() = 0;
	virtual int setupDamageAfterLoad() = 0;
	virtual void doBurstAndSoftGroundRatios() = 0;
	virtual long double getHeightAboveRoad() = 0;
	virtual bool playCarHorn() = 0;
	virtual int getNumContactWheels() = 0;
	virtual void _vehicleDamage(int a1, int a2, int a3, int a4, int a5, int a6) = 0;
	virtual bool canPedStepOutCar(unsigned char passengerId) = 0;
	virtual bool canPedJumpOutCar(unsigned char passengerId) = 0;
	virtual bool getTowHitchPos(cVector3D* pos, bool get, cEntity *pEntity) = 0;
	virtual bool getTowBarPos(cVector3D* pos, bool get, cEntity *pEntity) = 0;
	virtual bool SetTowLink(cEntity *pEntity, bool set) = 0;
	virtual bool breakTowLink() = 0;
	virtual long double _findWheelWidth(bool a1) = 0;
	virtual bool save() = 0;
	virtual bool load() = 0;

	auto getHitpoints() -> float;
	auto setHitpoints(float fHealth) -> void;
	auto repairCar() -> void;

	auto isBoat() -> bool;
	auto isCar() -> bool;
	auto isTrain() -> bool;
	auto isHeli() -> bool;
	auto isPlane() -> bool;
	auto isBike() -> bool;
	auto isFakePlane() -> bool;
	auto isMonsterTruck() -> bool;
	auto isQuadBike() -> bool;
	auto isBMX() -> bool;
	auto isTrailer() -> bool;

	auto lockVehicle() -> bool;
	auto setAngularVelocity(cVector3D angularVelocity) -> float;

};