#include<DxLib.h>
#include"System/SoundPlayer/SoundPlayer.h"
#include"System/KeyManager/KeyManager.h"
#include"system/PadInput/PadInput.h"
#include"Player.h"


Player::Player()
{
	location.x = 600;
	location.y = 500;
	speed = 0;
	imageCnt = 0;
	life = 3;
	JoyPadX = 128;
	atkFlg = FALSE;
	invincibleTime = 2;
	IsInvincible = FALSE;
	fpsCnt = 0;
	blinkFlg = FALSE;

	PlayerImage = LoadGraph("images/player.png");
	PlayerLeftRunImage = LoadGraph("images/player_left_run.png");
	PlayerRightRunImage = LoadGraph("images/player_right_run.png");
	Damege_SE = SoundPlayer::GetSE("damege");
	Attack_SE = SoundPlayer::GetSE("Attack");

	attack = nullptr;
}

Player::~Player()
{
	if(attack != nullptr)
	{
		delete attack;
	}
}

void Player::Update()
{
	JoyPadX = PAD_INPUT::GetLStick().x;
	fpsCnt++;

	///////////////////
	// パッド
	//左
	if (JoyPadX < -MARGIN && JoyPadX >= -MARGIN * 4 - 1) {
		imageCnt = 1;

		if (PlayerLimit() == 0) {
			if (speed < WALK_SPEED * -1) {
				speed += 5;
			}
			else if (speed > WALK_SPEED * -1) {
				speed -= 5;
			}
			else {
				speed = WALK_SPEED * -1;
			}

		}
	}
	//右
	else if (JoyPadX > MARGIN && JoyPadX <= MARGIN * 4) {
		imageCnt = 2;

		if (PlayerLimit() == 0) {
			if (speed > WALK_SPEED) {
				speed -= 5;
			}
			else if (speed < WALK_SPEED) {
				speed += 5;
			}
			else {
				speed = WALK_SPEED;
			}
		}
	}

	else if (JoyPadX <= MARGIN && -MARGIN <= JoyPadX) {
		if (PlayerLimit() == 0) {
			speed = 0;
			imageCnt = 0;
		}
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) &&
		attack == nullptr)
	{
		SoundPlayer::PlaySE(Attack_SE, FALSE);
		attack = new Attack((int)location.x, (int)location.y);
		atkFlg = TRUE;
	}

	if (atkFlg == TRUE) {
		attack->Update();
		if (attack->GetIsAttackEnd() == TRUE) {
			delete attack;
			attack = nullptr;
			atkFlg = FALSE;
		}
	}

	if (IsInvincible == TRUE)
	{
		if (invincibleTime > 0) {
			invincibleTime--;
			if (fpsCnt % 15 == 0) {
				blinkFlg = !blinkFlg;
			}
		}
		else {
			IsInvincible = FALSE;
			blinkFlg = FALSE;
		}
	}	

}

void Player::DrawPlayer()const
{
	//DrawFormatString(0, 0, 0xffffff, "%d", JoyPadX);
	if (imageCnt == 0) {
		if (speed == 0 && blinkFlg == FALSE) {
			DrawRotaGraphF(location.x, location.y, 0.3, 0, PlayerImage, TRUE);
		}
	}
	if (imageCnt == 1) {
		if (speed > -6 && blinkFlg == FALSE) {
			DrawRotaGraphF(location.x, location.y, 0.3, 0, PlayerLeftRunImage, TRUE);
		}
	}
	if (imageCnt == 2) {
		if (speed < 6 && blinkFlg == FALSE) {
			DrawRotaGraphF(location.x, location.y, 0.3, 0, PlayerRightRunImage, TRUE);
		}
	}

	if(attack != nullptr)
	{
		attack->Draw();
	}
	
}

int  Player::PlayerLimit()
{
	if (location.x < MOVE_LEFT_LIMIT) {
		speed = 0;
		location.x = MOVE_LEFT_LIMIT;
		return 1;
	}
	else if (location.x > MOVE_RIGHT_LIMIT) {
		speed = 0;
		location.x = MOVE_RIGHT_LIMIT;
		return 1;
	}
	else if (atkFlg == true)
	{
		speed = 0;
		imageCnt = 0;
		return 1;
	}
	else
	{
		location.x += speed;
		return 0;
	}
}

void Player::HitDamage()
{
	SoundPlayer::PlaySE(Damege_SE, FALSE);
	life--;
	invincibleTime = INVINCIBLE_TIME * 60;
	IsInvincible = TRUE;
}

bool Player::GetIsInvincible()
{
	return Player::IsInvincible;
}