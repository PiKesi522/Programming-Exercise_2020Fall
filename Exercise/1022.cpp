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

int T;

class Emails{
    public:
        string username ="\0";
        string pcname = "\0";
};

Emails adress[1000000];

bool cmp(Emails A,Emails B)
{
    if(A.pcname != B.pcname)
        return A.pcname < B.pcname;
    else
        return A.username > B.username;
}

void check(string s,int loc)
{
    int len = s.size();
    auto ita = s.find('@');
    adress[loc].username = s.substr(0,ita);
    adress[loc].pcname = s.substr(++ita, --len);
}

void question()
{
    getchar();
    string s;
    for (int i = 0; i < T;i++)
    {
        cin >> s;
        check(s,i);
    }

    sort(adress, adress + T, cmp);

    for (int i = 0; i < T;i++)
    {
        cout << adress[i].username << '@' << adress[i].pcname << endl;
    }
}

int main()
{
    cin >> T;

    question();

    return 0;
}