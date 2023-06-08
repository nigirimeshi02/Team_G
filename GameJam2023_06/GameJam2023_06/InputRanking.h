#pragma once
#include "SceneManager/AbstractScene.h"
#include "common.h"
#include <string>

#define D_CHARCTER_MAX (27)
using namespace std;

class InputRanking :
    public AbstractScene
{
public:
    InputRanking();
    ~InputRanking();
    AbstractScene* Update();
    void Draw()const;

private:
    string name;
    static const char charSet[D_CHARCTER_MAX];

    int imageBack;
    int imageCircle;

    int cursor;

};

