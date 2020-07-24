#pragma once
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <ctime>
#include <cmath>
#include <iostream>
#include <list>
#include <string>

#include "MObject.cpp"
#include "Screen.cpp"
#include "World.cpp"

class MyWorld
{
public:
    // std::list<MObject *> aObject;

    // void Loop()
    // {
    //     while (true)
    //     {
    //         for (auto it = aObject.begin(); it != aObject.end(); ++it)
    //         {
    //             (*it)->Tick();
    //         }
    //         usleep(300);
    //     }
    // }
};

int main()
{
    std::srand(std::time(nullptr)); // рандомизация генератора случайных чисел
    MObject *obj = new MObject();
    MObject *obj2 = new MObject();

    initscr();

    Screen *scr = new Screen;

    World *world = new World(scr);

    world->fAddRnfPoint();
    world->fAddRnfPoint();
    world->fAddRnfPoint();
    world->fAddRnfPoint();
    world->fAddRnfPoint();

    while (true)
    {
        usleep(100000);
        clear();

        for (auto it = world->aObject.begin(); it != world->aObject.end(); ++it)
        {
            if ((*it)->fGetState() == 0)
            {
                (*it)->fMoveToLoc(world->fGetRandomLoc());
            }
        }
        world->Tick();
        world->fPrint();
        refresh();
    }

    getch();
    endwin();
}
