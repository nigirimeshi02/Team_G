#pragma once
#include "../AbstractScene.h"
#include"../../Enemy.h"

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
	Enemy* enemy;

};

