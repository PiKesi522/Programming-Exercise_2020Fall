#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <cstring>
#include <sstream>
#include <deque>

using namespace std;

deque<char> table;

void question()
{
    char first, ch;
    ch = getchar();
    int len = 1;
    table.push_back(toupper(ch));
    while((ch = getchar()) != '\n')
    {
        len++;
        first = table[0];
        ch = toupper(ch);
        if(ch < first)
            table.push_back(ch);
        else
            table.push_front(ch);
    }
    for(auto v : table)
        cout << v;
    cout << endl;
    return;
}

int main()
{
    question();
    return 0;
}