#include "GameMain.h"
#include "../../Ranking.h"

#include "../../System/SoundPlayer/SoundPlayer.h"
#include "DxLib.h"
#include "../../System/KeyManager/KeyManager.h"

//int sceneCHG = false;
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

	gameMainBGM = SoundPlayer::GetBGM("GameMain");

	SoundPlayer::PlayBGM(gameMainBGM);
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

	if (KeyManager::OnKeyClicked(KEY_INPUT_S))
	{
		return new Ranking();
	}

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
			obstacle->ToggleIsShow();		//見えなくする 
			// TODO:↑余裕があれば壊れる動き付けるため、ToggleIsBrokenにする
			score += obstacle->GetScore();	//スコア加算
			if (dynamic_cast<Bomb*>(obstacle) != nullptr)
			{
				player->HitDamage();
			}
		}
		
		// プレイヤー本体との当たり判定
		if (obstacle->GetIsShow() &&					//対象のものが見えている(当たり判定を取る状態)か？
			player->HitCheck(obstacle))					//当たっているか
		{
			if (dynamic_cast<Food*>(obstacle) != nullptr)	//食べ物か？
			{
				score += obstacle->GetScore();
				obstacle->ToggleIsShow();
			}
			else if (player->GetIsInvincible() != true)
			{
				player->HitDamage();
				if (dynamic_cast<Enemy*>(obstacle) != nullptr)	//エネミーか？(消えないもの？)
				{
					score += obstacle->GetScore() * -0.2;  //減算用
				}
				else											//それ以外（爆弾）の場合
				{
					score += obstacle->GetScore();
					obstacle->ToggleIsShow();					//消す
				}

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