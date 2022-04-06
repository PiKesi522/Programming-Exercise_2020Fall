#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class aaa{
    public:
        int title = 0;
        int times = 1;
        int sum = 0;
};

bool cmp(aaa A, aaa B)
{
    return A.title < B.title;
}

void question()
{
    int N;
    cin >> N;
    int length = 0;
    vector<aaa> rooms;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        for (int j = 0; j < rooms.size(); j++)
        {
            if(rooms[j].title == temp)
            {
                rooms[j].times += 1;
                break;
            }
            else if(j == rooms.size() - 1)
            {
                aaa atemp;
                atemp.title = temp;
                rooms.push_back(atemp);
                length += 1;
                break;
            }
        }
    }
    for (int i = 0; i < length; i++)
    {
        rooms[i].sum = rooms[i].times * rooms[i].title;
    }
    sort(rooms.begin(), rooms.end(), cmp);

    unsigned long long max = 0;
    
}

int main()
{
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        question();
    }
    return 0;
}