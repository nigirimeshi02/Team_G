#pragma once
#include <stdio.h>
#include "DxLib.h"
#include "Collider/SphereCollider.h"
#define D_ATTACK_RANGE 100

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
	float rd;
};