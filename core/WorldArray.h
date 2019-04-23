#pragma once

/* Класс данных об мире или участка мира */
class WorldArrayClass
{
    /* высота и ширина */
    int width, height;

    /* массив точек */
    int *world;

public:
    WorldArrayClass(int w, int h);  

    int getXY(int x, int y);
    void setXY(int x, int y, int val);

    ~WorldArrayClass();
};
