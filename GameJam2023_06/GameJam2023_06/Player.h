#pragma once
#include"attack.h"
#include "Collider/BoxCollider.h"

#define MOVE_LEFT_LIMIT 120
#define MOVE_RIGHT_LIMIT 1170
#define WALK_SPEED 5

class Player:
	public BoxCollider
{
private:
	int imgflg;		//ÇOÇÕê√é~Å@ÇPÇÕç∂Å@ÇQÇÕâE
	float speed;
	int life;
	short JoyPadX;
	bool atkflg;

	int PlayerPaseImage;
	int PlayerLeftRunImage;
	int PlayerRightRunImage;

	Attack* attack;

public:
	Player();
	~Player();
	void DrawPlayer()const;
	void PlayerControll();
	int PlayerLimit();
	Attack* GetAttack()const { return attack; }
};