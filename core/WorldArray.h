#pragma once

/* Класс данных об мире */
class WorldArrayClass
{
    /* высота и ширина */
    int width, height;

    /* массив точек */
    int *world;

public:
    WorldArrayClass(int w, int h);  

    ~WorldArrayClass();
};
