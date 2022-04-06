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
    string s,t;
    
    getline(cin, s);
    stringstream linestring;
    linestring << s;
    vector<string> table;

    while(linestring >> t)
    {
        for (decltype(t.size()) i = 0; i < t.size();i++)
        {
            t[i] = tolower(t[i]);
        }

        if ((t != "the") && (t != "a") && (t != "an") && (t != "of") && (t != "for") && (t != "and"))
            table.push_back(t);

    }

    print();

    cout << table.size() << endl;
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