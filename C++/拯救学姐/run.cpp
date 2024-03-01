#include "game.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <conio.h>
game::game(){
    init();
}
void game::init(){
    srand(time(NULL));
    xfood=rand()%xmax;
    yfood=rand()%ymax;
    x = xmax / 2;
    y = ymax / 2;
    score = 0;
    ins = stop;
}
void game::mode(){
    system("cls");
    for (int i = 0; i < ymax; i++)
    {
        for (int j = 0; j < xmax; j++)
        {
            if (j == 0)
                cout << "*";
            if (i == y && j == x)
                cout << "O";
            else if (i == yfood && j == xfood)
                cout << "@";
            else
            {
                bool flag= false;
                for (int k = 0; k < lenth; k++)
                {
                    if (tailx[k] == j && taily[k] == i)
                    {
                        cout << "o";
                        flag = true;
                    }
                }
                if (!flag)
                    cout << " ";
            }
            if (j == xmax - 1)
                cout << "*";
        }
        cout << endl;
    }
    cout<<score<<endl;
}
void game::input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            ins = A;
            break;
        case 'd':
            ins = D;
            break;
        case 'w':
            ins = W;
            break;
        case 's':
            ins = S;
            break;
        case 'q':                        //push q to quit
            ins = stop;
            break;
        }
    }
}
int game::move(){
    int prex =tailx[0];
    int prey =taily[0];
    int nextx, nexty;
    tailx[0] = x;
    taily[0] = y;
    for (int i = 1; i < lenth; i++)
    {
        nextx = tailx[i];
        nexty = taily[i];
        tailx[i] = prex;
        taily[i] = prey;
        prex = nextx;
        prey = nexty;
    }
    switch (ins)
    {
    case A:
        x--;
        break;
    case D:
        x++;
        break;
    case S:
        y--;
        break;
    case W:
        y++;
        break;
    default:
        break;
    }
    if(x>=xmax)
        x = 0;
    else x = xmax - 1;
    if(y>=ymax)
        y = 0;
    else y = ymax - 1;
    for (int i = 0; i < lenth; i++)
        if (tailx[i] == x && taily[i] == y)
            score = 0;
    if (x == xfood && y == yfood)
    {
        score += 10;
        lenth += 1;
        xfood = rand() % xmax;
        yfood = rand() % ymax;
    }
    return score;
}