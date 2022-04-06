#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstdio>

using namespace std;

deque<char> moves;

void check()
{
    //bool reach = false;
    int finx, finy;
    cin >> finx >> finy;
    int x = 0,y = 0;
    deque<char> mov;
    for(auto v : moves)
        mov.push_back(v);
    char ch;
    int cnt = 1000;
    while(!mov.empty() && cnt != 0)
    {
        ch = *mov.begin();
        mov.pop_front();

        if(x == finx && y == finy)
        {
            cout << "Yes" << endl;
            return;
        }

        switch (ch)
        {
        case 'U':
            y += 1;
            break;
        case 'D':
            y -= 1;
            break;
        case 'R':
            x += 1;
            break;
        case 'L':
            x -= 1;
            break;
        default:
            break;
        }

        if(mov.empty())
        {
            cnt--;
            for(auto v : moves)
                mov.push_back(v);
        }
    }
    cout << "No" << endl;
}

void question()
{
    char ch;
    while((ch = getchar()) != '\n')
        moves.push_back(ch);

    int que;
    cin >> que;

    for (int i = 0; i < que;i++)
        check();
}

int main()
{
    question();
    return 0;
}