#include<DxLib.h>
#include"System/KeyManager/KeyManager.h"
#include"system/PadInput/PadInput.h"
#include"Player.h"


Player::Player()
{
	x = 600;
	y = 500;
	speed = 0;
	imgflg = 0;
	life = 3;
	JoyPadX = 128;

	PlayerPaseImage = LoadGraph("images/player.png");
	PlayerLeftRunImage = LoadGraph("images/player_left_run.png");
	PlayerRightRunImage = LoadGraph("images/player_right_run.png");
}

Player::~Player()
{



}

void Player::PlayerControll()
{
	JoyPadX = PAD_INPUT::GetLStick().x;

	///////////////////
	// パッド
	//左
	if (JoyPadX < 128) {
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
	//右
	else if (JoyPadX > 128) {
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

	else if (JoyPadX == 128) {
		if (PlayerLimit() == 0) {
			speed = 0;
			imgflg = 0;
		}
	}

	/////////////////////
	//// キーボード
	////左
	//if ((KeyManager::OnKeyPressed(KEY_INPUT_LEFT) == TRUE)) {
	//	imgflg = 1;

	//	if (PlayerLimit() == 0) {
	//		if (speed < WALK_SPEED * -1) {
	//			speed += 2;
	//		}
	//		else if (speed > WALK_SPEED * -1) {
	//			speed -= 2;
	//		}
	//		else {
	//			speed = WALK_SPEED * -1;
	//		}

	//	}
	//}
	////右
	//else if ((KeyManager::OnKeyPressed(KEY_INPUT_RIGHT) == TRUE)) {
	//	imgflg = 2;

	//	if (PlayerLimit() == 0) {
	//		if (speed > WALK_SPEED) {
	//			speed -= 2;
	//		}
	//		else if (speed < WALK_SPEED) {
	//			speed += 2;
	//		}
	//		else {
	//			speed = WALK_SPEED;
	//		}
	//	}
	//}
	//
	//else if((KeyManager::OnKeyPressed(KEY_INPUT_LEFT)==FALSE)&&(KeyManager::OnKeyPressed(KEY_INPUT_RIGHT))==FALSE){
	//	if (PlayerLimit() == 0) {
	//		speed = 0;
	//		imgflg = 0;
	//	}
	//}
}

void Player::DrawPlayer()const
{
	DrawFormatString(0, 0, 0xffffff, "%d", JoyPadX);
	if (imgflg == 0) {
		if (speed == 0) {
			DrawRotaGraph(x, y, 0.3, 0, PlayerPaseImage, TRUE);
		}
	}
	if (imgflg == 1) {
		if (speed > -3) {
			DrawRotaGraph(x, y, 0.3, 0, PlayerLeftRunImage, TRUE);
		}
	}
	if (imgflg == 2) {
		if (speed < 3) {
			DrawRotaGraph(x, y, 0.3, 0, PlayerRightRunImage, TRUE);
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