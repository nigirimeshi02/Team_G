#pragma once
#include "../GameJam2023_06/SceneManager/AbstractScene.h"
class Title :
	public AbstractScene
{
public:

	Title();
	//描画以外の更新を実行
	AbstractScene* Update()override;


	//描画に関することを実装
	void Draw() const override;

private:


};
