#include "DebugScene.h"
#include "../../System/SoundPlayer/SoundPlayer.h"
#include "../../System/KeyManager/KeyManager.h"

#include "DxLib.h"
/*
* �R���X�g���N�^
*/
DebugScene::DebugScene()
{
	attack = new Attack();
	box = new BoxCollider({300,250},{25,25});
}

/*
* �f�X�g���N�^
*/
DebugScene::~DebugScene()
{
	delete attack;
	delete box;
}

/*
* �X�V
* �߂�l ���̃t���[���ōX�V����V�[���̃|�C���^
*/
AbstractScene* DebugScene::Update()
{
	//attack->Update();
	return this;
}

/*
* �`��
*/
void DebugScene::Draw()const
{
	//attack->Draw();
	//box->Draw();

	if (attack->HitCheck(box))
	{
		DrawString(0, 0, "HIT", 0xFFFFFF);
	}
}