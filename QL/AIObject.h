#pragma once
#include "AIHeaders.h"
#include <stdlib.h>
#include <cmath>
#include "MObject.h"
#include "AISensor.h"
#include "AICtrl.h"

class AIObject : public MObject
{
protected:
    AICtrl *ctrl;
    MObject *target;
    int nKadr = 0; // сколько кадров прошло

    AIKadr kadr;
    int nMoveTo = 1; // в какую сторону двигаться
public:
    AIObject(Coord _loc, AICtrl *_ctrl, MObject *_target);
    ~AIObject();
    void Tick();

    void ActionMoveToLoc();

    void fMove1();
    void fMove2();
    void fMove3();
    void fMove4();
};

AIObject::AIObject(Coord _loc, AICtrl *_ctrl, MObject *_target) : MObject(_loc)
{
    ctrl = _ctrl;
    target = _target;
}

AIObject::~AIObject()
{
}

void AIObject::Tick()
{
    // продолжаем двигаться
    if (this->nState == 1)
    {
        ActionMoveToLoc();
    }
    // ожидание действия
    if (this->nState == 0)
    {
        this->nState = 2;
    }
    // сбор информации о наблюдаемом объекте
    if (this->nState == 2)
    {
        // получаем инфу

        // сдигаем счетчик кадров
        this->nKadr++;
    }

    if (nKadr > 1)
    {
        this->nMoveTo = this->ctrl->fGetNextStep(this->kadr);
        this->nState = 1;
        this->nState = 0;
    }
}

void AIObject::ActionMoveToLoc()
{
    if (nState == 1)
    {
        loc.X = (loc.X + (newLoc.X - loc.X) / speed);
        loc.Y = (loc.Y + (newLoc.Y - loc.Y) / speed);

        if ((std::round(loc.X) == std::round(newLoc.X)) && (std::round(loc.Y) == std::round(newLoc.Y)))
        {
            nState = 0;
        }
    }
}