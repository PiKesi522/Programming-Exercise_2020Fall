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

class WordBank{
    public:
        int cnt = 1;
        char it = '\0';
};

void print()
{
    cout << "case #" << present_location << ":" << endl;
    return;
}

void question()
{
    WordBank words[500];
    char ch;
    int loc = -1;
    while((ch = getchar()) != '\n')
    {
        if(ch != words[loc].it)
        {
            loc++;
            words[loc].it = ch;
            words[loc].cnt = 1;
        }
        else if(ch == words[loc].it)
        {
            words[loc].cnt++;
            if (words[loc].cnt > 255)
            {
                words[loc].cnt--;
                loc++;
                words[loc].it = ch;
                words[loc].cnt = 1;
            }
        }
    }

    print();

    for (int i = 0; i <= loc; i++)
    {
        cout << words[i].cnt << words[i].it;
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