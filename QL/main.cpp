#pragma once
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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


    MObject *obj = new MObject();
    obj->loc.X = 1.0;
    obj->loc.Y = 1.0;


    initscr();

    Coord loc;
    loc.X = 15.0;
    loc.Y = 30;
    obj->fMoveToLoc(loc);

    Screen *scr = new Screen;

    World* world = new World(scr);
    world->fAddObj(obj);
    int x = 10;
    int y = 30;

    while (obj->fGetState() != 0)
    {
        sleep(1);
        clear();

        world->Tick();
        world->fPrint();
        printw("x=%f y=%f", obj->loc.X, obj->loc.Y);
        refresh();
    }

    getch();
    endwin();
}
