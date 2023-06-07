#pragma once
#include "ColliderBase.h"
#include "../Area.h"
class BoxCollider :
	public ColliderBase
{

protected:
	Area area; //�͈�

public:
	BoxCollider(Location location = Location{}, Area area = Area{ 100,100 });
	~BoxCollider();

	virtual void Draw()const;

	//SphereCollider�Ƃ̓����蔻��
	bool HitSphere(const class SphereCollider* sphere_collider) const override;

	//BoxCollider�Ƃ̓����蔻��
	bool HitBox(const class BoxCollider* box_collider) const override;

	//LineCollider�Ƃ̓����蔻��
	bool HitLine(const class LineCollider* line_collider) const override;

	//PolyLine�Ƃ̓����蔻��
	//virtual bool HitPolyLine(const class PolyLine* poly_line)const override;

	//���S���W�̎擾
	Location GetLocation()const;

	//�͈͂̎擾
	Area GetArea()const;

	//����̍��W���擾
	Location GetMin()const
	{
		return Location{ location.x - area.width / 2,location.y - area.height / 2 };
	}
	//�E���̍��W���擾
	Location GetMax()const
	{
		return Location{ location.x + area.width / 2,location.y + area.height / 2 };
	}

};

