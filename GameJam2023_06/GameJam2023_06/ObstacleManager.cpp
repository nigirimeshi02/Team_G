#include "DxLib.h"
#include "ObstacleManager.h"

/*
* �f�t�H���g�R���X�g���N�^
*/
ObstacleManager::ObstacleManager()
{
	frameCount = 0;
	unavailableLane[0] = GetRand(GetRand(D_LANE_MAX - 1));
	unavailableLane[1] = GetRand(GetRand(D_LANE_MAX - 1));
	
}

/*
* �f�X�g���N�^
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
* �X�V
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
* �`��
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
* ��Q���̐���
* ���I������
* int pattern ��������p�^�[��
*/
void ObstacleManager::CreateObstacle(int pattern)
{
	int rand = GetRand(9) + 1;	//1�`10��10�̐������擾
	if ((D_LEVEL_MAX - 1) < pattern)
	{
		pattern = D_LEVEL_MAX - 1;
	}

	int ratio = Production_Ratio[pattern][0];	//�G�l�~�[�̂��

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
* �G�̐�������
*/
void ObstacleManager::CreateEnemy()
{
	Location location;
	location.x = LotteryLane();
	location.y = 50;
	obstacles.push_back(new Enemy(location, D_LANE_WIDTH / 2));
}

/*
* ���e�̐�������
*/
void ObstacleManager::CreateBomb()
{
	Location location;
	location.x = LotteryLane();
	location.y = 50;
	obstacles.push_back(new Bomb(location, D_LANE_WIDTH / 2));
}

/*
* �H�ו��̐�������
*/
void ObstacleManager::CreateFood()
{
	Location location;
	location.x = LotteryLane();
	location.y = 50;
	obstacles.push_back(new Food(location, D_LANE_WIDTH / 2));
}

/*
* ���[���̒��I
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
* �p�ς݂̃I�u�W�F�N�g�̍폜
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