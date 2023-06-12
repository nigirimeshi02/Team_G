#include"DxLib.h"
#include "Enemy.h"

int Enemy::image = 0;


/*
* �R���X�g���N�^
*/
Enemy::Enemy(Location location, float radius, float speed, int score)
	:ObstacleBase(location, radius, speed, score,30)
{
	if (image == 0)
	{
		image = LoadGraph("Images/enemy.png");
	}
	
	
}

/*
* �f�X�g���N�^
*/
Enemy::~Enemy()
{

}

/*
* �X�V
*/
void Enemy::Update()
{
	if (isBroken == false)
	{
		location.y += speed;
	}
	frameCount--;
}

/*
* �`��
*/
void Enemy::Draw()const
{
	if(isBroken == false)
	{
		DrawRotaGraphF(location.x, location.y, 1.0, 0, image, TRUE);
	}
	else
	{
		int alpha = static_cast<int>(((float)frameCount / MAX_FRAME) * 255);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		DrawRotaGraphF(location.x, location.y, 1.0, 0, image, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
}

/*
*
*/


/*
*
*/



