#include "Title.h"
#include "SceneManager/Scene/GameMain.h"
#include "ranking.h"
#include "common.h"
#include "DxLib.h"
#include "Ranking.h"
#include"System/PadInput/PadInput.h"
#include"System/SoundPlayer/SoundPlayer.h"
#include "System/KeyManager/KeyManager.h"
#include "SceneManager/Scene/GameMain.h"
#include"End.h"

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
	ChangeFont("HG行書体");
	
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
		if (TITLE_MENU::RANKING == Menu_Number)return new Ranking(); 
		//if (TITLE_MENU::END == Menu_Number)return new End();
		
		interval = 0;
	}
	return this;
}

void Title::Draw()const
{
	//背景画像
	DrawExtendGraph(0, 0, 1279, 719, TitleImage, TRUE);
	
	//カーソル
	DrawGraph(470, 370 + select * 71, cursor, TRUE);
	
	//DrawLine(D_SCREEN_WIDTH / 2, 0, D_SCREEN_WIDTH / 2, D_SCREEN_HEIGHT, 0xffffff);


	SetFontSize(150);
	//タイトル名
	DrawFormatString(416, D_SCREEN_HEIGHT / 5, 0x000000, "刃舞闘");  //右
	DrawFormatString(412, D_SCREEN_HEIGHT / 5+4, 0x000000, "刃舞闘");  //下
	DrawFormatString(412, D_SCREEN_HEIGHT / 5, 0xff0000, "刃舞闘");  //

	SetFontSize(30);
	//タイトル名
	DrawFormatString(537, D_SCREEN_HEIGHT / 5 - 15, 0x000000, "は　ば　と　う");  //
	DrawFormatString(535, D_SCREEN_HEIGHT / 5 - 13, 0x000000, "は　ば　と　う");  //
	DrawFormatString(535, D_SCREEN_HEIGHT / 5 - 15, 0xff0000, "は　ば　と　う");  //


	SetFontSize(65);
	//スタート
	DrawFormatString(555, 400, 0xffffff, "Start");  //上 
	DrawFormatString(561, 400, 0xffffff, "Start");  //下
	DrawFormatString(558, 403, 0xffffff, "Start");  //右
	DrawFormatString(558, 397, 0xffffff, "Start");  //左
	DrawFormatString(558, 400, 0x007f00, "Start");

	//ランキング
	DrawFormatString(555, 470, 0xffffff, "Ranking");
	DrawFormatString(561, 470, 0xffffff, "Ranking");
	DrawFormatString(558, 473, 0xffffff, "Ranking");
	DrawFormatString(558, 467, 0xffffff, "Ranking");
	DrawFormatString(558, 470, 0x007f00, "Ranking");
	//エンド
	DrawFormatString(555, 540, 0xffffff, "End");
	DrawFormatString(561, 540, 0xffffff, "End");
	DrawFormatString(558, 543, 0xffffff, "End");
	DrawFormatString(558, 537, 0xffffff, "End");
	DrawFormatString(558, 540, 0x007f00, "End");

	SetFontSize(16);
}