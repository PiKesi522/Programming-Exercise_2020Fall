#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;

typedef unsigned long long ull;

class Cir{
    public:
        ull R;
        ull H;
        ull bottom;
        ull side;

        void S_side()
        {
            side = H * 2 * R;
        }
        void B_side()
        {
            bottom = R * R;
        }
};

bool cmp1(Cir A, Cir B)
{
    if(A.side != B.side)
        return A.side > B.side;
    else
        return A.bottom > B.bottom;
}

void question()
{
    int n,m;
    cin >> n >> m;
    Cir circle[1000];

    for (int i = 0; i < n;i++)
    {
        cin >> circle[i].R >> circle[i].H;
        circle[i].B_side();
        circle[i].S_side();
    }

    sort(circle, circle + n, cmp1);

    unsigned long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        unsigned long long temp = circle[i].side + circle[i].bottom;

        int cout = 1;
        for (int j = 0;(j < n && cout < m);j++)
        {
            if((j == i) || (circle[j].R > circle[i].R))
                continue;

            temp += circle[j].side;
            cout++;
        }

        if((cout == m) && (ans < temp))
            ans = temp;
    }

    cout << ans << endl;
}

int main()
{
    question();
    return 0;
}