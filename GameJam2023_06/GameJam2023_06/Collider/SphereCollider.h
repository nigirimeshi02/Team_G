#pragma once
#include "ColliderBase.h"

class SphereCollider :public ColliderBase
{
protected:
/*
* ColliderBase:
*	E_Collider colliderType;
*	Location location;	//中心座標
*/
	float radius;			//半径
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

	//描画
	virtual void Draw()const;

	//SphereColliderとの当たり判定
	bool HitSphere(const SphereCollider* sphere_collider) const override;

	//BoxColliderとの当たり判定
	bool HitBox(const BoxCollider* box_collider) const override;

	//LineColliderとの当たり判定
	bool HitLine(const LineCollider* line_collider) const override;

	//中心座標の取得
	Location GetLocation() const
	{
		return location;
	}

	//半径の取得
	float GetRadius() const
	{
		return radius;
	}

	//中心座標の設定
	void SetLocation(Location location)
	{
		this->location = location;
	}
};