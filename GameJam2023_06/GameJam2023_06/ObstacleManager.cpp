#include "DxLib.h"
#include "ObstacleManager.h"

/*
* デフォルトコンストラクタ
*/
ObstacleManager::ObstacleManager()
{
	frameCount = 0;
	unavailableLane[0] = GetRand(GetRand(D_LANE_MAX - 1));
	unavailableLane[1] = GetRand(GetRand(D_LANE_MAX - 1));
	
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
	DeleteObstacles();

	for (ObstacleBase* obstacle : obstacles)
	{
		obstacle->Update();
	}

	if ((frameCount % 45) == 0)
	{
		CreateObstacle(0);
	}
}

/*
* 描画
*/
void ObstacleManager::Draw()const
{
	for (ObstacleBase* obstacle : obstacles)
	{
		if (obstacle->GetIsShow())
		{
			obstacle->Draw();
		}
	}
}

/*
* 障害物の生成
* 抽選からやる
* int pattern 生成するパターン
*/
void ObstacleManager::CreateObstacle(int pattern)
{
	int rand = GetRand(9) + 1;	//1～10の10個の数字を取得
	if ((D_LEVEL_MAX - 1) < pattern)
	{
		pattern = D_LEVEL_MAX - 1;
	}

	int ratio = Production_Ratio[pattern][0];	//エネミーのやつ

	if (rand <= ratio)
	{
		CreateEnemy();
	}
	else if (rand <= (ratio += Production_Ratio[pattern][1]))
	{
		CreateBomb();
	}
	else
	{
		CreateFood();
	}
}

/*
* 敵の生成処理
*/
void ObstacleManager::CreateEnemy()
{
	Location location;
	location.x = LotteryLane();
	location.y = 50;
	obstacles.push_back(new Enemy(location, D_LANE_WIDTH / 2));
}

/*
* 爆弾の生成処理
*/
void ObstacleManager::CreateBomb()
{
	Location location;
	location.x = LotteryLane();
	location.y = 50;
	obstacles.push_back(new Bomb(location, D_LANE_WIDTH / 2));
}

/*
* 食べ物の生成処理
*/
void ObstacleManager::CreateFood()
{
	Location location;
	location.x = LotteryLane();
	location.y = 50;
	obstacles.push_back(new Food(location, D_LANE_WIDTH / 2));
}

/*
* レーンの抽選
*/
float ObstacleManager::LotteryLane()
{
	int rand = GetRand(D_LANE_MAX - 1);
	while (unavailableLane[0] == rand || unavailableLane[1] == rand)
	{
		rand = GetRand(D_LANE_MAX - 1);
	}

	unavailableLane[1] = unavailableLane[0];
	unavailableLane[0] = rand;

	return  (float)(rand * D_LANE_WIDTH) + (D_LANE_WIDTH / 2);
}



/*
* 用済みのオブジェクトの削除
*/
void ObstacleManager::DeleteObstacles()
{
	for (int i = 0; i < obstacles.size(); i++)
	{
		if (obstacles[i]->GetIsShow() == false ||
			obstacles[i]->GetIsScreenOut() == true)
		{
			delete obstacles[i];
			obstacles.erase(obstacles.begin() + i);
		}
	}
}