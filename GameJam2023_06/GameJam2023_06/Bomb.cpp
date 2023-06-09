#include "DxLib.h"
#include "Bomb.h"

int Bomb::image = 0;
int Bomb::bakuhatu_Img= 0;

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
	if (bakuhatu_Img == 0)
	{
		bakuhatu_Img = LoadGraph("Images/bakuhatsu.png");
	}
	bakuhatu_Flg = FALSE;
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

		if (isShow == FALSE)
		{
			bakuhatu_Flg = TRUE;
		}
}

/*
* 描画
*/
void Bomb::Draw()const
{

	if (bakuhatu_Flg != TRUE)
	{
		DrawRotaGraphF(location.x, location.y, 1.0, 0, image, TRUE);
	}
	else
	{
		DrawRotaGraphF(location.x, location.y, 1.0, 0, bakuhatu_Img, TRUE);
	}
}
/*
*
*/


/*
*
*/

