#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <cstring>

using namespace std;

int present_location = 0;

int resize;

class WordBank{
    public:
        char it = '\0';
        int cnt = 0;
};

void print()
{
    cout << "case #" << present_location << ":" << endl;
    return;
}

int dele(WordBank *words)
{
    int r = resize;
    int cnt = 0;
    bool recycle = true;

    while(recycle)
    {
        recycle = false;

        for (int i = 0; i < resize;i++)
        {
            if(words[i].cnt > 1)
            {
                recycle = true;
                cnt += words[i].cnt;
                words[i].cnt = 0;
                r--;
                //移除已经处理完毕的字符
            }
        }     

    }

    return cnt;
}

int testA(WordBank *words)
{
    int ans = 0, temp = 0; //ans : 最多可以删除多少个， temp : 此次可以删除多少个

    WordBank nwords[100];

    for (int i = 0; i < resize; i++)
    {
        if (words[i].it == 'A')
        {
            for (int i = 0; i < resize;i++)
                nwords[i] = words[i];

            nwords[i].cnt++;
            temp = dele(nwords); // 某一次删除了多少个字符
        }

        if (ans < temp)
            ans = temp;
    }

    return ans;
}

int testB(WordBank *words)
{
    int ans = 0, temp = 0; //ans : 最多可以删除多少个， temp : 此次可以删除多少个

    WordBank nwords[100];

    for (int i = 0; i < resize; i++)
    {
        if (words[i].it == 'B')
        {
            for (int i = 0; i < resize;i++)
                nwords[i] = words[i];

            nwords[i].cnt++;
            temp = dele(nwords); // 某一次删除了多少个字符
        }

        if (ans < temp)
            ans = temp;
    }

    return ans;
}

int testC(WordBank *words)
{
    int ans = 0, temp = 0; //ans : 最多可以删除多少个， temp : 此次可以删除多少个

    WordBank nwords[100];

    for (int i = 0; i < resize; i++)
    {
        if (words[i].it == 'C')
        {
            for (int i = 0; i < resize;i++)
                nwords[i] = words[i];

            nwords[i].cnt++;
            temp = dele(nwords); // 某一次删除了多少个字符
        }

        if (ans < temp)
            ans = temp;
    }

    return ans;
}

void change(string s, WordBank *words) // 字符串读入class，计数，重复
{                                     // ABCBCCCAA -> A:1, B:1, C:1, B:1, C:3, A:2
    char ch = s[0];
    words[0].it = ch;
    words[0].cnt = 1;

    int len = s.size();
    int loc = 0;

    for (int i = 1; i < len; i++)
    {
        if(ch == s[i])
            words[loc].cnt++;
        else
        {
            ch = s[i];
            ++loc;
            words[loc].it = ch;
            words[loc].cnt = 1;
        }
    }

    resize = loc + 1;
}

void question()
{
    string s;
    getline(cin, s);
    WordBank words[100];

    change(s,words);
    
    print();

    multiset<int> abc;
    abc.insert(testA(words));
    abc.insert(testB(words));
    abc.insert(testC(words));

    cout << *(--abc.end()) << endl;

    return;
}

int main()
{
    int T;
    cin >> T;
    getchar();
    for (;present_location < T;present_location++)
    {
        question();
    }
    return 0;
}