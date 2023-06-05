#include "GameMain.h"

#include "DxLib.h"
/*
* コンストラクタ
*/
GameMain::GameMain()
{

}

/*
* デストラクタ
*/
GameMain::~GameMain()
{

}

/*
* 更新
* 戻り値 次のフレームで更新するシーンのポインタ
*/
AbstractScene* GameMain::Update()
{
	return this;
}

/*
* 描画
*/
void GameMain::Draw()const
{
	DrawFormatString(0, 0, 0xffffff, "test");
}