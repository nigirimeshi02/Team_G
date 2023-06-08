#pragma once
#include "SceneManager/AbstractScene.h"
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

	int TitleBGM;
	int Cursor_Move;
	int Cursor_Enter;
	int Cursor_Cancel;
	int TitleImage;
	int cursor;
	int interval;
	int select;
	short JoyPadY;
public:

	Title();
	//描画以外の更新を実行
	AbstractScene* Update()override;


	//描画に関することを実装
	void Draw() const override;




};
