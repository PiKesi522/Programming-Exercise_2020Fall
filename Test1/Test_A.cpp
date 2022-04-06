#include <iostream>
#include <string>

using namespace std;

void question()
{
    string m,d,k;
    cin >> m >> d >> k;
    string un,kn;
    if(m == "?")
    {
        un = m;
        kn = d;
    }
    else if(d == "?")
    {
        un = d;
        kn = m;
    }

    if(k == "?")
    {
        if(m == "A")
        {
            if(d == "A")
                k = "{A,O}";
            else if(d == "B")
                k = "{A,AB,B,O}";
            else if(d == "O")
                k = "{A,O}";
            else if(d == "AB")
                k = "{A,AB,B}";
        }
        else if(m == "B")
        {
            if(d == "A")
                k = "{A,AB,B,O}";
            else if(d == "B")
                k = "{B,O}";
            else if(d == "O")
                k = "{B,O}";
            else if(d == "AB")
                k = "{A,AB,B}";
        }
        else if(m == "O")
        {
            if(d == "A")
                k = "{A,O}";
            else if(d == "B")
                k = "{B,O}";
            else if(d == "O")
                k = "{O}";
            else if(d == "AB")
                k = "{A,B}";
        }
        else if(m == "AB")
        {
            if(d == "A")
                k = "{A,AB,B}";
            else if(d == "B")
                k = "{A,AB,B}";
            else if(d == "O")
                k = "{A,B}";
            else if(d == "AB")
                k = "{A,AB,B}";
        }
        cout << m << ' ' << d << ' ' << k << endl;
    }
    else
    {
        if(k == "A")
        {
            if(kn == "A")
                un = "{A,AB,B,O}";
            else if(kn == "B")
                un = "{A,AB}";
            else if(kn == "O")
                un = "{A,AB}";
            else if(kn == "AB")
                un = "{A,AB,B,O}";
        }
        else if(k == "B")
        {
            if(kn == "A")
                un = "{AB,B}";
            else if(kn == "B")
                un = "{A,AB,B,O}";
            else if(kn == "O")
                un = "{AB,B}";
            else if(kn == "AB")
                un = "{A,AB,B,O}";
        }
        else if(k == "O")
        {
            if(kn == "A")
                un = "{A,B,O}";
            else if(kn == "B")
                un = "{A,B,O}";
            else if(kn == "O")
                un = "{A,B,O}";
            else if(kn == "AB")
                un = "impossible";
        }
        else if(k == "AB")
        {
            if(kn == "A")
                un = "{AB,B}";
            else if(kn == "B")
                un = "{A,AB}";
            else if(kn == "O")
                un = "impossible";
            else if(kn == "AB")
                un = "{A,AB,B}";
        }
        if(m == "?")
            cout << un << ' ' << d << ' ' << k << endl;
        else
            cout << m << ' ' << un << ' ' << k << endl;
    }
}

int main()
{
    question();
    return 0;
}
