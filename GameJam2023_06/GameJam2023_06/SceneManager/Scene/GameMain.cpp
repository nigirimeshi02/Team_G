#include "GameMain.h"
#include "../../Title.h"
#include "../../System/SoundPlayer/SoundPlayer.h"
#include "DxLib.h"
/*
* �R���X�g���N�^
*/
GameMain::GameMain()
{
	player = new Player();
	obstacleManager = new ObstacleManager();
	ui = new UI();
	ui->SetLife(player->GetLife());
	ui->SetScore(&score);

	score = 0;

	gameMainBGM = SoundPlayer::GetBGM("GameMain");
	imageBack = LoadGraph("images/main.png");

	SoundPlayer::PlayBGM(gameMainBGM);

	frameCount = 0;
	isGameEnd = false;
}

/*
* �f�X�g���N�^
*/
GameMain::~GameMain()
{
	delete obstacleManager;
	delete player;
}

/*
* �X�V
* �߂�l ���̃t���[���ōX�V����V�[���̃|�C���^
*/
AbstractScene* GameMain::Update()
{
	if (isGameEnd)
	{
		frameCount--;
		if (frameCount <= 0)
		{
			return new Title();
		}
		return this;
	}

	player->Update();
	obstacleManager->Update();
	CheckHit();

	if (*(player->GetLife()) == 0)
	{
		isGameEnd = true;
		frameCount = 2 * 60;
	}
	return this;
}

/*
* �`��
*/
void GameMain::Draw()const
{
	DrawGraph(0, 0, imageBack,TRUE);

	obstacleManager->Draw();

	player->DrawPlayer();

	ui->Draw();
}

/*
* �����蔻��`�F�b�N
*/
void GameMain::CheckHit()
{
	//�v���C���[�̍U��
	Attack* attack = player->GetAttack();
	//�~���Ă�����̒B
	vector<ObstacleBase*> obstacles = obstacleManager->GetObstacles();

	//�~���Ă�����̂Ƃ̓����蔻��
	for (ObstacleBase* obstacle : obstacles)
	{

		// �v���C���[�̍U���Ƃ̓����蔻��
		if (attack != nullptr &&		//�v���C���[���U�����Ă��邩�H
			obstacle->GetIsShow() &&	//�Ώۂ̂��̂������Ă���(�����蔻��������)���H
			attack->HitCheck(obstacle))	//�������Ă��邩�H
		{
			obstacle->ToggleIsShow();		//�����Ȃ����� 
			// TODO:���]�T������Ή��铮���t���邽�߁AToggleIsBroken�ɂ���
			score += obstacle->GetScore();	//�X�R�A���Z
			if (dynamic_cast<Bomb*>(obstacle) != nullptr)
			{
				player->HitDamage();
			}
		}
		
		// �v���C���[�{�̂Ƃ̓����蔻��
		if (obstacle->GetIsShow() &&					//�Ώۂ̂��̂������Ă���(�����蔻��������)���H
			player->HitCheck(obstacle))					//�������Ă��邩
		{
			if (dynamic_cast<Food*>(obstacle) != nullptr)	//�H�ו����H
			{
				score += obstacle->GetScore();
				obstacle->ToggleIsShow();
			}
			else if (player->GetIsInvincible() != true)
			{
				player->HitDamage();
				if (dynamic_cast<Enemy*>(obstacle) != nullptr)	//�G�l�~�[���H(�����Ȃ����́H)
				{
					score += (int)(obstacle->GetScore() * -0.2);  //���Z�p
				}
				else											//����ȊO�i���e�j�̏ꍇ
				{
					if(obstacle != nullptr)
					{
						score += obstacle->GetScore();
						obstacle->ToggleIsShow();					//����
					}
				}

			}

		}
		
	}
}

/*
* ���������I�u�W�F�N�g�̎�ނ̃`�F�b�N
* ��ނɉ���������
*/
void GameMain::CheckType(ObstacleBase* obstacle)
{
	Enemy* enemy = dynamic_cast<Enemy*>(obstacle);
	if (enemy != nullptr)
	{
		return ;
	}
	
	Bomb* bomb = dynamic_cast<Bomb*>(obstacle);
	if (bomb != nullptr)
	{
		return ;
	}
	
	Food* food = dynamic_cast<Food*>(obstacle);
	if (food != nullptr)
	{
		return ;
	}
} //TODO: �g���H�H�H�H