#pragma once
#include "../../common.h"
#include "../AbstractScene.h"
#include "../../ObstacleManager.h"
#include "../../SlashAction.h"

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

private:
	SlashAction* slashAction;
	ObstacleManager* obstacleManager;


public:
	void CheckHit();
};

