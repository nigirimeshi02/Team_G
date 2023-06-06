#include "DxLib.h"
#include "Ranking.h"
#include "padkey.h"

/****************************************
*�@�ϐ��̐錾
*****************************************/
int RankingImg; //�����L���O�摜

int Ranking;
int GetScore;
int i, j;
RankingData work;

/*************************************
 * �����L���O�f�[�^�ǂݍ���
 *************************************/
int ReadRanking(RankingData Ranking[])
{
	FILE* fp;
#pragma warning(disable:4996)

	//�t�@�C���I�[�v��
	if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL) {
		//�G���[����
		printf("Ranking Data Error\n");
		return -1;
	}

	//�����L���O�f�[�^�z����f�[�^��ǂݍ���
	for (int i = 0; i < RANK_MAX; i++) {
		int dammy = fscanf(fp, "%2d %10s %10d", &Ranking[i].no, Ranking[i].name, &Ranking[i].score);
	}

	//�t�@�C���N���[�Y
	fclose(fp);

	return 0;
}

/*************************************
 * �����L���O�摜�Ǎ�
 *************************************/
int LoadRankingImages(void)
{
	// �����L���O�摜�̓Ǎ�
	if ((RankingImg = LoadGraph("images/ranking.png")) == -1) return -1;
	//�w�i�摜�̓ǂݍ�
	if ((RankingImg = LoadGraph("images/Back.png")) == -1)return -1;
	return 0;
}
//�R���X�g���N�^
Ranking::Ranking()
{
	sceneCHG=false;
}
//�f�X�g���N�^
Ranking::~Ranking()
{

}

AbstractScene* Ranking::Update()
{
	return this;
}

void Ranking::Draw()const
{
	//�����L���O�摜�\��
	DrawGraph(0, 0, RankingImg, FALSE);
	// �����L���O�ꗗ��\��
	SetFontSize(60);
	for (int i = 0; i < RANK_MAX; i++) {
		/*DrawFormatString(260, 180 + i * 85, 0x000000, "%2d %-10s %10d",
			Ranking[i].no, Ranking[i].name, Ranking[i].score);*/
		DrawFormatString(0, 0, 0xffffff, "�����L���O");
	}
}