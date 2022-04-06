#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void question()
{
    char a[1000005] = {'\0'};
    string b;
    while(cin >> a >> b)
    {
        bool flag = true;
        int loc = -1;
        int start = 0;
        while(a[++loc] != '\0')
        {
            char ch = a[loc];
            start = b.find(ch, start + 1);
            if(start == -1)
            {
                flag = false;
                break;
            }
        }
        if(flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

int main()
{
    question();
    return 0;
}