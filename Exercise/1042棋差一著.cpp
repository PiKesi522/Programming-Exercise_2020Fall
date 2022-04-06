#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <cstring>

using namespace std;

class Word{
    public:
        char it;
        int cnt;
};

Word word[100000][105];

string s[105];

int fsize = 0;

bool check(int size)
{
    for (int i = 0; i < fsize; i++)
    {
        char ch = word[0][i].it;
        for (int j = 1; j < size;j++)
        {
            if(ch != word[j][i].it)
                return false;
        }
    }
    return true;
}

int findavg(int line,int size)
{
    multiset<int> temp;

    for (int i = 0; i < size; i++)
        temp.insert(word[i][line].cnt);

    int len = temp.size();
    auto it = temp.begin();

    for (int j = 0; j < len / 2; j++)
        it++;

    return *it;
}

void calcu(int size)
{
    int ans = 0;
    int avg = 0;

    for (int i = 0; i < fsize + 1;i++)
    {
        avg = findavg(i,size);    //寻找每个字符对应的最中间的值
        for (int j = 0; j < size;j++)
            ans += abs(word[j][i].cnt - avg);
    }
    
    cout << ans << endl;
    return;
}

bool change(int size)
{
    for (int i = 0; i < size; i++) // 处理每一行数据
    {
        int loc = 0;
        char temp = s[i][0];
        word[i][loc].it  = temp;

        for (decltype(s[i].size()) j = 0; j < s[i].size();j++)
        {
            if(s[i][j] != temp)
            {
                temp = s[i][j];
                loc++;
                word[i][loc].it = temp;
                word[i][loc].cnt = 1;
            }

            else
                word[i][loc].cnt++;
        }

        if(i == 0)
            fsize = loc;
        else
            if(fsize != loc) // 如果含有不同数量的最小字符，必不可搭配
                return false;
    }
    return true;
}   

void question()
{
    int n;
    cin >> n;
    if(n == 1)
        cout << '0' << endl;

    for (int i = 0; i < n;i++)
    {
        cin >> s[i];
    }

    bool able = change(n); // 将输入数据变为所需要的类形式,含有可行性检测
    if(!able)
    {
        cout << "-1" << endl;
        return;
    }

    able = check(n);
    if(able) // 比较是否能够转换
        calcu(n);
    else
        cout << "-1" << endl;

    return;
}

int main()
{
    question();
    return 0;
}