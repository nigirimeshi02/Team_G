#pragma once
#include "ObstacleBase.h"

class Food :
	public ObstacleBase
{
public:
    Food(Location location = { 100,0 }, float radius = 10.f, float speed = 2, int score = 1000);
	~Food();

private:
	static int image;

public:
	void Update();
	void Draw()const;

	int GetScore()const override { return score * (int)isShow; }
};

