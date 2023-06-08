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
	imageEat = LoadGraph("Images/UI_eat.png");
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

	SetFontSize(64);
	DrawString(D_LIFE_SPACE, D_GAME_SCREEN_FOOTER + 3, "斬", 0);
	DrawGraph(D_LIFE_SPACE + (D_CHAR_SET * 1), D_GAME_SCREEN_FOOTER + 3, imageEnemy, TRUE);
	DrawFormatString(D_LIFE_SPACE + (D_CHAR_SET * 1) + (D_SET * 1), D_GAME_SCREEN_FOOTER + 3,0, "×%d", *killCount);

	DrawString(D_LIFE_SPACE + (D_CHAR_SET * 1) + (D_SET * 1) + (D_COUNT_SET * 1), D_GAME_SCREEN_FOOTER + 3, "避",0 );
	DrawGraph(D_LIFE_SPACE + (D_CHAR_SET * 2) + (D_SET * 1) + (D_COUNT_SET * 1), D_GAME_SCREEN_FOOTER + 3, imageBomb, TRUE);
	DrawFormatString(D_LIFE_SPACE + (D_CHAR_SET * 2) + (D_SET * 2) + (D_COUNT_SET * 1), D_GAME_SCREEN_FOOTER + 3, 0, "×%d", *avoidCount);
	
	DrawString(D_LIFE_SPACE + (D_CHAR_SET * 2) + (D_SET * 2) + (D_COUNT_SET * 2), D_GAME_SCREEN_FOOTER + 3, "食",0 );
	DrawGraph(D_LIFE_SPACE + (D_CHAR_SET * 3) + (D_SET * 2) + (D_COUNT_SET * 2), D_GAME_SCREEN_FOOTER + 3, imageEat, TRUE);
	DrawFormatString(D_LIFE_SPACE + (D_CHAR_SET * 3) + (D_SET * 3) + (D_COUNT_SET * 2), D_GAME_SCREEN_FOOTER + 3, 0, "×%d", *eatCount);
	
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
