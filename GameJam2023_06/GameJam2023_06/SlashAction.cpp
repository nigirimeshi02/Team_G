#include "DxLib.h"
#include "SlashAction.h"

SlashAction::SlashAction()
{
	location = { 0,0 };
	angle = 0;
	SlashAction(location);
}

SlashAction::~SlashAction()
{

}

SlashAction::SlashAction(Location location, float radius)
	:SphereCollider(location,radius)
{
	drawLocation = location;
	this->location.x -= D_ATTACK_RANGE;
	image = LoadGraph("images/slash_test.png");
	angle = 0;
}

void SlashAction::Update()
{	
	//location.x += (D_ATTACK_RANGE * 2) / (M_PI / D_ATTACK_SPEED);
	angle += D_ATTACK_SPEED;
	location.x = drawLocation.x - cosf(angle) * D_ATTACK_RANGE;
	location.y = drawLocation.y - sinf(angle) * D_ATTACK_RANGE;
	if (M_PI < angle)
	{
		angle = 0;
		location.x = drawLocation.x - D_ATTACK_RANGE;
		location.y = drawLocation.y;
	}
}

void SlashAction::Draw()const
{
	DrawRotaGraph2F(
		drawLocation.x, drawLocation.y
		, 100, 15, 1, angle, image, TRUE);

	DrawCircleAA(location.x, location.y, radius, 10, 0xFF0000);
}