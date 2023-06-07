#include"DxLib.h"
#include "Enemy.h"

int Enemy::image = 0;


/*
* �R���X�g���N�^
*/
Enemy::Enemy(Location location, float radius, float speed, int score)
	:ObstacleBase(location, radius, speed, score)
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
	location.y += speed;
}

/*
* �`��
*/
void Enemy::Draw()const
{
	
	DrawRotaGraphF(location.x, location.y, 1.0, 0, image, TRUE);
}

/*
*
*/


/*
*
*/



