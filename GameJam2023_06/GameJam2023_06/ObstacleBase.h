#pragma once
#include "Collider/SphereCollider.h"
#include "common.h"

class ObstacleBase:
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
	ObstacleBase(Location location,float radius);


protected:
	float speed;		//�ړ����x
	bool isBroken;		//��ꂽ���ǂ���
	int score;		//�X�R�A���Z

public:
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	bool GetIsBroken()const { return isBroken; }
	void ToggleIsBroken() { isBroken = !isBroken; }
 
};

