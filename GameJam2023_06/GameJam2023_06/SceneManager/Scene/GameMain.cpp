#include "GameMain.h"

#include "DxLib.h"
/*
* コンストラクタ
*/
GameMain::GameMain()
{
	enemy = new Enemy({100,100},10);
	food = new Food({ 200,200 }, 10);
	bomb = new Bomb({ 300,300 }, 10);

}

/*
* デストラクタ
*/
GameMain::~GameMain()
{
	delete enemy;
	delete food;
	delete bomb;
}

/*
* 更新
* 戻り値 次のフレームで更新するシーンのポインタ
*/
AbstractScene* GameMain::Update()
{
	enemy->Update();
	food->Update();
	bomb->Update();
	return this;
}

/*
* 描画
*/
void GameMain::Draw()const
{
	enemy->Draw();
	food->Draw();
	bomb->Draw();
	DrawFormatString(0, 0, 0xffffff, "test");
}