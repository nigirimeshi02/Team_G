#include "UI.h"
#include "DxLib.h"

//変数の宣言
int RoopC = 60;
int TF ;

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

}