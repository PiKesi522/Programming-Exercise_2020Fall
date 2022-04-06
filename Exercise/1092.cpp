#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <cstring>

using namespace std;

map<char, int> table;

void question()
{
    table.insert(make_pair('A', 0));
    table.insert(make_pair('B', 0));
    table.insert(make_pair('C', 0));
    table.insert(make_pair('D', 0));
    string sentence;
    while(cin >> sentence)
    {
        getchar();
        if(sentence == "IN")
        {
            char target;
            target = getchar();
            int num;
            while(true)
            {
                char ch = getchar();
                if(ch == ',')
                {
                    cin >> num;
                    break;
                }
            }
            auto tar_iter = table.find(target);
            tar_iter->second = num;
        }
        else if(sentence == "MOV")
        {
            char target;
            target = getchar();
            char another;
            while(true)
            {
                char ch = getchar();
                if(ch == ',')
                {
                    ch = getchar();
                    another = ch;
                    break;
                }
            }
            string useless;
            cin >> useless;
            auto oth_iter = table.find(another);

            if(table.find(target) == table.end())
                table.insert(make_pair(target, oth_iter->second));
            else
            {
                auto tar_iter = table.find(target);
                tar_iter->second = oth_iter->second;
            }
        }
        else if(sentence == "ADD")
        {
            char target;
            target = getchar();
            char another;
            while(true)
            {
                char ch = getchar();
                if(ch == ',')
                {
                    ch = getchar();
                    another = ch;
                    break;
                }
            }
            string useless;
            cin >> useless;
            auto tar_iter = table.find(target);
            auto oth_iter = table.find(another);
            tar_iter->second += oth_iter->second;
        }
        else if(sentence == "SUB")
        {
            char target;
            target = getchar();
            char another;
            while(true)
            {
                char ch = getchar();
                if(ch == ',')
                {
                    ch = getchar();
                    another = ch;
                    break;
                }
            }
            string useless;
            cin >> useless;
            auto tar_iter = table.find(target);
            auto oth_iter = table.find(another);
            
            tar_iter->second -= oth_iter->second;
        }
        else if(sentence == "MUL")
        {
            char target;
            target = getchar();
            char another;
            while(true)
            {
                char ch = getchar();
                if(ch == ',')
                {
                    ch = getchar();
                    another = ch;
                    break;
                }
            }
            string useless;
            cin >> useless;
            auto tar_iter = table.find(target);
            auto oth_iter = table.find(another);
            tar_iter->second *= oth_iter->second;
        }
        else if(sentence == "DIV")
        {
            char target;
            target = getchar();
            char another;
            while(true)
            {
                char ch = getchar();
                if(ch == ',')
                {
                    ch = getchar();
                    another = ch;
                    break;
                }
            }
            string useless;
            cin >> useless;
            auto tar_iter = table.find(target);
            auto oth_iter = table.find(another);
            tar_iter->second /= oth_iter->second;
        }
        else if(sentence == "OUT")
        {
            char target;
            target = getchar();
            
            auto tar_iter = table.find(target);
            cout << tar_iter->second << endl;

            string useless;
            cin >> useless;
        }
    }
}

int main()
{
    question();
    return 0;
}