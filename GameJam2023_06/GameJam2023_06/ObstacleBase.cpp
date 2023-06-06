#include "ObstacleBase.h"

/*
* デフォルトコンストラクタ
*/
ObstacleBase::ObstacleBase()
{

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
ObstacleBase::ObstacleBase(Location location, float radius = 5)
	:SphereCollider(location, radius)
{
	speed = 0;
	isBroken = false;
}
