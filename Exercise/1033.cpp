#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;

int question_num = 0;

string table[20]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};

class Maya{
    public:
        int day;
        string month;
        int Mself;
        int year;
};

void print()
{
    cout << "case #" << question_num << ":" << endl;
    return;
}

bool cmp(Maya A, Maya B)
{
    if(A.year != B.year)
        return A.year < B.year;
    else
    {
        if(A.Mself != B.Mself)
            return A.Mself < B.Mself;
        else
            return A.day < B.day;
    }
    return true;
}

void question()
{
    int data;
    cin >> data;
    Maya calender[10000];
    for (int i = 0; i < data;i++)
    {
        cin >> calender[i].day;
        getchar();
        cin >> calender[i].month >> calender[i].year;
        for (int j = 0; j < 20;j++)
            if(table[j] == calender[i].month)
                calender[i].Mself = j;
    }

    sort(calender, calender + data, cmp);

    print();
    for (int i = 0; i < data; i ++)
    {
        cout << calender[i].day << ". " << calender[i].month << ' ' << calender[i].year << endl;
    }
}

int main()
{
    int T;
    cin >> T;
    for (; question_num < T;question_num++)
    {
        question();
    }
    return 0;
}

