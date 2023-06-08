#include "GameMain.h"

#include "DxLib.h"

int bananaImg;
int EnemyImg;
int heartImgs[3];

// �̗͂̏������
int heartMax = 3;
int KeyPressed = FALSE;

/*
* �R���X�g���N�^
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
* �f�X�g���N�^
*/
GameMain::~GameMain()
{

}

/*
* �X�V
* �߂�l ���̃t���[���ōX�V����V�[���̃|�C���^
*/
AbstractScene* GameMain::Update()
{
	return this;
}

/*
* �`��
*/
void GameMain::Draw()const
{
	DrawBox(0, 650, 1280, 720, 0xa0522d, TRUE);

	// �܂�Ղ��Q�[�W�̕\��
	DrawExtendGraph(420, 660,470,710, bananaImg, TRUE);
	DrawBox(490, 670, 750, 700, 0xffffff, TRUE);

	// �G�̌��j���̕\��
	SetFontSize(40);
	DrawExtendGraph(935, 655, 995, 715, EnemyImg, TRUE);
	DrawFormatString(1000, 665, 0xffffff, "�~ 0");
	//DrawFormatString(1000, 665, 0xffffff, "�~ %3d", gEnemyCount);

	DrawFormatString(0, 0, 0xffffff, "test");

	int SpaceKeyState = CheckHitKey(KEY_INPUT_SPACE);

	// SPACE�L�[���������Ƒ̗͂�����
	if (SpaceKeyState && !KeyPressed)
	{
		if (heartMax > 0)
			heartMax--;
		KeyPressed = TRUE;//�L�[�������ꂽ�t���O�𗧂Ă�
	}

	// SPACE�L�[�𗣂��ƃt���O�����Z�b�g
	if (!SpaceKeyState && KeyPressed)
	{
		KeyPressed = FALSE;
	}
	
	// �̗͂̕\��
	for (int i = 0; i < heartMax; i++)
	{
		DrawExtendGraph(110 + (i * 50), 660, 160 + (i * 50), 710, heartImgs[i], TRUE);
	}
}