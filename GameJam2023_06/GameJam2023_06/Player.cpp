#include<DxLib.h>
#include"System/KeyManager/KeyManager.h"
#include"Player.h"


Player::Player()
{
	x = 600;
	y = 500;
	speed = 0;
	imgflg = 0;
	life = 3;

	PlayerPaseImage = LoadGraph("images/player.png");
	PlayerLeftRunImage = LoadGraph("images/player_left_run.png");
	PlayerRightRunImage = LoadGraph("images/player_right_run.png");
}

Player::~Player()
{



}

void Player::PlayerControll()
{
	//ç∂
	if ((KeyManager::OnKeyPressed(KEY_INPUT_LEFT) == TRUE)) {
		imgflg = 1;

		if (PlayerLimit() == 0) {
			if (speed < WALK_SPEED * -1) {
				speed += 2;
			}
			else if (speed > WALK_SPEED * -1) {
				speed -= 2;
			}
			else {
				speed = WALK_SPEED * -1;
			}

		}
	}
	//âE
	else if ((KeyManager::OnKeyPressed(KEY_INPUT_RIGHT) == TRUE)) {
		imgflg = 2;

		if (PlayerLimit() == 0) {
			if (speed > WALK_SPEED) {
				speed -= 2;
			}
			else if (speed < WALK_SPEED) {
				speed += 2;
			}
			else {
				speed = WALK_SPEED;
			}
		}
	}
	
	else if((KeyManager::OnKeyPressed(KEY_INPUT_LEFT)==FALSE)&&(KeyManager::OnKeyPressed(KEY_INPUT_RIGHT))==FALSE){
		if (PlayerLimit() == 0) {
			if (speed <= 3 && speed >= 3) {
				speed = 0;
				imgflg = 0;
			}
			else if(speed>0){
				speed -= 0.1;
			}
			else if (speed < 0) {
				speed += 0.1;
			}
			else {
				speed = 0;
				imgflg = 0;
			}
		}
	}
}

void Player::DrawPlayer()
{
	if (imgflg == 0) {
		if (speed == 0) {
			DrawRotaGraph(x, y, 0.3, 0, PlayerPaseImage, FALSE);
		}
	}
	if (imgflg == 1) {
		if (speed > -3) {
			DrawRotaGraph(x, y, 0.3, 0, PlayerLeftRunImage, FALSE);
		}
	}
	if (imgflg == 2) {
		if (speed < 3) {
			DrawRotaGraph(x, y, 0.3, 0, PlayerRightRunImage, FALSE);
		}
	}
}

int  Player::PlayerLimit()
{
	if (x < MOVE_LEFT_LIMIT) {
		speed = 0;
		x = MOVE_LEFT_LIMIT;
		return 1;
	}
	else if (x > MOVE_RIGHT_LIMIT) {
		speed = 0;
		x = MOVE_RIGHT_LIMIT;
		return 1;
	}
	else {
		x += speed;
		return 0;
	}
}