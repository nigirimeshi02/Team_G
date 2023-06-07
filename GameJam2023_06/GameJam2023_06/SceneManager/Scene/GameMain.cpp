#include "GameMain.h"

#include "DxLib.h"
/*
* �R���X�g���N�^
*/
GameMain::GameMain()
{
	enemy = new Enemy({100,100},10);
	food = new Food({ 200,200 }, 10);
	bomb = new Bomb({ 300,300 }, 10);

}

/*
* �f�X�g���N�^
*/
GameMain::~GameMain()
{
	delete enemy;
	delete food;
	delete bomb;
}

/*
* �X�V
* �߂�l ���̃t���[���ōX�V����V�[���̃|�C���^
*/
AbstractScene* GameMain::Update()
{
	enemy->Update();
	food->Update();
	bomb->Update();
	return this;
}

/*
* �`��
*/
void GameMain::Draw()const
{
	enemy->Draw();
	food->Draw();
	bomb->Draw();
	DrawFormatString(0, 0, 0xffffff, "test");
}