#pragma once
#pragma once
#include "SceneManager/AbstractScene.h"

class GameMain : public AbstractScene {

private:
	int MainBGM;

public:
	// �C���X�g���N�^
	GameMain();
	// �f�X�g���N�^
	virtual ~GameMain() {};

	// �`��ȊO�̍X�V����������
	virtual AbstractScene* Update() override;

	// �`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;
};