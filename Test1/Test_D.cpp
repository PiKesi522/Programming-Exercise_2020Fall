#include <iostream>
#include <vector>


using namespace std;

void question()
{
    vector<char> moves;
    int n,m;
    cin >> n >> m;
    unsigned long long sum = 0;
    int migong[202][202];
    for(int i = 0; i < 202; i++)
    {
        for(int j = 0; j < 202; j++)
        {
            migong[i][j] = -1;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> migong[i][j];
        }
    }
    /*for(int i = 0; i <= n + 1; i++)
    {
        for(int j = 0; j <= m + 1; j++)
        {
            cout << migong[i][j];
        }
        cout << endl;
    }*/

    sum = migong[1][1];
    int x = 1, y = 1;
    while(true)
    {
        int down = migong[x+1][y];
        int right = migong[x][y+1];

        if(x == n && y == m)
            break;

        if(right == -1)
        {
            moves.push_back('D');
            x += 1;
            sum += down;
            continue;
        }
        else if(down == -1)
        {
            moves.push_back('R');
            y += 1;
            sum += right;
            continue;
        }


        if(right > down)
        {
            moves.push_back('D');
            x += 1;
            sum += down;
        }
        else
        {
            moves.push_back('R');
            y += 1;
            sum += right;
        }
    }
    cout << sum << endl;
    for(char ch : moves)
        cout << ch;
    cout << endl;
}

int main()
{
    question();
    return 0;
}
