#include<stdio.h>
#include"DxLib.h"
#include"attack.h"

int Attack::Sward = 0;

Attack::Attack()
{
	if (Sward == 0)
	{
		Sward = (LoadGraph("Images/slash_test.png"));
	}
	// ”»’èˆ—
	radius = 5;
	angle = 0;
	P_x = 300;
	P_y = 300;
	X_a[5] = {};
	Y_a[5] = {};
	t = 0;
}

Attack::~Attack()
{

}

void Attack::Update()
{
	// Šp“x‚Ì‘‰Á
	angle += 0.15f;
	if (angle >= M_PI) angle = 0;
	
	// “–‚½‚è”»’è
	float rd = angle + M_PI / 2;
	location.x = 0 * cos(rd) - D_ATTACK_RANGE * sin(rd) + P_x;
	location.y = 0 * sin(rd) + D_ATTACK_RANGE * cos(rd) + P_y;
	
	// location—š—ð
	for (int a = t; a > 0; a--)
	{
		X_a[a] = X_a[a - 1];
		Y_a[a] = Y_a[a - 1];
	}
	X_a[0] = location.x;
	Y_a[0] = location.y;
	if (t <= 5) {
		t++;
	}
}

void Attack::Draw()const
{
	// ‰æ‘œˆ—
	DrawRotaGraph2(P_x, P_y, 100, 15, 1.0, angle, Sward, 1, 0);
	for (int a = t - 1; a > 0; a--)
	{
		DrawCircle(X_a[a], Y_a[a], 2, 0xFFFFFF, 1);
	}

	// “–‚½‚è”»’è(‰¼•\Ž¦)
	DrawCircle(location.x, location.y, (int)radius, 0xFF0000, 1);
}


