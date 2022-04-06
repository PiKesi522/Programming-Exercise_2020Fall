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

void myplus(int ans[],int a)
{
    int len = 0;
    int *temp = (int *)malloc(sizeof(int) * 1000);
    for (; len < 1000;len++)
    {
        if(ans[len] == -1)
            break;
        temp[len] = ans[len];
    }

    int j = 0;
    for (; j < len; j++)
    {
        for (int i = 0; i < a - 1;i++)
        {
            ans[j] += temp[j];
        }

        if(ans[j] >= 10)
        {
            int zs = ans[j] / 10;
            ans[j] = ans[j] % 10;
            if(ans[j + 1] == -1)
                ans[j + 1]++;
            ans[j + 1] += zs;
        }
    }

    free(temp);
}

void question()
{
    int a, n;
    cin >> a >> n;
    if (n == 0)
    {
        print();
        cout << 1 << endl;
        return;
    }

    int *ans = (int *)malloc(sizeof(int) * 1000);
    for (int i = 0; i < 1000;i++)
    {
        ans[i] = -1;
    }

    ans[0] = a;

    for (int i = 0; i < n - 1;i++)
    {
        myplus(ans,a);
    }

    print();
    int len = 0;
    //vector<int> rans;
    while(ans[len] != -1)
        len++;

    for (int i = len - 1; i >= 0;i--)
    {
        cout << ans[i];
    }
    cout << endl;

    free(ans);
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