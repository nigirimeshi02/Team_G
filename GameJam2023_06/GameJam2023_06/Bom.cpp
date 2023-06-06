#include "Bom.h"


/*
* デフォルトコンストラクタ
*/
Bom::Bom()
{




}

/*
* デストラクタ
*/
Bom::~Bom()
{


}

/*
* 引数付きコンストラクタ
*/
Bom::Bom(Location location, float radius = 5)
	:ObstacleBase(location, radius)
{




	speed = 0;
	isBroken = false;
}

