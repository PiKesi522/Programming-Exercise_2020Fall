#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <cstring>

using namespace std;

class WordBank{
    public:
        string it;
        int num = -1;
};

WordBank words[100];

int check(string s)
{
    char ch;
    int ans = 0;
    bool has_num = false;
    int len = s.size();
    for (int i = 0; i < len;i++)
    {
        ch = s[i];
        if(isdigit(ch))
        {
            has_num = true;
            ans *= 10;
            ans += ch - 48;
        }
    }
    if(has_num)
        return ans;
    else
        return -1;
}

bool cmp(WordBank A,WordBank B)
{
    if(A.num != B.num)
        return A.num < B.num;
    else
        return A.it < B.it;
}

void question()
{
    string temp;
    int i = 0;
    while(cin >> temp)
    {
        words[i].it = temp;
        words[i].num = check(temp);
        i++;
    }

    sort(words, words + i, cmp);

    for (int j = 0; j < i;j++)
    {
        cout << words[j].it << ' ';
    }

    cout << endl;

    return;
}

int main()
{
    question();
    return 0;
}