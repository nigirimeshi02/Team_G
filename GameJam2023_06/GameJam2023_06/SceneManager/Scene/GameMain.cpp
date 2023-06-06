#include "GameMain.h"

#include "DxLib.h"
/*
* コンストラクタ
*/
GameMain::GameMain()
{
	enemy = new Enemy({100,100},10);
}

/*
* デストラクタ
*/
GameMain::~GameMain()
{
	delete enemy;
}

/*
* 更新
* 戻り値 次のフレームで更新するシーンのポインタ
*/
AbstractScene* GameMain::Update()
{
	enemy->Update();
	return this;
}

/*
* 描画
*/
void GameMain::Draw()const
{
	enemy->Draw();
	DrawFormatString(0, 0, 0xffffff, "test");
}