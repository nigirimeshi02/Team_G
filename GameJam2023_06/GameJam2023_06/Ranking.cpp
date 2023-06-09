#include "DxLib.h"
#include "Title.h"
#include "Ranking.h"
#include "InputRanking.h"
#include "SceneManager/Scene/GameMain.h"
#include "System/KeyManager/KeyManager.h"
#include "System/PadInput/PadInput.h"
#include "System/SoundPlayer/SoundPlayer.h"



/****************************************
*�@�ϐ��̐錾
*****************************************/
int RankingImg; //�����L���O�摜

int Ranking;
int GetScore;
int i, j;




//�R���X�g���N�^
Ranking::Ranking(int score)
{
	//�摜�̉��\��
	RankingImg = LoadGraph("images/ranking.png");
	ReadRanking(work);
	SortRanking(work);
	Cursor_Cancel = SoundPlayer::GetSE("Cursor_Cancel");
	newScore = score;
	newName = string();
	mScene = nullptr;
	if (work[4].score < score)
	{
		work[4].score = score;
		mScene = new InputRanking((work[4].name));
	}
}
//�f�X�g���N�^
Ranking::~Ranking()
{
	
}

AbstractScene* Ranking::Update()
{
	if (mScene != nullptr)
	{
		mScene = mScene->Update();
		if (mScene == nullptr)
		{
			delete mScene;
			mScene = nullptr;

			SortRanking(work);
			SaveRanking(work);
		}
		else
		{
			return this;
		}
		//sprintf_s(work[4].name, 10, newName.c_str());
	}


	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		SoundPlayer::PlaySE(Cursor_Cancel, FALSE);
		return new Title();
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
		DrawFormatString(260, 180 + i * 85, 0x8b0000, "%2d %-10s %10d", work[i].no, work[i].name, work[i].score);
	}
	DrawString(350, 620, "A�{�^���Ń^�C�g����",0x8b0000, 0);

	if (mScene != nullptr)
	{
		mScene->Draw();
	}
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

