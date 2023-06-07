#include "GameMain.h"
#include "../../Ranking.h"

#include "DxLib.h"

//int sceneCHG = false;
/*
* コンストラクタ
*/
GameMain::GameMain()
{
	//sceneCHG = false;
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
	DrawFormatString(0, 0, 0xffffff, "GameMain");
}