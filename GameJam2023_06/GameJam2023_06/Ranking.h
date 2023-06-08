#pragma once
#include "SceneManager/AbstractScene.h"
#include "Title.h"

#define RANK_MAX (5)
#define NAME_MAX (10)

//構造体
typedef struct {
	int no;
	char name[NAME_MAX];
	long score;
}RankingData;

class Ranking :public AbstractScene
{
public:
	Ranking();
	~Ranking();

	//描画以外の更新を実行
	AbstractScene* Update()override;
	RankingData work[RANK_MAX];

	//描画に関することを実装
	void Draw() const override;

private:
	enum class RANKING_MENU {
		START,
		RANKING,
		END
	};

	RANKING_MENU Menu_Number;

	int interval;
	int select;
	short JoyPadY;
	int RankingImg;//ランキングイメージ
	bool sceneCHG;//シーン変更地
	int Cursor_Cancel;
	
};

//プロトタイプ宣言
int ReadRanking(RankingData Ranking[]);
void SortRanking(RankingData Ranking[]);
