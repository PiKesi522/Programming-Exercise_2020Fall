#include <iostream>

using namespace std;

void question()
{
    string s;
    cin >> s;
    char num[21] = {'\0'};
    int max = 9;
    bool flag = false;
    for(decltype(s.size()) len = 0; len < s.size(); len++)
    {
        char temp = s.at(len);
        if(temp == '\0')
            break;
        
        if(flag)
        {
            num[len] = '0';
            continue;
        }

        if(temp - '0' <= max)
        {
            num[len] = temp;
            max = temp - '0';
        }
        else
        {
            num[len - 1] += 1;
            num[len] = '0';
            flag = true;
        }
    }
    for(char c : num)
        cout << c;
    cout << endl;
}

int main()
{
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cout << "case #" << i << ":" << endl;
        question();
    }
    return 0;
}