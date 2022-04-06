#include <iostream>
#include <string>

using namespace std;

//int DP[10000][10000] = {0};

int main()
{
    int **DP = (int**)malloc(sizeof(int*) * 50125);  //sizeof(int*),不能少*，一个指针的内存大小，每个元素是一个指针。
    for (int i = 0;i < 50125;i++)
    {
        DP[i] = (int*)malloc(sizeof(int) * 50125);
    }
    string s1,s2;
    cin >> s1 >> s2;
    int bg = 0/*,st = 0,ed = 0*/;
    int sizeX = s1.size();
    int sizeY = s2.size();
    for(int i = 1; i <= sizeX; i++)
    {
        for(int j = 1; j <= sizeY; j++)
        {
            if(s1[i - 1] == s2[j - 1])
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
                if(DP[i][j] > bg)
                {
                    bg = DP[i][j];
                    //st = i - bg + 2;
                    //ed = j - bg + 2;
                }
            }
            else
                DP[i][j] = 0;
        }
    }
    cout << bg << endl;
    return 0;
}