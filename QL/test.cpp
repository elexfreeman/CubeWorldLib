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
    
}

int main()
{

    std::cout << "test \r\n";
}
