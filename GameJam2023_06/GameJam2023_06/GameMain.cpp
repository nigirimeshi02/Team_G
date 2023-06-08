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
	printf("GameMain‚Å‚·B\n");
	printf("®”’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢„");
}