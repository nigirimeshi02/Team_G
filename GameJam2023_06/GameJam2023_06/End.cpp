#pragma once
#include"DxLib.h"
#include"End.h"

#define TIME_LIMIT 300
#define MOVE_SPEED 7

End::End() {
	//������
	TitleImage = LoadGraph("Images/Title.png");
	WaitTime = TIME_LIMIT;
	MoveString = 0;

	//�t�H���g�̒ǉ�
	EndFont1 = CreateFontToHandle("HGS�n�p�p�߯�ߑ�", 70, 8, DX_FONTTYPE_ANTIALIASING);
	EndFont2 = CreateFontToHandle("HGS�n�p�p�߯�ߑ�", 50, 8, DX_FONTTYPE_ANTIALIASING);
	EndFont3 = CreateFontToHandle("HGS�n�p�p�߯�ߑ�", 90, 8, DX_FONTTYPE_ANTIALIASING);

}

End::~End()
{
	DeleteFontToHandle(EndFont1);
	DeleteFontToHandle(EndFont2);
	DeleteFontToHandle(EndFont3);
	//�T�E���h�̍폜
	DeleteSoundMem(EndBGM);
	DeleteSoundMem(EndSE);
}

AbstractScene* End::Update() {
	if (WaitTime-- < 0) {
		return nullptr;
	}
	if (++MoveString >= 200) {
		MoveString = 200;
	}
	return this;
}

void End::Draw()const {
	//�Q�[���I�����
	DrawGraph(0, 0, TitleImage, TRUE);
	DrawStringToHandle(500, 680 - MoveString * MOVE_SPEED, "SE & BGM", 0x0000ff, EndFont1);

	DrawStringToHandle(540, 780 - MoveString * MOVE_SPEED, "OtoLogic", 0x000000, EndFont2);
	DrawStringToHandle(515, 840 - MoveString * MOVE_SPEED, "�������ʉ�", 0x000000, EndFont2);
	DrawStringToHandle(470, 900 - MoveString * MOVE_SPEED, "�Ò��̉��y�H�[", 0x000000, EndFont2);

	DrawStringToHandle(505, 1050 - MoveString * MOVE_SPEED, "�摜�f��", 0xff0000, EndFont1);

	DrawStringToHandle(510, 1150 - MoveString * MOVE_SPEED, "�C���X�g��", 0x000000, EndFont2);
	DrawStringToHandle(545, 1210 - MoveString * MOVE_SPEED, "illustAC", 0x000000, EndFont2);
	DrawStringToHandle(560, 1270 - MoveString * MOVE_SPEED, "illust8", 0x000000, EndFont2);
	DrawStringToHandle(545, 1330 - MoveString * MOVE_SPEED, "SVG Silh", 0x000000, EndFont2);

	DrawStringToHandle(340, 2000 - MoveString * (MOVE_SPEED + 1.5), "Thank You For ", 0x000000, EndFont3);
	DrawStringToHandle(310, 2100 - MoveString * (MOVE_SPEED + 1.5), "Playing Game !!", 0x000000, EndFont3);
}