#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <vector>


using namespace std;

int present_location;

class mul{
    public:
        int cishu;
        int xishu;
};

void print()
{
    cout << "case #" << present_location << ":" << endl;
}

void question()
{
    mul x[9];
    bool allzero = true;
    int start = -1;
    for(int i = 0; i <= 8; i++)
    {
        x[i].cishu = 8 - i;
        cin >> x[i].xishu;
        if(x[i].xishu != 0)
            allzero = false;
        if(allzero)
        {
            start = i;
        }
    }
    start++;

    print();
    if(allzero)
    {
        cout << 0 << endl;
        return;
    }

    for(int i = start; i <= 8; i++)
    {
        int xishu = x[i].xishu;
        int cishu = x[i].cishu;
        if(cishu == 8 - start && cishu != 0)
        {
            if(xishu == -1)
                cout << '-';
            else if(xishu > 1)
                cout << xishu;
            else if(xishu < -1)
                cout << xishu;


            if(cishu > 1)
                cout << "x^" << cishu;
            else if(cishu == 1)
                cout << 'x';
        }
        else if(cishu == 8 - start && cishu == 0)
        {
            cout << xishu;
        }
        else if(xishu != 0 && cishu > 0)
        {
            if(xishu == -1)
                cout << '-';
            else if(xishu == 1)
                cout << '+';
            else if(xishu > 1)
                cout << '+' << xishu;
            else if(xishu < -1)
                cout << xishu;


            if(cishu > 1)
                cout << "x^" << cishu;
            else if(cishu == 1)
                cout << 'x';
        }
        else if(cishu == 0)
        {
            if(xishu > 0)
                cout << "+" << xishu;
            else if(xishu < 0)
                cout << xishu;
        }
    }
    cout << endl;
}

int main()
{
    int N;
    cin >> N;
    for(present_location = 0; present_location < N; present_location++)
    {
        question();
    }
    return 0;
}
