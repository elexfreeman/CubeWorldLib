#pragma once

#include "Player.h"

PlayerClass::PlayerClass(int x, int y, int w, int h)
{
    width = w;
    height = height;
    visibleWorld = new WorldArrayClass(w, h);
}

PlayerClass::~PlayerClass()
{
    delete visibleWorld;
}

int PlayerClass::getVisibleWorld(WorldArrayClass *worldArray)
{
    return worldArray->getXY(0, 0);
}
