#pragma once
#include "ObstacleBase.h"
class Enemy :
    public ObstacleBase
{
public:
    Enemy();
    ~Enemy();
    Enemy(Location location, float radius);

public:
    virtual void Update();
    virtual void Draw()const ;

};

