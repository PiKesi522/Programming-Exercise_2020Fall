#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;

int question_num = 0;

class Banks{
    public:
        char Word = '\0';
        double freq = 0.0;
        int lo = 0;
};

class fre{
    public:
        char Word = '\0';
        double freq = 0.0;
        int lo = 0;
};

void print()
{
    cout << "case #" << question_num << ":" << endl;
    return;
}

bool cmp(fre A,fre B)
{
    if(A.freq != B.freq)
        return A.freq > B.freq;
    else
        return A.lo < B.lo;
}

void question()
{
    Banks table[52];
    char cC = 'A';
    char cc = 'a';
    int loc = 0;
    for (int i = 0; i < 26; i++)
    {
        double freq;
        cin >> freq;
        table[loc].Word = cc++;
        table[loc].lo = loc;
        table[loc++].freq = freq;

        table[loc].Word = cC++;
        table[loc].lo = loc;
        table[loc++].freq = freq;
    }

    fre words[100];
    getchar();
    char temp;
    int i = 0;
    while((temp = getchar()) != '\n')
    {
        words[i].Word = temp;
        for (int j = 0; j < 52;j++)
        {
            if(temp == table[j].Word)
            {
                words[i].lo = table[j].lo;
                words[i].freq = table[j].freq;
            }
        }
        i++;
    }

    sort(words, words + i, cmp);

    print();
    for (int j = 0; j < i; j++)
    {
        cout << words[j].Word;
    }
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    for (; question_num < T;question_num++)
    {
        question();
    }
    return 0;
}

