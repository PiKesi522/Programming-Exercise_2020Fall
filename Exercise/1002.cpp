#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef struct compose
{
    long long it;
    int OneCnt;
}C;

int count_One(long long number)
{
    int cnt = 0;
    long long test = 1;

    for (int t = 0; t < 64;t++)
    {
        if(number & test)
            cnt++;

        test = test << 1;
    }

    return cnt;
}

bool cmp(compose A,compose B)
{
    if(A.OneCnt != B.OneCnt)
        return A.OneCnt > B.OneCnt;
    else
        return A.it < B.it;
}

void question(int present_question)
{
    int N;
    cin >> N;

    C combine[10005];

    long long temp;
    for (int i = 0; i < N;i++)
    {
        cin >> temp;
        combine[i].it = temp;
        combine[i].OneCnt = count_One(temp);
        //cout << combine[i].it << " : " << combine[i].OneCnt << endl;
    }

    sort(combine, combine + N, cmp);

    cout << "case #" << present_question << ":" << endl;
    for (int i = 0; i < N;i++)
    {
        cout << combine[i].it << ' ';
    }
    cout << endl;

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