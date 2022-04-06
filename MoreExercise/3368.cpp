#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class C{
    public:
        string subject;
        int time1 = 0;
        int time2 = 0;
};

void question()
{
    int n;
    cin >> n;
    C sch[10000];
    int count = 0;
    for (int i = 0;i < n; i++)
    {
        string sub;
        int t;
        cin >> sub >> t;
        bool appear = false;
        int j = 0;
        for (j = 0; j < count; j++)
        {
            if(sch[j].subject == sub)
            {
                appear = true;
                break;
            }
        }
        if(appear)
        {
            if(sch[j].time2 == 0)
            {
                if(t > sch[j].time1)
                {
                    sch[j].time2 = sch[j].time1;
                    sch[j].time1 = t;
                }
                else
                {
                    sch[j].time2 = t;
                }
            }
            else if(t > sch[j].time1)
            {
                sch[j].time2 = sch[j].time1;
                sch[j].time1 = t;
            }
            else if(t > sch[j].time2)
            {
                sch[j].time2 = t;
            }
        }
        else
        {
            sch[j].subject = sub;
            sch[j].time1 = t;
            count += 1;
        }
    }
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += sch[i].time1 + sch[i].time2;
    }
    cout << sum << endl;
}

int main()
{
    question();
    return 0;
}