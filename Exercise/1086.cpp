#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <cstring>

using namespace std;

string str;

void question()
{
    char table[199][100] = {'\0'};
    int size = str.size();
    int row = 99;
    int loc = 0;
    table[row][loc] = str[loc];
    set<int> ava;
    ava.insert(row);
    for (loc = 1; loc < size;loc++)
    {
        char temp = str[loc - 1];
        if(str[loc] > temp)
            row--;
        else if(str[loc] < temp)
            row++;
        ava.insert(row);
        table[row][loc] = str[loc];
    }

    int begin = *ava.begin();
    int end = *(--ava.end());
    for (int i = begin; i <= end;i++)
    {
        for(auto v : table[i])
        {
            if(v == '\0')
                cout << ' ';
            else
                cout << v;
        }
        cout << endl;
    }
}

int main()
{
    while(cin >> str)
    {
        question();
    }
    return 0;
}