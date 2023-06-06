#include "GameMain.h"

#include "DxLib.h"
/*
* �R���X�g���N�^
*/
GameMain::GameMain()
{
	obstacleManager = new ObstacleManager();
}

/*
* �f�X�g���N�^
*/
GameMain::~GameMain()
{
	delete obstacleManager;
}

/*
* �X�V
* �߂�l ���̃t���[���ōX�V����V�[���̃|�C���^
*/
AbstractScene* GameMain::Update()
{
	obstacleManager->Update();

	return this;
}

/*
* �`��
*/
void GameMain::Draw()const
{
	obstacleManager->Draw();

	DrawFormatString(0, 0, 0xffffff, "test");
}