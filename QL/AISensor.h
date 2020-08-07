#include "AIHeaders.h"
#include <cmath>
class AISensor
{
private:
    /* data */
protected:
    Sensors sensors;
    Coord obj;
    Coord observer;

public:
    AISensor(Coord _obj, Coord _observer);
    ~AISensor();

    /**
     * Информаия об объекте 
     * */
    Sensors fGetObjInfo();
};

AISensor::AISensor(Coord _obj, Coord _observer)
{
    this->obj = _obj;
    this->observer = _observer;
}

AISensor::~AISensor()
{
}

Sensors AISensor::fGetObjInfo()
{
    sensors.L = std::sqrt((obj.X - observer.X) * (obj.X - observer.X) + (obj.Y - observer.Y) * (obj.Y - observer.Y));

/*
-- sensors --
        
    4   1
      *
    3   2
*/

    sensors.S1 = (obj.X >= observer.X) && (obj.Y >= observer.Y);
    sensors.S2 = (obj.X >= observer.X) && (obj.Y <= observer.Y);
    sensors.S3 = (obj.X <= observer.X) && (obj.Y <= observer.Y);
    sensors.S4 = (obj.X <= observer.X) && (obj.Y >= observer.Y);

    return sensors;
}