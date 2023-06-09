#include "DxLib.h"
#include "InputRanking.h"
#include "Ranking.h"
#include "System/SoundPlayer/SoundPlayer.h"

const char InputRanking::charSet[D_CHARACTER_MAX] =
{
	'a','b','c','d','e','f','g','h','i',
	'j','k','l','m','n','o','p','q','r',
	's','t','u','v','w','x','y','z'
};

/*
* コンストラクタ
*/
InputRanking::InputRanking(char t[])
{
	seCursorMove = SoundPlayer::GetSE("Cursor_Move");
	seCursorEnter = SoundPlayer::GetSE("Cursor_Enter");
	imageBack = LoadGraph("images/ranking_back.png");//1000 * 700
	imageCircle = LoadGraph("images/circle.png");//100 * 100
	cursor = 0;
	interval = 0;
	pName = t;
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
	if (interval < D_INTERVAL)
	{
		interval++;
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		if (name.size() >= NAME_MAX-1)
		{
			name.erase(name.end() - 1);
		}
		name = name + charSet[cursor];
		SoundPlayer::PlaySE(seCursorEnter, false);
	}
	
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		name.erase(name.end() - 1);
	}

	if ( InputUp() && interval >= D_INTERVAL)
	{
		SoundPlayer::PlaySE(seCursorMove, false);
		cursor -= D_COL;
		if (cursor < 0)
		{
			cursor = (D_COL * D_ROW) + cursor;
			if (D_CHARACTER_MAX - 1 < cursor)
			{
				cursor -= D_COL;
			}
		}
		interval = 0;
	}
	else if (InputDown() && interval >= D_INTERVAL)
	{
		SoundPlayer::PlaySE(seCursorMove, false);
		cursor += D_COL;
		if (D_CHARACTER_MAX - 1 < cursor)
		{
			cursor = cursor % D_COL;
		}
		interval = 0;
	}
	else if (InputRight() && interval >= D_INTERVAL)
	{
		SoundPlayer::PlaySE(seCursorMove, false);
		cursor++;
		if (cursor % D_COL == 0)
		{
			cursor -= D_COL;
		}
		if (D_CHARACTER_MAX - 1 < cursor)
		{
			cursor = D_COL * (D_ROW - 1);
		}
		interval = 0;
	}
	else if (InputLeft() && interval >= D_INTERVAL)
	{
		SoundPlayer::PlaySE(seCursorMove, false);
		if (cursor % D_COL == 0)
		{
			cursor += D_COL;
			if (D_CHARACTER_MAX - 1 < cursor)
			{
				cursor--;
			}
		}
		cursor--;
		interval = 0;
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_START) &&
		name.size() > 0)
	{
		sprintf_s(pName, 10, name.c_str());
		return nullptr;
	}

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
	for (int i = 0; i < D_CHARACTER_MAX; i++)
	{
		DrawFormatString(
			(140 + 100) + 50 + (80 * (i % D_COL)), 310 + 30 + (85 * (i / D_COL)),
			0, "%c", charSet[i]
		);
	}

	DrawFormatString((140 + 100) + 50, (10 + 100) + 30,
		0, "%s", name.c_str());


	SetFontSize(16);

	DrawGraph(
		(140 + 100) + 20 + (80 * (cursor % D_COL)),
		310 + 10 + (85 * (cursor / D_COL))
		,imageCircle, TRUE);

	SetFontSize(64);

	DrawString(200, 630, "A:入力 B:一つ戻る START:決定", 0xffffff);
}

/*
* 
*/


/*
* 
*/
