#include "AIHeaders.h"
#include "MObject.h"

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
}