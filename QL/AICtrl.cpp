#pragma once

#include <ctime>
#include <list>
#include <stdlib.h>
#include <cmath>
#include "MObject.cpp"

#define buffer_length 20

/*
// sensors
     
   4   1
     *
   3   2
*/
class Sensors
{
    bool S[3]; // сенсор
    float L; // растояние до объекта
};

class AIKadr
{
public:
    // сенсоры 3-х кадров
    Sensors *S1;
    Sensors *S2;
    Sensors *S3;
};



class AICtrl
{
protected:
    int state = 0;
    std::list<AIKadr *> aBuffer;
    MObject* dObj; // искомый объект

public:
    AICtrl(MObject* obj)
    {
        std::srand(std::time(nullptr)); // рандомизация генератора случайных чисел
        // заполняем буфер
        for (int i = 0; i < buffer_length; i++)
        {
        }

        this->dObj = obj;
    }
};
