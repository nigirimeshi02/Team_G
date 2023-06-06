#pragma once
#include "ColliderBase.h"

class SphereCollider :public ColliderBase
{
protected:
/*
* ColliderBase:
*	E_Collider colliderType;
*	Location location;	//���S���W
*/
	float radius;			//���a
public:

	SphereCollider() :ColliderBase()
	{
		SphereCollider({ 5,5 });
	}

	SphereCollider(Location location, float radius = 5.f) :ColliderBase(location)
	{
		colliderType = E_Collider::Sphere;
		this->radius = radius;
	}

	//�`��
	virtual void Draw()const;

	//SphereCollider�Ƃ̓����蔻��
	bool HitSphere(const SphereCollider* sphere_collider) const override;

	//BoxCollider�Ƃ̓����蔻��
	bool HitBox(const BoxCollider* box_collider) const override;

	//LineCollider�Ƃ̓����蔻��
	bool HitLine(const LineCollider* line_collider) const override;

	//���S���W�̎擾
	Location GetLocation() const
	{
		return location;
	}

	//���a�̎擾
	float GetRadius() const
	{
		return radius;
	}

	//���S���W�̐ݒ�
	void SetLocation(Location location)
	{
		this->location = location;
	}
};