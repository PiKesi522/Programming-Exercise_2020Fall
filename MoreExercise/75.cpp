#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

class lalala{
    public:
        string itself;
        int appear = 0;
};

bool cmp(lalala A, lalala B)
{
    if(A.appear != B.appear)
        return A.appear < B.appear;
    else
        return A.itself > B.itself;
}

void question()
{
    int DNA_nums = 0;
    int occupy = 0;

    lalala DNA[200000];
    cin >> DNA_nums;

    for (int i = 0; i < DNA_nums; i++)
    {
        string temp;
        cin >> temp;
        bool found = false;
        for (int j = 0; j < occupy;j++)
        {
            if(temp == DNA[j].itself)
            {
                DNA[j].appear++;
                found = true;
                break;
            }
        }
        if(!found)
        {
            DNA[occupy++].itself = temp;
        }
    }

    sort(DNA, DNA + occupy, cmp);

    for (int i = 0; i < occupy; i++)
    {
        cout << DNA[i].itself << endl;
    }
}

int main()
{
    question();
    return 0;
}