#pragma once
#include "ObstacleBase.h"
#include "Food.h"

#include <vector>

//ê∂ê¨ÉpÉ^Å[Éì
#define D_TYPE_ENEMY (0)
#define D_TYPE_BOMB	 (1)
#define D_TYPE_FOOD	 (2)

using namespace std;

class ObstacleManager
{
public:
	ObstacleManager();
	~ObstacleManager();

	void Update();
	void Draw()const;

private:
	const int Production_Ratio[2][3] =
	{
		{5,3,2},{3,5,2},
	};
	vector<ObstacleBase*> obstacles;
	int frameCount;


public:
	void CreateObstacle();	//è·äQï®ÇÃê∂ê¨

};

