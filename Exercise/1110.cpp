#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

void question()
{
    char s[1000000] = {'\0'};
    cin >> s;
    char ch;
    int len = 0;
    while(s[len] != ('\0'))
    {
        len++;
    }
    vector<char> table;
    vector<char> ans;
    int pre_max = 0;
    for(int i = 0 ; i < len ; i++)
    {
        table.clear();
        int pre_len = 0;
        for(int j = i; j < len ; j++)
        {
            bool found = false;
            for(char v : table)
            {
                if(v == s[j])
                {
                    found = true;
                    break;
                }
            }

            if(found)
            {
                break;
            }
            else
            {
                table.push_back(s[j]);
                pre_len++;
            }
        }

        if(pre_len > pre_max)
        {
            ans.clear();
            for(int k = 0;k < pre_len;k++)
            {
                ans.push_back(table[k]);
            }
            pre_max = pre_len;
        }
    }
    for(char v : ans)
        cout << v;
    cout << endl;
}

int main()
{
    question();
    return 0;
}