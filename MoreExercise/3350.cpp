#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class h{
    public:
        int hard = 0;
        int loc = 0;
};

bool cmp1(h A, h B)
{
    return A.hard > B.hard;
}

bool cmp2(h A, h B)
{
    return A.loc < B.loc;
}

void question()
{
    int n, k;
    cin >> n >> k;
    h paper[1001];
    for (int i = 0; i < n; i++)
    {
        int diff;
        cin >> diff;
        paper[i].hard = diff;
        paper[i].loc = i + 1;
    }
    sort(paper, paper + n, cmp1);
    sort(paper, paper + k, cmp2);
    for (int i = 0; i < k; i++)
    {
        cout << paper[i].loc;
        if(i == k - 1)
        {
            cout << endl;
            return;
        }
        else
            cout << ' ';
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        question();
    }
    return 0;
}