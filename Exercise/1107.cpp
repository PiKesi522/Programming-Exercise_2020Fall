#include <iostream>
#include <string>
/*
给定一个矩阵和其中值为 1 的位置，共有 n 个，求至少包含 k 个 1 的矩阵                                                                                                                                                                    
*/

using namespace std;

void check(int num)
{
    int r,c,n,k;
    int xi,yi;
    int cnt = 0;

    cin >> r >> c >> n >> k;
    
    int table[10][10] = {0};

    for(int j = 0;j < n;j++)
    {
        cin >> xi >> yi;
        table[xi-1][yi-1] = 1;
    }

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            for(int m = 0; m < r; m++)
            {
                for(int n = 0; n < c; n++)// i j n m 分别为矩阵的四个边界
                {                         // x y在上面四个元素构成的矩阵内进行遍历，查看是否满足条件
                    int sum = 0;
                    
                    for(int x = i; x <= m; x++)
                    {
                        for(int y = j; y <= n; y++)
                        {
                            if(table[x][y]) 
                                sum++;
                        }
                    }

                    if(sum >= k) 
                        cnt++;
                }
            }
        }
    }
    

    cout << "case #" << num << ":" << endl << cnt << endl;

    return;
}

int main()
{
    int T;

    cin >> T;

    for(int i =0;i < T;i++)
        check(i);

    return 0;
}