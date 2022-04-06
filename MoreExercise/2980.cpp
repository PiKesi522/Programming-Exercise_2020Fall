#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull gcd(ull a,ull b) {
    while(b^=a^=b^=a%=b);
    return a;
}

void question()
{
    string s;
    cin >> s;
    int point = s.find('.');
    int st = s.find('[');
    int ed = s.find(']');

    if(point == -1)
        cout << s << endl;

    ull zs = 0;
    for (int i = 0; i < point; i++)
    {
        zs *= 10;
        zs += s.at(i) - '0';
    }

    ull no_re = 0;
    ull len = 1;
    if(st == -1)
    {
        for (int i = point + 1; i < s.size(); i++)
        {
            no_re *= 10;
            no_re += s.at(i) - '0';
            len *= 10;
        }

        ull fen_zi = no_re / gcd(no_re, len);
        ull fen_mu = len / gcd(no_re, len);
        while(zs--)
        {
            fen_zi += fen_mu;
        }
        cout << fen_zi << '/' << fen_mu << endl;
    }
    else
    {
        for (int i = point + 1; i < st; i++)
        {
            no_re *= 10;
            no_re += s.at(i) - '0';
            len *= 10;
        }

        ull re = 0;
        ull re_fen_mu = 1;

        for (int i = st + 1; i < ed; i++)
        {
            re *= 10;
            re += s.at(i) - '0';
            re_fen_mu *= 10;
        }
        re_fen_mu -= 1;

        ull fen_zi = no_re * re_fen_mu + re;
        ull fen_mu = len * re_fen_mu;
        int tt = gcd(fen_zi, fen_mu);
        fen_zi = fen_zi / tt;
        fen_mu = fen_mu / tt;
        while(zs--)
        {
            fen_zi += fen_mu;
        }
        
        cout << fen_zi << '/' << fen_mu << endl;
    }

}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cout << "case #" << i << ":" << endl;
        question();
    }
    return 0;
}