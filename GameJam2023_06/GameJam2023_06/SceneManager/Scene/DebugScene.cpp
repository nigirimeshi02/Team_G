#include "DebugScene.h"
#include "../../System/SoundPlayer/SoundPlayer.h"
#include "../../System/KeyManager/KeyManager.h"

#include "DxLib.h"
/*
* コンストラクタ
*/
DebugScene::DebugScene()
{

}

/*
* デストラクタ
*/
DebugScene::~DebugScene()
{

}

/*
* 更新
* 戻り値 次のフレームで更新するシーンのポインタ
*/
AbstractScene* DebugScene::Update()
{
	return this;
}

/*
* 描画
*/
void DebugScene::Draw()const
{

}