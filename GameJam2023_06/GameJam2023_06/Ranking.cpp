#include "DxLib.h"
#include "Ranking.h"
#include "SceneManager/Scene/GameMain.h"
#include "System/KeyManager/KeyManager.h"


/****************************************
*　変数の宣言
*****************************************/
int RankingImg; //ランキング画像

int Ranking;
int GetScore;
int i, j;
//int GetScore;

RankingData work;


//コンストラクタ
Ranking::Ranking()
{
	//画像の仮表示
	RankingImg = LoadGraph("images/ranking01.png");
	ReadRanking(work);
}
//デストラクタ
Ranking::~Ranking()
{

}

AbstractScene* Ranking::Update()
{
	if (KeyManager::OnKeyClicked(KEY_INPUT_A))
	{
		return new GameMain();
	}
	return this;
}

void Ranking::Draw()const
{
	//ランキング画像表示
	DrawGraph(0, 0, RankingImg, FALSE);
	//ランキング一覧を表示
	SetFontSize(60);
	for (int i = 0; i < RANK_MAX; i++) {
		DrawFormatString(260, 180 + i * 85, 0x800000, "%2d %-10s %10d", work[i].no, work[i].name, work[i].score);
	}
	DrawString(350, 620, "Aボタンでタイトルへ",0x800000, 0);
}

/***********************************************
 * ランキングデータの保存
 ***********************************************/
int  SaveRanking(RankingData Ranking[])
{
	FILE* fp;
#pragma warning(disable:4996)

	// ファイルオープン
	if ((fp = fopen("dat/rankingdata.txt", "w")) == NULL) {
		/* エラー処理 */
		printf("Ranking Data Error\n");
		return -1;
	}

	// ランキングデータ分配列データを書き込む
	for (int i = 0; i < RANK_MAX; i++) {
		fprintf(fp, "%2d %10s %10d\n", Ranking[i].no, Ranking[i].name, Ranking[i].score);
	}

	//ファイルクローズ
	fclose(fp);

	return 0;
}


/***********************************************
 * ランキング並べ替え
 ***********************************************/
void SortRanking(RankingData Ranking[])
{
	int i, j;
	RankingData work;

	// 選択法ソート
	for (i = 0; i < RANK_MAX - 1; i++) {
		for (j = i + 1; j < RANK_MAX; j++) {
			if (Ranking[i].score <= Ranking[j].score) {
				work = Ranking[i];
				Ranking[i] = Ranking[j];
				Ranking[j] = work;
			}
		}
	}

	// 順位付け
	for (i = 0; i < RANK_MAX; i++) {
		Ranking[i].no = 1;
	}
	// 得点が同じ場合は、同じ順位とする
	// 同順位があった場合の次の順位はデータ個数が加算された順位とする
	for (i = 0; i < RANK_MAX - 1; i++) {
		for (j = i + 1; j < RANK_MAX; j++) {
			if (Ranking[i].score > Ranking[j].score) {
				Ranking[j].no++;
			}
		}
	}

}

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

