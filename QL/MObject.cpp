#pragma once

#include <stdlib.h>
#include <cmath>

struct Coord
{
    float X;
    float Y;
};

class MObject
{
protected:
    int state = 0;

public:
    Coord loc;

    Coord newLoc;

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
