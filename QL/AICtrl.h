#pragma once

#include <ctime>
#include <list>
#include <stdlib.h>
#include <cmath>

#define buffer_length 200
#include "AIHeaders.h"
#include "AIEqual.h"

class AICtrl
{
protected:
    int nState = 0;
    FaBuffer aBuffer;
    int nMaxBufferSize;
    AIEqual* aieq;

public:
    AICtrl(AIEqual* _aieq, int _nMaxBufferSize)
    {
        nMaxBufferSize = _nMaxBufferSize;
        this->aieq = _aieq; 
    }

    // получить похожий сенсор
    int fGetEqualSensor(AIKadr kadr)
    {
        int res = -1;
        aieq->fAddABuffer(this->aBuffer);
        res = aieq->fRun(kadr);
        return res;
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
    int fAddToBuffer(AIKadr kadr)
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
    int fGetNextStep(AIKadr kadr)
    {
        int res = 0;
        // находим похожую ситуацию из буфера сравнивая показания сенсоров
        res = this->fGetEqualSensor(kadr);
        // если не нашли делаем рандом
        if (res == -1)
        {
            kadr.step = this->fGetRandomStep();
            res = this->fAddToBuffer(kadr);
        }

        return res;
    }
};
