#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void question()
{
    char present_max = '0';
    int max_loc = 0;

    char s[20000] = {'\0'};
    cin >> s;

    int loc = 0;

    vector<char> ans;

    int present_length = 0;

    bool allzero = true;
    while(s[loc] != '\0')
    {
        if(s[loc] != '0')
        {
            allzero = false;
            break;
        }
        loc += 1;
    }
    if(allzero)
    {
        cout << 0 << endl;
        return;
    }

    while(s[loc] != '\0')
    {
        char present_num = s[loc];
        if(present_num > present_max)
        {
            ans.clear();
            ans.push_back(present_num);
            present_max = present_num;
            present_length = 1;
            max_loc = loc;
        }
        else if(present_num == present_max)
        {
            int more = 0;
            bool replace = true;
            while(true)
            {
                if(s[loc + more] == '\0')
                {
                    replace = false;
                    break;
                }
                if(s[max_loc + more] != s[loc + more])
                {
                    if(s[max_loc + more] < s[loc + more])
                    {
                        replace = true;
                        break;
                    }
                    else
                    {
                        replace = false;
                        break;
                    }
                }
                more++;
            }
            if(replace)
            {
                ans.clear();
                ans.push_back(s[loc]);
                present_length = 1;
                max_loc = loc;
            }
            else
            {
                ans.push_back(present_num);
            }
        }
        else if(present_num < present_max)
        {
            present_length += 1;
            ans.push_back(present_num);
        }
        loc++;
    }
    for (auto it = ans.end() - 1; it != ans.begin(); it--)
    {
        if(*it == '0')
            ans.pop_back();
        else if(*it != '0')
            break;
    }
    for(char v : ans)
    {
        cout << v;
    }
}

int main()
{
    question();
    return 0;
}