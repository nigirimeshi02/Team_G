#include "Enemy.h"
#include"DxLib.h"

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

void Enemy:: Update() {

}

void Enemy::Draw()const {
	

	DrawCircle(640, 100, GetColor(255, 255, 255), TRUE);
}