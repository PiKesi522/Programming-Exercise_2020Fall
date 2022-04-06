#include <iostream>
#include <deque>
#include <string>

using namespace std;

void question()
{
    string s;
    cin >> s;
    deque<char> load;
    int m = s.size();
    bool ele = true;
    int next = -1;
    int i = 0;

    while(i < m)
    {
        char ch = s[i++];
        load.push_front(ch);
        if(ch == '{')
        {
            if(next != 3 && next != -1)
            {
                ele = false;
                break;
            }
            next = 2;
        }
        else if(ch == '[')
        {
            if(next != 2 && next != -1)
            {
                ele = false;
                break;
            }
            next = 1;
        }
        else if(ch == '(')
        {
            if(next != 1 && next != -1)
            {
                ele = false;
                break;
            }
            next = 3;
        }
        else if(ch == ')')
        {
            if(next != 3)
            {
                ele = false;
                break;
            }
            load.pop_back();
            load.pop_back();
            if(load.empty())
                next = -1;
            else
                next = 1;
        }
        else if(ch == ']')
        {
            if(next != 1)
            {
                ele = false;
                break;
            }
            load.pop_back();
            load.pop_back();
            if(load.empty())
                next = -1;
            else
                next = 2;
        }
        else if(ch == '}')
        {
            if(next != 2)
            {
                ele = false;
                break;
            }
            load.pop_back();
            load.pop_back();
            if(load.empty())
                next = -1;
            else
                next = 3;
        }
    }
    if(!load.empty())
    {
        cout << "No" << endl;
        return;
    }

    if(ele)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        question();
    }
    return 0;
}
