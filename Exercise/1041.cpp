#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <cstring>

using namespace std;

void question()
{
    string s;
    cin >> s;
    bool flag = true;
    bool print = true;

    for (decltype(s.size()) i = 0; i < s.size() - 1;i++)
    {
        if(s[i] == '0')
        {
            if(s[++i] == 'x')
            {
                print = false;
                long long ans = 0;
                while(i < s.size() - 1)
                {
                    i++;
                    if('a' <= s[i] && s[i] <= 'f')
                    {
                        print = true;
                        flag = false;
                        ans *= 16;
                        ans += s[i] - 87;
                    }
                    else if ('0' <= s[i] && s[i] <= '9') 
                    {
                        print = true;
                        flag = false;
                        ans *= 16;
                        ans += s[i] - 48;
                    }
                    else 
                    {
                        break;
                    }
                }

                if(print)
                    cout << ans << ' ';
            }

            else
            {
                i--;
            }

        }
    }

    if(flag)
        cout << -1;

    cout << endl;
}

int main()
{
    question();
    return 0;
}