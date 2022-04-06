#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef long long LL;
map<int,char> ls;

char WordBank[62] = {'1', '0', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

class Box{
    public:
        char itself = '\0';
        char itnum = '\0';
};

Box combine[61];

long long TODEC(vector<char> s,int R) // 这个函数用于把数字字符串翻译成十进制数字
{
    LL cons = 0;
    for (decltype(s.size()) i = 0; i < s.size();i++)
    {
        cons *= R;
        if(s[i] <= '9' && s[i] >= '0')
            cons += s[i] - 48;
        else if(s[i] >= 'A' && s[i] <= 'Z')
            cons += s[i] - 'A' + 10;
        else if(s[i] >= 'a' && s[i] <= 'z')
            cons += s[i] - 'a' + 37;
    }

    return cons;
}

void translate(string s,int present_location,int R) //这个函数用于把所有函数翻译成数字字符串
{
    vector<char> cons;
    for (decltype(s.size()) i = 0; i < s.size();i++)
    {
        char ch = s[i];
        for (int j = 0;;j++)
        {      
            if(ch == combine[j].itself)
            {
                cons.push_back(combine[j].itnum);
                break;
            }
        }
    }

    cout << "case #" << present_location << ":" << endl;
    cout << TODEC(cons,R) << endl;
}

void question(int present_location) // 这个函数用于把所有的字母赋一个对应值
{
    string s;
    cin >> s;
    //getchar();

    combine[0].itnum = WordBank[0];
    combine[0].itself = s[0];

    bool flag = true;
    int num = 1;
    for (decltype(s.size()) i = 1; i < s.size();i++)
    {
        flag = true;
        for (decltype(i) j = 0; j < i;j++) // 检测是否出现过相同的字符
        {
            char ch = combine[j].itself;
            if(ch == s[i]) // 若出现，则跳过该字母
            {
                flag = false;
                break;
            }
        }

        if(flag) // 若不出现，则进行赋值
        {
            combine[num].itself = s[i];
            combine[num].itnum = WordBank[num];
            ++num;
        }
    }


    int R = (num == 1) ? 2 : num; // R进制
    translate(s,present_location,R); // 把 cats 翻译成 1023;

    return;
}

int main()
{
    int T;
    cin >> T;
    //getchar();

    for (int i = 0; i < T;i++)
    {
        question(i);
    }

    return 0;
}