#include "../../System/PadInput/PadInput.h"
#include "ResultScene.h"
#include "DxLib.h"

/*
* �R���X�g���N�^
*/
ResultScene::ResultScene(int score, int kill_count, int avoid_count, int eat_count)
	:score(score),killCount(kill_count),avoidCount(avoid_count),eatCount(eat_count)
{
	imageBack = LoadGraph("images/Result_back.png");
}

/*
* �f�X�g���N�^
*/
ResultScene::~ResultScene()
{

}

/*
* �X�V
*/
AbstractScene* ResultScene::Update()
{
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		return nullptr;
	}
	return this;
}

/*
* �`��
*/
void ResultScene::Draw()const
{
	DrawRotaGraph(D_SCREEN_WIDTH / 2, D_SCREEN_HEIGHT / 2, 1.0, 0, imageBack, TRUE);
}

/*
* 
*/
