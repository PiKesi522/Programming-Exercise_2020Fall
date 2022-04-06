#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int present_location = 0;

string table[36] = {".-", "-...", "-.-.", "-..",
                  ".", "..-.", "--.", "....", "..", ".---",
                  "-.-", ".-..", "--", "-.", "---", ".--.",
                  "--.-", ".-.", "...", "-", "..-", "...-",
                  ".--", "-..-", "-.--", "--..",
                  "-----", ".----", "..---", "...--", "....-",
                  ".....", "-....", "--...", "---..", "----."};

char zifu[36] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
               'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
               'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0',
               '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void print()
{
    cout << "case #" << present_location << ":" << endl;
}

void findword(string str)
{
    int i = 0;
    bool found = false;
    for (; i < 36;i++)
    {
        if(str == table[i])
        {
            found = true;
            break;
        }
    }

    if(found)
        cout << zifu[i];
    else
        cout << "findword 函数出错" << endl;
}

void question()
{
    string str,temp;
    cin >> str;
    int size = str.length();
    int cnt = 0;
    print();
    for (int i = 0; i < size;i++)
    {
        if (str[i] == '/')
        {
            //temp += '\0';
            cnt++;
            if(temp.size() > 0)
            {
                findword(temp);
                temp.erase();
            }
        }
        else
        {
            if(cnt == 3)
                cout << ' ';
            else if(cnt == 5)
                cout << '.';
            cnt = 0;
            temp += str[i];
        }
    }
    
    if(cnt == 0)
        findword(temp);
}

int main()
{
    int T;
    cin >> T;
    getchar();
    for (; present_location < T; present_location++)
        question();
    return 0;
}