#include "BoxCollider.h"
#include "DxLib.h"

/*
* デフォルトコンストラクタ
* Location ColliderBase 中心座標
* Area		BoxCollider	 範囲
*/
BoxCollider::BoxCollider(Location location = Location{}, Area area = Area{ 100,100 })
	:ColliderBase(location)
{
	colliderType = E_Collider::Box;
	this->area = area;

}

//-----------------------------------
// デストラクタ
//-----------------------------------
BoxCollider::~BoxCollider()
{

}


/*
* 描画関数
* 子クラスから呼ぶことで当たり判定の描画をする
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
// SphereColliderとの当たり判定
//-----------------------------------
bool BoxCollider::HitSphere(const class SphereCollider* sphere_collider) const
{

	//bool ret = false;//返り値
	//float rad; //2点の角度
	//float sphere_x; //円の座標(x)
	//float sphere_y; //円の座標(y)

	////自分の当たり判定の範囲
	//float my_x[2];
	//float my_y[2];

	////角度の計算
	//rad = atan2f(location.y - sphere_collider->GetLocation().y,
	//	location.x - sphere_collider->GetLocation().x);

	////座標の計算
	//sphere_x = sphere_collider->GetLocation().x
	//	+ (sphere_collider->GetRadius() * cosf(rad));
	//sphere_y = sphere_collider->GetLocation().y
	//	+ (sphere_collider->GetRadius() * sinf(rad));

	////自分の当たり判定の範囲の計算
	//my_x[0] = location.x - (area.width / 2);
	//my_y[0] = location.y - (area.height / 2);
	//my_x[1] = my_x[0] + area.width;
	//my_y[1] = my_y[0] + area.height;

	//if ((my_x[0] <= sphere_x) && (sphere_x <= my_x[1])
	//	&& (my_y[0] <= sphere_y) && (sphere_y <= my_y[1])) //当たり判定
	//{
	//	ret = true;
	//}

	//return ret;
	return false;
}

//-----------------------------------
// BoxColliderとの当たり判定
//-----------------------------------
bool BoxCollider::HitBox(const BoxCollider* box_collider) const
{

	bool ret = false; //返り値

	//自分の当たり判定の範囲
	float my_x[2];
	float my_y[2];

	//相手の当たり判定の範囲
	float sub_x[2];
	float sub_y[2];

	//自分の当たり判定の範囲の計算
	my_x[0] = location.x - (area.width / 2);
	my_y[0] = location.y - (area.height / 2);
	my_x[1] = my_x[0] + area.width;
	my_y[1] = my_y[0] + area.height;

	//相手の当たり判定の範囲の計算
	sub_x[0] = box_collider->GetLocation().x - (box_collider->GetArea().width / 2);
	sub_y[0] = box_collider->GetLocation().y - (box_collider->GetArea().height / 2);
	sub_x[1] = sub_x[0] + box_collider->GetArea().width;
	sub_y[1] = sub_y[0] + box_collider->GetArea().height;

	if ((my_x[0] <= sub_x[1]) &&
		(sub_x[0] <= my_x[1]) &&
		(my_y[0] <= sub_y[1]) &&
		(sub_y[0] <= my_y[1])) //当たり判定
	{
		ret = true;
	}

	return ret;
}

//-----------------------------------
// LineColliderとの当たり判定
//-----------------------------------
bool BoxCollider::HitLine(const class LineCollider* line_collider) const
{
	//	bool is_hit = false;
	//	bool box_ishit = false;
	//	float sign = 0;
	//
	//	Location vertex[4] =
	//	{
	//		//四隅
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
	//	if (box_ishit == false)return false; //線分を囲う四角形にすら当たってない
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
	//		if (closs_product == 0)return true;	//0なら線と頂点が重なっているので当たり
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
// PolyLineとの当たり判定
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
// 中心座標の取得
//-----------------------------------
Location BoxCollider::GetLocation()const
{

	return location;
}

//-----------------------------------
// 半径の取得
//-----------------------------------
Area BoxCollider::GetArea()const
{

	return area;
}

