#pragma once
#include "../../common.h"
#include "../AbstractScene.h"
#include "../../ObstacleManager.h"
#include "../../Player.h"
#include "../../UI.h"

class GameMain :
    public AbstractScene
{

public:
	GameMain();
	~GameMain();

	//�`��ȊO�̍X�V�����s
	AbstractScene* Update()override;

	//�`��Ɋւ��邱�Ƃ�����
	void Draw() const override;
	//void Updata() override;

private:
	ObstacleManager* obstacleManager;
	Player* player;
	UI* ui;

	int gameMainBGM;
	int imageBack;
	int score;

	int frameCount;
	bool isGameEnd;

public:
	void CheckHit();	//�����蔻��
	void CheckType(ObstacleBase*);	//���������I�u�W�F�N�g�̎�ނ̃`�F�b�N,��ނɉ���������
};

