#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;

int question_num = 0;

void print()
{
    cout << "case #" << question_num << ":" << endl;
    return;
}

void question()
{
    int n;
    cin >> n;
    multiset<int> a;
    multiset<int> b;
    int temp;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.insert(temp);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        b.insert(temp);
    }

    long long ans = 0;
    auto ait = a.begin();
    auto bit = b.rbegin();
    for (; ait != a.end(),bit != b.rend();ait++,bit++)
    {
        //cout << *ait << ' ' << *bit << endl;
        int t = (*ait) * (*bit);
        ans += t;
    }

    print();
    cout << ans << endl;
    return;
}

int main()
{
    int T;
    cin >> T;
    for (; question_num < T;question_num++)
    {
        question();
    }
}