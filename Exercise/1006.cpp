#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <vector>

/*找两个数在二进制下不同的位数*/

using namespace std;
typedef long long LL;

void func()
{
    LL x, y;
    cin >> x >> y;

    int cnt = 0;

    while(x || y)
    {
        if (x % 2 != y % 2)
            cnt++;
        x = x / 2;
        y = y / 2;
    }

    cout << cnt << endl;

    return;
}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        func();
    }

    return 0;
}
