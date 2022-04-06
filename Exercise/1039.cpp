#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;

set<char> v;
set<set<char>> ans;

void print(int present_location)
{
    cout << "case #" << present_location << ":" << endl;
    return;
}

void fac(bool prt,char *s,int present_location,int limit)
{
    if(present_location > limit)
        return;

    if(prt)
        v.insert(s[present_location]);
    
    
    fac(true, s, present_location + 1, limit);

    fac(false, s, present_location + 1, limit);

    ans.insert(v);

    v.erase(s[present_location]);

    return;
}

void question(int present_location)
{
    set<char> ls;
    char ch;
    while(!v.empty())
        v.clear();
    
    while(!ans.empty())
        ans.clear();

    while((ch = getchar()) != '\n')
        ls.insert(ch);

    int len = ls.size();

    char s[20] = {'\0'};

    int i = 0;
    for (auto it = ls.begin(); it != ls.end();it++)
    {
        s[i] = *it;
        i++;
    }

    print(present_location);

    fac(true, s, 0, len - 1);
    fac(false, s, 0, len - 1);

    for (auto it = ++ans.begin(); it != ans.end();it++)
    {
        for(auto v : *it)
        {
            cout << v;
        }

        cout << endl;
    }

        return;
}

int main()
{
    int T;
    cin >> T;

    getchar();
    for (int i = 0; i < T;i++)
        question(i);

    return 0;
}