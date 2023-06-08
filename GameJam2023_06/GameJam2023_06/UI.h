#pragma once
#include "common.h"
#define D_SET (81 + 20)		//UI•\Ž¦ˆêŒÂ•ª
#define D_CHAR_SET (64 + 10)//UI•\Ž¦ˆê•¶Žš•ª
#define D_COUNT_SET (120)//UI•\Ž¦ˆê•¶Žš•ª
#define D_LIFE_SPACE (20 + (3 * D_SET))
class UI
{
public:
	UI();
	~UI();

	void Draw()const;
private:
	int imageBack;	
	int imagePlayerLife;
	int imageEnemy;
	int imageBomb;
	int imageEat;

	const int* life = 0;
	const int* killCount = 0;
	const int* avoidCount = 0;
	const int* eatCount = 0;

public:

	void SetLife(const int* p_life) { life = p_life; }
	void SetKillCount(const int* p_killCount) { killCount = p_killCount; }
	void SetAvoidCount(const int* p_avoidCount) { avoidCount = p_avoidCount; }
	void SetEatCount(const int* p_eatCount) { eatCount = p_eatCount; }
};

