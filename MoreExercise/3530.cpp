#include <iostream>
#include <algorithm>
#include <deque>
#include <math.h>

using namespace std;

class number{
    public:
        deque<int> itnum ;
};

bool cmp(number A, number B)
{
    int len = (A.itnum.size() > B.itnum.size()) ? B.itnum.size() : A.itnum.size();
    for (int i = 0; i < len; i++)
    {
        if(A.itnum[i] != B.itnum[i])
            return A.itnum[i] > B.itnum[i];
    }
    return true;
}


void question()
{
    int N;
    cin >> N;
    number nums[20];
    int temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        if(temp == 0)
            nums[i].itnum.push_front(0);
        while(temp != 0)
        {
            int res = temp % 10;
            nums[i].itnum.push_front(res);
            temp /= 10;
        }
    }

    sort(nums, nums + N, cmp);

    for(int i = 0; i < N; i++)
    {
        for (int v : nums[i].itnum)
        {
            cout << v;
        }
    }
    cout << endl;
}

int main()
{
    question();
    return 0;
}