#include "Food.h"


/*
* �f�t�H���g�R���X�g���N�^
*/
Food::Food()
{




}

/*
* �f�X�g���N�^
*/
Food::~Food()
{


}

/*
* �����t���R���X�g���N�^
*/
Food::Food(Location location, float radius = 5)
	:ObstacleBase(location, radius)
{




	speed = 0;
	isBroken = false;
}