#pragma once
#include "SceneManager/AbstractScene.h"

#define RANK_MAX (5)
#define NAME_MAX (10)

typedef struct {
	int no;
	char name[NAME_MAX];
	long score;
}RankingData;

class Ranking :
	public AbstractScene
{
public:
	Ranking();
	~Ranking();

	//�`��ȊO�̍X�V�����s
	AbstractScene* Update()override;
	
	//�`��Ɋւ��邱�Ƃ�����
	void Draw() const override;

private:
	bool sceneCHG;  //�V�[���ύX�l

};

//�v���g�^�C�v�錾
int ReadRanking(RankingData Ranking[]);
