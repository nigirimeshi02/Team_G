#pragma once
#include "../Location.h"
#include "E_Collider.h"

#define _USE_MATH_DEFINES
#include <math.h>

class SphereCollider;
class BoxCollider;
class LineCollider;

class ColliderBase
{

public:

	ColliderBase(Location location = { 100,100 })
	{
		this->location = location;
	}

protected:

	E_Collider colliderType;
	Location location;	//���S���W

	//2�̃x�N�g���̂Ȃ��p���s�p���ǂ��������߂�
	bool CheckIsAcute(Location vector1, Location vector2)const;

	//�󂯎�����x�N�^�[�̃X�J����Ԃ�
	float MakeScalar(Location vector)const;

	//�����P��������Q�ɑ΂���O�ς�Ԃ�
	float MakeCrossProduct(Location vector1, Location vector2)const;

public:

	//���S���W�̎擾
	Location GetLocation()const
	{
		return location;
	}
	//���S���W�̐ݒ�
	virtual void SetLocation(Location location)
	{
		this->location = location;
	}

	//SphereCollider�Ƃ̓����蔻��
	virtual bool HitSphere(const SphereCollider* sphere_collider) const = 0;

	//BoxCollider�Ƃ̓����蔻��
	virtual bool HitBox(const BoxCollider* box_collider) const = 0;

	//LineCollider�Ƃ̓����蔻��
	virtual bool HitLine(const LineCollider* line_collider)const = 0;

	bool HitCheck(const ColliderBase* collider)const;

	virtual void Draw()const = 0;

	E_Collider GetColliderType()const { return colliderType; };

};

