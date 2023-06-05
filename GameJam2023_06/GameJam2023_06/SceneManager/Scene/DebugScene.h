#include "../AbstractScene.h"
#pragma once
class DebugScene:
	public AbstractScene
{
public:
	DebugScene();
	~DebugScene();

	//描画以外の更新を実行
	AbstractScene* Update()override;

	//描画に関することを実装
	void Draw() const override;

private:

};

