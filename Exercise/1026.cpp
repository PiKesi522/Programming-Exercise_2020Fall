#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool cmp(int A,int B)
{
    return A > B;
}

void question(int n)
{
    int temp;
    vector<int> s;
    for (int i = 0; i < n;i++)
    {
        cin >> temp;
        s.push_back(temp);
    }

    sort(s.begin(), s.end(), cmp);

    int sum = 0;
    for (int i = 0; i < n;)
    {
        sum += s[i] - s[i + 1];
        i += 2;
    }

    cout << sum << endl;
    return;
}

int main()
{
    int n; // 点的数量
    cin >> n;
    question(n);
    return 0;
}