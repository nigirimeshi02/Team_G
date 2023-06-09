#include<stdio.h>
#include"DxLib.h"
#include"attack.h"

int Attack::Sward = 0;

Attack::Attack(int x, int y)
{
	// 初回のみ刀の画像を読み込む
	if (Sward == 0)
	{
		Sward = (LoadGraph("Images/katana.png"));
	}

	// 初期化処理
	radius = 5;
	angle = 0;
	P_x = x;
	P_y = y - D_ATTACK_SHIFT_Y;
	//angle_a[D_ANGLE_MEMOLY] = {};
	for (int i = 0; i < D_ANGLE_MEMOLY; i++)
	{
		trailAlpha[i] = (int)(255 - ((double)i / (double)D_ANGLE_MEMOLY * 255));
	}
	t = 0;
	isAttackEnd = false;

}

Attack::~Attack()
{

}

void Attack::Update()
{
	// 角度の増加
	angle += D_SWARD_SPEED;
	if (angle >= M_PI) {
		isAttackEnd = true;
	}

	// 当たり判定
	float rd = angle + float(M_PI / 2);
	location.x = 0 * cosf(rd) - D_ATTACK_RANGE * sinf(rd) + P_x;
	location.y = 0 * sinf(rd) + D_ATTACK_RANGE * cosf(rd) + P_y;

	// angle履歴
	for (int a = t; a > 0; a--)
	{
		angle_a[a] = angle_a[a - 1];
	}
	angle_a[0] = angle;

	// 数列の上限になるまでインクリメント
	if (t < D_ANGLE_MEMOLY - 1) {
		t++;
	}
}

void Attack::Draw()const
{
	// 画像処理
	DrawRotaGraph2(P_x, P_y, 180, 13, 1.0, angle, Sward, 1, 0);

	// 残像描画
	for (int a = 0; a < t - 1; a++)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, trailAlpha[a]);
		DrawRotaGraph2(P_x, P_y, 180, 13, 1.0, angle_a[a], Sward, 1, 0);
	}

	// 通常の画像を描画
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//// 当たり判定(仮表示)
	//DrawCircleAA(location.x, location.y, radius, 20, 0xFF0000, 1);

	//DrawFormatString(0, 60, 0xFFFFFF, "%lf", angle);
}

int Attack::GetIsAttackEnd() {
	return Attack::isAttackEnd;
}
