#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

class table{
    public:
        char itself = '\0';
        int freq = 0;
        int power = 0;
};

bool cmp(table A, table B)
{
    if(A.freq != B.freq)
        return A.freq > B.freq;
    return true;
}

void question()
{
    int power = 26;
    string words;
    cin >> words;
    vector<char> UPPER;
    table need[26];
    int diff_words = 0;

    for (int i = 0; i < words.length(); i++)
    {
        char ch = (toupper(words[i]));

        UPPER.push_back(ch);

        bool exist = false;
        for (int j = 0; j < 26; j++)
        {
            if(need[j].itself == ch)    // 遍历已经出现过的单词
            {
                exist = true;
                need[j].freq++;
                break;
            }
            if(need[j].itself == '\0')  // 还没有操作到这里，直接弹出
            {
                break;
            }
        }
        if(!exist)                      // 不存在则添加
        {
            need[diff_words].itself = ch;
            need[diff_words++].freq = 1;
        }
    }

    sort(need, need + diff_words, cmp); //按频率排序
    for (int i = 0; i < diff_words; i++)
    {
        need[i].power = power--;        // 添加权重
    }

    unsigned long long ans = 0;
    for (int i = 0; i < words.length(); i++)
    {
        char now = UPPER[i];
        for (int j = 0; j < diff_words; j++)
        {
            if(need[j].itself == now)
            {
                ans += need[j].power;
                break;
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    question();
    return 0;
}