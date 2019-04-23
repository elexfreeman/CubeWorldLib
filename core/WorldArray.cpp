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

int WorldArrayClass::getXY(int x, int y)
{
    if (x >= width)
    {
        return 0;
    }
    if (y >= height)
    {
        return 0;
    }
    return world[x + height * y];
}

void WorldArrayClass::setXY(int x, int y, int val)
{
    if ((x < width) && (y < height))
    {
        world[x + height * y] = val;
    }
}