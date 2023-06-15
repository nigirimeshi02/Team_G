#include "ObstacleBase.h"

/*
* デフォルトコンストラクタ
*/
ObstacleBase::ObstacleBase()
	:frameCount(0),MAX_FRAME(0)
{
	location = { 100,0 };
	score = 100;
	isBroken = false;
}

/*
* デストラクタ
*/
ObstacleBase::~ObstacleBase()
{
	int a = 0;
}

/*
* 引数付きコンストラクタ
*/
ObstacleBase::ObstacleBase(Location location, float radius, float speed, int score , int max_frame)
	:SphereCollider(location, radius)
	, frameCount(0), MAX_FRAME(max_frame)
{
	this->speed = speed;
	this->score = score;
	isBroken = false;
}
