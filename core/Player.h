#pragma once

#include "WorldArray.h"

/* Класс данных об мире или участка мира */
class PlayerClass
{
    /* координаты игрока */
    int x, y;

    WorldArrayClass visibleWorld;
    

public:
    PlayerClass(int x, int y);      

    ~PlayerClass();

    void getVisibleWorld();
};
