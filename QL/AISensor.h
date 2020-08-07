#include "AIHeaders.h"
#include "MObject.h"
#include <cmath>
class AISensor
{
private:
    /* data */
protected:
    Sensors sensors;
    MObject *obj;
    MObject *observer;

public:
    AISensor(MObject *_obj, MObject *_observer);
    ~AISensor();

    /**
     * Информаия об объекте 
     * */
    Sensors fGetObjInfo();
};

AISensor::AISensor(MObject *_obj, MObject *_observer)
{
    this->obj = _obj;
    this->observer = _observer;
}

AISensor::~AISensor()
{
}

Sensors AISensor::fGetObjInfo()
{
    sensors.L = std::sqrt((obj->loc.X - observer->loc.X) * (obj->loc.X - observer->loc.X) + (obj->loc.Y - observer->loc.Y) * (obj->loc.Y - observer->loc.Y));


/*
-- sensors --
        
    4   1
      *
    3   2
*/

    sensors.S1 = (obj->loc.X >= observer->loc.X) && (obj->loc.Y >= observer->loc.Y);
    sensors.S2 = (obj->loc.X >= observer->loc.X) && (obj->loc.Y <= observer->loc.Y);
    sensors.S3 = (obj->loc.X <= observer->loc.X) && (obj->loc.Y <= observer->loc.Y);
    sensors.S4 = (obj->loc.X <= observer->loc.X) && (obj->loc.Y >= observer->loc.Y);

    return sensors;
}