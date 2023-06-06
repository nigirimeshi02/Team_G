#pragma once
#include "ObstacleBase.h"
class Food:
    public ObstacleBase
{
public:
    Food();
    ~Food();
    Food(Location location, float radius);

public:
    virtual void Update() = 0;
    virtual void Draw()const = 0;

};
