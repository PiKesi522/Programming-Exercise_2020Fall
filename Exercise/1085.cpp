#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <cstring>

using namespace std;

int question()
{
    int n;
    cin >> n;

    int ind[105] = {0}, outd[105] = {0};
    int vis[105][105] = {0};

    int id, od;
    for (int i = 0; i < n; ++i)
    {
        cin >> od >> id;
        if(!vis[od][id])
        {
            outd[od]++;
            ind[id]++;
            vis[od][id] = 1;
        }
    }

    bool flag = true;

    for (int i = 0; i < 105; ++i)
    {
        if (outd[i] > 1 || (ind[i] && outd[i]))
        {
            flag = false;
            break;
        }
    }

    if(flag)
        cout << "Lucky dxw!" << endl;
    else
        cout << "Poor dxw!" << endl;
    
    return 0;
}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T;i++)
        question();

    return 0;
}