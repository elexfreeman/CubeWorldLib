#pragma once
#include <vector>
#include "conf.h"
#include "AIHeaders.h"
#include "Screen.h"
#include "MObject.h"

class World
{
protected:
    Screen *scr;

public:
    std::vector<MObject *> aObject;

    World(Screen *_scr)
    {
        this->scr = _scr;
    }

    /**
     * Добавить объект в мир 
     * */
    void fAddObj(MObject *obj)
    {
        this->aObject.push_back(obj);
    }

    /**
     * Тики объктов 
     * */
    void Tick()
    {
        for (int i = 0; i < aObject.size(); i++)
        {
            aObject[i]->Tick();
        }
    }

    /**
     * вывод на экран 
     * */
    void fPrint()
    {
        int x, y;
        scr->fClear();
        for (int i = 0; i < aObject.size(); i++)
        {
            if (aObject[i]->fIsVisible(mx, my))
            {
                x = std::round(aObject[i]->loc.X);
                y = std::round(aObject[i]->loc.Y);
                scr->aMatrix[x][y] = 9;
            }
        }
        scr->fPrint();
    }

    /**
     * Добавить случайную точку
     * */
    MObject *fAddRnfPoint()
    {
        MObject *obj = new MObject(fGetRandomLoc());
        fAddObj(obj);
        return obj;
    }
};
