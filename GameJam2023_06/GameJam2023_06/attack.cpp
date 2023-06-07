#include<stdio.h>
#include"DxLib.h"
#include"attack.h"

int Attack::Sward = 0;

Attack::Attack()
{
    // ����̂ݓ��̉摜��ǂݍ���
	if (Sward == 0)
	{
		Sward = (LoadGraph("Images/katana.png"));
	}

	// ����������
	radius = 5;
	angle = 0;
	P_x = 300;
	P_y = 300;
	for (int i = 0; i < D_ANGLE_MEMOLY; i++)
	{
		trailAlpha[i] = 255 - ((double)i / (double)D_ANGLE_MEMOLY * 255);
	}
	t = 0;
}

Attack::~Attack()
{

}

void Attack::Update()
{
	// �p�x�̑���
	angle += D_SWARD_SPEED;
	
	// �����蔻��
	float rd = angle + M_PI / 2;
	location.x = 0 * cos(rd) - D_ATTACK_RANGE * sin(rd) + P_x;
	location.y = 0 * sin(rd) + D_ATTACK_RANGE * cos(rd) + P_y;
	
	// angle����
	for (int a = t; a > 0; a--)
	{
		angle_a[a] = angle_a[a - 1];
	}
	angle_a[0] = angle;

	// ����̏���ɂȂ�܂ŃC���N�������g
	if (t < D_ANGLE_MEMOLY - 1) {
		t++;
	}
}

void Attack::Draw()const
{
	// �摜����
	DrawRotaGraph2(P_x, P_y, 180, 13, 1.0, angle, Sward, 1, 0);

	// �c���`��
	for (int a = 0; a < t - 1; a++)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, trailAlpha[a]);
		DrawRotaGraph2(P_x, P_y, 180, 13, 1.0, angle_a[a], Sward, 1, 0);
	}
	
	// �s�����x��������O�ɉ�ʂ��X�V����
	ScreenFlip();

	// �ʏ�̉摜��`��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// �����蔻��(���\��)
	DrawCircle(location.x, location.y, (int)radius, 0xFF0000, 1);
}


