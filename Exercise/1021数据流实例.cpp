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

string table;

bool cmp(string A,string B)
{
    int la = A.size(), lb = B.size();

    for (int i = 0; i < min(la, lb); i++)
    {
        char cha = A[i], chA = toupper(A[i]), chb = B[i], chB = toupper(B[i]);
        if(chA != chB)
            return table.find(chA) < table.find(chB);
        else if(cha != chb)
            return cha < chb;
    }

    return la < lb;
}

void question()
{
    while(cin >> table)
    {   
        vector<string> s;
        string t, line;

        getchar();

        getline(cin, line);  // 这一步是真厉害，把已经读入的东西拿出来重新读入，在读入的时候就可以有很多骚操作了
        stringstream linestream;
        linestream << line;
        while(linestream >> t)
            s.push_back(t);

        //cout << *(--s.end());
        sort(s.begin(), s.end(), cmp);

        int len = s.size();
        for (int j = 0; j < len;j++)
        {
            cout << s[j] << ' ';
        }
        cout << endl;

        s.clear();
    }

    return;
}

int main()
{
    question();

    return 0;
}