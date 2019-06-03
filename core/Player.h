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
    WorldArrayClass *visibleWorld;

public:

    /* 
        x, y - координаты в пространстве
        w, h - ширина и высота видимой области
    */
    PlayerClass(int xx, int yy, int w, int h);

    ~PlayerClass();

    /* устанавливает координаты */
    void setXY(int xx, int yy);

    /* выдает область видимости игрока */
    WorldArrayClass *getVisibleWorld(WorldArrayClass *worldArray);
};
