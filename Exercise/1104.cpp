#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <cstring>

using namespace std;

unsigned long long DP[111];

int k;

void fac(int loc)
{
    if(DP[loc + 9] != -1)
        return;
    else
        DP[loc + 9] = 0;
    
    for(int i = 1; i <= k ;i ++)
    {
        if(DP[loc + 9 - i] == -1)
        {
            fac(loc - i);
        }

        DP[loc + 9] += DP[loc + 9 - i];
    }
    //return DP[loc + 9];
}

void question()
{
    int loc;
    cin >> k >> loc;
    memset(DP,-1,sizeof(DP));
    for(int i=0;i<10;i++)
    {
        DP[i] = 0;
    }
    DP[10] = 0;
    DP[11] = 1;

    //long long ans = fac(k,loc);
    fac(loc);

    cout << DP[loc + 9] << endl;
}

int main()
{
    question();
    return 0;
}
