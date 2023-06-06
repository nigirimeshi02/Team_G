#include "Food.h"


/*
* デフォルトコンストラクタ
*/
Food::Food()
{




}

/*
* デストラクタ
*/
Food::~Food()
{


}

/*
* 引数付きコンストラクタ
*/
Food::Food(Location location, float radius = 5)
	:ObstacleBase(location, radius)
{




	speed = 0;
	isBroken = false;
}