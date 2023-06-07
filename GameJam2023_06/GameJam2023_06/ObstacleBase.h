#pragma once
#include "Collider/SphereCollider.h"
#include "common.h"

class ObstacleBase :
	public SphereCollider
{
	/*
	* ColliderBase:
	*	E_Collider colliderType;
	*	Location location;		//’†SÀ•W
	* SphereCollider:
	* 	float radius;			//”¼Œa
	*/
public:
	ObstacleBase();
	~ObstacleBase();
	ObstacleBase(Location location, float radius, float speed, int score);
	

protected:
	float speed;		//ˆÚ“®‘¬“x
	bool isBroken;		//‰ó‚ê‚½‚©‚Ç‚¤‚©
	int score;

public:
	virtual void Update() = 0;
	virtual void Draw()const = 0;

	bool GetIsBroken()const { return isBroken; }
	void ToggleIsBroken() { isBroken = !isBroken; }
};

