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
    string t1 = "\0",t2 = "\0";
    string test = "\0";
    cin >> t1 >> t2 >> test;
    auto pos1 = test.find(t1);
    auto pos2 = test.find(t2);
    if(pos1 == test.npos || pos2 == test.npos)
    {
        print();
        cout << 0 << endl;
        return;
    }

    int loc_t1_first = test.find(t1) + t1.size();
    int loc_t2_first = test.find(t2) + t2.size();
    int loc_t1_last = test.rfind(t1);
    int loc_t2_last = test.rfind(t2);


    int ans1 = 0;
    ans1 = abs(loc_t1_first - loc_t2_last);
    int ans2 = 0;
    ans2 = abs(loc_t2_first - loc_t1_last);

    print();
    cout << (ans1 > ans2 ? ans1 : ans2 ) << endl;

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
