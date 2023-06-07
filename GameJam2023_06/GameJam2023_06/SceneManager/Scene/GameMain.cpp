#include "GameMain.h"
#include "../../SlashAction.h"

#include "DxLib.h"
/*
* �R���X�g���N�^
*/
GameMain::GameMain()
{
	player = new Player();
	obstacleManager = new ObstacleManager();
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
	player->PlayerControl();
	obstacleManager->Update();
	CheckHit();

	return this;
}

/*
* �`��
*/
void GameMain::Draw()const
{
	obstacleManager->Draw();

	player->DrawPlayer();
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
		if (attack != nullptr &&		//�v���C���[���U�����Ă��邩�H
			obstacle->GetIsShow() &&	//�Ώۂ̂��̂������Ă���(�����蔻��������)���H
			attack->HitCheck(obstacle))	//�������Ă��邩�H
		{
			obstacle->ToggleIsShow();	//�����Ȃ����� 
			// TODO:���]�T������Ή��铮���t���邽�߁AToggleIsBroken�ɂ���
			/*Enemy* buf = dynamic_cast<Enemy*>(obstacle);
			if (buf != nullptr)
			{
				buf->Test();
			}*/
		}
		
		if (obstacle->GetIsShow() &&
			player->HitCheck(obstacle))
		{
			obstacle->ToggleIsShow();
		}
	}
}