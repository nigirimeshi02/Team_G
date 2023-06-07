#include "DxLib.h"
#include "Food.h"

int Food::image = 0;

/*
* コンストラクタ
*/
Food::Food(Location location, float radius, float speed, int score)
	:ObstacleBase(location, radius, speed, score)
{
	if (image == 0)
	{
		image = LoadGraph("Images/banana.png");
	}
	food.emplace_back(100);
}

/*
* デストラクタ
*/
Food::~Food()
{

}

/*
* 更新
*/
void Food::Update()
{
	location.y += speed;
}

/*
* 描画
*/
void Food::Draw()const
{
	SphereCollider::Draw();
	DrawRotaGraphF(location.x, location.y, 0.5, 0, image, TRUE);
}

/*
*
*/


/*
*
*/

