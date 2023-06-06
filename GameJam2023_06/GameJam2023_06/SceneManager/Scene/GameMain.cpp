#include "GameMain.h"

#include "DxLib.h"
/*
* コンストラクタ
*/
GameMain::GameMain()
{
	obstacleManager = new ObstacleManager();
}

/*
* デストラクタ
*/
GameMain::~GameMain()
{
	delete obstacleManager;
}

/*
* 更新
* 戻り値 次のフレームで更新するシーンのポインタ
*/
AbstractScene* GameMain::Update()
{
	obstacleManager->Update();

	return this;
}

/*
* 描画
*/
void GameMain::Draw()const
{
	obstacleManager->Draw();

	DrawFormatString(0, 0, 0xffffff, "test");
}