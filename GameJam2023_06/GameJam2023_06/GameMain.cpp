#include<stdio.h>
#include"GameMain.h"
#include"System/SoundPlayer/SoundPlayer.h"
GameMain::GameMain()
{
	TitleBGM = SoundPlayer::GetBGM("BGM");

	SoundPlayer::PlayBGM(TitleBGM);
}
AbstractScene* GameMain::Update() {
	int nInt;
	scanf_s("%d", &nInt);
	if (nInt == 1) {
		return nullptr;
	}
	return this;
}

void GameMain::Draw() const {
	printf("GameMainです。\n");
	printf("整数値を入力してください＞");
}