#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Team{
    public:
        int loc = 0;
        int win = 0;
        int lose = 0;
        int draw = 0;
        int num = 0;
};

bool cmp(Team A,Team B)
{
    if(A.num != B.num)
        return A.num > B.num;
    else
    {
        if(A.win != B.win)
            return A.win > B.win;
        else
        {
            if(A.lose != B.lose)
                return A.lose < B.lose;
            else
                return A.loc < B.loc;
        }
    }
}

void func(int a, int b, int cons, Team team[])
{
    switch (cons)
    {
    case -1:
        team[a - 1].lose++;
        team[a - 1].num -= 1;
        team[b - 1].win++;
        team[b - 1].num += 3;
        break;
    case 0:
        team[a - 1].draw++;
        team[a - 1].num += 1;
        team[b - 1].draw++;
        team[b - 1].num += 1;
        break;
    case 1:
        team[a - 1].win++;
        team[a - 1].num += 3;
        team[b - 1].lose++;
        team[b - 1].num -= 1;
        break;            
    default:
        break;
    }
    return;
}

void question(int n,int m)
{
    Team team[10];
    for (int i = 0; i < n;i++)
    {
        team[i].loc = i + 1;
    }
        int teama, teamb, cons;
    for (int i = 0; i < m;i++)
    {
        cin >> teama >> teamb >> cons;
        func(teama, teamb, cons, team);
    }

    sort(team, team + n, cmp);

    for (int i = 0; i < n;i++)
    {
        cout << team[i].loc << ' ';
    }
    cout << endl;

    return;
}


int main()
{
    int n, m;
    while(true)
    {
        cin >> n >> m;
        if(n == 0 && m == 0)
            break;
        question(n, m);
    }
    return 0;
}