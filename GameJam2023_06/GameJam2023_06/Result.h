#pragma once
#include "SceneManager/AbstractScene.h"


class Result :public AbstractScene
{
public:
	Result(int score, int value);
	~Result();

	AbstractScene* Update()override;
	//void Update();
	void Draw();

private:
	int r_score;
	int r_value;

	int backImg;
	int enemyImg;
};
