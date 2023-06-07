#pragma once
#include "Collider/SphereCollider.h"
#include "common.h"

class ObstacleBase :
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
	ObstacleBase(Location location, float radius, float speed, int score);

protected:
	float speed;		//移動速度
	bool isBroken;		//壊れたかどうか
	bool isShow;		//映す映さない
	int score;			//スコア

public:
	virtual void Update() = 0;
	virtual void Draw()const = 0;

	bool GetIsBroken()const { return isBroken; }
	void ToggleIsBroken() { isBroken = !isBroken; }
	bool GetIsShow()const { return isShow; }
	void ToggleIsShow() { isShow = !isShow; }
	int GetScore() const { return score; }
};

