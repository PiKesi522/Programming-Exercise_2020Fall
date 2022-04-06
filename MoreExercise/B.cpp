#include <iostream>
#include <string>

using namespace std;

void question()
{
    char inweek[5], inday[10];
    cin >> inweek >> inday;
    int week = inweek[4] - '0';
    int days = (week - 1) * 7;
    switch (inday[0])
    {
        case 'M':
            days += 1;
            break;
        case 'T':
            if(inday[1] == 'u')
                days += 2;
            else if(inday[1] == 'h')
                days += 4;
            break;
        case 'W':
            days += 3;
            break;
        case 'F':
            days += 5;
            break;
        case 'S':
            if(inday[1] == 'a')
                days += 6;
            else if(inday[1] == 'u')
                days += 7;
            break;
        default:
            cout << "bug" << endl;
            break;
    }

    char people[6] = {'A', 'B', 'C', 'D', 'E','F'};
    int who = (days - 1) % 6;
    cout << people[who] << " sir" << endl;
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