#include "LineCollider.h"
#include "BoxCollider.h"
#include "SphereCollider.h"
#include "DxLib.h"

//------------------------------------
// �R���X�g���N�^
//------------------------------------
LineCollider::LineCollider()
{
	int width;
	int height;
	GetDrawScreenSize(&width, &height);

	colliderType = E_Collider::Line;
	//��΍��W
	vector[LINE_START] = { 0,0 };
	vector[LINE_END] = { (float)width, (float)height };

	location = GetMiddlePoint();
	Relativize();
}

//------------------------------------
// �R���X�g���N�^
//------------------------------------
LineCollider::LineCollider(Location point1, Location point2)
{
	colliderType = E_Collider::Line;

	//�_����Ȃ����Ƃ�ۏ؂���
	if (point1 == point2)
	{
		point2.x += 1;
		point2.y += 1;
	}

	//��΍��W
	vector[LINE_START] = point1;
	vector[LINE_END] = point2;

	location = GetMiddlePoint();
	Relativize();
}

//--------------------------------------
// �f�X�g���N�^
//--------------------------------------
LineCollider::~LineCollider()
{

}

//--------------------------------------
// �`��
//--------------------------------------
void LineCollider::Draw()const
{

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawLineAA(
		GetLocation(LINE_START).x
		,GetLocation(LINE_START).y
		,GetLocation(LINE_END).x
		,GetLocation(LINE_END).y
		,0xE9FF00, 3);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

//-----------------------------------
// �_�Ƃ̓����蔻��
//-----------------------------------
bool LineCollider::HitDot(Location point)const
{

	bool is_hit = false;
	float cross_product;

	Location vector1 =
		GetLocation(LINE_START) - GetLocation(LINE_END);
	Location vector2 =
		point - GetLocation(LINE_END);

	cross_product = (vector1.x * vector2.y) - (vector1.y * vector2.x);
	//�����͈͓̔����ǂ���
	if ((GetMin().x <= point.x) &&
		(GetMin().y <= point.y) &&
		(point.x <= GetMax().x) &&
		(point.y <= GetMax().y))
	{
		if (cross_product == 0)
		{
			is_hit = true;
		}
	}

	return is_hit;
}

//-----------------------------------
// SphereCollider�Ƃ̓����蔻��
//-----------------------------------
bool LineCollider::HitSphere(const SphereCollider* sphere)const
{
	bool is_hit = false;
	Location vector1 =
		GetLocation(LINE_END) - GetLocation(LINE_START);
	Location vector2 =
		sphere->GetLocation() - GetLocation(LINE_START);

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

	if (distance_sphere_near_pos > sphere->GetRadius())
	{
		return false;
	}

	bool is_start_acute = CheckIsAcute(GetLocation(LINE_END)
		- GetLocation(LINE_START), vector2);
	bool is_end_acute
		= CheckIsAcute(GetLocation(LINE_END) - GetLocation(LINE_START)
			, sphere->GetLocation() - GetLocation(LINE_END));

	if (is_start_acute ^ is_end_acute)
	{
		is_hit = true;
	}

	float distance_tips_sphere
		= MakeScalar(sphere->GetLocation() - GetLocation(LINE_START));
	if (distance_tips_sphere <= sphere->GetRadius())
	{
		is_hit = true;
	}
	distance_tips_sphere
		= MakeScalar(sphere->GetLocation() - GetLocation(LINE_END));
	if (distance_tips_sphere <= sphere->GetRadius())
	{
		is_hit = true;
	}

	return is_hit;
}

//-----------------------------------
// BoxCollider�Ƃ̓����蔻��
//-----------------------------------
bool LineCollider::HitBox(const BoxCollider* box)const
{

	bool is_hit = false;
	bool box_ishit = false;
	float sign = 0;

	Location vertex[4] =
	{
		//�l��
		{box->GetLocation().x - box->GetArea().width / 2,
		box->GetLocation().y - box->GetArea().height / 2 },

		{box->GetLocation().x + box->GetArea().width / 2,
		box->GetLocation().y - box->GetArea().height / 2 },

		{box->GetLocation().x - box->GetArea().width / 2,
		box->GetLocation().y + box->GetArea().height / 2 },

		{box->GetLocation().x + box->GetArea().width / 2,
		box->GetLocation().y + box->GetArea().height / 2},

	};

	for (int i = 0; i < 4; i++)
	{
		if ((GetMin().x <= vertex[i].x) && 
			(GetMin().y <= vertex[i].y) &&
			(vertex[i].x <= GetMax().x) &&
			(vertex[i].y <= GetMax().y))
		{
			box_ishit = true;
		}
	}
	if (box_ishit == false)return false; //�������͂��l�p�`�ɂ��瓖�����ĂȂ�

	for (int i = 0; i < 4; i++)
	{
		float closs_product = 0;

		Location vector1 =
			GetLocation(LINE_START) - GetLocation(LINE_END);
		Location vector2 =
			vertex[i] - GetLocation(LINE_END);

		closs_product = (vector1.x * vector2.y) - (vector1.y * vector2.x);
		if (closs_product == 0)return true;	//0�Ȃ���ƒ��_���d�Ȃ��Ă���̂œ�����

		if (i == 0)
		{
			sign = closs_product;
		}
		else
		{
			if ((sign * closs_product) < 0)
			{
				is_hit = true;
				break;
			}
		}
	}

	return is_hit;
}

//-----------------------------------
// LineCollider�Ƃ̓����蔻��
//-----------------------------------
bool LineCollider::HitLine(const LineCollider* line)const
{

	bool is_hit = false;

	Location this_vector
		= this->GetLocation(LINE_END) - this->GetLocation(LINE_START);

	Location arg_vector
		= line->GetLocation(LINE_END) - line->GetLocation(LINE_START);

	float cross_product[2];
	cross_product[0]
		= MakeCrossProduct(this_vector,
			line->GetLocation(LINE_START) - this->GetLocation(LINE_START));

	cross_product[1]
		= MakeCrossProduct(this_vector,
			line->GetLocation(LINE_END) - this->GetLocation(LINE_START));

	if (0 < cross_product[0] * cross_product[1])
	{
		return false;
	}

	cross_product[0]
		= MakeCrossProduct(arg_vector,
			this->GetLocation(LINE_START) - line->GetLocation(LINE_START));

	cross_product[1]
		= MakeCrossProduct(arg_vector,
			this->GetLocation(LINE_END) - line->GetLocation(LINE_START));

	if (cross_product[0] * cross_product[1] <= 0)
	{
		is_hit = true;
	}

	return is_hit;
}

//-----------------------------------------------------
// ���̒[�̍��W�̎擾 �n�_���I�_�Ԃ� �f�t�H���g�͎n�_
//-----------------------------------------------------
Location LineCollider::GetLocation(int index)const
{

	if (index < 2)
	{
		return MakeTip(index);
	}
	else
	{
		return MakeTip(LINE_START);
	}
}

//--------------------------------------------------
// �n�_�A�I�_���W�̐ݒ� �����F���W�A�n�_�F0 �I�_�F1
//--------------------------------------------------
void LineCollider::SetLocation(Location location, int index)
{

	if (index < 2)
	{
		vector[LINE_START] = MakeTip(LINE_START);
		vector[LINE_END] = MakeTip(LINE_END);
		vector[index] = location;
		this->location = GetMiddlePoint();
		Relativize();
	}
}

/*
* ������Ίp���Ƃ�����`�̍���̍��W��Ԃ�
*/
Location LineCollider::GetMin()const
{
	Location vector_min = {};
	float x;
	float y;

	if (GetLocation(LINE_START).x < GetLocation(LINE_END).x)
	{
		x = GetLocation(LINE_START).x;
	}
	else
	{
		x = GetLocation(LINE_END).x;
	}

	if (GetLocation(LINE_START).y < GetLocation(LINE_END).y)
	{
		y = GetLocation(LINE_START).y;
	}
	else
	{
		y = GetLocation(LINE_END).y;
	}

	vector_min = { x,y };

	return vector_min;
}

/*
* ������Ίp���Ƃ�����`�̉E���̍��W��Ԃ�
*/
Location LineCollider::GetMax()const
{
	Location vector_max{};
	float x;
	float y;

	if (GetLocation(LINE_START).x > GetLocation(LINE_END).x)
	{
		x = GetLocation(LINE_START).x;
	}
	else
	{
		x = GetLocation(LINE_END).x;
	}

	if (GetLocation(LINE_START).y > GetLocation(LINE_END).y)
	{
		y = GetLocation(LINE_START).y;
	}
	else
	{
		y = GetLocation(LINE_END).y;
	}

	vector_max = { x,y };

	return vector_max;
}

/*
* ���S���W����Ώۂ̍��W�܂ł̃x�N�g����Ԃ�
*/
Location LineCollider::GetVector(int index)const
{
	if (LINE_START <= index && index <= LINE_END)
	{
		return vector[index];
	}
	else
	{
		return {};
	}
}

/*
* �����̒��_��Ԃ�
*/
Location LineCollider::GetMiddlePoint()const
{
	Location middle_point;
	middle_point.x = (vector[LINE_START].x + vector[LINE_END].x) / 2;
	middle_point.y = (vector[LINE_START].y + vector[LINE_END].y) / 2;

	return middle_point;
}

/*
* ���W�𒆐S���W����̃x�N�^�[�ɑ��Ή�����
*/
void LineCollider::Relativize()
{
	vector[LINE_START].x = vector[LINE_START].x - location.x;
	vector[LINE_START].y = vector[LINE_START].y - location.y;

	vector[LINE_END].x = vector[LINE_END].x - location.x;
	vector[LINE_END].y = vector[LINE_END].y - location.y;
}

/*
* �����̒[�̐�΍��W��Ԃ�
*/
Location LineCollider::MakeTip(int index)const
{
	//�����̒[�̐�΍��W���v�Z����
	Location tip;
	tip.x = location.x + vector[index].x;
	tip.y = location.y + vector[index].y;

	return tip;
}