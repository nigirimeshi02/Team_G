#include "ObstacleManager.h"

/*
* デフォルトコンストラクタ
*/
ObstacleManager::ObstacleManager()
{
	frameCount = 0;
}

/*
* デストラクタ
*/
ObstacleManager::~ObstacleManager()
{
	for (ObstacleBase* obstacle : obstacles)
	{
		delete obstacle;
	}
	obstacles.clear();
}

/*
* 更新
*/
void ObstacleManager::Update()
{
	frameCount++;

	for (ObstacleBase* obstacle : obstacles)
	{
		obstacle->Update();
	}

	if ((frameCount % 45) == 0)
	{
		obstacles.push_back(new Food());
	}
}

/*
* 描画
*/
void ObstacleManager::Draw()const
{
	for (ObstacleBase* obstacle : obstacles)
	{
		obstacle->Draw();
	}
}

/*
* 
*/


/*
* 
*/


/*
* 
*/

