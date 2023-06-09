#pragma once
#include "ObstacleBase.h"

class Enemy :
    public ObstacleBase
{
public:
    Enemy(Location location = { 100,0 }, float radius = 10.0f, float speed = 2, int score = 200);
    ~Enemy();
     
    
   

private:
    static int image;
   
public:
    virtual void Update();
    virtual void Draw()const ;
    void Test() {}
}; 

