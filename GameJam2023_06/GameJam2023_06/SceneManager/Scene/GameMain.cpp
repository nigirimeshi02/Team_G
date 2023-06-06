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
}

/*
* �f�X�g���N�^
*/
GameMain::~GameMain()
{
	delete slashAction;
}

/*
* �X�V
* �߂�l ���̃t���[���ōX�V����V�[���̃|�C���^
*/
AbstractScene* GameMain::Update()
{
	slashAction->Update();
	return this;
}

/*
* �`��
*/
void GameMain::Draw()const
{
	slashAction->Draw();
	DrawPixel(D_SCREEN_WIDTH / 2, D_SCREEN_HEIGHT - 60 - 100, 0xFF0000);
	DrawFormatString(0, 0, 0xffffff, "test");
}