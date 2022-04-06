#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <deque>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

typedef unsigned long long ll;

vector<int> table = {1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

struct BigInteger
{
    typedef unsigned long long LL;

    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> s;

    BigInteger &clean()
    {
        while (!s.back() && s.size() > 1)
            s.pop_back();
        return *this;
    }
    BigInteger(LL num = 0) { *this = num; }
    BigInteger(string s) { *this = s; }
    BigInteger &operator=(long long num)
    {
        s.clear();
        do
        {
            s.push_back(num % BASE);
            num /= BASE;
        } while (num > 0);
        return *this;
    }
    BigInteger &operator=(const string &str)
    {
        s.clear();
        int x, len = (str.length() - 1) / WIDTH + 1;
        for (int i = 0; i < len; i++)
        {
            int end = str.length() - i * WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start, end - start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return (*this).clean();
    }

    BigInteger operator+(const BigInteger &b) const
    {
        BigInteger c;
        c.s.clear();
        for (int i = 0, g = 0;; i++)
        {
            if (g == 0 && i >= s.size() && i >= b.s.size())
                break;
            int x = g;
            if (i < s.size())
                x += s[i];
            if (i < b.s.size())
                x += b.s[i];
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }
    
    BigInteger operator*(const BigInteger &b) const
    {
        int i, j;
        LL g;
        vector<LL> v(s.size() + b.s.size(), 0);
        BigInteger c;
        c.s.clear();
        for (i = 0; i < s.size(); i++)
            for (j = 0; j < b.s.size(); j++)
                v[i + j] += LL(s[i]) * b.s[j];
        for (i = 0, g = 0;; i++)
        {
            if (g == 0 && i >= v.size())
                break;
            LL x = v[i] + g;
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c.clean();
    }
};

ostream &operator<<(ostream &out, const BigInteger &x)
{
    out << x.s.back();
    for (int i = x.s.size() - 2; i >= 0; i--)
    {
        char buf[20];
        sprintf(buf, "%08d", x.s[i]);
        for (int j = 0; j < strlen(buf); j++)
            out << buf[j];
    }
    return out;
}

void question()
{
    //vector<ull>dec;
    char num[100] = {'\0'};
    if(num[0] == '0')
    {
        cout << 0 << endl;
        return;
    }
    cin >> num;
    int weishu = 0;
    deque<int>prime;
    int prinum = 0;
    for(int i = 0 ; i < 100 ; i++)
    {
        if(num[i] == '\0')
        {
            prime.push_front(prinum);
            weishu++;
            prinum = 0;
            break;
        }
        else if(num[i] == ',')
        {
            prime.push_front(prinum);
            weishu++;
            prinum = 0;
        }
        else
        {
            prinum *= 10;
            prinum += num[i] - 48;
        }
    }

    BigInteger ans = 0;
    for(int i = weishu ; i > 0 ; i--)
    {
        ans = ans * table[i];
        ans = ans + prime[i-1];
    }
    //ans += prime[0];
    cout << ans << endl;
}

int main()
{
    question();
    return 0;
}