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
    char cc = 'A';
    for(int i = 0 ; i < 26 ; i++)
    {
        table.insert(make_pair(cc,0));
        cc++;
    }
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
        else if(sentence == "OUT")
        {
            char target;
            target = getchar();

            auto tar_iter = table.find(target);
            cout << tar_iter->second << endl;

            string useless;
            cin >> useless;
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
        else if(sentence == "XCHG")
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

            int temp = tar_iter->second;
            tar_iter->second = oth_iter->second;
            oth_iter->second = temp;
        }
        else if(sentence == "ADD")
        {
            char target;
            target = getchar();
            char another;
            char third;
            bool triele = false;
            while(true)
            {
                char ch = getchar();
                if(ch == ',')
                {
                    ch = getchar();
                    another = ch;
                    while(true)
                    {
                        ch = getchar();
                        if(ch == ',')
                        {
                            ch = getchar();
                            third = ch;
                            triele = true;
                            break;
                        }
                        if(ch == '\n')
                            break;
                    }
                }
                if(ch == '\n')
                    break;
            }
            auto tar_iter = table.find(target);
            auto oth_iter = table.find(another);
            if(!triele)
                tar_iter->second += oth_iter->second;
            else
            {
                auto tri_iter = table.find(third);
                tar_iter->second = oth_iter->second + tri_iter->second;
            }
        }
        else if(sentence == "SUB")
        {
            char target;
            target = getchar();
            char another;
            char third;
            bool triele = false;
            while(true)
            {
                char ch = getchar();
                if(ch == ',')
                {
                    ch = getchar();
                    another = ch;
                    while(true)
                    {
                        ch = getchar();
                        if(ch == ',')
                        {
                            ch = getchar();
                            third = ch;
                            triele = true;
                            break;
                        }
                        if(ch == '\n')
                            break;
                    }
                }
                if(ch == '\n')
                    break;
            }
            auto tar_iter = table.find(target);
            auto oth_iter = table.find(another);
            if(!triele)
                tar_iter->second -= oth_iter->second;
            else
            {
                auto tri_iter = table.find(third);
                tar_iter->second = oth_iter->second - tri_iter->second;
            }
        }
        else if(sentence == "MUL")
        {
            char target;
            target = getchar();
            char another;
            char third;
            bool triele = false;
            while(true)
            {
                char ch = getchar();
                if(ch == ',')
                {
                    ch = getchar();
                    another = ch;
                    while(true)
                    {
                        ch = getchar();
                        if(ch == ',')
                        {
                            ch = getchar();
                            third = ch;
                            triele = true;
                            break;
                        }
                        if(ch == '\n')
                            break;
                    }
                }
                if(ch == '\n')
                    break;
            }

            auto tar_iter = table.find(target);
            auto oth_iter = table.find(another);
            if(!triele)
                tar_iter->second *= oth_iter->second;
            else
            {
                auto tri_iter = table.find(third);
                tar_iter->second = oth_iter->second * tri_iter->second;
            }
        }
        else if(sentence == "DIV")
        {
            char target;
            target = getchar();
            char another;
            char third;
            bool triele = false;
            while(true)
            {
                char ch = getchar();
                if(ch == ',')
                {
                    ch = getchar();
                    another = ch;
                    while(true)
                    {
                        ch = getchar();
                        if(ch == ',')
                        {
                            ch = getchar();
                            third = ch;
                            triele = true;
                            break;
                        }
                        if(ch == '\n')
                            break;
                    }
                }
                if(ch == '\n')
                    break;
            }
            auto tar_iter = table.find(target);
            auto oth_iter = table.find(another);
            if(!triele)
                tar_iter->second /= oth_iter->second;
            else
            {
                auto tri_iter = table.find(third);
                tar_iter->second = oth_iter->second / tri_iter->second;
            }
        }
        else if(sentence == "MOD")
        {
            char target;
            target = getchar();
            char another;
            char third;
            bool triele = false;
            while(true)
            {
                char ch = getchar();
                if(ch == ',')
                {
                    ch = getchar();
                    another = ch;
                    while(true)
                    {
                        ch = getchar();
                        if(ch == ',')
                        {
                            ch = getchar();
                            third = ch;
                            triele = true;
                            break;
                        }
                        if(ch == '\n')
                            break;
                    }
                }
                if(ch == '\n')
                    break;
            }
            auto tar_iter = table.find(target);
            auto oth_iter = table.find(another);
            if(!triele)
                tar_iter->second =tar_iter->second % oth_iter->second;
            else
            {
                auto tri_iter = table.find(third);
                tar_iter->second = oth_iter->second % tri_iter->second;
            }
        }
        else if(sentence == "AND")
        {
            char target;
            target = getchar();
            char another;
            char third;
            bool triele = false;
            while(true)
            {
                char ch = getchar();
                if(ch == ',')
                {
                    ch = getchar();
                    another = ch;
                    while(true)
                    {
                        ch = getchar();
                        if(ch == ',')
                        {
                            ch = getchar();
                            third = ch;
                            triele = true;
                            break;
                        }
                        if(ch == '\n')
                            break;
                    }
                }
                if(ch == '\n')
                    break;
            }
            auto tar_iter = table.find(target);
            auto oth_iter = table.find(another);
            if(!triele)
                tar_iter->second =tar_iter->second & oth_iter->second;
            else
            {
                auto tri_iter = table.find(third);
                tar_iter->second = oth_iter->second & tri_iter->second;
            }
        }
        else if(sentence == "OR")
        {
            char target;
            target = getchar();
            char another;
            char third;
            bool triele = false;
            while(true)
            {
                char ch = getchar();
                if(ch == ',')
                {
                    ch = getchar();
                    another = ch;
                    while(true)
                    {
                        ch = getchar();
                        if(ch == ',')
                        {
                            ch = getchar();
                            third = ch;
                            triele = true;
                            break;
                        }
                        if(ch == '\n')
                            break;
                    }
                }
                if(ch == '\n')
                    break;
            }
            auto tar_iter = table.find(target);
            auto oth_iter = table.find(another);
            if(!triele)
                tar_iter->second =tar_iter->second | oth_iter->second;
            else
            {
                auto tri_iter = table.find(third);
                tar_iter->second = oth_iter->second | tri_iter->second;
            }
        }
        else if(sentence == "XOR")
        {
            char target;
            target = getchar();
            char another;
            char third;
            bool triele = false;
            while(true)
            {
                char ch = getchar();
                if(ch == ',')
                {
                    ch = getchar();
                    another = ch;
                    while(true)
                    {
                        ch = getchar();
                        if(ch == ',')
                        {
                            ch = getchar();
                            third = ch;
                            triele = true;
                            break;
                        }
                        if(ch == '\n')
                            break;
                    }
                }
                if(ch == '\n')
                    break;
            }
            auto tar_iter = table.find(target);
            auto oth_iter = table.find(another);
            if(!triele)
                tar_iter->second =tar_iter->second ^ oth_iter->second;
            else
            {
                auto tri_iter = table.find(third);
                tar_iter->second = oth_iter->second ^ tri_iter->second;
            }
        }
    }
}

int main()
{
    question();
    return 0;
}
