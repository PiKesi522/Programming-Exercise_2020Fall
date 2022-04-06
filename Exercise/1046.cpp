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

bool cmp(string A,string B)
{
    return A < B;
}

void question()
{
    print();
    string line,temp;
    getline(cin, line);
    set<string> table;
    stringstream linestream;
    linestream << line;
    while(linestream >> temp)
    {
        int len = temp.size();
        bool allalpha = true;
        for (int i = 0;i < len;i++)
        {
            if(!isalpha(temp[i]))
            {
                allalpha = false;

                string s1 = temp.substr(0, i);
                if(s1.size() > 0)
                    table.insert(s1);

                string s2 = temp.substr(++i, --len);
                if(s2.size() > 0)
                    table.insert(s2);

                break;
            }
        }

        if(allalpha)
            table.insert(temp);
    }

    //sort(table.begin(), table.end(), cmp);

    for(auto v : table)
        cout << v << ' ';
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