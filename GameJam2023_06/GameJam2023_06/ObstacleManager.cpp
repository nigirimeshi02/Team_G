#include "DxLib.h"
#include "ObstacleManager.h"

/*
* �f�t�H���g�R���X�g���N�^
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

	if ((frameCount % 450) == 0)
	{
		OBJECT_MAX += 1;
	}
}

/*
* �`��
*/
void ObstacleManager::Draw()const
{
	for (ObstacleBase* obstacle : obstacles)
	{
		obstacle->Draw();
	}
}

/*
* ��Q���̐���
* ���I������
* int pattern ��������p�^�[��
*/
void ObstacleManager::CreateObstacle(int pattern)
{
	for (int i = 0; i < OBJECT_MAX; i++)
	{
		int rand = GetRand(9) + 1;	//1�`10��10�̐������擾

		int Rate = Production_Ratio[pattern][0];	//�G�l�~�[�̂��

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
* �p�ς݂̃I�u�W�F�N�g�̍폜
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