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
	ui = new UI();
	ui->SetLife(player->GetLife());
	ui->SetScore(&score);

	score = 0;
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
	player->Update();
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

	ui->Draw();
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
		// プレイヤーの攻撃との当たり判定
		if (attack != nullptr &&		//プレイヤーが攻撃しているか？
			obstacle->GetIsShow() &&	//対象のものが見えている(当たり判定を取る状態)か？
			attack->HitCheck(obstacle))	//当たっているか？
		{
			CheckType(obstacle);
			obstacle->ToggleIsShow();		//見えなくする 
			// TODO:↑余裕があれば壊れる動き付けるため、ToggleIsBrokenにする
			score += obstacle->GetScore();	//スコア加算
			
		}
		
		// プレイヤー本体との当たり判定
		if (obstacle->GetIsShow() &&					//対象のものが見えている(当たり判定を取る状態)か？
			player->HitCheck(obstacle))					//当たっているか
		{
			if (dynamic_cast<Enemy*>(obstacle) == nullptr)	//エネミー以外か？(消えるもの？)
			{
				if (dynamic_cast<Food*>(obstacle) != nullptr)//食べ物か？
				{
					score += obstacle->GetScore();
				}
				else	//それ以外(ダメージを受けるもの)の場合
				{
					//プレイヤーのライフを削る
				}
				obstacle->ToggleIsShow();

			}
			else	//エネミーの場合
			{
				//消さずにプレイヤーのライフを削る処理
			}
		}
		
	}
}

/*
* 当たったオブジェクトの種類のチェック
* 種類に応じた処理
*/
void GameMain::CheckType(ObstacleBase* obstacle)
{
	Enemy* enemy = dynamic_cast<Enemy*>(obstacle);
	if (enemy != nullptr)
	{
		return ;
	}
	
	Bomb* bomb = dynamic_cast<Bomb*>(obstacle);
	if (bomb != nullptr)
	{
		return ;
	}
	
	Food* food = dynamic_cast<Food*>(obstacle);
	if (food != nullptr)
	{
		return ;
	}
} //TODO: 使う？？？？