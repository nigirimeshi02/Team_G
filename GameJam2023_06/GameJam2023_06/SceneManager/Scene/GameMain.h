#pragma once
#include "../../common.h"
#include "../AbstractScene.h"
#include "../../ObstacleManager.h"
#include "../../SlashAction.h"
#include"../../Player.h"

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

	int score;
public:
	void CheckHit();	//�����蔻��
};

