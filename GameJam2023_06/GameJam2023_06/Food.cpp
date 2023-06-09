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
		image = LoadGraph("Images/onigiri.png");
	}
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
	DrawRotaGraphF(location.x, location.y, 1.0, 0, image, TRUE);
}

/*
*
*/


/*
*
*/

