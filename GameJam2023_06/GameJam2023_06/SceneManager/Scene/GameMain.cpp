#include "GameMain.h"

#include "DxLib.h"
/*
* �R���X�g���N�^
*/
GameMain::GameMain()
{

}

/*
* �f�X�g���N�^
*/
GameMain::~GameMain()
{

}

/*
* �X�V
* �߂�l ���̃t���[���ōX�V����V�[���̃|�C���^
*/
AbstractScene* GameMain::Update()
{
	return this;
}

/*
* �`��
*/
void GameMain::Draw()const
{
	DrawFormatString(0, 0, 0xffffff, "test");
}