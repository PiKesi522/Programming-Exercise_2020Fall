#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <cstring>

using namespace std;

void question()
{
    char funx[1000] = {'\0'};
    cin >> funx;

    int len = 0;
    char unknown = '/0';
    bool leftnow = true;

    char left[1000] = {'\0'};
    int left_len = 0;
    char right[1000] = {'\0'};
    int right_len = 0;

    while(funx[len] != '\0')
    {
        char temp = funx[len++];
        if(temp == '=')
        {
            leftnow = false;
            continue;
        }
        if('a' <= temp && temp <= 'z')
            unknown = temp;
        if(leftnow)
            left[left_len++] = temp;
        else
            right[right_len++] = temp;
    }

    int left_unknow = 0;
    int left_number = 0;
    int right_unknow = 0;
    int right_number = 0;
    bool negetive = false;
    bool havexishu = false;
    int tempnumber = 0;
    for(int i = 0; i <= left_len; i++)
    {
        if(left[i] == '\0')
        {
            if(negetive)
                left_number -= tempnumber;
            else
                left_number += tempnumber;

            negetive = false;
            havexishu = false;
            tempnumber = 0;
            break;
        }

        if(left[i] == '+')
        {
            if(i == 0)
                continue;
            if(left[i - 1] != unknown)
            {
                if(negetive)
                    left_number -= tempnumber;
                else
                    left_number += tempnumber;
            }
            tempnumber = 0;
            havexishu = false;
            negetive = false;
        }
        else if(left[i] == '-')
        {
            if(left[i - 1] != unknown)
            {
                if(negetive)
                    left_number -= tempnumber;
                else
                    left_number += tempnumber;
            }
            tempnumber = 0;
            havexishu = false;
            negetive = true;
        }
        else if('0' <= left[i] && left[i] <= '9')
        {
            tempnumber *= 10;
            tempnumber += left[i] - '0';
            havexishu = true;
        }
        else if(left[i] == unknown)
        {
            if(havexishu)
            {
                if(negetive)
                    left_unknow -= tempnumber;
                else
                    left_unknow += tempnumber;
            }
            else
            {
                if(negetive)
                    left_unknow -= 1;
                else
                    left_unknow += 1;
            }
            tempnumber = 0;
            negetive = false;
        }
    }
    for(int i = 0; i <= right_len; i++)
    {
        if(right[i] == '\0')
        {
            if(negetive)
                right_number -= tempnumber;
            else
                right_number += tempnumber;

            negetive = false;
            havexishu = false;
            tempnumber = 0;
            break;
        }
        if(right[i] == '+')
        {
            if(i == 0)
                continue;
            if(right[i - 1] != unknown)
            {
                if(negetive)
                    right_number -= tempnumber;
                else
                    right_number += tempnumber;
            }
            tempnumber = 0;
            havexishu = false;
            negetive = false;
        }
        else if(right[i] == '-')
        {
            if(right[i - 1] != unknown)
            {
                if(negetive)
                    right_number -= tempnumber;
                else
                    right_number += tempnumber;
            }
            tempnumber = 0;
            havexishu = false;
            negetive = true;
        }
        else if('0' <= right[i] && right[i] <= '9')
        {
            tempnumber *= 10;
            tempnumber += right[i] - '0';
            havexishu = true;
        }
        else if(right[i] == unknown)
        {
            if(havexishu)
            {
                if(negetive)
                    right_unknow -= tempnumber;
                else
                    right_unknow += tempnumber;
            }
            else
            {
                if(negetive)
                    right_unknow -= 1;
                else
                    right_unknow += 1;
            }
            tempnumber = 0;
            negetive = false;
        }
    }
    int allunknow = left_unknow - right_unknow;
    int allnumber = right_number - left_number;
    double ans = (double)allnumber / (double)allunknow;
    printf("%c=%.3lf\n",unknown,ans);
}

int main()
{
    question();
    return 0;
}
