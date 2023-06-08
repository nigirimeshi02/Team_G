#include "Title.h"
#include "common.h"
#include "DxLib.h"
#include "Ranking.h"
#include"System/PadInput/PadInput.h"
#include"System/SoundPlayer/SoundPlayer.h"
#include "System/KeyManager/KeyManager.h"
#include "SceneManager/Scene/GameMain.h"

Title::Title()
{
	TitleBGM = SoundPlayer::GetBGM("Title_BGM");
	Cursor_Move = SoundPlayer::GetSE("Cursor_Move");
	Cursor_Enter = SoundPlayer::GetSE("Cursor_Enter");
	Cursor_Cancel = SoundPlayer::GetSE("Cursor_Canccel");
	TitleImage = LoadGraph("Images/Title.png");
	cursor = LoadGraph("Images/cursor.png");
	interval = 0;
	select = 0;
	
	SoundPlayer::PlayBGM(TitleBGM);
}

AbstractScene* Title::Update()
{
	if (interval < 30)interval++;
	JoyPadY = PAD_INPUT::GetLStick().y;

	if (JoyPadY > MARGIN && interval >= 30) {
		SoundPlayer::PlaySE(Cursor_Move, FALSE);
		select--;
		interval = 0;
	}
	else if (JoyPadY < -MARGIN && interval >= 30) {
		SoundPlayer::PlaySE(Cursor_Move, FALSE);
		select++;
		interval = 0;
	}

	if (JoyPadY < MARGIN && -MARGIN < JoyPadY && !PAD_INPUT::OnPressed(XINPUT_BUTTON_B))interval = 30;

	if (select == 0) Menu_Number = TITLE_MENU::START;
	if (select == 1) Menu_Number = TITLE_MENU::RANKING;
	if (select == 2) Menu_Number = TITLE_MENU::END;

	if (select < 0)select = 2;
	if (select > 2)select = 0;

	if (PAD_INPUT::OnPressed(XINPUT_BUTTON_B) && interval >= 30) {
		
		SoundPlayer::PlaySE(Cursor_Enter, TRUE);
		//各シーン
		if (TITLE_MENU::START == Menu_Number) return new GameMain(); 
		//if (TITLE_MENU::RANKING == Menu_Number)return new Ranking(); 
		//if (TITLE_MENU::END == Menu_Number)return new End();
		
		interval = 0;
	}
	if (KeyManager::OnKeyClicked(KEY_INPUT_S))
	{
		return new Ranking();
	}
	
	return this;
}

void Title::Draw()const
{
	//背景画像
	DrawExtendGraph(0, 0, 1279, 719, TitleImage, TRUE);
	
	//カーソル
	DrawGraph(470, 370 + select * 71, cursor, TRUE);
	


	SetFontSize(65);
	//タイトル名
	DrawFormatString(558, D_SCREEN_HEIGHT / 5, 0xff0000, "Title");

	//スタート
	DrawFormatString(558, 400, 0x007f00, "Start");

	//ランキング
	DrawFormatString(558, 470, 0x007f00, "Ranking");

	//エンド
	DrawFormatString(558, 540, 0x007f00, "End");

	SetFontSize(16);
}