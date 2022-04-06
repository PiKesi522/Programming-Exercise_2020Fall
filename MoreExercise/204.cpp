#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class lalala{
    public:
        string yu_ming;
        string di_zhi;
};

bool cmp(lalala A, lalala B)
{
    if(A.yu_ming != B.yu_ming)
        return A.yu_ming < B.yu_ming;
    else
        return A.di_zhi < B.di_zhi;
}

void question()
{
    int N;
    cin >> N;
    lalala website[105];
    int used = 0;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;

        if(temp[4] == 's')
            continue;

        int last_point = temp.rfind('.');
        int fen_ge = temp.find('/',last_point);
        website[used].yu_ming = temp.substr(7, fen_ge - 7);
        website[used].di_zhi  = temp.substr(fen_ge + 1);
        used++;
    }

    sort(website, website + used, cmp);

    for (int i = 0; i < used; i++)
    {
        cout << "http://" << website[i].yu_ming << '/' << website[i].di_zhi << endl;
    }
}

int main()
{
    question();
    return 0;
}