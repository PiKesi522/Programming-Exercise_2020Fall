#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set<long long> s;

void question(int method)
{
    long long temp;
    while(cin >> temp)
        s.insert(temp);
    //auto beg = --s.begin();
    if(method == 'A')
        for(auto v : s)
        {
            cout << v << ' ';
        }
    else
        for(auto it = s.rbegin();it != s.rend();it++)
        {
            cout << *it << ' ';
        }
    cout << endl;
    return;
}

int main()
{
    char method;
    cin >> method;
    question(method);
    return 0;
}
