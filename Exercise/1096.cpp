#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <cstring>

using namespace std;

int present_location = 0;

void print()
{
    cout << "case #" << present_location << ":" << endl;
    return;
}

void question()
{
    bool table[5][5];
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            table[i][j] = true;
        }
    }

    int moves;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cin >> moves;
            for(int k=0;k<moves;k++)
            {
                table[i][j]   = !table[i][j];
                table[i-1][j] = !table[i-1][j];
                table[i+1][j] = !table[i+1][j];
                table[i][j-1] = !table[i][j-1];
                table[i][j+1] = !table[i][j+1];
            }
        }
    }

    print();
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(table[i][j])
                cout << 1 << ' ';
            else
                cout << 0 << ' ';
        }
        cout << endl;
    }

}

int main()
{
    int T;
    cin >> T;
    getchar();
    for (; present_location < T;present_location++)
    {
        question();
    }
    return 0;
}
