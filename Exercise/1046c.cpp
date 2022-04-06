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

void question()
{
    char ch;
    int loc = 0;
    vector<char> table[500];
    memset(table, '\0', sizeof(table));
    while((ch = getchar()) != '\n')
    {
        if(isalpha(ch))
        {
            table[loc].push_back(ch);
        }
        else
        {
            if(table[loc].size() > 0)
                loc++;
        }
    }

    if(table[loc].size() > 0)
        loc++;

    print();
    set<string> ans;
    
    //stringstream line;
    for (int i = 0; i < loc;i++)
    {
        string s;
        for(auto v : table[i])
            s += v;
        ans.insert(s);
    }

    for (auto it = ans.begin(); it != ans.end();it++)
    {
        cout << *it << ' ';
    }
    cout << endl;
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