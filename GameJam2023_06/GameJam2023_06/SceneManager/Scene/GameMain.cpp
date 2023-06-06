#include "GameMain.h"
#include "../../Ranking.h"
#include "../../padkey.h"

#include "DxLib.h"

int sceneCHG = false;
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
	if (padkey::OnClick(XINPUT_BUTTON_A)) {
		sceneCHG = true;
		return new Ranking();
	}
	return this;
}

/*
* 描画
*/
void GameMain::Draw()const
{
	DrawFormatString(0, 0, 0xffffff, "test");
}