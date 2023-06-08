#include "DxLib.h"
#include "Ranking.h"
#include "SceneManager/Scene/GameMain.h"
#include "System/KeyManager/KeyManager.h"


/****************************************
*�@�ϐ��̐錾
*****************************************/
int RankingImg; //�����L���O�摜

int Ranking;
int GetScore;
int i, j;
//int GetScore;

RankingData work;


//�R���X�g���N�^
Ranking::Ranking()
{
	//�摜�̉��\��
	RankingImg = LoadGraph("images/ranking01.png");
	ReadRanking(work);
}
//�f�X�g���N�^
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
	//�����L���O�摜�\��
	DrawGraph(0, 0, RankingImg, FALSE);
	//�����L���O�ꗗ��\��
	SetFontSize(60);
	for (int i = 0; i < RANK_MAX; i++) {
		DrawFormatString(260, 180 + i * 85, 0x800000, "%2d %-10s %10d", work[i].no, work[i].name, work[i].score);
	}
	DrawString(350, 620, "A�{�^���Ń^�C�g����",0x800000, 0);
}

/***********************************************
 * �����L���O�f�[�^�̕ۑ�
 ***********************************************/
int  SaveRanking(RankingData Ranking[])
{
	FILE* fp;
#pragma warning(disable:4996)

	// �t�@�C���I�[�v��
	if ((fp = fopen("dat/rankingdata.txt", "w")) == NULL) {
		/* �G���[���� */
		printf("Ranking Data Error\n");
		return -1;
	}

	// �����L���O�f�[�^���z��f�[�^����������
	for (int i = 0; i < RANK_MAX; i++) {
		fprintf(fp, "%2d %10s %10d\n", Ranking[i].no, Ranking[i].name, Ranking[i].score);
	}

	//�t�@�C���N���[�Y
	fclose(fp);

	return 0;
}


/***********************************************
 * �����L���O���בւ�
 ***********************************************/
void SortRanking(RankingData Ranking[])
{
	int i, j;
	RankingData work;

	// �I��@�\�[�g
	for (i = 0; i < RANK_MAX - 1; i++) {
		for (j = i + 1; j < RANK_MAX; j++) {
			if (Ranking[i].score <= Ranking[j].score) {
				work = Ranking[i];
				Ranking[i] = Ranking[j];
				Ranking[j] = work;
			}
		}
	}

	// ���ʕt��
	for (i = 0; i < RANK_MAX; i++) {
		Ranking[i].no = 1;
	}
	// ���_�������ꍇ�́A�������ʂƂ���
	// �����ʂ��������ꍇ�̎��̏��ʂ̓f�[�^�������Z���ꂽ���ʂƂ���
	for (i = 0; i < RANK_MAX - 1; i++) {
		for (j = i + 1; j < RANK_MAX; j++) {
			if (Ranking[i].score > Ranking[j].score) {
				Ranking[j].no++;
			}
		}
	}

}

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

