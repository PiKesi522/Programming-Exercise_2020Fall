#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Words{
    public:
        string itself;
        int complex = 0;
};

void print(int present_location)
{
    cout << "case #" << present_location << ":" << endl;
    return;
}

bool cmp(Words A,Words B)
{
    if(A.complex != B.complex)
        return A.complex > B.complex;
    else
        return A.itself < B.itself;
}

int count_complex(string s)
{
    set<char> temp;
    for (decltype(s.size()) i = 0; i < s.size();i++)
    {
        temp.insert(s[i]);
    }
    return temp.size();
}

void question(int present_location)
{
    int n;
    cin >> n;
    Words s[100];
    string temp;
    for (int i = 0; i < n;i++)
    {
        cin >> temp;
        s[i].itself = temp;
        s[i].complex = count_complex(temp);
    }

    sort(s, s + n, cmp);

    print(present_location);

    for (int i = 0; i < n;i++)
    {
        cout << s[i].itself << endl;
    }

    return;
}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T;i++)
    {
        question(i);
    }

    return 0;
}