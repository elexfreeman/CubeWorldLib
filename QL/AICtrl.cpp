#pragma once

#include <ctime>
#include <list>
#include <stdlib.h>
#include <cmath>

#define buffer_length 200

/*
// sensors
     
   4   1
     *
   3   2
*/
struct Sensors
{
    bool S[3]; // сенсор
    float L;   // растояние до объекта
};

struct AIKadr
{
    // сенсоры 3-х кадров
    Sensors *S1;
    Sensors *S2;
    Sensors *S3;

    int step; // в какую сторону сделался шаг
    float L;  // какое стало растояние после шага
};

class AICtrl
{
protected:
    int nState = 0;
    std::list<AIKadr *> aBuffer;
    int nMaxBufferSize;

public:
    AICtrl()
    {
        nMaxBufferSize = buffer_length;
    }

    // получить похожий сенсор
    int fGetEqualSensor(AIKadr *kadr)
    {
        return -1;
    }

    /**
     * получить случайный шаг 
     * */
    int fGetRandomStep()
    {
        // TODO: проверить
        return 1 + std::rand() % 4;
    }

    /**
     * Добавить кадр в буфер 
     * */
    int fAddToBuffer(AIKadr *kadr)
    {
        if (this->aBuffer.size() < this->nMaxBufferSize)
        {
            this->aBuffer.push_back(kadr);
        }
        else
        {
            this->aBuffer.pop_front();
            this->aBuffer.push_back(kadr);
        }

        return this->aBuffer.size() - 1;
    }

    /**
     *  Получить куда ходить индекс массива буфера
     * */
    int fGetNextStep(AIKadr *kadr)
    {
        int res = 0;
        // находим похожую ситуацию из буфера сравнивая показания сенсоров
        int sensor = this->fGetEqualSensor(kadr);
        // если не нашли делаем рандом
        if (sensor == -1)
        {
            kadr->step = this->fGetRandomStep();
            res = this->fAddToBuffer(kadr);
        }

        return res;
    }
};
