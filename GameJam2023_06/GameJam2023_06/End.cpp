#pragma once
#include"DxLib.h"
#include"End.h"

#define TIME_LIMIT 300
#define MOVE_SPEED 7

End::End() {
	//初期化
	TitleImage = LoadGraph("Images/Title.png");
	WaitTime = TIME_LIMIT;
	MoveString = 0;

	//フォントの追加
	EndFont1 = CreateFontToHandle("HGS創英角ﾎﾟｯﾌﾟ体", 70, 8, DX_FONTTYPE_ANTIALIASING);
	EndFont2 = CreateFontToHandle("HGS創英角ﾎﾟｯﾌﾟ体", 50, 8, DX_FONTTYPE_ANTIALIASING);
	EndFont3 = CreateFontToHandle("HGS創英角ﾎﾟｯﾌﾟ体", 90, 8, DX_FONTTYPE_ANTIALIASING);

}

End::~End()
{
	DeleteFontToHandle(EndFont1);
	DeleteFontToHandle(EndFont2);
	DeleteFontToHandle(EndFont3);
}

AbstractScene* End::Update() {
	if (WaitTime-- < 0) {
		return nullptr;
	}
	if (++MoveString >= 240) {
		MoveString = 240;
	}
	return this;
}

void End::Draw()const {
	//ゲーム終了画面
	DrawGraph(0, 0, TitleImage, TRUE);
	DrawStringToHandle(550, 680 - MoveString * MOVE_SPEED, "BGM", 0x0000ff, EndFont1);

	DrawStringToHandle(400, 780 - MoveString * MOVE_SPEED, "DOVA-SYNDROME", 0x000000, EndFont2);

	DrawStringToHandle(560, 880 - MoveString * MOVE_SPEED, "SE", 0x0000ff, EndFont1);

	DrawStringToHandle(475, 980 - MoveString * MOVE_SPEED, "効果音ラボ", 0x000000, EndFont2);
	DrawStringToHandle(475, 1040 - MoveString * MOVE_SPEED, "効果音工房", 0x000000, EndFont2);
	DrawStringToHandle(400, 1100 - MoveString * MOVE_SPEED, "くつろぎスタジオ", 0x000000, EndFont2);

	DrawStringToHandle(470, 1290 - MoveString * MOVE_SPEED, "画像素材", 0xff0000, EndFont1);

	DrawStringToHandle(485, 1390 - MoveString * MOVE_SPEED, "いらすとや", 0x000000, EndFont2);
	DrawStringToHandle(485, 1450 - MoveString * MOVE_SPEED, "みんちりえ", 0x000000, EndFont2);
	DrawStringToHandle(415, 1510 - MoveString * MOVE_SPEED, "フレームぽけっと", 0x000000, EndFont2);
	DrawStringToHandle(520, 1570 - MoveString * MOVE_SPEED, "illustAC", 0x000000, EndFont2);

	DrawStringToHandle(340, 2300 - MoveString * (MOVE_SPEED + 1.5), "Thank You For ", 0x000000, EndFont3);
	DrawStringToHandle(310, 2400 - MoveString * (MOVE_SPEED + 1.5), "Playing Game !!", 0x000000, EndFont3);
}