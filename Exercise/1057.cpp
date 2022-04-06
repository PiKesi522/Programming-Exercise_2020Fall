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
    return;
}

double fac()
{
    char s[10];
    cin >> s;
    switch (s[0])
    {
    case '+':
        return fac() + fac();
        break;
    case '-':
        return fac() - fac();
        break;    
    case '*':
        return fac() * fac();
        break;
    case '/':
        return fac() / fac();
        break;          
    default:
        return atof(s);
        break;
    }
}

void question()
{
    print();
    printf("%lf", fac());
    cout << endl;
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