#include "Title.h"
#include "common.h"
#include "DxLib.h"

Title::Title()
{


}

AbstractScene* Title::Update()
{


	return this;
}

void Title::Draw()const
{
	
	
		SetFontSize(65);
		DrawFormatString(558, D_SCREEN_HEIGHT / 5, 0xffffff, "Title");

		//スタート
		DrawFormatString(558, 400, 0xffffff, "Start");

		//ランキング
		DrawFormatString(558, 470, 0xfffffff, "Ranking");

		//エンド
		DrawFormatString(558, 540, 0xffffff, "End");
	

		//カーソル
		DrawTriangle(520, 420, 520, 440, 550, 430, 0xffffff, TRUE);


	
	/*DrawLine(D_SCREEN_WIDTH / 2, 0, D_SCREEN_WIDTH / 2, D_SCREEN_HEIGHT, 0xffffff);
	DrawLine(D_SCREEN_WIDTH / 3, 0, D_SCREEN_WIDTH / 3, D_SCREEN_HEIGHT, 0xffffff);
	DrawLine(0, D_SCREEN_HEIGHT / 2, D_SCREEN_WIDTH, D_SCREEN_HEIGHT / 2, 0xffffff);*/

}