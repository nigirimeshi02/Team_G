#pragma once
#include "Collider/SphereCollider.h"
#include "common.h"

class BaseThatDrop:
	public SphereCollider
{
	/*
	* ColliderBase:
	*	E_Collider colliderType;
	*	Location location;	//���S���W
	* SphereCollider:
	* 	float radius;			//���a
	*/
public:
	BaseThatDrop();
	~BaseThatDrop();
	BaseThatDrop(Location location,float radius);

private:
	float speed;
};

