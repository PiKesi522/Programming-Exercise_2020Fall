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

int cnt = 0;

void print()
{
    cout << "case #" << present_location << ":" << endl;
    return;
}

void recru(int now, int all ,int steps,int end)
{
    if(steps == 0)
    {
        if(now == end)
            cnt++;
        return;
    }

    if(now == all)
        recru(now - 1, all, steps - 1, end);
    else if(now == 1)
        recru(2, all, steps - 1, end);
    else
    {
        recru(now - 1, all, steps - 1, end);
        recru(now + 1, all, steps - 1, end);
    }
}

void question()
{
    cnt = 0;
    int house, start, end, steps;
    cin >> house >> start >> steps >> end;

    recru(start, house, steps, end);
    cout << cnt << endl;
}

int main()
{
    int T;
    cin >> T;
    getchar();
    for (; present_location < T;present_location++)
    {
        question();
    }
    return 0;
}