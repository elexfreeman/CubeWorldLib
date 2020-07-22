#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <cmath>
#include <iostream>
#include <list>
#include <string>

#define mx 20
#define my 80

struct Coord
{
    float X;
    float Y;
};

class MAction
{
    void fDo()
    {
    }
};

class MObject
{
protected:
    int state = 0;

public:
    Coord loc;

    Coord newLoc;

    float speed = 4;

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
};

class MyWorld
{
public:
    std::list<MObject *> aObject;

    void Loop()
    {
        while (true)
        {
            for (auto it = aObject.begin(); it != aObject.end(); ++it)
            {
                (*it)->Tick();
            }
            usleep(300);
        }
    }
};

class Screen
{
public:
    int aMatrix[mx][my] = {};

    void fClear()
    {
        for (int x = 0; x < mx; x++)
        {
            for (int y = 0; y < my; y++)
            {
                aMatrix[x][y] = 0;
            }
        }
    }

    void fPrint()
    {
        for (int x = 0; x < mx; x++)
        {
            for (int y = 0; y < my; y++)
            {
                if (aMatrix[x][y] == 0)
                {
                    printw(" ");
                }
                else
                {
                    printw("%d", aMatrix[x][y]);
                }
            }
            printw("\n");
        }
    }
};

class World
{
private:
    int aMatrix[mx][my] = {};

public:
    std::list<MObject *> aObject;

    World()
    {
        for (int x = 0; x < mx; x++)
        {
            for (int y = 0; y < my; y++)
            {
                aMatrix[x][y] = 0;
            }
        }
    }

    void clear()
    {
        for (int x = 0; x < mx; x++)
        {
            for (int y = 0; y < my; y++)
            {
                aMatrix[x][y] = 0;
            }
        }
    }

    void fPrint()
    {
        for (int x = 0; x < mx; x++)
        {
            for (int y = 0; y < my; y++)
            {
                if (aMatrix[x][y] == 0)
                {
                    printw(" ");
                }
                else
                {
                    printw("%d", aMatrix[x][y]);
                }
            }
            printw("\n");
        }
    }

    void fPoint(int dx, int dy)
    {
        aMatrix[dx][dy] = 9;
        int val = 0;
        for (int x = 0; x < mx; x++)
        {
            for (int y = 0; y < my; y++)
            {
                if (!((dx == x) && (dy == y)))
                {
                    val = std::round(9 - std::sqrt(((dx - x) * (dx - x)) + ((dy - y) * (dy - y))));

                    if ((val > 0) && (aMatrix[x][y] != 9))
                    {
                        aMatrix[x][y] = val + aMatrix[x][y];
                    }
                }
            }
        }
    }
};

void screen1()
{
    initscr();                // Переход в curses-режим
    printw("Hello world!\n"); // Отображение приветствия в буфер
    refresh();                // Вывод приветствия на настоящий экран
    getch();                  // Ожидание нажатия какой-либо клавиши пользователем

    clear();
    printw("Helclo worlsdsdd!\n"); // Отображение приветствия в буфер
    refresh();                     // Вывод приветствия на настоящий экран
    getch();                       // Ожидание нажатия какой-либо клавиши пользователем
    endwin();
}

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
