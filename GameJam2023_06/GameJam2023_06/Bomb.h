#pragma once
#include "ObstacleBase.h"

class Bomb :
	public ObstacleBase
{
public:
	Bomb(Location location = { 100,0 }, float radius = 10.0f, float speed = 2, int score = -500);
	~Bomb();

private:
	static int image;

public:
	void Update();
	void Draw()const;
};