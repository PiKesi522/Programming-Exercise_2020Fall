#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;

class Data{
    public:
        int a[51] = {0};
};

bool cmp(Data A, Data B)
{
    for (int i = 0; i < 51;i++)
    {
        if(A.a[i] != B.a[i])
            return A.a[i] > B.a[i];
    }
    return false;
}

void question()
{
    int N;
    cin >> N;
    Data data[1000];
    int temp;

    for (int i = 0; i < N;i++) // 把数据读入数组
    {
        int k = 0;
        while(true)
        {
            cin >> temp;

            if(temp == -1)
            {
                for (; k < 51;k++)
                {
                    data[i].a[k] = -1;
                }
                break;
            }
            else
                data[i].a[k] = temp;

            k++;
        }
    }

    sort(data, data + N, cmp);

    for(int i = 0;i < N;i++)
    {
        int k = 0;
        while(data[i].a[k] != -1)
        {
            cout << data[i].a[k++] << ' ';
        }
        cout << endl;
    }

    return;
}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T;i++)
        question();

    return 0;
}