#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Angle{
    public:
        double x = 0.0;
        double y = 0.0;
        double p = 0.0;
        double deg = 3.1415926;
};

bool cmp(Angle A,Angle B)
{
    if(A.deg != B.deg)
        return A.deg < B.deg;
    else
        return A.p >                                                                                                                                                                                                                                                                                         B.p;
}                                                                                                                                                                                               

void print(int present_location)
{
    cout << "case #" << present_location << ":" << endl;
    return;
}

void change(Angle *A,int N)
{
    for (int i = 0; i < N;i++)
    {
        A[i].p = sqrt(pow(A[i].x, 2) + pow(A[i].y, 2));
        A[i].deg = atan2(A[i].y , A[i].x);
        if (A[i].deg < 0)
        {
            A[i].deg += 3.1415926 * 2;
        }
    }

    return;
}

void question(int present_location)
{
    int N; // 点的个数
    cin >> N;
    Angle angle[1000];
    for (int i = 0; i < N;i++)
    {
        cin >> angle[i].x >> angle[i].y;
    }

    change(angle,N);

    sort(angle, angle + N, cmp);

    print(present_location);

    for (int i = 0; i < N;i++)
    {
        printf("(%.4lf,%.4lf)", angle[i].p, angle[i].deg);
        cout << endl;
    }

    return;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T;i++)
    {
        question(i);
    }

    return 0;
}