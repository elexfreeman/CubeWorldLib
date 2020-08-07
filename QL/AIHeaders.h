#pragma once
#include <stdlib.h>
#include <queue>
#include "conf.h"
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
  float L; // растояние до объекта
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
typedef std::queue<AIKadr> FaBuffer;

struct Coord
{
  float X;
  float Y;
};

/**
 * Получить случайную локацию в пределах мира
 * */
Coord fGetRandomLoc()
{
  Coord resp;
  resp.Y = 0;
  resp.X = 0;

  resp.X = 1 + std::rand() % mx;
  resp.Y = 1 + std::rand() % my;
  return resp;
}