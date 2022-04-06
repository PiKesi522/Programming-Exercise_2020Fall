#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <cstring>
#include <sstream>

using namespace std;

int present_location = 0;

void print()
{
    cout << "case #" << present_location << ":" << endl;
    return;
}

long long f(int n,long long DP[])
{
    if(DP[n] != -1)
        return DP[n];
    else
    {
        long long temp = f(n - 1,DP) + f(n - 2,DP) + f(n - 3,DP) + f(n - 4,DP);
        DP[n] = temp;
        return temp;
    }
}

void question()
{
    long long DP[100];
    memset(DP, -1, sizeof(DP));
    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    DP[4] = 8;
    int n;
    cin >> n;
    print();
    long long ans = 0;
    ans = f(n,DP);
    cout << ans << endl;
    return;
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