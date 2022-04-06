#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef long long LL;

string table;

long long test(int present_location)
{
    char x = table[present_location];

    LL test = 1;
    LL cnt = 0;
    for (int t = 0; t < 8;t++)
    {
        if(x & test)
            cnt++;

        test = test << 1;
    }
    
    return cnt;
}   

void GCD(LL small,LL big)
{
    LL MAX = sqrt(small);
    for (LL i = 2; i <= MAX + 1;i++)
    {
        while(small % i == 0 && big % i == 0)
        {
            small = small / i;
            big = big / i;
        }

        if(small < i)
        {
            cout << small << '/' << big << endl;
            return;
        }
    }
    cout << small << '/' << big << endl;
    return;
}

void question()
{
    long long ONECNT = 0; //1的总数

    for (decltype(table.size()) i = 0; i < table.size();i++)
    {
        ONECNT += test(i);
    }

    LL bytes = (long long)table.size() * 8;

    GCD(ONECNT,bytes); //化简

    return;
}

int main()
{
    //cout << sizeof(char) << endl;
    int T = 0;
    cin >> T;

    string s;
    getline(cin, s);

    for (int i = 0; i < T;i++)
    {
        getline(cin, table);
        question();
    }

    return 0;
}