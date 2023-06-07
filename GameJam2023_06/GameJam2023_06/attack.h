#pragma once
#include <stdio.h>
#include "DxLib.h"
#include "Collider/SphereCollider.h"
#define D_ATTACK_RANGE 50
#define D_SWARD_SPEED 0.15f
#define D_ANGLE_MEMOLY 9

class Attack:public SphereCollider
{
public:
	Attack();
	~Attack();
	void Draw()const;
	void Update();
private:
	int P_x, P_y;
	static int Sward;
	float angle;
	// 残像の座標と不透明度を管理する配列
	float angle_a[D_ANGLE_MEMOLY];
	int trailAlpha[D_ANGLE_MEMOLY];
	int t;
};