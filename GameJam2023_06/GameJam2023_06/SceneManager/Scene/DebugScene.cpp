#include "DebugScene.h"
#include "../../System/SoundPlayer/SoundPlayer.h"
#include "../../System/KeyManager/KeyManager.h"

#include "DxLib.h"
/*
* コンストラクタ
*/
DebugScene::DebugScene()
{
	attack = new Attack();
	box = new BoxCollider({300,250},{25,25});
	player = new Player();
}

/*
* デストラクタ
*/
DebugScene::~DebugScene()
{
	delete attack;
	delete box;
}

/*
* 更新
* 戻り値 次のフレームで更新するシーンのポインタ
*/
AbstractScene* DebugScene::Update()
{
	player->PlayerLimit();
	player->PlayerControll();
	attack->Update();
	return this;
}

/*
* 描画
*/
void DebugScene::Draw()const
{
	attack->Draw();
	box->Draw();
	player->DrawPlayer();

	if (attack->HitCheck(box))
	{
		DrawString(0, 0, "HIT", 0xFFFFFF);
	}
}