#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char sentence[10005] = {'\0'};

void question()
{
    cin >> sentence;
    int loc = -1;
    vector<char> words;
    int times = 0;
    while(sentence[++loc] != '\0')
    {
        char ch = sentence[loc];
        if('a' <= ch && ch <= 'z')
        {
            times = 0;
            words.push_back(ch);
        }
        else if('0' <= ch && ch <= '9')
        {
            times *= 10;
            times += ch - '0';
            if(('a' <= sentence[loc + 1] && sentence[loc + 1] <= 'z') || sentence[loc + 1] == '\0')
            {
                for (int i = 0; i < times; i++)
                {
                    for(char v : words)
                    {
                        cout << v;
                    }
                }
                words.clear();
                times = 0;
            }
        }

        if(sentence[loc + 1] == '\0')
        {
            for(char v : words)
            {
                cout << v;
            }
        }
    }
    cout << endl;
}

int main()
{
    question();
    return 0;
}