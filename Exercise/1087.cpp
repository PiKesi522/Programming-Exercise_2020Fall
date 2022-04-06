#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int present_location = 0;

void print()
{
    cout << "case #" << present_location << ":" << endl;
}

void question()
{
    string table;
    cin >> table;
    //map<int, char> ans;
    int R = -1, B = -1, Y = -1, G = -1;
    string str = "RBYG";
    char cans[4] = {'\0'};
    int ians[4];
    memset(ians, -1, sizeof(ians));

    if(table.find('R') != table.npos)
    {
        R = table.find('R') % 4;
        cans[R] = 'R';
        ians[R] = R;
    }
    if(table.find('B') != table.npos)
    {
        B = table.find('B') % 4;
        cans[B] = 'B';
        ians[B] = B;
    }
    if(table.find('Y') != table.npos)
    {
        Y = table.find('Y') % 4;
        cans[Y] = 'Y';
        ians[Y] = Y;
    }
    if(table.find('G') != table.npos)
    {
        G = table.find('G') % 4;
        cans[G] = 'G';
        ians[G] = G;
    }

    int still = 3;
    while(still+1)
    {
        int appear = false;
        for (int i = 0; i < 4;i++)
        {
            if(ians[i] == still) // 是否已经被记录
            {
                appear = true; // 已经被记录
                break;
            }
        }

        if(!appear)
        {
            if(R == -1)
            {
                cans[still] = 'R';
                R = still;
            }
            else if(B == -1)
            {
                cans[still] = 'B';
                B = still;
            }
            else if(Y == -1)
            {
                cans[still] = 'Y';
                Y = still;
            }
            else if(G == -1)
            {
                cans[still] = 'G';
                G = still;
            }
            ians[still] = still;     
        }
        still--;
    }

    int len = table.length();
    int tot[4] = {0};
    for (int i = 0; i < len;i++)
    {
        if (table[i] != cans[i % 4])
            tot[i % 4]++;
    }

    print();
    int lloc[4] = {R, B, Y, G};
    for (int i = 0; i < 4;i++)
    {
        cout << tot[lloc[i]] << ' ';
    }
        cout << endl;
    return;
}

int main()
{
    int T;
    cin >> T;
    for (; present_location < T; present_location++)
        question();
    return 0;
}