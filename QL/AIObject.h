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
    AISensor* sensor;
    AICtrl* ctrl;
public:
    AIObject(Coord _loc, AISensor* _sensor, AICtrl* _ctrl);
    ~AIObject();
};

AIObject::AIObject(Coord _loc, AISensor* _sensor, AICtrl* _ctrl) : MObject(_loc)
{
    sensor = _sensor;
    ctrl = _ctrl;
}

AIObject::~AIObject()
{
}
