#include<stdio.h>
#include"GameMain.h"
#include"System/SoundPlayer/SoundPlayer.h"
#include "Ranking.h"

GameMain::GameMain()
{
	MainBGM = SoundPlayer::GetBGM("GameMain");

	SoundPlayer::PlayBGM(MainBGM);
}
AbstractScene* GameMain::Update() {
	int nInt;mmm
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