#include "DxLib.h"
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
* 障害物の生成
* 抽選からやる
*/
void ObstacleManager::CreateObstacle(int ratio_enemy, int ratio_bomb, int ratio_food)
{
	int rand = GetRand(9) + 1;	//1～10の10個の数字を取得

	if(rand<=ratio_enemy)
}

/*
* 
*/


/*
* 
*/

