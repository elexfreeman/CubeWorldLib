#pragma once

#include "WorldArray.h"


/* Класс данных об мире или участка мира */
class PlayerClass
{
    /* координаты игрока */
    int x, y;
    /* высота и ширина видимой области */
    int width, height;

    /* видимая область */
    WorldArrayClass* visibleWorld;
    

public:
    PlayerClass(int x, int y, int w, int h);      

    ~PlayerClass();

    int getVisibleWorld(WorldArrayClass *worldArray);
};
