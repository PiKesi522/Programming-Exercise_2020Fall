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

long long T[74];

int cnt = 0;

void print()
{
    cout << "case #" << present_location << ":" << endl;
    return;
}

long long recru(int n)
{
    if(T[n] == -1)
        T[n] = recru(n - 1) + recru(n - 2) + recru(n - 3);

    return T[n];
}

void question()
{
    int n;
    cin >> n;
    recru(n);
    print();
    cout << T[n] << endl;
}

int main()
{
    int Case;
    cin >> Case;
    memset(T, -1, sizeof(T));
    T[0] = 0;
    T[1] = 1;
    T[2] = 1;
    getchar();
    for (; present_location < Case;present_location++)
    {
        question();
    }
    return 0;
}