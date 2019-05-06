#pragma once
#include "WorldArray.h"
#include <cmath>

WorldArrayClass::WorldArrayClass(unsigned int w, unsigned int h)
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

int WorldArrayClass::getXY(unsigned int x, unsigned int y)
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

void WorldArrayClass::setXY(unsigned int x, unsigned int y, int val)
{
    if ((x < width) && (y < height))
    {
        world[x + height * y] = val;
    }
}

void WorldArrayClass::generate(double scale, double scale_d, double scale_s)
{

    // Create a PerlinNoise object with the reference permutation vector
    PerlinNoise pn;

    for (unsigned int i = 0; i < height; ++i)
    { // y
        for (unsigned int j = 0; j < width; ++j)
        { // x
            double x = (double)j / ((double)width);
            double y = (double)i / ((double)height);

            // Typical Perlin noise
            double n = scale_d * pn.noise(scale_s * width * x / scale, scale_s * height * y / scale, 0.05);
            //double n = 10*pn.noise(x, y, sin(jj * PI / 180));

            // Wood like structure
            //n = 20 * pn.noise(x, y, 0.8);
            n = n - floor(n);

            if (floor(255 * n) < 100)
            {
                setXY(j, i, texture_sky);
            }
            else if (floor(255 * n) < 110)
            {
                setXY(j, i, texture_grass);
            }
            else if (floor(255 * n) < 151)
            {
                setXY(j, i, texture_ground);
            }

            else if (floor(255 * n) < 200)
            {
                setXY(j, i, texture_granite);
            }
            else
            {
                setXY(j, i, texture_lava);
            }

        } //x

    } //y
}

/* выводит текущий массв на экран */
void WorldArrayClass::print()
{
    std::cout << "height: " << height << ", width: " << width << " \r\n";
    for (unsigned int y = 0; y < height; y++)
    { // y
        for (unsigned int x = 0; x < width; x++)
        { // x
            std::cout << getXY(x, y);
        }
        std::cout << " \r\n";
    }
}

void WorldArrayClass::line(int x0, int y0, int x1, int y1, int color)
{
    int A, B, sign;
    A = y1 - y0;
    B = x0 - x1;
    if (abs(A) > abs(B))
        sign = 1;
    else
        sign = -1;
    int signa, signb;
    if (A < 0)
        signa = -1;
    else
        signa = 1;
    if (B < 0)
        signb = -1;
    else
        signb = 1;
    int f = 0;
    setXY(y0, x0, color);
    int x = x0, y = y0;
    if (sign == -1)
    {
        do
        {
            f += A * signa;
            if (f > 0)
            {
                f -= B * signb;
                y += signa;
            }
            x -= signb;
            setXY(y, x, color);

        } while (x != x1 || y != y1);
    }
    else
    {
        do
        {
            f += B * signb;
            if (f > 0)
            {
                f -= A * signa;
                x -= signb;
            }
            y += signa;
            setXY(y, x, color);
        } while (x != x1 || y != y1);
    }
}

void WorldArrayClass::lineEye(int x1, int y1, int x2, int y2)
{
}
