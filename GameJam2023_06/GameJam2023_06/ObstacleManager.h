#pragma once
#include "ObstacleBase.h"
#include "Food.h"

#include <vector>

#define D_LEVEL_MAX (2)	//��Փx���

#define D_LANE_MAX	(16)	//�����Ă��郌�[���̍ő吔
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
		{0,0,10},{3,5,2}
	};
	vector<ObstacleBase*> obstacles;
	int frameCount;
	int unavailableLane[2];


public:
	void CreateObstacle(int pattern);	//��Q���̐���
	void CreateFood();					//�H�ו��̐���

	int LotteryLane();					//���[���̒��I, x���W�̌v�Z
	void DeleteObstacles();

	vector<ObstacleBase*> GetObstacles()const
	{
		return obstacles;
	}
};

