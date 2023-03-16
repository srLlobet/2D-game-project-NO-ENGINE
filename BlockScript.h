#pragma once

#include "Script.h"

using namespace std;

class BlockScript : public Script
{
    using Script::Script;


public:

    void tickScript(float deltaTime);

private:
    float t = 0;
    float timer = 10;
    int hp = 1;
    bool destroyed = false;
};