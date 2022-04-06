#include <iostream>

using namespace std;

void question()
{
    int N,k;
    int a, b;
    cin >> N >> k;
    unsigned long long money = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        money += (a > b) ? b : a;
    }
    cout << money << endl;
}

int main()
{
    int M;
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        question();
    }
    return 0;
}