#include "GameMain.h"
#include "../../SlashAction.h"

#include "DxLib.h"
/*
* コンストラクタ
*/
GameMain::GameMain()
{
	player = new Player();
	obstacleManager = new ObstacleManager();
}

/*
* デストラクタ
*/
GameMain::~GameMain()
{
	delete obstacleManager;
	delete player;
}

/*
* 更新
* 戻り値 次のフレームで更新するシーンのポインタ
*/
AbstractScene* GameMain::Update()
{
	player->PlayerControl();
	obstacleManager->Update();
	CheckHit();

	return this;
}

/*
* 描画
*/
void GameMain::Draw()const
{
	obstacleManager->Draw();

	player->DrawPlayer();
}

/*
* 当たり判定チェック
*/
void GameMain::CheckHit()
{
	//プレイヤーの攻撃
	Attack* attack = player->GetAttack();
	//降ってくるもの達
	vector<ObstacleBase*> obstacles = obstacleManager->GetObstacles();

	//降ってくるものとの当たり判定
	for (ObstacleBase* obstacle : obstacles)
	{
		if (attack != nullptr &&		//プレイヤーが攻撃しているか？
			obstacle->GetIsShow() &&	//対象のものが見えている(当たり判定を取る状態)か？
			attack->HitCheck(obstacle))	//当たっているか？
		{
			obstacle->ToggleIsShow();	//見えなくする 
			// TODO:↑余裕があれば壊れる動き付けるため、ToggleIsBrokenにする
			/*Enemy* buf = dynamic_cast<Enemy*>(obstacle);
			if (buf != nullptr)
			{
				buf->Test();
			}*/
		}
		
		if (obstacle->GetIsShow() &&
			player->HitCheck(obstacle))
		{
			obstacle->ToggleIsShow();
		}
	}
}