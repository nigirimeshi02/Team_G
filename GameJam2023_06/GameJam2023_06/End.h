#pragma once
#include "../GameJam2023_06/SceneManager/AbstractScene.h"

class End :
    public AbstractScene
{
private:
    int WaitTime;   //�I���܂ł̎���
    int MoveString; //�G���h���[���p
    int TitleImage;  //�摜�p
    int EndBGM;     //BGM�p
    int EndSE;      //SE�p
    int EndFont1;
    int EndFont2;
    int EndFont3;


public:
    //�R���X�g���N�^
    End();
    //�f�X�g���N�^
    ~End();
    //�`��ȊO�̍X�V�����s
    AbstractScene* Update() override;
    //�`��Ɋւ��邱�Ƃ�����
    void Draw()const;

    ////�V�[���̕ύX����
    //AbstractScene* ChangeScene()override;
};