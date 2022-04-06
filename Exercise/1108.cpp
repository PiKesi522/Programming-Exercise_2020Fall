#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

typedef long long LL;
string s;
map<char, int> ls;

/*
输入第一行 有几个砝码
输入第二行 这些砝码各是多少重、
输出    从1开始到所有重量加和，那些重量的物体可以被称出来
*/

int weights[10] ={0};
int ans[1005] = {0};

void fac(int prime_sum, int present_location, int num,int n)
{
    if(present_location == n)
        return;

    prime_sum = prime_sum + num * weights[present_location];

    ans[abs(prime_sum)] = 1;

    fac(prime_sum, present_location + 1, -1, n);
    fac(prime_sum, present_location + 1, 0, n);
    fac(prime_sum, present_location + 1, 1, n);

    return;
}

void check(int n)
{
    fac(0, 0, -1, n);
    fac(0, 0, 0, n);
    fac(0, 0, 1, n);

    return;
}

int main()
{
    int n;
    cin >> n;

    int max = 0,temp;
    for(int i = 0;i < n; i++)
    {
        cin >> temp;
        weights[i] = temp;
        max += temp;
    }

    check(n);

    for (int i = 1; i <= max; i++)
    {
        cout << ans[i];
    }
    
    return 0;
}