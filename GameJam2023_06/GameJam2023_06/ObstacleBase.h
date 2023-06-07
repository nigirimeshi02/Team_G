#pragma once
#include "Collider/SphereCollider.h"
#include "common.h"

class ObstacleBase :
	public SphereCollider
{
	/*
	* ColliderBase:
	*	E_Collider colliderType;
	*	Location location;		//���S���W
	* SphereCollider:
	* 	float radius;			//���a
	*/
public:
	ObstacleBase();
	~ObstacleBase();
	ObstacleBase(Location location, float radius, float speed, int score);
	

protected:
	float speed;		//�ړ����x
	bool isBroken;		//��ꂽ���ǂ���
	int score;

public:
	virtual void Update() = 0;
	virtual void Draw()const = 0;

	bool GetIsBroken()const { return isBroken; }
	void ToggleIsBroken() { isBroken = !isBroken; }
};

