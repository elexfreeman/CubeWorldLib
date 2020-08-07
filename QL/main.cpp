#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <ctime>
#include <cmath>
#include <iostream>
#include <list>
#include <string>

#include "MObject.h"
#include "Screen.h"
#include "World.h"

int main()
{
    std::srand(std::time(nullptr)); // рандомизация генератора случайных чисел

    MObject *obj = new MObject(fGetRandomLoc());
    MObject *obj2 = new MObject(fGetRandomLoc());

    initscr();

    Screen *scr = new Screen;

    World *world = new World(scr);

    world->fAddObj(obj);
    world->fAddObj(obj2);

    while (true)
    {
        usleep(100000);
        clear();

        world->Tick();
        world->fPrint();
        refresh();
    }

    getch();
    endwin();
}
