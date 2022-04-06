#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;

typedef unsigned long long ull;

bool cmp(int A, int B)
{
    if(A != B)
        return A > B;
    return true;
}

void question()
{
    int n, m;
    cin >> n >> m;
    vector<ull> table;
    for(int i = 0; i < n ; i++)
    {
        ull temp;
        cin >> temp;
        table.push_back(temp);
    }


    sort(table.begin(), table.end(),cmp);

    ull ans = 100000000000000;
    for (int i = 0; i < n - m + 1;i++)
    {
        ull temp = 0;
        for (int j = 1; j < m;j++)
        {
            temp += table[i] - table[i + j];
        }

        if(ans > temp)
            ans = temp;
    }


    cout << ans << endl;
}

int main()
{
    question();
    return 0;
}