#include "GameMain.h"
#include "../../Ranking.h"

#include "../../Title.h"
#include "ResultScene.h"
#include "../../System/SoundPlayer/SoundPlayer.h"
#include "DxLib.h"
#include "../../System/KeyManager/KeyManager.h"

//int sceneCHG = false;
/*
* コンストラクタ
*/
GameMain::GameMain()
{
	mScene = nullptr;
	player = new Player();
	obstacleManager = new ObstacleManager();
	ui = new UI();
	ui->SetLife(player->GetLife());
	ui->SetKillCount(&killCount);
	ui->SetAvoidCount(obstacleManager->GetCount());
	ui->SetEatCount(&eatCount);

	gameMainBGM = SoundPlayer::GetBGM("GameMain");
	boomSE = SoundPlayer::GetSE("Boom");
	eatSE = SoundPlayer::GetSE("eat");
	imageBack = LoadGraph("images/main.png");
	SoundPlayer::PlayBGM(gameMainBGM);

	score = 0;
	killCount = 0;
	eatCount = 0;

	frameCount = 0;
	isGameEnd = false;
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
	if (mScene != nullptr)
	{
		mScene = mScene->Update();
		if (mScene == nullptr)
		{
			delete mScene;
			return new Ranking(score);
		}
		return this;
	}

	if (isGameEnd)
	{
		frameCount--;
		if (frameCount <= 0)
		{
			mScene = new ResultScene(score, killCount, *(obstacleManager->GetCount()),eatCount);
		}
		return this;		//以降の処理を止める
	}

	player->Update();
	obstacleManager->Update();
	CheckHit();

	if (*(player->GetLife()) == 0)
	{
		isGameEnd = true;
		frameCount = 2 * 60;
	}
	return this;
}

/*
* 描画
*/
void GameMain::Draw()const
{
	DrawGraph(0, 0, imageBack,TRUE);

	obstacleManager->Draw();

	player->DrawPlayer();

	ui->Draw();

	if (mScene != nullptr)
	{
		mScene->Draw();
	}
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
				SoundPlayer::PlaySE(boomSE, FALSE);
				player->HitDamage();
			}
			if (dynamic_cast<Enemy*>(obstacle) != nullptr)
			{
				killCount++;
			}
		}
		
		// プレイヤー本体との当たり判定
		if (obstacle->GetIsShow() &&					//対象のものが見えている(当たり判定を取る状態)か？
			player->HitCheck(obstacle))					//当たっているか
		{
			if (dynamic_cast<Food*>(obstacle) != nullptr)	//食べ物か？
			{
				SoundPlayer::PlaySE(eatSE, FALSE);
				eatCount++;
				score += obstacle->GetScore();
				obstacle->ToggleIsShow();
			}
			else if (player->GetIsInvincible() != true)
			{
				player->HitDamage();
				if (dynamic_cast<Enemy*>(obstacle) != nullptr)	//エネミーか？(消えないもの？)
				{
					player->HitEnemy();
					score += (int)(obstacle->GetScore() * -0.2);  //減算用
				}
				else											//それ以外（爆弾）の場合
				{
					if(obstacle != nullptr)
					{
						SoundPlayer::PlaySE(boomSE, FALSE);
						score += obstacle->GetScore();
						obstacle->ToggleIsShow();					//消す
					}
				}

			}

		}
		
	}
}