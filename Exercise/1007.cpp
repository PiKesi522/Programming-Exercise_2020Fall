#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef long long LL;

void func(int present_loccation)
{
    long long n;
    cin >> n;
    int cnt = 1;
    int table[33] = {0};
    int i = 0;

    while (n != 0)
    {
        table[i] = n % 2;
        n = n / 2;
        i++;
    }

    int ans = 1;
    int temp = table[0];
    for (int j = 1; j < i;j++)
    {
        if(table[j] != temp)
        {
            cnt++;
            if(ans < cnt)
                ans = cnt;
        }
        else
        {
            cnt = 1;
        }
        temp = table[j];
    }

    cout << "case #" << present_loccation << ":" << endl;
    cout << ans << endl;

}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T;i++)
    {
        func(i);
    }

    return 0;
}