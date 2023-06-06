#include "Title.h"
#include "common.h"
#include "DxLib.h"
#include"System/PadInput/PadInput.h"
Title::Title()
{
	interval = 0;

}

AbstractScene* Title::Update()
{
	if (interval < 30)interval++;
	JoyPadY = PAD_INPUT::GetRStick().y;

	if (JoyPadY > MARGIN && interval >= 30) {
		select--;
		interval = 0;
	}
	else if (JoyPadY < -MARGIN && interval >= 30) {
	
		select++;
		interval = 0;
	}

	if (JoyPadY < MARGIN && -MARGIN < JoyPadY && !PAD_INPUT::OnPressed(XINPUT_BUTTON_B))interval = 30;

	if (select == 0) Menu_Number = TITLE_MENU::START;
	if (select == 1) Menu_Number = TITLE_MENU::RANKING;
	if (select == 2) Menu_Number = TITLE_MENU::END;

	if (select < 0)select = 2;
	if (select > 2)select = 0;

	/*if (PAD_INPUT::OnPressed(XINPUT_BUTTON_B) && interval >= 30) {
		
		if (TITLE_MENU::START == Menu_Number) return new GameMain(); 
		if (TITLE_MENU::RANKING == Menu_Number)return new Ranking(); 
		if (TITLE_MENU::END == Menu_Number)return new End();
		interval = 0;
	}*/






	return this;
}

void Title::Draw()const
{
	
	DrawTriangle(520, 420, 520, 440, 550, 430, 0xffffff, TRUE);
	

	
		SetFontSize(65);
		DrawFormatString(558, D_SCREEN_HEIGHT / 5, 0xffffff, "Title");

		//スタート
		DrawFormatString(558, 400, 0xffffff, "Start");

		//ランキング
		DrawFormatString(558, 470, 0xfffffff, "Ranking");

		//エンド
		DrawFormatString(558, 540, 0xffffff, "End");
	

		

	
	/*DrawLine(D_SCREEN_WIDTH / 2, 0, D_SCREEN_WIDTH / 2, D_SCREEN_HEIGHT, 0xffffff);
	DrawLine(D_SCREEN_WIDTH / 3, 0, D_SCREEN_WIDTH / 3, D_SCREEN_HEIGHT, 0xffffff);
	DrawLine(0, D_SCREEN_HEIGHT / 2, D_SCREEN_WIDTH, D_SCREEN_HEIGHT / 2, 0xffffff);*/

}