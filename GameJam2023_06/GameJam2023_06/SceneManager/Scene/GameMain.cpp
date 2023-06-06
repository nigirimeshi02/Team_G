#include "GameMain.h"

#include "DxLib.h"
/*
* �R���X�g���N�^
*/
GameMain::GameMain()
{
	enemy = new Enemy({100,100},10);
}

/*
* �f�X�g���N�^
*/
GameMain::~GameMain()
{
	delete enemy;
}

/*
* �X�V
* �߂�l ���̃t���[���ōX�V����V�[���̃|�C���^
*/
AbstractScene* GameMain::Update()
{
	enemy->Update();
	return this;
}

/*
* �`��
*/
void GameMain::Draw()const
{
	enemy->Draw();
	DrawFormatString(0, 0, 0xffffff, "test");
}