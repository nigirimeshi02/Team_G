#include"DxLib.h"
#include "Enemy.h"


/*
* �f�t�H���g�R���X�g���N�^
*/
Enemy::Enemy()
{

	


}

/*
* �f�X�g���N�^
*/
Enemy::~Enemy()
{


}

/*
* �����t���R���X�g���N�^
*/
Enemy::Enemy(Location location, float radius = 5)
	:ObstacleBase(location, radius)
{




	speed = 0;
	isBroken = false;
}

void Enemy::Update() {
	// �Q�[�����[�v
	while ((ProcessMessage() == 0) &&
		sceneManager->Update() != nullptr
		)
	{
		ClearDrawScreen();		// ��ʂ̏�����

		sceneManager->Draw();

		ScreenFlip();
	}
}


void Enemy::Draw()const {
	

	DrawCircle(640, 100, GetColor(255, 255, 255), TRUE);
}