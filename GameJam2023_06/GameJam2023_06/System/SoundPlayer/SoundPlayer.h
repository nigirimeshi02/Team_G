#pragma once
#include <map>
#include <string>

using namespace std;

struct Sound
{
	int handle;		//�������Ɋm�ۂ����n���h��
	bool isDone = false;	//�Ō�܂ōĐ����ꂽ��
};

class SoundPlayer
{
private:
	SoundPlayer();					//�R���X�g���N�^
	static SoundPlayer* instance;	//�C���X�^���X
public:
	~SoundPlayer();
	//�V���O���g��
	static SoundPlayer* GetInstance();//�C���X�^���X�̎擾
	static void DeleteThis();		//�����̍폜



private:
	map<string, Sound>bgm;			//BGM�p�z��
	map<string, Sound>se;			//SE�p�z��

public:
	static int GetBGM(const char*);		//BGM�n���h���̎擾
	static int GetSE(const char*);		//SE�n���h���̎擾
	static void PlayBGM(int handle);	//BGM�̍Đ�
	static void PlaySE(int handle, bool isSingle);		//SE�̍Đ�
};

