#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <cstring>

using namespace std;

int T;

void question()
{
    cin >> T;
    int x = 0, y = 0;
    long long loc = 0;
    long long mov = -1;

    while(T >= loc)
    {
        mov += 8;
        loc += mov;
        x++;
        if(T == loc)
        {
            cout << '(' << x << ",0)" << endl;
            return;
        }
    }
    x--;
    loc -= mov;

    int cc = x;

    for (int i = 0; i < cc + 1 ;i++)
    {
        if(loc == T)
        {
            cout << '(' << x << ',' << y << ')' << endl;
            return;
        }
        else
        {
            loc++;
            y += 1;
        }
    }

    for (int i = 0; i < 2 * cc + 1 ;i++)
    {
        if(loc == T)
        {
            cout << '(' << x << ',' << y << ')' << endl;
            return;
        }
        else
        {
            loc++;
            x -= 1;
        }
    }

    for (int i = 0; i < 2 * (cc + 1) ;i++)
    {
        if(loc == T)
        {
            cout << '(' << x << ',' << y << ')' << endl;
            return;
        }
        else
        {
            loc++;
            y -= 1;
        }
    }

    for (int i = 0; i < 2 * (cc + 1) ;i++)
    {
        if(loc == T)
        {
            cout << '(' << x << ',' << y << ')' << endl;
            return;
        }
        else
        {
            loc++;
            x += 1;
        }
    }

    for (int i = 0; i < cc + 1 ;i++)
    {
        if(loc == T)
        {
            cout << '(' << x << ',' << y << ')' << endl;
            return;
        }
        else
        {
            loc++;
            y += 1;
        }
    }

    cout << "bug";
}

int main()
{
    question();
    return 0;
}
