#include "LineCollider.h"
#include "BoxCollider.h"
#include "SphereCollider.h"
#include "DxLib.h"

//------------------------------------
// コンストラクタ
//------------------------------------
LineCollider::LineCollider()
{
	int width;
	int height;
	GetDrawScreenSize(&width, &height);

	colliderType = E_Collider::Line;
	//絶対座標
	vector[LINE_START] = { 0,0 };
	vector[LINE_END] = { (float)width, (float)height };

	location = GetMiddlePoint();
	Relativize();
}

//------------------------------------
// コンストラクタ
//------------------------------------
LineCollider::LineCollider(Location point1, Location point2)
{
	colliderType = E_Collider::Line;

	//点じゃないことを保証する
	if (point1 == point2)
	{
		point2.x += 1;
		point2.y += 1;
	}

	//絶対座標
	vector[LINE_START] = point1;
	vector[LINE_END] = point2;

	location = GetMiddlePoint();
	Relativize();
}

//--------------------------------------
// デストラクタ
//--------------------------------------
LineCollider::~LineCollider()
{

}

//--------------------------------------
// 描画
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
// 点との当たり判定
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
	//線分の範囲内かどうか
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
// SphereColliderとの当たり判定
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
// BoxColliderとの当たり判定
//-----------------------------------
bool LineCollider::HitBox(const BoxCollider* box)const
{

	bool is_hit = false;
	bool box_ishit = false;
	float sign = 0;

	Location vertex[4] =
	{
		//四隅
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
	if (box_ishit == false)return false; //線分を囲う四角形にすら当たってない

	for (int i = 0; i < 4; i++)
	{
		float closs_product = 0;

		Location vector1 =
			GetLocation(LINE_START) - GetLocation(LINE_END);
		Location vector2 =
			vertex[i] - GetLocation(LINE_END);

		closs_product = (vector1.x * vector2.y) - (vector1.y * vector2.x);
		if (closs_product == 0)return true;	//0なら線と頂点が重なっているので当たり

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
// LineColliderとの当たり判定
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
// 線の端の座標の取得 始点か終点返す デフォルトは始点
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
// 始点、終点座標の設定 引数：座標、始点：0 終点：1
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
* 線分を対角線とした矩形の左上の座標を返す
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
* 線分を対角線とした矩形の右下の座標を返す
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
* 中心座標から対象の座標までのベクトルを返す
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
* 線分の中点を返す
*/
Location LineCollider::GetMiddlePoint()const
{
	Location middle_point;
	middle_point.x = (vector[LINE_START].x + vector[LINE_END].x) / 2;
	middle_point.y = (vector[LINE_START].y + vector[LINE_END].y) / 2;

	return middle_point;
}

/*
* 座標を中心座標からのベクターに相対化する
*/
void LineCollider::Relativize()
{
	vector[LINE_START].x = vector[LINE_START].x - location.x;
	vector[LINE_START].y = vector[LINE_START].y - location.y;

	vector[LINE_END].x = vector[LINE_END].x - location.x;
	vector[LINE_END].y = vector[LINE_END].y - location.y;
}

/*
* 線分の端の絶対座標を返す
*/
Location LineCollider::MakeTip(int index)const
{
	//線分の端の絶対座標を計算する
	Location tip;
	tip.x = location.x + vector[index].x;
	tip.y = location.y + vector[index].y;

	return tip;
}