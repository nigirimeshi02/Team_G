#pragma once
#include"attack.h"
#include "Collider/BoxCollider.h"

#define MOVE_LEFT_LIMIT 120
#define MOVE_RIGHT_LIMIT 1170
#define WALK_SPEED 5
#define INVINCIBLE_TIME 2

class Player:
	public BoxCollider
{
private:
	int imageCnt;			//０は静止　１は左　２は右
	float speed;			//移動量
	int life;				//残機
	short JoyPadX;			//コントローラーの左スティックの値を格納
	bool atkFlg;			//攻撃中かどうか	FALSE:攻撃していない	TRUE:攻撃中
	int invincibleTime;		//無敵時間
	bool IsInvincible;		//無敵かどうか	FALSE:なし	TRUE:無敵
	int fpsCnt;
	bool blinkFlg;			//点滅フラグ	FALSE:表示	TRUE:消す

	int PlayerImage;		//プレイヤーの止まっている画像
	int PlayerLeftRunImage;	//プレイヤーの左へ移動している画像
	int PlayerRightRunImage;//プレイヤーの右へ移動している画像

	int Damege_SE;
	int Attack_SE;

	Attack* attack;

public:
	Player();
	~Player();
	void DrawPlayer()const;
	void Update();
	int PlayerLimit();
	Attack* GetAttack()const { return attack; }
	void HitDamage();
	bool GetIsInvincible();
	const int* GetLife()const { return &life; }
};