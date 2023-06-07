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
	Location vector[2];	//中心から線の端の座標までのベクター(0:始点,1:終点)

public:
	//描画
	virtual void Draw()const;

	//点との当たり判定
	bool HitDot(Location point)const;

	//SphereColliderとの当たり判定
	bool HitSphere(const class SphereCollider* sphere_collider)const override;

	//BoxColliderとの当たり判定
	bool HitBox(const class BoxCollider* box_collider)const override;

	//LineColliderとの当たり判定
	bool HitLine(const class LineCollider* line_collider)const override;

	//線の端の座標の取得
	Location GetLocation(int i)const;	//オーバーロード

	//始点、終点座標の設定
	void SetLocation(Location location, int i);


	//線分を対角線とした矩形の左上の座標を返す
	Location GetMin()const;

	//線分を対角線とした矩形の右下の座標を返す
	Location GetMax()const;

	//中心座標から対象の座標までのベクトルを返す
	Location GetVector(int index)const;

private:

	//中点を返す
	Location GetMiddlePoint()const;

	//座標を中心座標からのベクターに相対化する
	void Relativize();

	//線分の端の絶対座標を返す
	Location MakeTip(int index)const;


};