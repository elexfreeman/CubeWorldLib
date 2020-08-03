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
    AIEqual();
    ~AIEqual();
    AIEqual *fAddABuffer(FaBuffer _aBuffer);
    int fRun(AIKadr kadr);
};

AIEqual::AIEqual()
{
}

AIEqual::~AIEqual()
{
}

AIEqual *AIEqual::fAddABuffer(FaBuffer _aBuffer)
{
    this->aBuffer = _aBuffer;
    return this;
}

int AIEqual::fRun(AIKadr kadr)
{
    return -1;
}