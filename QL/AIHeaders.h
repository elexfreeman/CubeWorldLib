#pragma once
#include <stdlib.h>
#include <list>
/*
// sensors
     
   4   1
     *
   3   2
*/
struct Sensors
{
    bool S1;
    bool S2;
    bool S3;
    bool S4;
    float L;   // растояние до объекта
};

struct AIKadr
{
    // сенсоры 3-х кадров
    Sensors K1;
    Sensors K2;
    Sensors K3;

    int step; // в какую сторону сделался шаг
    float L;  // какое стало растояние после шага
};

/**
 * Буфер кадров
 * */
typedef std::list<AIKadr> FaBuffer;