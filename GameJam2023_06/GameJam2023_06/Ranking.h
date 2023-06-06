#pragma once
#include "SceneManager/AbstractScene.h"

#define RANK_MAX (5)
#define NAME_MAX (10)

typedef struct {
	int no;
	char name[NAME_MAX];
	long score;
}RankingData;

class Ranking :
	public AbstractScene
{
public:
	Ranking();
	~Ranking();

	//描画以外の更新を実行
	AbstractScene* Update()override;
	
	//描画に関することを実装
	void Draw() const override;

private:
	bool sceneCHG;  //シーン変更値

};

//プロトタイプ宣言
int ReadRanking(RankingData Ranking[]);
