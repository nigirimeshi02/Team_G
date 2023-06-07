#pragma once
#include "ObstacleBase.h"
#include <vector>

class Food :
	public ObstacleBase
{
public:
	Food(Location location = { 100,0 }, float radius = 10.0f, float speed = 2, int score = 100);
	~Food();

private:
	static int image;

public:
	void Update();
	void Draw()const;
	std::vector<int>food;
};
