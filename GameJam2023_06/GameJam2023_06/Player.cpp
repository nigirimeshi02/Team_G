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
	atkflg = FALSE;

	PlayerPaseImage = LoadGraph("images/player.png");
	PlayerLeftRunImage = LoadGraph("images/player_left_run.png");
	PlayerRightRunImage = LoadGraph("images/player_right_run.png");

	attack = nullptr;
}

Player::~Player()
{
	if(attack != nullptr)
	{
		delete attack;
	}
}

void Player::PlayerControll()
{
	JoyPadX = PAD_INPUT::GetLStick().x;
	

	///////////////////
	// �p�b�h
	//��
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
	//�E
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

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		attack = new Attack(x, y);
		atkflg = TRUE;
	}

	if (atkflg == TRUE) {
		attack->Update();
		if (attack->GetIsAttackEnd() == TRUE) {
			delete attack;
			attack = nullptr;
			atkflg = FALSE;
		}
	}
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

	if(attack != nullptr)
	{
		attack->Draw();
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