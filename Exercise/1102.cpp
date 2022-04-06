#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <cstring>
#include <sstream>

using namespace std;

int present_location = 0;

void print()
{
    cout << "case #" << present_location << ":" << endl;
    return;
}

void question()
{
    int num[21] = {0};
    int prenum[21] = {0};
    char ch;
    int i = 0;
    while((ch = getchar()) != '\n')
    {
        num[i] = ch - 48;
        prenum[i] = num[i];
        i++;
    }

    next_permutation(num, num + i);

    int pre = 0, now = 0;
    for (int j = 0; j < i; j++)
    {
        pre *= 10;
        now *= 10;

        pre += prenum[j];
        now += num[j];
    }
    
    if(now > pre)
    {
        print();
        for (int j = 0; j < i; j++)
        {
            cout << num[j];
        }
    }
    else
    {
        prev_permutation(num, num + i);
        for (int j = i; j > 0;j--)
        {
            num[j] = num[j - 1];
        }
        num[0] = 0;
        i++;
        next_permutation(num, num + i);
        print();
        for (int j = 0; j < i; j++)
        {
            cout << num[j];
        }
    }
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    getchar();
    for (; present_location < T;present_location++)
    {
        question();
    }
    return 0;
}
