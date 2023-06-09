#include "DxLib.h"
#include "ObstacleManager.h"

/*
* デフォルトコンストラクタ
*/
ObstacleManager::ObstacleManager()
{
	frameCount = 0;
	for (int i : unavailableLane)
	{
		i = 0;
	}
	avoidCount = 0;
	OBJECT_MAX = 1;
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

	if ((frameCount % 450) == 0)
	{
		OBJECT_MAX += 1;
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
* int pattern 生成するパターン
*/
void ObstacleManager::CreateObstacle(int pattern)
{
	for (int i = 0; i < OBJECT_MAX; i++)
	{
		int rand = GetRand(9) + 1;	//1〜10の10個の数字を取得

		int Rate = Production_Ratio[pattern][0];	//エネミーのやつ

		if (rand <= Rate)
		{
			CreateEnemy();
		}
		else if (rand <= 10 - Production_Ratio[pattern][1])
		{
			CreateBomb();
		}
		else
		{
			CreateFood();

		}
		if (i % 5 == 0 && i != 0) {
			pattern++;
		}
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
	bool isCovered = true;
	int rand;
	while (isCovered)
	{
		rand = GetRand(D_LANE_MAX - 1);
		for (int lane : unavailableLane)
		{
			if (lane == rand)
			{
				isCovered = true;
				break;
			}
			else
			{
				isCovered = false;
			}
		}
	}

	for (int i = 0; i < 6; i++)
	{
		unavailableLane[i] = unavailableLane[i + 1];
	}
	unavailableLane[6] = rand;

	return  (float)(rand * D_LANE_WIDTH) + (D_LANE_WIDTH / 2);
}



/*
* 用済みのオブジェクトの削除
*/
void ObstacleManager::DeleteObstacles()
{
	for (int i = 0; i < obstacles.size(); i++)
	{
		if (obstacles[i]->IsAbleDelete() == true)
		{
			delete obstacles[i];
			obstacles.erase(obstacles.begin() + i);
		}
		else if (obstacles[i]->GetIsScreenOut() == true &&
				 dynamic_cast<Bomb*>(obstacles[i]) != nullptr)
		{
			avoidCount++;
			delete obstacles[i];
			obstacles.erase(obstacles.begin() + i);
		}
	}
}