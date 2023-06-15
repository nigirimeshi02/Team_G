#include "ObstacleBase.h"

/*
* �f�t�H���g�R���X�g���N�^
*/
ObstacleBase::ObstacleBase()
	:frameCount(0),MAX_FRAME(0)
{
	location = { 100,0 };
	score = 100;
	isBroken = false;
}

/*
* �f�X�g���N�^
*/
ObstacleBase::~ObstacleBase()
{
	int a = 0;
}

/*
* �����t���R���X�g���N�^
*/
ObstacleBase::ObstacleBase(Location location, float radius, float speed, int score , int max_frame)
	:SphereCollider(location, radius)
	, frameCount(0), MAX_FRAME(max_frame)
{
	this->speed = speed;
	this->score = score;
	isBroken = false;
}
