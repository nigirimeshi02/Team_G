#include "../AbstractScene.h"
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

};

