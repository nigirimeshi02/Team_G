#include"DxLib.h"
#include "Enemy.h"

int Enemy::image = 0;


/*
* コンストラクタ
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
* デストラクタ
*/
Enemy::~Enemy()
{

}

/*
* 更新
*/
void Enemy::Update()
{
	location.y += speed;
}

/*
* 描画
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



