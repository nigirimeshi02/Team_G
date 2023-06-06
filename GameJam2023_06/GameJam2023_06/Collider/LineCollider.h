#pragma once
#include "ColliderBase.h"
#include "../Location.h"

#define _USE_MATH_DEFINES
#include <math.h>

#define LINE_START 0
#define LINE_END 1

class LineCollider :public ColliderBase
{
public:
	LineCollider();
	LineCollider(Location point1, Location point2);
	~LineCollider();

protected:
	Location vector[2];	//���S������̒[�̍��W�܂ł̃x�N�^�[(0:�n�_,1:�I�_)

public:
	//�`��
	virtual void Draw()const;

	//�_�Ƃ̓����蔻��
	bool HitDot(Location point)const;

	//SphereCollider�Ƃ̓����蔻��
	bool HitSphere(const class SphereCollider* sphere_collider)const override;

	//BoxCollider�Ƃ̓����蔻��
	bool HitBox(const class BoxCollider* box_collider)const override;

	//LineCollider�Ƃ̓����蔻��
	bool HitLine(const class LineCollider* line_collider)const override;

	//���̒[�̍��W�̎擾
	Location GetLocation(int i)const;	//�I�[�o�[���[�h

	//�n�_�A�I�_���W�̐ݒ�
	void SetLocation(Location location, int i);


	//������Ίp���Ƃ�����`�̍���̍��W��Ԃ�
	Location GetMin()const;

	//������Ίp���Ƃ�����`�̉E���̍��W��Ԃ�
	Location GetMax()const;

	//���S���W����Ώۂ̍��W�܂ł̃x�N�g����Ԃ�
	Location GetVector(int index)const;

private:

	//���_��Ԃ�
	Location GetMiddlePoint()const;

	//���W�𒆐S���W����̃x�N�^�[�ɑ��Ή�����
	void Relativize();

	//�����̒[�̐�΍��W��Ԃ�
	Location MakeTip(int index)const;


};