#include "GameMain.h"
#include "../../Ranking.h"
#include "../../padkey.h"

#include "DxLib.h"

int sceneCHG = false;
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
	if (padkey::OnClick(XINPUT_BUTTON_A)) {
		sceneCHG = true;
		return new Ranking();
	}
	return this;
}

/*
* �`��
*/
void GameMain::Draw()const
{
	DrawFormatString(0, 0, 0xffffff, "test");
}