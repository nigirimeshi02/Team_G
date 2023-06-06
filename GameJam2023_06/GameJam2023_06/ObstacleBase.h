#pragma once
#include "Collider/SphereCollider.h"
#include "common.h"

class ObstacleBase:
	public SphereCollider
{
	/*
	* ColliderBase:
	*	E_Collider colliderType;
	*	Location location;		//中心座標
	* SphereCollider:
	* 	float radius;			//半径
	*/
public:
	ObstacleBase();
	~ObstacleBase();
	ObstacleBase(Location location,float radius);


protected:
	float speed;		//移動速度
	bool isBroken;		//壊れたかどうか
	int score;		//スコア加算

public:
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	bool GetIsBroken()const { return isBroken; }
	void ToggleIsBroken() { isBroken = !isBroken; }
 
};

