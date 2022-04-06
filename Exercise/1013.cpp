#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

char table[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
int n, R;

void question()
{
    cin >> n >> R;
    if(n == 0)
    {
        cout << 0 << endl;
        return;
    }
    deque<char> ans;
    while(n != 0)
    {
        int temp = n % R;
        if(temp < 0)
        {
            int rest = -R  + temp;
            ans.push_front(table[rest]);
            n -= rest;
            n = n / R;
        }
        else
        {
            ans.push_front(table[temp]);
            n = (n - temp) / R;
        }
    }

    for(auto v : ans)
        cout << v;
    cout << endl;

}

int main()
{
    question();
    return 0;
}