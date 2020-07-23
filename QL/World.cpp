#pragma once

#include "conf.cpp"
#include "Screen.cpp"
#include <list>
#include "MObject.cpp"

class World
{
protected:
    Screen *scr;
    std::list<MObject *> aObject;

public:
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
        for (auto it = aObject.begin(); it != aObject.end(); ++it)
        {
            (*it)->Tick();
        }
    }

    /**
     * вывод на экран 
     * */
    void fPrint()
    {
        int x, y;
        scr->fClear();
        for (auto it = aObject.begin(); it != aObject.end(); ++it)
        {
            if ((*it)->fIsVisible(mx, my))
            {
                x = std::round((*it)->loc.X);
                y = std::round((*it)->loc.Y);
                scr->aMatrix[x][y] = 9;
            }
        }
        scr->fPrint();
    }
};
