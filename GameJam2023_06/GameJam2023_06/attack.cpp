#include<stdio.h>
#include"DxLib.h"
#include"attack.h"

int Attack::Sward = 0;

Attack::Attack()
{
    // 初回のみ刀の画像を読み込む
	if (Sward == 0)
	{
		Sward = (LoadGraph("Images/katana.png"));
	}

	// 初期化処理
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
	// 角度の増加
	angle += D_SWARD_SPEED;
	
	// 当たり判定
	float rd = angle + M_PI / 2;
	location.x = 0 * cos(rd) - D_ATTACK_RANGE * sin(rd) + P_x;
	location.y = 0 * sin(rd) + D_ATTACK_RANGE * cos(rd) + P_y;
	
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
	
	// 不透明度を下げる前に画面を更新する
	ScreenFlip();

	// 通常の画像を描画
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// 当たり判定(仮表示)
	DrawCircle(location.x, location.y, (int)radius, 0xFF0000, 1);
}


