#include "SphereCollider.h"
#include "BoxCollider.h"
#include "LineCollider.h"
#include "DxLib.h"

#define _USE_MATH_DEFINES
#include <math.h>

//---------------------
// �`��
//---------------------
void SphereCollider::Draw()const
{

	DrawCircleAA(
		GetLocation().x
		,GetLocation().y
		,GetRadius(), 10, GetColor(128, 128, 128), TRUE);
}

bool SphereCollider::HitSphere(const SphereCollider* sphere_collider) const
{

	bool ret = false;//�Ԃ�l
	float distance;	//���S���W�̋���

	//���S���W�̋����̌v�Z
	distance = sqrtf(powf(sphere_collider->GetLocation().x - location.x, 2) + powf(sphere_collider->GetLocation().y - location.y, 2));

	if (distance < radius + sphere_collider->GetRadius()) //�����蔻��
	{
		ret = true;
	}

	return ret;
}

bool SphereCollider::HitBox(const BoxCollider* box_collider) const
{

	bool ret = false; //�Ԃ�l
	float rad; //2�_�̊p�x
	float sphere_x; //�~�̍��W(x)
	float sphere_y; //�~�̍��W(y)

	//����̓����蔻��͈̔�
	float sub_x[2];
	float sub_y[2];

	//�p�x�̌v�Z
	rad = atan2f(box_collider->GetLocation().y - location.y, box_collider->GetLocation().x - location.x);

	//���W�̌v�Z
	sphere_x = location.x + (radius * cosf(rad));
	sphere_y = location.y + (radius * sinf(rad));

	//����̓����蔻��͈̔͂̌v�Z
	sub_x[0] = box_collider->GetLocation().x - (box_collider->GetArea().width / 2);
	sub_y[0] = box_collider->GetLocation().y - (box_collider->GetArea().height / 2);
	sub_x[1] = sub_x[0] + box_collider->GetArea().width;
	sub_y[1] = sub_y[0] + box_collider->GetArea().height;

	if ((sub_x[0] <= sphere_x) && (sphere_x <= sub_x[1]) && (sub_y[0] <= sphere_y) && (sphere_y <= sub_y[1])) //�����蔻��
	{
		ret = true;
	}

	return ret;
}

bool SphereCollider::HitLine(const LineCollider* line_collider) const
{
	bool is_hit = false;
	Location vector1 =
		line_collider->GetLocation(LINE_END)
		- line_collider->GetLocation(LINE_START);
	Location vector2 =
		GetLocation() - line_collider->GetLocation(LINE_START);

	float len = powf(vector1.x * vector1.x + vector1.y * vector1.y, 0.5);

	Location unit_vector;
	unit_vector.x = vector1.x / len;
	unit_vector.y = vector1.y / len;

	float distance_near_pos = unit_vector.x * vector2.x
		+ unit_vector.y * vector2.y;

	Location near_pos;

	near_pos.x = unit_vector.x * distance_near_pos;
	near_pos.y = unit_vector.y * distance_near_pos;

	float distance_sphere_near_pos;

	distance_sphere_near_pos =
		powf(powf(near_pos.x - vector2.x, 2.0) + powf(near_pos.y - vector2.y, 2.0), 0.5);

	if (distance_sphere_near_pos > GetRadius())
	{
		return false;
	}

	bool is_start_acute =
		CheckIsAcute(line_collider->GetLocation(LINE_END)
			- line_collider->GetLocation(LINE_START), vector2);
	bool is_end_acute
		= CheckIsAcute(
			line_collider->GetLocation(LINE_END)
			- line_collider->GetLocation(LINE_START)
			, GetLocation() - line_collider->GetLocation(LINE_END));

	if (is_start_acute ^ is_end_acute)
	{
		is_hit = true;
	}

	float distance_tips_sphere
		= MakeScalar(GetLocation() - line_collider->GetLocation(LINE_START));
	if (distance_tips_sphere <= GetRadius())
	{
		is_hit = true;
	}
	distance_tips_sphere
		= MakeScalar(GetLocation() - line_collider->GetLocation(LINE_END));
	if (distance_tips_sphere <= GetRadius())
	{
		is_hit = true;
	}

	return is_hit;
}
