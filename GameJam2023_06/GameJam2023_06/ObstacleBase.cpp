#include "ObstacleBase.h"

/*
* �f�t�H���g�R���X�g���N�^
*/
ObstacleBase::ObstacleBase()
{

}

/*
* �f�X�g���N�^
*/
ObstacleBase::~ObstacleBase()
{

}

/*
* �����t���R���X�g���N�^
*/
ObstacleBase::ObstacleBase(Location location, float radius = 5)
	:SphereCollider(location, radius)
{
	speed = 0;
	isBroken = false;
}
