#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <vector>

using namespace std;

deque<int> pre;
deque<int> ans;
deque<int> temp;

void count_One(long long number,deque<int> *queue)
{
    long long test = 1;

    for (int t = 0; t < 64;t++)
    {
        if(test > number)
            break;
        if(number & test)
            queue->push_front(1);
        else
            queue->push_front(0);

        test = test << 1;
    }

    return;
}

void ZIP()
{
    auto bit = pre.begin();
    for (decltype(pre.size()) i = 0; i < pre.size();i++)
    {
        int cnt = 1;

        if(bit == pre.end())
            break;

        if(*bit == 0)
        {
            ans.push_back(0);
            bit++;
        }
        else
        {
            while(++bit != pre.end() && *bit == 1) //下一个还有元素存在并且为1
                cnt++;

            if(cnt > 2)
            {
                count_One(cnt, &temp);

                while(!temp.empty())
                {
                    ans.push_back(temp.front());
                    temp.pop_front();
                }
            }
            else if(cnt == 1)
            {
                ans.push_back(1);
            }
            else if(cnt == 2)
            {
                ans.push_back(1);
                ans.push_back(1);
            }
        }
    }
    return;
}

long long regenerate()
{
    long long num = 0;

    for (decltype(ans.size()) i = 0; i < ans.size();i++)
    {
        num *= 2;
        num += ans[i];
    }
        
    return num;
}

void print(long long num)
{
    //printf("%lld,%llu,%llu", num,pre.size(),ans.size());
    cout << num << ',' << pre.size() << ',' << ans.size() << endl;
    return;
}

void question(long long N)
{
    count_One(N,&pre); // 原数字化为二进制串

    ZIP(); //压缩

    long long num = regenerate(); // 压缩二进制串变为数字

    print(num); //输出数据

    return;
}

int main()
{
    long long N;
    cin >> N;
    question(N);

    //deque<int> ls = {1};
    //cout << ls.back() << endl;

    return 0;
}