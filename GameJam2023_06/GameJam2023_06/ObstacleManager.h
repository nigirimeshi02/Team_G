#pragma once
#include "ObstacleBase.h"
#include "Food.h"

#include <vector>

using namespace std;

class ObstacleManager
{
public:
	ObstacleManager();
	~ObstacleManager();

	void Update();
	void Draw()const;

private:
	vector<ObstacleBase*> obstacles;
	int frameCount;


};

