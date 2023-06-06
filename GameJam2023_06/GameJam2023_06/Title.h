#pragma once
#include "../GameJam2023_06/SceneManager/AbstractScene.h"
class Title :
	public AbstractScene
{

private:
	enum class TITLE_MENU {
		START,
		RANKING,
		END
	};

	TITLE_MENU Menu_Number;

	int interval;
	int select;
	short JoyPadY;
public:

	Title();
	//�`��ȊO�̍X�V�����s
	AbstractScene* Update()override;


	//�`��Ɋւ��邱�Ƃ�����
	void Draw() const override;




};
