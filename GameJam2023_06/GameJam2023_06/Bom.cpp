#include "Bom.h"


/*
* �f�t�H���g�R���X�g���N�^
*/
Bom::Bom()
{




}

/*
* �f�X�g���N�^
*/
Bom::~Bom()
{


}

/*
* �����t���R���X�g���N�^
*/
Bom::Bom(Location location, float radius = 5)
	:ObstacleBase(location, radius)
{




	speed = 0;
	isBroken = false;
}

