#include "GameMain.h"
#include "../../SlashAction.h"

#include "DxLib.h"
/*
* �R���X�g���N�^
*/
GameMain::GameMain()
{
	slashAction = new SlashAction(
		{ D_SCREEN_WIDTH / 2, D_SCREEN_HEIGHT - 60 - 100 });
	obstacleManager = new ObstacleManager();
}

/*
* �f�X�g���N�^
*/
GameMain::~GameMain()
{
	delete slashAction;
	delete obstacleManager;
}

/*
* �X�V
* �߂�l ���̃t���[���ōX�V����V�[���̃|�C���^
*/
AbstractScene* GameMain::Update()
{
	slashAction->Update();
	obstacleManager->Update();
	CheckHit();

	return this;
}

/*
* �`��
*/
void GameMain::Draw()const
{
	obstacleManager->Draw();

	slashAction->Draw();
	DrawPixel(D_SCREEN_WIDTH / 2, D_SCREEN_HEIGHT - 60 - 100, 0xFF0000);
	DrawFormatString(0, 0, 0xffffff, "test");
}

/*
* �����蔻��`�F�b�N
*/
void GameMain::CheckHit()
{
	vector<ObstacleBase*> obstacles = obstacleManager->GetObstacles();

	for (ObstacleBase* obstacle : obstacles)
	{
		if (obstacle->GetIsShow() && slashAction->HitCheck(obstacle))
		{
			obstacle->ToggleIsShow();
			Enemy* buf = dynamic_cast<Enemy*>(obstacle);
			if(buf != nullptr)
			{
				buf->Test();
			}
		}
	}
}