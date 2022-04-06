#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool cmp(int A, int B)
{
    return A > B;
}

void question(int size)
{
    int temp;
    vector<int> houses;
    for (int i = 0; i < size; i++)
    {
        string rubbish;
        cin >> temp;
        if(temp < 10 || temp > 30)
        {
            cout << "Is not SBT" << endl;
            getline(cin, rubbish);
            return;
        }
        houses.push_back(temp);
    }

    sort(houses.begin(), houses.end(), cmp);

    if(abs(*houses.begin() - houses.back()) > 3)
    {
        cout << "Is not SBT" << endl;
        return;
    }
    cout << "Is SBT" << endl;
}

int main()
{
    int size;
    while(cin >> size)
    {
        question(size);
    }
    return 0;
}