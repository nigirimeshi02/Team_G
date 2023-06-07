#pragma once

#define MOVE_LEFT_LIMIT 120
#define MOVE_RIGHT_LIMIT 1170
#define WALK_SPEED 1.0

class Player
{
private:
	int x;
	int y;
	int imgflg;		//�O�͐Î~�@�P�͍��@�Q�͉E
	float speed;
	int life;

	int PlayerPaseImage;
	int PlayerLeftRunImage;
	int PlayerRightRunImage;

public:
	Player();
	~Player();
	void DrawPlayer();
	void PlayerControll();
	int PlayerLimit();
};