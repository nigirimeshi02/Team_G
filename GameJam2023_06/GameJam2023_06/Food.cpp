#include "DxLib.h"
#include "Food.h"

int Food::image = 0;

/*
* �R���X�g���N�^
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
* �f�X�g���N�^
*/
Food::~Food()
{

}

/*
* �X�V
*/
void Food::Update()
{
	location.y += speed;
}

/*
* �`��
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
