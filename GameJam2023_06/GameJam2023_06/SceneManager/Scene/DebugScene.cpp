#include "DebugScene.h"
#include "../../System/SoundPlayer/SoundPlayer.h"
#include "../../System/KeyManager/KeyManager.h"

#include "DxLib.h"
/*
* �R���X�g���N�^
*/
DebugScene::DebugScene()
{
	//attack = new Attack();
	box = new BoxCollider({300,250},{25,25});
	player = new Player();
	//result = new Result(0,0);
}

/*
* �f�X�g���N�^
*/
DebugScene::~DebugScene()
{
	delete box;
	delete player;
	delete result;
}

/*
* �X�V
* �߂�l ���̃t���[���ōX�V����V�[���̃|�C���^
*/
AbstractScene* DebugScene::Update()
{
	player->PlayerControl();
	return this;
}

/*
* �`��
*/
void DebugScene::Draw()const
{
	//attack->Draw();
	//box->Draw();
	//result->Draw();
	player->DrawPlayer();
	const Attack* attack = player->GetAttack();
	if (attack != nullptr && attack->HitCheck(box))
	{
		DrawString(0, 0, "HIT", 0xFFFFFF);
	}
}