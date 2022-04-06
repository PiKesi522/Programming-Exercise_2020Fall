#include <algorithm> // max
#include <cassert>   // assert
#include <cstdio>    // printf,sprintf
#include <cstring>   // strlen
#include <iostream>  // cin,cout
#include <string>    // string类
#include <vector>    // vector类

using namespace std;

struct BigInteger
{
	typedef unsigned long long LL;
	static const int BASE = 100000000;
	static const int WIDTH = 8;
	vector<int> s;

	BigInteger &clean()
	{
		while(!s.back() && s.size() > 1)
			s.pop_back();
		return *this;
	}
	BigInteger(LL num = 0){ *this = num;}
	BigInteger(string s){ *this = s;}
	BigInteger &operator=(long long num){
		s.clear();
		do
		{
			s.push_back(num % BASE);
			num /= BASE;
		}while(num > 0);
		return *this;
	}

	BigInteger &operator=(const string &str){
		s.clear();
		int x, len = (str.length() - 1) / WIDTH + 1;
		for(int i = 0; i < len; i++)
        {
            int ed = str.length() - i * WIDTH;
            int st = max(0, ed - WIDTH);
            sscanf(str.substr(st, ed - st).c_str(), "%d" , &x);
            s.push_back(x);
        }
        return (*this).clean();
	}

	BigInteger operator+(const BigInteger &b) const
	{
	    BigInteger c;
	    c.s.clear();
	    for(int i = 0, g = 0;; i++)
        {
            if(g == 0 && i >= s.size() && i >= b.s.size())
                break;
            int x = g;
            if(i < s.size())
                x += s[i];
            if(i < b.s.size())
                x += b.s[i];
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
	}
	BigInteger operator*(const BigInteger &b) const
	{
	    int i,j;
	    LL g;
	    vector<LL> v(s.size() + b.s.size(), 0);
	    BigInteger c;
	    c.s.clear();
	    for(i = 0; i < s.size(); i++)
        {
            for(j = 0; j < b.s.size(); j++)
            {
                v[i + j] += LL(s[i]) * b.s[j];
            }
        }
        for(i = 0, g = 0;; i++)
        {
            if(g == 0 && i >= v.size())
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
    for(int i = x.s.size() - 2; i >= 0; i--)
    {
        char buf[20];
        sprintf(buf, "%08d", x.s[i]);
        for(int j = 0; j < strlen(buf); j++)
        {
            out << buf[j];
        }
    }
    return out;
}


void question()
{
    int N;
    cin >> N;
    BigInteger zheng[501];
    BigInteger fu[501];
    zheng[0] = 1;
    fu[0] = 0;
    for(int i = 1; i <= N; i++)
    {
        zheng[i] = zheng[i - 1] * 3 + fu[i - 1];
        fu[i] = zheng[i - 1] + fu[i - 1] * 3;
    }
    cout << zheng[N] << ' ' << fu[N] << endl;
}

int main()
{
    question();
    return 0;
}
