#pragma once
#include "SceneManager/AbstractScene.h"
#include "common.h"
#include <string>
#include "System/PadInput/PadInput.h"

#define D_CHARACTER_MAX (26)
#define D_INTERVAL (12)
#define D_ROW (3)
#define D_COL (9)
using namespace std;

class InputRanking :
    public AbstractScene
{
public:
    InputRanking(string* name = 0);
    ~InputRanking();
    AbstractScene* Update();
    void Draw()const;


private:
    string* name;
    static const char charSet[D_CHARACTER_MAX];

    int imageBack;
    int imageCircle;
    int seCursorMove;
    int seCursorEnter;

    int cursor;
    int interval;

    bool InputUp()
    {
        if (PAD_INPUT::GetLStick().y > MARGIN ||
            PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_UP))
        {
            return true;
        }
        return false;
    }
    bool InputDown()
    {
        if (PAD_INPUT::GetLStick().y < -MARGIN ||
            PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_DOWN))
        {
            return true;
        }
        return false;
    }
    bool InputRight()
    {
        if (PAD_INPUT::GetLStick().x > MARGIN ||
            PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT))
        {
            return true;
        }
        return false;
    }
    bool InputLeft()
    {
        if (PAD_INPUT::GetLStick().x < -MARGIN ||
            PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT))
        {
            return true;
        }
        return false;
    }
};

