#include "ObstacleBase.h"

/*
* �f�t�H���g�R���X�g���N�^
*/
ObstacleBase::ObstacleBase()
{
	location = { 100,0 };
	score = 100;
	isBroken = false;
	isShow = true;
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
ObstacleBase::ObstacleBase(Location location, float radius = 5, float speed = 2, int score = 100)
	:SphereCollider(location, radius)
{
	this->speed = speed;
	this->score = score;
	isBroken = false;
	isShow = true;
}
