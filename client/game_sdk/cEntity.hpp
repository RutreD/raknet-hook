#pragma once

#include "cTypes/cTypes.hpp"
#include "cPlaceable.hpp"

enum eEntityType {

	ENTITY_TYPE_NOTHING,
	ENTITY_TYPE_BUILDING,
	ENTITY_TYPE_VEHICLE,
	ENTITY_TYPE_PED,
	ENTITY_TYPE_OBJECT,
	ENTITY_TYPE_DUMMY,
	ENTITY_TYPE_NOTINPOOLS

};

enum eEntityStatus {

	STATUS_PLAYER,
	STATUS_PLAYER_PLAYBACKFROMBUFFER,
	STATUS_SIMPLE,
	STATUS_PHYSICS,
	STATUS_ABANDONED,
	STATUS_WRECKED,
	STATUS_TRAIN_MOVING,
	STATUS_TRAIN_NOT_MOVING,
	STATUS_HELI,
	STATUS_PLANE,
	STATUS_PLAYER_REMOTE,
	STATUS_PLAYER_DISABLED,
	STATUS_TRAILER,
	STATUS_SIMPLE_TRAILER

};

class cEntity : public cPlaceable {

public:

	unsigned long   ptr_RwObject;
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
	unsigned short			modelID;
	unsigned char			__unknown_36[4];
	unsigned int			*m_pLastRenderedLink;	
	unsigned short			timer;			
	unsigned char			m_iplIndex;		
	unsigned char			interior_id;
	unsigned char			__unknown_48[6];
	unsigned char			nType : 3;
	unsigned char			nStatus : 5;
	unsigned char			__unknown_56[8];
	unsigned char			quantumPhysics;

	virtual int		__add_CRect() = 0;
	virtual void	add() = 0;
	virtual int		remove() = 0;
	virtual void	setIsStatic(bool state) = 0;
	virtual void	setModelIndex(eModelIndex index) = 0;
	virtual void	*setModelIndexNoCreate(eModelIndex index) = 0;
	virtual int		createRwObject() = 0;
	virtual void	deleteRwObject() = 0;
	virtual cRect	*getBoundRect(cRect *rect) = 0;
	virtual int		processControl() = 0;
	virtual int		__processCollision() = 0;
	virtual int		processShift() = 0;
	virtual bool	_testCollision(char a2) = 0;
	virtual bool	Teleport(float X, float Y, float Z, bool lockRotate = true) = 0;
	virtual bool	_specialEntityPreCollisionStuff(int a1, int a2, int a3, int a4, int a5, int a6) = 0;
	virtual bool	_SpecialEntityCalcCollisionSteps(int a1, int a2) = 0;
	virtual void	preRender() = 0;
	virtual void	render() = 0;
	virtual bool	setupLighting() = 0;
	virtual bool	_removeLighting(bool a2 = true) = 0;
	virtual void	flagToDestroyWhenNextProcessed() = 0;

	auto Teleport(cVector3D vecPos, bool lockRotate = true) -> void;
	auto IsPed() -> bool;
	auto IsVehicle() -> bool;
	auto IsOnScreen() -> bool;
	auto IsUnderWater() -> bool;
	auto IsVisible() -> bool;
	auto SetVisible(bool bVisible) -> void;
	auto IsUsesCollision() -> bool;
	auto SetUsesCollision(bool bCollision) -> void;

};