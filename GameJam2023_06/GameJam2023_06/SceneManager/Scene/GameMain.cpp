#include "GameMain.h"

#include "DxLib.h"

int bananaImg;
int EnemyImg;
int heartImgs[3];

// 体力の初期状態
int heartMax = 3;
int KeyPressed = FALSE;

/*
* コンストラクタ
*/
GameMain::GameMain()
{
	bananaImg = LoadGraph("images/banana.png");
	EnemyImg = LoadGraph("images/enemy.png");
	heartImgs[0] = LoadGraph("images/heart.png");
	heartImgs[1] = LoadGraph("images/heart.png");
	heartImgs[2] = LoadGraph("images/heart.png");
}

/*
* デストラクタ
*/
GameMain::~GameMain()
{

}

/*
* 更新
* 戻り値 次のフレームで更新するシーンのポインタ
*/
AbstractScene* GameMain::Update()
{
	return this;
}

/*
* 描画
*/
void GameMain::Draw()const
{
	DrawBox(0, 650, 1280, 720, 0xa0522d, TRUE);

	// まんぷくゲージの表示
	DrawExtendGraph(420, 660,470,710, bananaImg, TRUE);
	DrawBox(490, 670, 750, 700, 0xffffff, TRUE);

	// 敵の撃破数の表示
	SetFontSize(40);
	DrawExtendGraph(935, 655, 995, 715, EnemyImg, TRUE);
	DrawFormatString(1000, 665, 0xffffff, "× 0");
	//DrawFormatString(1000, 665, 0xffffff, "× %3d", gEnemyCount);

	DrawFormatString(0, 0, 0xffffff, "test");

	int SpaceKeyState = CheckHitKey(KEY_INPUT_SPACE);

	// SPACEキーが押されると体力が減る
	if (SpaceKeyState && !KeyPressed)
	{
		if (heartMax > 0)
			heartMax--;
		KeyPressed = TRUE;//キーが押されたフラグを立てる
	}

	// SPACEキーを離すとフラグをリセット
	if (!SpaceKeyState && KeyPressed)
	{
		KeyPressed = FALSE;
	}
	
	// 体力の表示
	for (int i = 0; i < heartMax; i++)
	{
		DrawExtendGraph(110 + (i * 50), 660, 160 + (i * 50), 710, heartImgs[i], TRUE);
	}
}