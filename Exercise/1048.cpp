#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <cstring>
#include <sstream>

using namespace std;

int present_location = 0;

char table[64] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/'};

void print()
{
    cout << "case #" << present_location << ":" << endl;
    return;
}

void trans(vector<int> bina_ans,int len)
{
    for(int i = 0;i < len; i++)
    {
        int temp = 0;
        for (int j = 0; j < 6;j++)
        {
            int bit = *(bina_ans.begin() + 6*i + j);
            temp *= 2;
            temp += bit;
        }
        cout << table[temp];
    }
    for(int i = 0;i < 4 - len; i++)
    {
        cout << "=";
    }
}

void question()
{
    string s;
    cin >> s;
    int len = s.size();
    int r = len % 3;
    int z = len / 3;
    int loc = -1;
    print();

    for(int i = 0; i < z; i ++)
    {
        vector<int> bina_ans;
        vector<int> t;

        int one = s[++loc];
        for(int j = 0; j < 8;j++)
        {
            int temp = one % 2;
            one = one / 2;
            t.push_back(temp);
        }
        for (auto it = t.rbegin(); it != t.rend();it++)
        {
            bina_ans.push_back(*it);
        } 
        t.clear();
        
        
        int two = s[++loc];
        for(int j = 0; j < 8;j++)
        {
            int temp = two % 2;
            two = two / 2;
            t.push_back(temp);
        }        
        for (auto it = t.rbegin(); it != t.rend();it++)
        {
            bina_ans.push_back(*it);
        }       
        t.clear();
        
        
        int three = s[++loc];
        for(int j = 0; j < 8;j++)
        {
            int temp = three % 2;
            three = three / 2;
            t.push_back(temp);
        }

        for (auto it = t.rbegin(); it != t.rend();it++)
        {
            bina_ans.push_back(*it);
        }    
        t.clear();
        
        
        trans(bina_ans,4);
        
        bina_ans.clear();
        
    }
    
    switch (r)
    {
        case 0:
            break;
            
        case 1:
        {
            vector<int> bina_ans;
            vector<int> t;
            
            int one = s[++loc];
            for(int j = 0; j < 8;j++)
            {
                int temp = one % 2;
                one = one / 2;
                t.push_back(temp);
            }

            for (auto it = t.rbegin(); it != t.rend();it++)
            {
                bina_ans.push_back(*it);
            }
            t.clear(); 
            
            for(int i = 0 ; i< 4;i++)
            {
                bina_ans.push_back(0);
            }
            
            trans(bina_ans,2);
        }
            break;
            
            
        case 2:
        {
            vector<int> bina_ans;
            vector<int> t;
            
            int one = s[++loc];
            for(int j = 0; j < 8;j++)
            {
                int temp = one % 2;
                one = one / 2;
                t.push_back(temp);
            }
            for (auto it = t.rbegin(); it != t.rend();it++)
            {
                bina_ans.push_back(*it);
            }
            t.clear(); 

            one = s[++loc];
            for(int j = 0; j < 8;j++)
            {
                int temp = one % 2;
                one = one / 2;
                t.push_back(temp);
            }
            for (auto it = t.rbegin(); it != t.rend();it++)
            {
                bina_ans.push_back(*it);
            }
            t.clear();  
                       
            for(int i = 0 ; i< 2;i++)
            {
                bina_ans.push_back(0);
            }
            
            trans(bina_ans,3);
        }
            break;
            
        default:
            break;
    }
    
    cout << endl;
    return;
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
