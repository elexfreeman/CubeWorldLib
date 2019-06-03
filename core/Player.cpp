#pragma once

#include "Player.h"

PlayerClass::PlayerClass(int xx, int yy, int w, int h)
{
    width = w;
    height = height;
    visibleWorld = new WorldArrayClass(w, h);

    x = xx;
    y = yy;
}

PlayerClass::~PlayerClass()
{
    delete visibleWorld;
}

WorldArrayClass *PlayerClass::getVisibleWorld(WorldArrayClass *worldArray)
{
    return visibleWorld;
}

void PlayerClass::setXY(int xx, int yy)
{
    x = xx;
    y = yy;
}