#include "GameMain.h"
#include "../../SlashAction.h"

#include "DxLib.h"
/*
* コンストラクタ
*/
GameMain::GameMain()
{
	slashAction = new SlashAction(
		{ D_SCREEN_WIDTH / 2, D_SCREEN_HEIGHT - 60 - 100 });
	obstacleManager = new ObstacleManager();
}

/*
* デストラクタ
*/
GameMain::~GameMain()
{
	delete slashAction;
	delete obstacleManager;
}

/*
* 更新
* 戻り値 次のフレームで更新するシーンのポインタ
*/
AbstractScene* GameMain::Update()
{
	slashAction->Update();
	obstacleManager->Update();

	return this;
}

/*
* 描画
*/
void GameMain::Draw()const
{
	obstacleManager->Draw();

	slashAction->Draw();
	DrawPixel(D_SCREEN_WIDTH / 2, D_SCREEN_HEIGHT - 60 - 100, 0xFF0000);
	DrawFormatString(0, 0, 0xffffff, "test");
}