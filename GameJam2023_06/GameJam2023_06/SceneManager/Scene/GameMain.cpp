#include "GameMain.h"
#include "../../Ranking.h"

#include "DxLib.h"

//int sceneCHG = false;
/*
* �R���X�g���N�^
*/
GameMain::GameMain()
{
	//sceneCHG = false;
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
	DrawFormatString(0, 0, 0xffffff, "GameMain");
}