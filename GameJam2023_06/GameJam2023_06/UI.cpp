#include "UI.h"
#include "DxLib.h"

/*
* コンストラクタ
*/
UI::UI()
{
	imageBack = LoadGraph("images/UI_back.png");
	imagePlayerLife = LoadGraph("Images/UI_life.png");
	imageEnemy = LoadGraph("Images/UI_enemy.png");
	imageBomb = LoadGraph("Images/UI_bomb.png");
}

/*
* デストラクタ
*/
UI::~UI()
{

}

/*
* 描画
*/
void UI::Draw()const
{
	DrawGraph(0, D_GAME_SCREEN_FOOTER, imageBack, TRUE);
	for (int i = 0; i < (*life); i++)
	{
		DrawGraph(20 + (i * (81 + 20)), D_GAME_SCREEN_FOOTER + 3, imagePlayerLife, TRUE);
	}

	DrawGraph(D_LIFE_SPACE, D_GAME_SCREEN_FOOTER + 3, imageEnemy, TRUE);
	DrawGraph(D_LIFE_SPACE, D_GAME_SCREEN_FOOTER + 3, imageBomb, TRUE);
	
	SetFontSize(64);
	DrawFormatString(D_LIFE_SPACE + (101 * 2), D_GAME_SCREEN_FOOTER + 3, 0x00ff00,
		"SCORE: %d", (*score));
	SetFontSize(16);
}

/*
* 
*/


/*
* コンストラクタ
*/


/*
* コンストラクタ
*/
