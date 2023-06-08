#pragma once
#include "common.h"
#define D_LIFE_SPACE (20 + (3 * (81 + 20)))
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
	const int* score = 0;
	const int* life = 0;

public:

	void SetScore(const int* p_score) { score = p_score; }
	void SetLife(const int* p_life) { life = p_life; }
};

