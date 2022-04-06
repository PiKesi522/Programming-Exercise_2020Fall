#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;

class NumH{
    public:
        int head;
        long long itself;
};


void print(int present_location,NumH *num,int N)
{
    cout << "case #" << present_location << ":" << endl;

    for(int i = 0 ;i < N ;i++)
    {
        cout << num[i].itself << ' ';
    }

    cout << endl;

    return;
}

bool cmp(NumH A,NumH B)
{
    if(A.head != B.head)
        return A.head > B.head;
    else
        return A.itself < B.itself;
}

int Find_Head(long long x)
{
    int head = 0;
    x = abs(x);

    while(x >= 10)
    {
        x = ( x - x % 10) / 10;
    }

    head = x;

    return head;
}

void question(int present_location)
{
    int N;
    cin >> N;
    NumH num[10000];
    long long temp;
    for(int i = 0;i < N;i++)
    {
        cin >> temp;
        num[i].itself = temp;
        num[i].head = Find_Head(temp);
    }

    sort(num,num+N,cmp);

    print(present_location,num,N);

    return;
}

int main()
{
    int T;
    cin >> T;
    for(int i=0;i < T;i++)
    {
        question(i);
    }
    return 0;
}
