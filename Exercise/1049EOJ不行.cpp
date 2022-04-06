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

void reorg(map<char,int> table)
{
    multiset<int> ans;
    auto itE = table.find('E');
    auto itF = table.find('F');
    auto itG = table.find('G');
    auto itH = table.find('H');
    auto itI = table.find('I');
    auto itN = table.find('N');
    auto itO = table.find('O');
    auto itR = table.find('R');
    auto itS = table.find('S');
    auto itT = table.find('T');
    auto itU = table.find('U');
    auto itV = table.find('V');
    auto itW = table.find('W');
    auto itX = table.find('X');
    auto itZ = table.find('Z');
    
    // 第一阶段：找 Z:0, W:2, U:4, X:6, G:8;
    while(table.count('Z'))
    {
        if(itZ->second)
        {
            itZ->second--;
            itE->second--;
            itR->second--;
            itO->second--;
            ans.insert(0);
        }
        else
        {
            table.erase('Z');

            if(!itE->second)
                table.erase('E');
            if(!itR->second)
                table.erase('R');
            if(!itO->second)
                table.erase('O');
        }

    }

    while(table.count('U'))
    {
        if(itU->second)
        {
            itF->second--;
            itO->second--;
            itU->second--;
            itR->second--;
            ans.insert(4);
        }
        else
        {
            if(!itF->second)
                table.erase('F');
            if(!itO->second)
                table.erase('O');

            table.erase('U');

            if(!itR->second)
                table.erase('R');
        }

    }

    while(table.count('W'))
    {
        if(itW->second)
        {
            itT->second--;
            itW->second--;
            itO->second--;
            ans.insert(2);
        }
        else
        {
            if(!itT->second)
                table.erase('T');

            table.erase('W');

            if(!itO->second)
                table.erase('O');
        }
    }

    while(table.count('X'))
    {
        if(itX->second)
        {
            itS->second--;
            itX->second--;
            itI->second--;
            ans.insert(6);
        }
        else
        {
            if(!itS->second)
                table.erase('S');
            if(!itI->second)
                table.erase('I');

            table.erase('X');
        }
    }

    while(table.count('G'))
    {
        if(itG->second > 0)
        {
            itE->second--;
            itI->second--;
            itG->second--;
            itH->second--;
            itT->second--;
            ans.insert(8);
        }
        else
        {
            if(!itE->second)
                table.erase('E');
            if(!itI->second)
                table.erase('I');

            table.erase('G');

            if(!itH->second)
                table.erase('H');
            if(!itT->second)
                table.erase('T'); 
        }
    }

    // 第二阶段：找 O:1, R:3, F:5, S:7;
    while(table.count('O'))
    {
        if(itO->second)
        {
            itO->second--;
            itN->second--;
            itE->second--;
            ans.insert(1);
        }
        else
        {
            table.erase('O');

            if(!itN->second)
                table.erase('N');
            if(!itE->second)
                table.erase('E');
        }

    }

    while(table.count('R'))
    {
        if(itR->second)
        {
            itT->second--;
            itH->second--;
            itR->second--;
            itE->second -= 2;
            ans.insert(3);
        }
        else
        {
            if(!itT->second)
                table.erase('T');
            if(!itH->second)
                table.erase('H');

            table.erase('R');

            if(!itE->second)
                table.erase('E');
        }

    }

    while(table.count('F'))
    {
        if(itF->second)
        {
            itF->second--;
            itI->second--;
            itV->second--;
            itE->second--;
            ans.insert(5);
        }
        else
        {
            table.erase('F');

            if(!itI->second)
                table.erase('I');
            if(!itV->second)
                table.erase('V');
            if(!itE->second)
                table.erase('E');
        }

    }

    while(table.count('S'))
    {
        if(itS->second)
        {
            itS->second--;
            itE->second -= 2;
            itV->second--;
            itN->second--;
            ans.insert(7);
        }
        else
        {
            table.erase('S');

            if(!itE->second)
                table.erase('E');
            if(!itV->second)
                table.erase('V');
            if(!itN->second)
                table.erase('N');
        }

    }

    // 第三阶段： 找 9
    while(table.count('E'))
    {
        auto it = table.find('E');        
        if(!it->second)
        {
            break;
        }
        ans.insert(9);
        it->second--;
    }

    print();

    for(auto v : ans)
        cout << v;
    cout << endl;

    return;
}

void question() // 读取字符串并且存储计数,不保留位置
{
    map<char, int> table;
    char ch;

    while ((ch = getchar()) != '\n')
    {
        if(!table.count(ch))
        {
            table.insert(make_pair(ch, 1));
        }
        else
        {
            auto it = table.find(ch);
            it->second++;
        }
    }
    
    reorg(table);
    
    return;
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