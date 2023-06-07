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

	//描画以外の更新を実行
	AbstractScene* Update()override;

	//描画に関することを実装
	void Draw() const override;
	//void Updata() override;

private:
	Enemy* enemy;
	Food* food;
	Bomb* bomb;

};

