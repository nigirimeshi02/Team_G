#include "ObstacleBase.h"

/*
* デフォルトコンストラクタ
*/
ObstacleBase::ObstacleBase()
{
	location = { 100,0 };
	score = 100;
	isBroken = false;
	isShow = true;
}

/*
* デストラクタ
*/
ObstacleBase::~ObstacleBase()
{

}

/*
* 引数付きコンストラクタ
*/
ObstacleBase::ObstacleBase(Location location, float radius = 5, float speed = 2, int score = 100)
	:SphereCollider(location, radius)
{
	this->speed = speed;
	this->score = score;
	isBroken = false;
	isShow = true;
}
