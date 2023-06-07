#pragma once
#include "../AbstractScene.h"
#include"../../Enemy.h"
#include"../../Food.h"
#include"../../Bomb.h"

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
	Enemy* enemy;
	Food* food;
	Bomb* bomb;

};

