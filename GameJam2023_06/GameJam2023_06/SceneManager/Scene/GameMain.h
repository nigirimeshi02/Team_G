#pragma once
#include "../../common.h"
#include "../AbstractScene.h"
#include "../../ObstacleManager.h"
#include "../../SlashAction.h"

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

private:
	SlashAction* slashAction;
	ObstacleManager* obstacleManager;


public:
	void CheckHit();
};

