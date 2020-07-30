#pragma once
#include "AIHeaders.h"
/**
 * Класс поиска похожего события
 * */
class AIEqual
{
private:
    /* data */
    FaBuffer aBuffer;

public:
    AIEqual(/* args */);
    ~AIEqual();
    AIEqual *fAddABuffer(FaBuffer _aBuffer);
    int fRun(AIKadr kadr);
};

AIEqual::AIEqual(/* args */)
{
}

AIEqual::~AIEqual()
{
}

AIEqual *AIEqual::fAddABuffer(FaBuffer _aBuffer)
{
    this->aBuffer = _aBuffer;
}

int AIEqual::fRun(AIKadr kadr)
{
    return -1;
}