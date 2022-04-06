#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;

void question(char *s)
{
    int cnt = 1, temp = 1;
    char ttemp = s[0];
    int it = 0;

    while(ttemp != '\0')
    {
        temp = 1;
        ttemp = s[it];

        while(ttemp != s[++it])
        {
            if(s[it] == '\0')
            {
                break;
            }
            ttemp = s[it];
            temp++;
        }

        if(cnt <= temp)
            cnt = temp;
    }

    cout << cnt << endl;
    return;
}

int main()
{
    char s[51] = {'\0'};
    cin >> s;

    question(s);

    return 0;
}