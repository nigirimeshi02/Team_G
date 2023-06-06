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
	rd = angle + M_PI / 2;
	location.x = 0 * cos(rd) - D_ATTACK_RANGE * sin(rd) + P_x;
	location.y = 0 * sin(rd) + D_ATTACK_RANGE * cos(rd) + P_y;
}

void Attack::Draw()const
{
	// ‰æ‘œˆ—
	DrawRotaGraph2(P_x, P_y, 100, 15, 1.0, angle, Sward, 1, 0);
	// “–‚½‚è”»’è(‰¼•\¦)
	DrawCircle(location.x, location.y, radius, 0xFF0000, 1);
}


