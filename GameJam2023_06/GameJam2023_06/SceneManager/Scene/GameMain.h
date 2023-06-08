#pragma once
#include "../../common.h"
#include "../AbstractScene.h"
#include "../../ObstacleManager.h"
#include "../../Player.h"
#include "../../UI.h"

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
	ObstacleManager* obstacleManager;
	Player* player;
	UI* ui;

	int gameMainBGM;
	int imageBack;
	int score;

	int frameCount;
	bool isGameEnd;

public:
	void CheckHit();	//当たり判定
	void CheckType(ObstacleBase*);	//当たったオブジェクトの種類のチェック,種類に応じた処理
};

