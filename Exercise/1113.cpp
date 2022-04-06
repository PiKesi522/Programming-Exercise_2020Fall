#include <iostream>

using namespace std;

int martix[200][200] = {0};
int n,m,k;
unsigned long long cnt = 0;

void test(int x, int y,string dr)
{
    int sum = martix[x][y];
    int moves = 0;
    bool flag = false;
    if(dr == "ur")
    {
        for(int i = x,j = y;;i++,j--)
        {   
            if((i == n - 1) || (j == 0) )
                break;
            if(flag)
            {
                cnt++;
                continue;
            }
            moves++;

            for (int t = 0; t <= moves; t++)
            {
                sum += martix[x + moves - t][y - t];
            }
            
            if(sum >= k)
            {
                flag = true;
                cnt++;
            }
        }        
    }
    else if(dr == "ul")
    {
        for(int i = x,j = y;;i--,j--)
        {
            if((i == 0) || (j == 0))
                break;
            if(flag)
            {
                cnt++;
                continue;
            }
            moves++;

            for (int t = 0; t <= moves; t++)
            {
                sum += martix[x - moves + t][y - t];
            }
            
            if(sum >= k)
            {
                flag = true;
                cnt++;
            }
        }    
    }
    else if(dr == "dr")
    {
        for(int i = x,j = y;;i++,j++)
        {
            if((i == n - 1) || (j == m - 1))
                break;   
            if(flag)
            {
                cnt++;
                continue;
            }  
            moves++;  

            for (int t = 0; t <= moves; t++)
            {
                sum += martix[x + moves - t][y + t];
            }
            
            if(sum >= k)
            {
                flag = true;
                cnt++;
            }     
        } 
    }
    else if(dr == "dl")
    {
        for(int i = x,j = y;;i--,j++)
        {
            if((i == 0) || (j == m - 1))
                break;
            if(flag)
            {
                cnt++;
                continue;
            }
            moves++;

            for (int t = 0; t <= moves; t++)
            {
                sum += martix[x - moves + t][y + t];
            }
            
            if(sum >= k)
            {
                flag = true;
                cnt++;
            }
        }      
    }
}

void question()
{
    cin >> n >> m >> k;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0; j < m;j++)
        {
            cin >> martix[i][j];
        }
    }
    
    //unsigned long long cnt = 0;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0; j < m;j++)
        {
            test(i,j,"ur");
            test(i,j,"ul");
            test(i,j,"dr");
            test(i,j,"dl");
        }
    }
    cout << cnt << endl;
}

int main()
{
    question();
    return 0;
}