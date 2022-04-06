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
string s;
map<char, int> ls;

/*
输入一个十进制数 N，将它转换成 R 进制数输出。

输入格式
输入一个正整数 T 。表示测试数据的组数。

每个测试实例包含两个整数 N (32bits整数) 和 R (2 <= R <= 36).

输出格式
为每个测试实例输出转换后的数，每个输出占一行。如果 R 大于 10 ，则对应的数字规则参考 16 进制
（比如，10 用 A 表示 , 16 用 G 表示等等）。
*/

char table[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

void change()
{
    int N;
    int R;
    cin >> N >> R;
    bool flag = false;
    if(N < 0)
    {
        N = -N;
        flag = true;
    }

    vector<char> ans;

    while(N >= R)
    {
        ans.push_back(table[N % R]);
        N = N / R;
    }
    ans.push_back(table[N]);

    if(flag)
        cout << '-';

    for (auto i = ans.end() - 1; i != ans.begin();i--)
    {
        cout << *i;
    }
    cout << *(ans.begin());

    cout << endl;
}

int main()
{
    LL T;
    cin >> T;

    for (LL i = 0; i < T; i++)
        change();

    return 0;
}