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

    int dL = 10; // растояние для обмера
public:
    AIEqual();
    ~AIEqual();
    AIEqual *fAddABuffer(FaBuffer _aBuffer);
    AIEqual *fSetDl(int _dL);
    int fRun(AIKadr kadr);

    /**
     * Сравнивает кадры 
     * */
    bool fEqKadr(AIKadr kadr1, AIKadr kadr2);

    /**
     * Сравнивает длину 
     * */
    bool fEqL(float L1, float L2);
};

AIEqual::AIEqual()
{
}

AIEqual::~AIEqual()
{
}

AIEqual *AIEqual::fSetDl(int _dL)
{
    this->dL = _dL;
    return this;
}

AIEqual *AIEqual::fAddABuffer(FaBuffer _aBuffer)
{
    this->aBuffer = _aBuffer;
    return this;
}

// ....L2.........
// -10 ...L1 ... 10
// ...........L2...
bool AIEqual::fEqL(float L1, float L2)
{
    bool bL1 = (L2 > L1) && (L2 < L1 + this->dL);
    bool bL2 = (L2 > L1 - this->dL) && (L2 < L1);
    return bL1 || bL2;
}

bool AIEqual::fEqKadr(AIKadr kadr1, AIKadr kadr2)
{
    bool eqS1 = false;
    bool eqS2 = false;
    bool eqS3 = false;
    bool eqS4 = false;
    bool eqL = false;

    // первый кадр
    eqS1 = kadr1.K1.S1 == kadr2.K1.S1;
    eqS2 = kadr1.K1.S2 == kadr2.K1.S2;
    eqS3 = kadr1.K1.S3 == kadr2.K1.S3;
    eqS4 = kadr1.K1.S4 == kadr2.K1.S4;
    eqL = this->fEqL(kadr1.K1.L, kadr2.K1.L);
    if (!(eqS1 && eqS2 && eqS3 && eqS4 && eqL))
    {
        return false;
    }

    // второй кадр
    eqS1 = kadr1.K2.S1 == kadr2.K2.S1;
    eqS2 = kadr1.K2.S2 == kadr2.K2.S2;
    eqS3 = kadr1.K2.S3 == kadr2.K2.S3;
    eqS4 = kadr1.K2.S4 == kadr2.K2.S4;
    eqL = this->fEqL(kadr1.K2.L, kadr2.K2.L);
    if (!(eqS1 && eqS2 && eqS3 && eqS4 && eqL))
    {
        return false;
    }

    // третий кадр
    eqS1 = kadr1.K3.S1 == kadr2.K3.S1;
    eqS2 = kadr1.K3.S2 == kadr2.K3.S2;
    eqS3 = kadr1.K3.S3 == kadr2.K3.S3;
    eqS4 = kadr1.K3.S4 == kadr2.K3.S4;
    eqL = this->fEqL(kadr1.K3.L, kadr2.K3.L);
    if (!(eqS1 && eqS2 && eqS3 && eqS4 && eqL))
    {
        return false;
    }

    return true;
}

int AIEqual::fRun(AIKadr kadr)
{
    for (auto it = aBuffer.begin(); it != aBuffer.end(); ++it)
    {
        //(*it)->fMoveToLoc(world->fGetRandomLoc());
    }
    return -1;
}