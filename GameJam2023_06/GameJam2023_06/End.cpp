#pragma once
#include"DxLib.h"
#include"End.h"

#define TIME_LIMIT 300
#define MOVE_SPEED 7

End::End() {
	//ú»
	TitleImage = LoadGraph("Images/Title.png");
	WaitTime = TIME_LIMIT;
	MoveString = 0;

	//tHgÌÇÁ
	EndFont1 = CreateFontToHandle("HGSnppÎß¯ÌßÌ", 70, 8, DX_FONTTYPE_ANTIALIASING);
	EndFont2 = CreateFontToHandle("HGSnppÎß¯ÌßÌ", 50, 8, DX_FONTTYPE_ANTIALIASING);
	EndFont3 = CreateFontToHandle("HGSnppÎß¯ÌßÌ", 90, 8, DX_FONTTYPE_ANTIALIASING);

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
	//Q[I¹æÊ
	DrawGraph(0, 0, TitleImage, TRUE);
	DrawStringToHandle(550, 680 - MoveString * MOVE_SPEED, "BGM", 0x0000ff, EndFont1);

	DrawStringToHandle(400, 780 - MoveString * MOVE_SPEED, "DOVA-SYNDROME", 0x000000, EndFont2);

	DrawStringToHandle(560, 880 - MoveString * MOVE_SPEED, "SE", 0x0000ff, EndFont1);

	DrawStringToHandle(475, 980 - MoveString * MOVE_SPEED, "øÊ¹{", 0x000000, EndFont2);
	DrawStringToHandle(475, 1040 - MoveString * MOVE_SPEED, "øÊ¹H[", 0x000000, EndFont2);
	DrawStringToHandle(400, 1100 - MoveString * MOVE_SPEED, "­Âë¬X^WI", 0x000000, EndFont2);

	DrawStringToHandle(470, 1290 - MoveString * MOVE_SPEED, "æfÞ", 0xff0000, EndFont1);

	DrawStringToHandle(485, 1390 - MoveString * MOVE_SPEED, "CXg®", 0x000000, EndFont2);
	DrawStringToHandle(520, 1450 - MoveString * MOVE_SPEED, "illustAC", 0x000000, EndFont2);
	DrawStringToHandle(535, 1510 - MoveString * MOVE_SPEED, "illust8", 0x000000, EndFont2);
	DrawStringToHandle(520, 1570 - MoveString * MOVE_SPEED, "SVG Silh", 0x000000, EndFont2);

	DrawStringToHandle(340, 2300 - MoveString * (MOVE_SPEED + 1.5), "Thank You For ", 0x000000, EndFont3);
	DrawStringToHandle(310, 2400 - MoveString * (MOVE_SPEED + 1.5), "Playing Game !!", 0x000000, EndFont3);
}