#pragma once
#include "AIHeaders.h"
#include <stdlib.h>
#include <cmath>


class MObject
{
protected:
    int state = 0;

public:
    Coord loc;

    Coord newLoc;

    MObject(Coord _loc)
    {
        this->loc = _loc;
    }

    float speed = 20;

    int fGetState()
    {
        return state;
    }

    void Tick()
    {
        if (state == 1)
        {
            ActionMoveToLoc();
        }
        if (state == 0)
        {
            fMoveToLoc(fGetRandomLoc());
        }
    }

    void ActionMoveToLoc()
    {
        if (state == 1)
        {
            loc.X = (loc.X + (newLoc.X - loc.X) / speed);
            loc.Y = (loc.Y + (newLoc.Y - loc.Y) / speed);

            if ((std::round(loc.X) == std::round(newLoc.X)) && (std::round(loc.Y) == std::round(newLoc.Y)))
            {
                state = 0;
            }
        }
    }

    void fMoveToLoc(Coord _newLoc)
    {
        if (state == 0)
        {
            this->newLoc = _newLoc;
            this->state = 1; // move to loc
        }
    }

    /**
     * Проверка на возможность отображать на экране 
     */
    bool fIsVisible(int maxX, int maxY)
    {
        return (loc.X < maxX) && (loc.X >= 0) && (loc.Y < maxY) && (loc.Y >= 0);
    }
};
