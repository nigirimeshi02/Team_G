#pragma once
#include "../GameJam2023_06/SceneManager/AbstractScene.h"
class Title :
	public AbstractScene
{
public:

	Title();
	//�`��ȊO�̍X�V�����s
	AbstractScene* Update()override;


	//�`��Ɋւ��邱�Ƃ�����
	void Draw() const override;

private:


};
