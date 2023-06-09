#include "GameMain.h"
#include "../../Ranking.h"

#include "../../Title.h"
#include "ResultScene.h"
#include "../../System/SoundPlayer/SoundPlayer.h"
#include "DxLib.h"
#include "../../System/KeyManager/KeyManager.h"

//int sceneCHG = false;
/*
* �R���X�g���N�^
*/
GameMain::GameMain()
{
	mScene = nullptr;
	player = new Player();
	obstacleManager = new ObstacleManager();
	ui = new UI();
	ui->SetLife(player->GetLife());
	ui->SetKillCount(&killCount);
	ui->SetAvoidCount(obstacleManager->GetCount());
	ui->SetEatCount(&eatCount);

	gameMainBGM = SoundPlayer::GetBGM("GameMain");
	boomSE = SoundPlayer::GetSE("Boom");
	eatSE = SoundPlayer::GetSE("eat");
	imageBack = LoadGraph("images/main.png");
	SoundPlayer::PlayBGM(gameMainBGM);

	score = 0;
	killCount = 0;
	eatCount = 0;

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
	if (mScene != nullptr)
	{
		mScene = mScene->Update();
		if (mScene == nullptr)
		{
			delete mScene;
			return new Ranking(score);
		}
		return this;
	}

	if (isGameEnd)
	{
		frameCount--;
		if (frameCount <= 0)
		{
			mScene = new ResultScene(score, killCount, *(obstacleManager->GetCount()),eatCount);
		}
		return this;		//�ȍ~�̏������~�߂�
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

	if (mScene != nullptr)
	{
		mScene->Draw();
	}
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
				SoundPlayer::PlaySE(boomSE, FALSE);
				player->HitDamage();
			}
			if (dynamic_cast<Enemy*>(obstacle) != nullptr)
			{
				killCount++;
			}
		}
		
		// �v���C���[�{�̂Ƃ̓����蔻��
		if (obstacle->GetIsShow() &&					//�Ώۂ̂��̂������Ă���(�����蔻��������)���H
			player->HitCheck(obstacle))					//�������Ă��邩
		{
			if (dynamic_cast<Food*>(obstacle) != nullptr)	//�H�ו����H
			{
				SoundPlayer::PlaySE(eatSE, FALSE);
				eatCount++;
				score += obstacle->GetScore();
				obstacle->ToggleIsShow();
			}
			else if (player->GetIsInvincible() != true)
			{
				player->HitDamage();
				if (dynamic_cast<Enemy*>(obstacle) != nullptr)	//�G�l�~�[���H(�����Ȃ����́H)
				{
					player->HitEnemy();
					score += (int)(obstacle->GetScore() * -0.2);  //���Z�p
				}
				else											//����ȊO�i���e�j�̏ꍇ
				{
					if(obstacle != nullptr)
					{
						SoundPlayer::PlaySE(boomSE, FALSE);
						score += obstacle->GetScore();
						obstacle->ToggleIsShow();					//����
					}
				}

			}

		}
		
	}
}