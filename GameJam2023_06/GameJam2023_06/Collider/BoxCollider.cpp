#include "BoxCollider.h"
#include "DxLib.h"

/*
* �f�t�H���g�R���X�g���N�^
* Location ColliderBase ���S���W
* Area		BoxCollider	 �͈�
*/
BoxCollider::BoxCollider(Location location = Location{}, Area area = Area{ 100,100 })
	:ColliderBase(location)
{
	colliderType = E_Collider::Box;
	this->area = area;

}

//-----------------------------------
// �f�X�g���N�^
//-----------------------------------
BoxCollider::~BoxCollider()
{

}


/*
* �`��֐�
* �q�N���X����ĂԂ��Ƃœ����蔻��̕`�������
*/
void BoxCollider::Draw()const
{
	Location min = GetMin();
	Location max = GetMax();
	DrawBoxAA(
		min.x,min.y
		,max.x,max.y
		,0xFFFF00, FALSE, 3.f);
}

//-----------------------------------
// SphereCollider�Ƃ̓����蔻��
//-----------------------------------
bool BoxCollider::HitSphere(const class SphereCollider* sphere_collider) const
{

	//bool ret = false;//�Ԃ�l
	//float rad; //2�_�̊p�x
	//float sphere_x; //�~�̍��W(x)
	//float sphere_y; //�~�̍��W(y)

	////�����̓����蔻��͈̔�
	//float my_x[2];
	//float my_y[2];

	////�p�x�̌v�Z
	//rad = atan2f(location.y - sphere_collider->GetLocation().y,
	//	location.x - sphere_collider->GetLocation().x);

	////���W�̌v�Z
	//sphere_x = sphere_collider->GetLocation().x
	//	+ (sphere_collider->GetRadius() * cosf(rad));
	//sphere_y = sphere_collider->GetLocation().y
	//	+ (sphere_collider->GetRadius() * sinf(rad));

	////�����̓����蔻��͈̔͂̌v�Z
	//my_x[0] = location.x - (area.width / 2);
	//my_y[0] = location.y - (area.height / 2);
	//my_x[1] = my_x[0] + area.width;
	//my_y[1] = my_y[0] + area.height;

	//if ((my_x[0] <= sphere_x) && (sphere_x <= my_x[1])
	//	&& (my_y[0] <= sphere_y) && (sphere_y <= my_y[1])) //�����蔻��
	//{
	//	ret = true;
	//}

	//return ret;
	return false;
}

//-----------------------------------
// BoxCollider�Ƃ̓����蔻��
//-----------------------------------
bool BoxCollider::HitBox(const BoxCollider* box_collider) const
{

	bool ret = false; //�Ԃ�l

	//�����̓����蔻��͈̔�
	float my_x[2];
	float my_y[2];

	//����̓����蔻��͈̔�
	float sub_x[2];
	float sub_y[2];

	//�����̓����蔻��͈̔͂̌v�Z
	my_x[0] = location.x - (area.width / 2);
	my_y[0] = location.y - (area.height / 2);
	my_x[1] = my_x[0] + area.width;
	my_y[1] = my_y[0] + area.height;

	//����̓����蔻��͈̔͂̌v�Z
	sub_x[0] = box_collider->GetLocation().x - (box_collider->GetArea().width / 2);
	sub_y[0] = box_collider->GetLocation().y - (box_collider->GetArea().height / 2);
	sub_x[1] = sub_x[0] + box_collider->GetArea().width;
	sub_y[1] = sub_y[0] + box_collider->GetArea().height;

	if ((my_x[0] <= sub_x[1]) &&
		(sub_x[0] <= my_x[1]) &&
		(my_y[0] <= sub_y[1]) &&
		(sub_y[0] <= my_y[1])) //�����蔻��
	{
		ret = true;
	}

	return ret;
}

//-----------------------------------
// LineCollider�Ƃ̓����蔻��
//-----------------------------------
bool BoxCollider::HitLine(const class LineCollider* line_collider) const
{
	//	bool is_hit = false;
	//	bool box_ishit = false;
	//	float sign = 0;
	//
	//	Location vertex[4] =
	//	{
	//		//�l��
	//		{GetLocation().x - GetArea().width / 2,
	//		GetLocation().y - GetArea().height / 2 },
	//
	//		{GetLocation().x + GetArea().width / 2,
	//		GetLocation().y - GetArea().height / 2 },
	//
	//		{GetLocation().x - GetArea().width / 2,
	//		GetLocation().y + GetArea().height / 2 },
	//
	//		{GetLocation().x + GetArea().width / 2,
	//		GetLocation().y + GetArea().height / 2},
	//
	//	};
	//
	//	for (int i = 0; i < 4; i++)
	//	{
	//		if ((line_collider->GetMin() <= vertex[i]) &&
	//			vertex[i] <= line_collider->GetMax())
	//		{
	//			box_ishit = true;
	//		}
	//	}
	//	if (box_ishit == false)return false; //�������͂��l�p�`�ɂ��瓖�����ĂȂ�
	//
	//
	//	for (int i = 0; i < 4; i++)
	//	{
	//		float closs_product = 0;
	//
	//		Location vector1 =
	//			line_collider->GetLocation(LINE_START) -
	//			line_collider->GetLocation(LINE_END);
	//		Location vector2 =
	//			vertex[i] - line_collider->GetLocation(LINE_END);
	//
	//		closs_product = (vector1.x * vector2.y) - (vector1.y * vector2.x);
	//		if (closs_product == 0)return true;	//0�Ȃ���ƒ��_���d�Ȃ��Ă���̂œ�����
	//
	//		if (i == 0)
	//		{
	//			sign = closs_product;
	//		}
	//		else
	//		{
	//			if ((sign * closs_product) < 0)
	//			{
	//				is_hit = true;
	//				break;
	//			}
	//		}
	//	}
	//
	//	return is_hit;
	return false;
}

//---------------------------------
// PolyLine�Ƃ̓����蔻��
//---------------------------------
//bool BoxCollider::HitPolyLine(const class PolyLine* poly_line)const
//{
//	bool is_hit = false;
//	const vector<LineCollider*>* lines = poly_line->GetLines();
//
//	for (auto line : *lines)
//	{
//		if (HitLine(line))
//		{
//			is_hit = true;
//			break;
//		}
//	}
//
//	return is_hit;
//}

//-----------------------------------
// ���S���W�̎擾
//-----------------------------------
Location BoxCollider::GetLocation()const
{

	return location;
}

//-----------------------------------
// ���a�̎擾
//-----------------------------------
Area BoxCollider::GetArea()const
{

	return area;
}

