#include<DxLib.h>
#include"Result.h"
#include"common.h"
#include "Ranking.h"
#include "System/KeyManager/KeyManager.h"

Result::Result(int score, int value)
{
	r_score = score;
	r_value = value;

	backImg = LoadGraph("images/Title.png");
	enemyImg = LoadGraph("images/enemy.png");
}

Result::~Result()
{

}

AbstractScene* Result::Update()
{
	return this;
}

void Result::Draw()
{
	DrawExtendGraph(0, 0, 1279, 719, backImg, TRUE);


	SetFontSize(65);
	//DrawFormatString(508, D_SCREEN_HEIGHT / 5, 0xffffff, "りざると",0x000000);

	DrawRotaGraph(350, 350, 0.3, 0, enemyImg, TRUE);
	DrawString(470, 350, "を切った数", 0xffffff, 0xffffff);
	DrawFormatString(980, 350, 0xffffff, "%d", r_value);

	DrawString(270, 550, "スコア", 0xffffff, 0x000000);
	DrawFormatString(980, 550, 0xffffff, "%d", r_score);

	DrawString(400, 630, "A:進む", 0xffffff);


	SetFontSize(16);
}
