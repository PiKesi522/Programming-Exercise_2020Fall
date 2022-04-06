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

int mov = 0;
long long n, m;
bool Getit = false;

bool check()
{
    m = 0;
    int tm[100] = {0};
    long long temp = n;
    int size = 0;
    while(temp != 0)
    {
        tm[size] = temp % 10;
        m *= 10;
        m += temp % 10;
        temp /= 10;
        size++;
    }

    temp = n;
    for (int i = 0; i < size;i++)
    {
        if(tm[size - 1 -i] != tm[i])
            return false;
    }
    return true;
}

void question()
{
    Getit = check();
    while(!Getit)
    {
        n += m;
        mov++;
        Getit = check();
    }
    cout << mov << ' ' << n << endl;
}

int main()
{
    cin >> n;
    question();
    return 0;
}