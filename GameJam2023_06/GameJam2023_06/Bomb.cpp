#include "DxLib.h"
#include "Bomb.h"

int Bomb::image = 0;

/*
* コンストラクタ
*/
Bomb::Bomb(Location location, float radius, float speed, int score)
	:ObstacleBase(location, radius, speed, score)
{
	if (image == 0)
	{
		image = LoadGraph("Images/bomb.png");
	}
	bomb.emplace_back(100);
}

/*
* デストラクタ
*/
Bomb::~Bomb()
{

}

/*
* 更新
*/
void Bomb::Update()
{
	location.y += speed;
}

/*
* 描画
*/
void Bomb::Draw()const
{
	DrawRotaGraphF(location.x, location.y, 1.0, 0, image, TRUE);
}

/*
*
*/


/*
*
*/

