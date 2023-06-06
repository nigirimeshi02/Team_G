#pragma once
#include "ObstacleBase.h"
class Bom :
    public ObstacleBase
{
public:
    Bom();
    ~Bom();
    Bom(Location location, float radius);

public:
    virtual void Update() = 0;
    virtual void Draw()const = 0;

};

