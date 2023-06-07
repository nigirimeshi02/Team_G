#include "DxLib.h"
#include "Bomb.h"

int Bomb::image = 0;

/*
* �R���X�g���N�^
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
* �f�X�g���N�^
*/
Bomb::~Bomb()
{

}

/*
* �X�V
*/
void Bomb::Update()
{
	location.y += speed;
}

/*
* �`��
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

