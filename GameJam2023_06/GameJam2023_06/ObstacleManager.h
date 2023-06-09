#pragma once
#include "ObstacleBase.h"
#include "Food.h"
#include "Bomb.h"
#include "Enemy.h"

#include <vector>

#define D_LEVEL_MAX (3)	//難易度上限

#define D_LANE_MAX	(16)	//落ちてくるレーンの最大数
#define D_LANE_WIDTH	(1280 / D_LANE_MAX)



using namespace std;

class ObstacleManager
{
public:
	ObstacleManager();
	~ObstacleManager();

	void Update();
	void Draw()const;

private:
	const int Production_Ratio[D_LEVEL_MAX][3] =
	{
		{5,3,2},{6,2,2},{6,1,3}
	};
	int OBJECT_MAX;
	vector<ObstacleBase*> obstacles;
	int frameCount;
	int unavailableLane[7];
	int avoidCount;

public:
	void CreateObstacle(int pattern);	//障害物の生成
	void CreateEnemy();					//敵の生成
	void CreateBomb();					//爆弾の生成
	void CreateFood();					//食べ物の生成

	float LotteryLane();					//レーンの抽選, x座標の計算
	void DeleteObstacles();				//使い終わったオブジェクトの削除

	vector<ObstacleBase*> GetObstacles()const
	{
		return obstacles;
	}

	const int* GetCount()const { return &avoidCount; }
};

