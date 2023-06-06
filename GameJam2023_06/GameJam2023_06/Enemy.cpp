#include"DxLib.h"
#include "Enemy.h"


/*
* デフォルトコンストラクタ
*/
Enemy::Enemy()
{

	


}

/*
* デストラクタ
*/
Enemy::~Enemy()
{


}

/*
* 引数付きコンストラクタ
*/
Enemy::Enemy(Location location, float radius = 5)
	:ObstacleBase(location, radius)
{




	speed = 0;
	isBroken = false;
}

void Enemy::Update() {
	// ゲームループ
	while ((ProcessMessage() == 0) &&
		sceneManager->Update() != nullptr
		)
	{
		ClearDrawScreen();		// 画面の初期化

		sceneManager->Draw();

		ScreenFlip();
	}
}


void Enemy::Draw()const {
	

	DrawCircle(640, 100, GetColor(255, 255, 255), TRUE);
}