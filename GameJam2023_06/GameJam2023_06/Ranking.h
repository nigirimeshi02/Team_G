#pragma once
#include "SceneManager/AbstractScene.h"
#include "Title.h"

#define RANK_MAX (5)
#define NAME_MAX (10)

//�\����
typedef struct {
	int no;
	char name[NAME_MAX];
	long score;
}RankingData;

class Ranking :public AbstractScene
{
public:
	Ranking();
	~Ranking();

	//�`��ȊO�̍X�V�����s
	AbstractScene* Update()override;
	RankingData work[RANK_MAX];

	//�`��Ɋւ��邱�Ƃ�����
	void Draw() const override;

private:
	enum class RANKING_MENU {
		START,
		RANKING,
		END
	};

	RANKING_MENU Menu_Number;

	int interval;
	int select;
	short JoyPadY;
	int RankingImg;//�����L���O�C���[�W
	bool sceneCHG;//�V�[���ύX�n
	int Cursor_Cancel;
	
};

//�v���g�^�C�v�錾
int ReadRanking(RankingData Ranking[]);
void SortRanking(RankingData Ranking[]);
