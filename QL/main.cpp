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

    int x = 10;
    int y = 30;

    while (obj->fGetState() != 0)
    {
        sleep(1);
        clear();
        /* code */
        scr->fClear();
        x = std::round(obj->loc.X);
        y = std::round(obj->loc.Y);
        scr->aMatrix[x][y] = 9;
        obj->Tick();
        scr->fPrint();
        printw("x=%f y=%f", obj->loc.X, obj->loc.Y);
        refresh();
    }

    getch();
    endwin();
}
