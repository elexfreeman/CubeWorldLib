#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <ctime>
#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include "AIHeaders.h"
#include "AICtrl.h"
#include "AIEqual.h"

void testGetRandomStep()
{
    AIEqual *eq = new AIEqual();
    AICtrl *ctrl = new AICtrl(eq, 200);

    int out = 1;
    while (out != 5)
    {
        out = ctrl->fGetRandomStep();
        std::cout << out << "\n\r";
    }
}

void testEqual()
{
    Sensors s1;
    s1.L = 10;
    s1.S1 = true;
    s1.S2 = false;
    s1.S3 = false;
    s1.S4 = false;

    Sensors s2;
    s2.L = 12;
    s2.S1 = true;
    s2.S2 = false;
    s2.S3 = false;
    s2.S4 = false;

    Sensors s3;
    s3.L = 13;
    s3.S1 = true;
    s3.S2 = false;
    s3.S3 = false;
    s3.S4 = false;

    Sensors s4;
    s4.L = 13;
    s4.S1 = true;
    s4.S2 = false;
    s4.S3 = false;
    s4.S4 = false;

    AIKadr k;

    k.K1 = s1;
    k.K2 = s2;
    k.K3 = s3;

    k.L = 14;
    k.step = 1;

    FaBuffer aBuffer;

    aBuffer.push(k);
    aBuffer.push(k);
    aBuffer.push(k);
    aBuffer.push(k);


    AIEqual *eq = new AIEqual();
    eq->fAddABuffer(aBuffer);

    AIKadr item;
    item.L = 2;

    item = eq->fRun(k);

    std::cout << item.L;
}

void testDl()
{
    AIEqual *eq = new AIEqual();

    if (eq->fEqL(20, 15))
    {
        std::cout << "TRUE";
    }
}

int main()
{

    std::cout << "test \r\n";
    testEqual();
}
