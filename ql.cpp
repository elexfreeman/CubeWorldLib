#include <iostream>
#include <cmath>
#include <ncurses.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#define mx 20
#define my 80

class World
{
private:
    int aMatrix[mx][my] = {};

public:
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
                printw("%d", aMatrix[x][y]);
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
                    val = floor(9 - std::sqrt(((dx - x) * (dx - x)) + ((dy - y) * (dy - y))));

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
    initscr();

    World *world = new World();

    world->fPoint(5, 5);
    world->fPoint(15, 15);
    world->fPrint();

    refresh(); // Вывод приветствия на настоящий экран

    getch(); // Ожидание нажатия какой-либо клавиши пользователем
    endwin();
}
