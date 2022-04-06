#include <iostream>

using namespace std;

typedef unsigned long long ull;
/*
2 9 1 4 7
*/

void question()
{
    ull profit = 0, profit_today = 0;
    int N;
    cin >> N;
    int array[1005] = {-1};
    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
    }
    int buyit = array[0];
    for (int i = 1; i < N; i++)
    {
        int price = array[i];
        if(price < buyit)
        {
            buyit = price;
        }
        else if(price > buyit)
        {
            profit_today = price - buyit;
            if(profit_today > profit)
                profit = profit_today;
        }
    }
    cout << profit << endl;
}

int main()
{
    int M;
    cin >> M;
    for(int i = 0; i < M; i++)
        question();
    return 0;
}