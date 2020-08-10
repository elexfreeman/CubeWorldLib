#pragma once
#include "AIHeaders.h"
#include <stdlib.h>
#include <cmath>


class MObject
{
protected:
    int nState = 0;

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
        return nState;
    }

    void Tick()
    {
        if (nState == 1)
        {
            ActionMoveToLoc();
        }
        if (nState == 0)
        {
            fMoveToLoc(fGetRandomLoc());
        }
    }

    void ActionMoveToLoc()
    {
        if (nState == 1)
        {
            loc.X = (loc.X + (newLoc.X - loc.X) / speed);
            loc.Y = (loc.Y + (newLoc.Y - loc.Y) / speed);

            if ((std::round(loc.X) == std::round(newLoc.X)) && (std::round(loc.Y) == std::round(newLoc.Y)))
            {
                nState = 0;
            }
        }
    }

    void fMoveToLoc(Coord _newLoc)
    {
        if (nState == 0)
        {
            this->newLoc = _newLoc;
            this->nState = 1; // move to loc
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
