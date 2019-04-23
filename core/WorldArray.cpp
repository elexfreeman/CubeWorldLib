#pragma once
#include "WorldArray.h"

WorldArrayClass::WorldArrayClass(int w, int h)
{
    width = w;
    height = h;

    /* выделяем память */
    world = new int[width * height];
    /* заполняем нулями */
    for (int i = 0; i < width * height; i++)
    {
        world[i] = 0;
    }
}

WorldArrayClass::~WorldArrayClass()
{
    delete world;
}
