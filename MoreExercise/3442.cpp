#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char sentence[100001] = {'\0'};
int times,start,fin;
char check[100001] = {'\0'};

void question()
{
    cin >> sentence >> times;
    for (int q = 0; q < times; q++)
    {
        int cnt = 0;
        cin >> start >> fin;
        getchar();
        char ch;
        int len = 0;

        while((ch = getchar()) != '\n')
        {
            check[len++] = ch;
        }

        for (int i = start; i <= fin - len + 1; i++)
        {
            int from = 0;
            bool match = true;
            for (int loc = i; loc < i + len;)
            {
                if(sentence[loc++] != check[from++])
                {
                    match = false;
                    break;
                }
                if(loc > fin + 1)
                {
                    match = false;
                    break;
                }
            }
            if(match)
                cnt++;
        }

        cout << cnt << endl;
    }
}

int main()
{
    question();
    return 0;
}