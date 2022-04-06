#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

using namespace std;

void question()
{
    vector<string> ans;
    string s;
    getline(cin,s);
    int start = 0;
    while(s.find("<br>") != s.npos)
    {
        string temp = s.substr(0,s.find("<br>"));
        ans.push_back(temp);
        start = s.find("<br>") + 4;
        s = s.substr(start);
    }
    ans.push_back(s);
    for(string v : ans)
    {
        cout << v << endl;
    }
    
}

int main()
{
    question();
    return 0;
}