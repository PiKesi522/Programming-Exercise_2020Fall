#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <vector>

using namespace std;

int ans = 0;

void func(int x)
{
    ans *= 3;
    ans += x;
}

void question(int present_location)
{
    string s;
    cin >> s;
    for (decltype(s.size()) i = 0; i < s.size();i++)
    {
        char ch = s[i];
        if(ch == '-')
            func(-1);
        else if(ch == '0')
            func(0);
        else if(ch == '1')
            func(1);
    }
    cout << "case #" << present_location << ":" << endl << ans << endl;
    return;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T;i++)
    {
        ans = 0;
        question(i);
    }
    return 0;
}