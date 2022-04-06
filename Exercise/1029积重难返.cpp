#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

class Word{
    public:
        string itself;
        int length;
        bool alpha = true;
};

void change(Word A[], Word B[], int len)
{
    map<char,int> s;
    for(int i = 0;i < len;i++) // THE BREAD -> A:1,B:1,D:1,E:2,H:1,R:1,T:1  (s)
    {
        if(A[i].alpha)
            for(int j = 0;j < A[i].length;j++)
            {
                if(s.count(A[i].itself[j]))
                {
                    auto it = s.find(A[i].itself[j]);
                    it->second++;
                }
                else
                    s[A[i].itself[j]] = 1;
            }
    }
        
    for(int i =0;i < len;i++) // A:1,B:1,D:1,E:2,R:1,T:1  (s) -> ABD EEHRT
    {
        if(A[i].alpha)
            for(int j = 0 ; j < B[i].length; j++)
            {
                auto it = s.begin();
                B[i].itself += it->first;
                it->second--;
                if(it->second == 0)
                {
                    s.erase(s.begin());
                }
            }
    }
    
    return;
}

void print(Word *A,int present_location,int len,bool flag)
{
    cout << "case #" << present_location << ":" << endl;

    if(flag)
        for(int i = 0;i < len; i++)
            cout << A[i].itself << ' ';
    else
        for(int i = 0;i < len; i++)
            cout << A[i].itself << ((i == len - 1) ? '.'  : ' ');

    return;
}

void question(int present_location)
{
    char line[200];
    char temp;
    Word word[200];
    Word ans[200];
    int len = 0;
    int start = 0;
    int end = 0;
    int i = 0;

    while(true)
    {
        scanf("%c",&temp);
        if(temp=='\n') 
        {
            line[len]='\0';
            string ttemp(line, start, end - start);
            word[i].itself = ttemp;
            word[i].length = end - start;
            i++;
            start = end;
            break;
        }
        else if(temp == ' ')
        {
            string ttemp(line, start, end - start);
            word[i].itself = ttemp;
            word[i].length = end - start;
            i++;
            start = end;
        }
        else
        {
            line[len++] = temp;
            end++;
        }

    }

    bool flag = true;
    for (int k = 0; k < i;k++)
    {
        for(int j = 0;j < word[k].length;j++)
        {
            if(!isalpha(word[k].itself[j]))
            {
                if(word[k].itself[j] == '.')
                {
                    flag = false;
                    word[k].length--;
                    word[k].itself[j] = '\0';
                }
                else
                {
                    word[k].alpha = false;
                    ans[k].alpha = false;
                    ans[k].itself = word[k].itself;
                    break;
                }
            }
        }

        ans[k].length = word[k].length;
    }
    
    change(word,ans,i);//排序
    
    print(ans,present_location,i,flag);
    
    return;
}

int main()
{
    int T;
    cin >> T;
    getchar();
    for(int i=0;i<T;i++)
    {
        question(i);
    }
    return 0;
}
