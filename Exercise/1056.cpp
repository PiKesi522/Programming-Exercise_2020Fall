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

long long DP[10000];

void question()
{
    long long a, b;
    cin >> a >> b;
    DP[0] = 0;
    DP[1] = 1;
    if(a == b)
    {
        cout << 4 * a << endl;
        return;
    }

    long long ans = 0;
    while(a > 1 && b > 1)
    {
        if(a < b)
        {
            long long times = b / a;
            b = b % a;
            if(DP[a] == -1)
                DP[a] = a * 4;
            for (int i = 0; i < times;i++)
            {
                ans += DP[a];
            }
        }
        else if(a > b)
        {
            long long times = a / b;
            a = a % b;
            if(DP[b] == -1)
                DP[b] = b * 4;
            for (int i = 0; i < times;i++)
            {
                ans += DP[b];
            }
        }
        else if(a == b)
        {
            ans += 4 * a;
            cout << ans << endl;
            return;
        }
    }
    if(a == 1 || b == 1)
        ans += ((a > b) ? (a * 4) : (b * 4));
    cout << ans << endl;
    return;
}

int main()
{
    memset(DP, -1, sizeof(DP));
    question();
    return 0;
}