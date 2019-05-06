#pragma once
#include <iostream>
#include "../perlinNoise/PerlinNoise.h"
#define PI 3.14159265

#define texture_sky 0
#define texture_grass 1
#define texture_ground 2
#define texture_granite 3
#define texture_lava 4

/* Класс данных об мире или участка мира */
class WorldArrayClass
{
    /* высота и ширина */
    unsigned width, height;

    /* массив точек */
    int *world;
    

public:
    WorldArrayClass(unsigned int w, unsigned int h);
    ~WorldArrayClass();
    int getXY(unsigned int x, unsigned int y);
    void setXY(unsigned int x, unsigned int y, int val);

    void generate(double scale, double scale_d, double scale_s);
    void print();

    /* рисует линию */
    void line(int x0, int y0, int x1, int y1, int color);

    /* линия взгляда */
    void lineEye(int x1, int y1, int x2, int y2);
};
