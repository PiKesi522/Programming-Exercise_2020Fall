#include <iostream>
#include <vector>

using namespace std;

void tobits(unsigned long long u, vector<char> *ubit)
{
    unsigned long long test = 1;
    for (int i = 0; i < 64; i++)
    {
        if(test > u)
            ubit->push_back(0);

        if(test & u)
            ubit->push_back(1);
        else
            ubit->push_back(0);
        test = test << 1;
    }
}

void question()
{
    unsigned long long a, b, c;
    cin >> a >> b >> c;
    vector<char> abit, bbit, cbit;
    tobits(a, &abit);
    tobits(b, &bbit);
    tobits(c, &cbit);
    unsigned long long moves = 0;
    for (int i = 0; i < 64; i++)
    {
        if(cbit[i] == 1)
        {
            if(abit[i] == 0 && bbit[i] == 0)
                moves += 1;
        }
        else if(cbit[i] == 0)
        {
            if(abit[i] == 1 && bbit[i] == 1)
                moves += 2;
            else if(abit[i] == 1 || bbit[i] == 1)
                moves += 1;
        }
    }
    cout << moves << endl;
}

int main()
{
    int M;
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        question();
    }
    return 0;
}