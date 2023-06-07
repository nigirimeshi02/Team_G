#pragma once
#include <stdio.h>
#include "DxLib.h"
#include "Collider/SphereCollider.h"
#define D_ATTACK_RANGE 110
#define D_SWARD_SPEED 0.2f
#define D_ANGLE_MEMOLY 6
#define D_ATTACK_SHIFT_Y 60

class Attack:public SphereCollider
{
public:
	Attack(int x,int y);
	~Attack();
	void Draw()const;
	void Update();

	int GetIsAttackEnd();
private:
	int P_x, P_y; // �v���C���[���W
	static int Sward; // ���摜
	float angle; // ���̊p�x
	// �c���̍��W�ƕs�����x���Ǘ�����z��
	float angle_a[D_ANGLE_MEMOLY] = {};
	int trailAlpha[D_ANGLE_MEMOLY];
	int t;

	bool isAttackEnd;
};