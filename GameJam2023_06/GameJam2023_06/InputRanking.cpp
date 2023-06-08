#include "DxLib.h"
#include "InputRanking.h"

const char InputRanking::charSet[D_CHARCTER_MAX] =
{
	'a','b','c','d','e','f','g','h','i',
	'j','k','l','m','n','o','p','q','r',
	's','t','u','v','w','x','y','z'
};

/*
* コンストラクタ
*/
InputRanking::InputRanking()
{
	imageBack = LoadGraph("images/ranking_back.png");//1000 * 700
	imageCircle = LoadGraph("images/circle.png");//100 * 100
	cursor = 3;
}

/*
* デストラクタ
*/
InputRanking::~InputRanking()
{

}

/*
* 更新
*/
AbstractScene* InputRanking::Update()
{
	return this;
}

/*
* 描画
*/
void InputRanking::Draw()const
{
	DrawRotaGraph(D_SCREEN_WIDTH / 2, D_SCREEN_HEIGHT / 2, 1.0, 0, imageBack, TRUE);
	DrawBox(
		(140 + 100), (10 + 100), //画像まで + margin, (画像まで + margin)
		(140 + 100) + 800, (10 + 100) + 100,//x1 + width, y1 + height
		0xffffff, TRUE);

	DrawBox(
		(140 + 100), ((10 + 100) + 100) + 100,//画像まで + margin, (画像まで + margin) + 上のboxの大きさ + margin
		(140 + 100) + 800, (((10 + 100) + 100) + 100) + 300, //x1 + width, y1 + height
		0xffffff, TRUE);

	SetFontSize(64);
	for (int i = 0; i < D_CHARCTER_MAX; i++)
	{
		DrawFormatString(
			(140 + 100) + 50 + (80 * (i % 9)), 310 + 30 + (85 * (i / 9)),
			0, "%c", charSet[i]
		);
	}
	SetFontSize(16);

	DrawGraph(
		(140 + 100) + 20 + (80 * (cursor % 9)),
		310 + 10 + (85 * (cursor / 9))
		,imageCircle, TRUE);
}

/*
* 
*/


/*
* 
*/
