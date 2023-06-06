#include "DxLib.h"
#include "Ranking.h"
#include "padkey.h"

/****************************************
*　変数の宣言
*****************************************/
int RankingImg; //ランキング画像

int Ranking;
int GetScore;
int i, j;
RankingData work;

/*************************************
 * ランキングデータ読み込み
 *************************************/
int ReadRanking(RankingData Ranking[])
{
	FILE* fp;
#pragma warning(disable:4996)

	//ファイルオープン
	if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL) {
		//エラー処理
		printf("Ranking Data Error\n");
		return -1;
	}

	//ランキングデータ配分列データを読み込む
	for (int i = 0; i < RANK_MAX; i++) {
		int dammy = fscanf(fp, "%2d %10s %10d", &Ranking[i].no, Ranking[i].name, &Ranking[i].score);
	}

	//ファイルクローズ
	fclose(fp);

	return 0;
}

/*************************************
 * ランキング画像読込
 *************************************/
int LoadRankingImages(void)
{
	// ランキング画像の読込
	if ((RankingImg = LoadGraph("images/ranking.png")) == -1) return -1;
	//背景画像の読み込
	if ((RankingImg = LoadGraph("images/Back.png")) == -1)return -1;
	return 0;
}
//コンストラクタ
Ranking::Ranking()
{
	sceneCHG=false;
}
//デストラクタ
Ranking::~Ranking()
{

}

AbstractScene* Ranking::Update()
{
	return this;
}

void Ranking::Draw()const
{
	//ランキング画像表示
	DrawGraph(0, 0, RankingImg, FALSE);
	// ランキング一覧を表示
	SetFontSize(60);
	for (int i = 0; i < RANK_MAX; i++) {
		/*DrawFormatString(260, 180 + i * 85, 0x000000, "%2d %-10s %10d",
			Ranking[i].no, Ranking[i].name, Ranking[i].score);*/
		DrawFormatString(0, 0, 0xffffff, "ランキング");
	}
}