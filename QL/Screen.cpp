#pragma once

#define mx 20
#define my 80
#include <ncurses.h>


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
