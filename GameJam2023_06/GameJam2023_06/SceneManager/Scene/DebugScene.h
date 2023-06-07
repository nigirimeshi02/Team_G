#include "../AbstractScene.h"
#include "../../attack.h"
#include "../../Collider/BoxCollider.h"
#include"../../Player.h"
#include"../../Result.h"
#pragma once
class DebugScene:
	public AbstractScene
{
public:
	DebugScene();
	~DebugScene();

	//�`��ȊO�̍X�V�����s
	AbstractScene* Update()override;

	//�`��Ɋւ��邱�Ƃ�����
	void Draw() const override;

private:
	BoxCollider* box;
	Player* player;
	Result* result;
	int back;
};

