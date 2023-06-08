#pragma once
#include "ObstacleBase.h"
#include "Food.h"
#include "Bomb.h"
#include "Enemy.h"

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
		{5,3,2},{3,5,2}
	};
	vector<ObstacleBase*> obstacles;
	int frameCount;
	int unavailableLane[2];

public:
	void CreateObstacle(int pattern);	//��Q���̐���
	void CreateEnemy();					//�G�̐���
	void CreateBomb();					//���e�̐���
	void CreateFood();					//�H�ו��̐���

	float LotteryLane();					//���[���̒��I, x���W�̌v�Z
	void DeleteObstacles();				//�g���I������I�u�W�F�N�g�̍폜

	vector<ObstacleBase*> GetObstacles()const
	{
		return obstacles;
	}
};

