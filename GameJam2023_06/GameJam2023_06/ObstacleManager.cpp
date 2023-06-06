#include "ObstacleManager.h"

/*
* �f�t�H���g�R���X�g���N�^
*/
ObstacleManager::ObstacleManager()
{
	frameCount = 0;
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
* 
*/


/*
* 
*/


/*
* 
*/

