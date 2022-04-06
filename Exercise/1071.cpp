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

void question()
{
    //int *zsa = (int *)malloc(sizeof(int) * 500);
    //int *zsb = (int *)malloc(sizeof(int) * 500);
    //int *xsa = (int *)malloc(sizeof(int) * 500);
    //int *xsb = (int *)malloc(sizeof(int) * 500);

    int acc;

    string a, b;
    cin >> a >> b >> acc;

    auto pa = a.find('.');
    auto pb = b.find('.');

    string zsa, xsa, zsb, xsb;

    zsa = a.substr(0, pa);
    xsa = a.substr(++pa, a.size() - 1);
    if(zsa.size() == 0)
        zsa = "0";
    if(xsa.size() == 0)
        xsa = "0";

    zsb = b.substr(0, pb);
    xsb = b.substr(++pb, b.size() - 1);
    if(zsb.size() == 0)
        zsb = "0";
    if(xsb.size() == 0)
        xsb = "0";    

    int zsans[501], xsans[501];
    memset(zsans, 0, sizeof(zsans));
    memset(xsans, 0, sizeof(xsans));

    int xslen = (xsa.size() > xsb.size() ? xsa.size() : xsb.size());
    int zslen = (zsa.size() > zsb.size() ? zsa.size() : zsb.size());

    reverse(zsa.begin(),zsa.end());
    reverse(zsb.begin(),zsb.end());

    bool bmore = false;

    if(xsa.size() >= xsb.size())
        for (decltype(xsb.size()) i = xsb.size(); i < xsa.size();i++)
            xsb += "0";
    else
        for (decltype(xsb.size()) i = xsa.size(); i < xsb.size();i++)
            xsa += "0";
    reverse(xsa.begin(),xsa.end());
    reverse(xsb.begin(),xsb.end());

    for (int i = 0; i < xslen;i++)
    {
        xsans[i] = xsa[i] - 48 + xsb[i] - 48;
        if(bmore)
            xsans[i] += 1;

        bmore = false;            

        if(xsans[i] >= 10)
        {
            xsans[i] -= 10;
            bmore = true;
        }         
    }

    if(zsa.size() >= zsb.size())
    {
        for (decltype(zsb.size()) i = 0; i < zsb.size();i++)
        {
            zsans[i] = zsa[i] - 48 + zsb[i] - 48;
            if(bmore)
                zsans[i] += 1;

            bmore = false;

            if(zsans[i] >= 10)
            {
                zsans[i] -= 10;
                bmore = true;
            }
        }

        for (decltype(xsb.size()) i = zsb.size(); i < zsa.size();i++)
        {
            zsans[i] = zsa[i] - 48;
            if(bmore)
                zsans[i] += 1;

            bmore = false;            

            if(zsans[i] >= 10)
            {
                zsans[i] -= 10;
                bmore = true;
            }            
        }
    }
    else
    {
        for (decltype(zsb.size()) i = 0; i < zsa.size();i++)
        {
            zsans[i] = zsa[i] - 48 + zsb[i] - 48;
            if(bmore)
                zsans[i] += 1;

            bmore = false;

            if(zsans[i] >= 10)
            {
                zsans[i] -= 10;
                bmore = true;
            }
        }

        for (decltype(xsb.size()) i = zsa.size(); i < zsb.size();i++)
        {
            zsans[i] = zsb[i] - 48;
            if(bmore)
                zsans[i] += 1;

            bmore = false;            

            if(zsans[i] >= 10)
            {
                zsans[i] -= 10;
                bmore = true;
            }            
        }
    }

    if(bmore)
    {
        zsans[zslen] = 1;
        zslen++;
        bmore = false;
    }

    if(acc > xslen)
    {
        int ter = xslen - acc - 1;    
        if(xsans[ter] >= 5)
        {
            xsans[ter]++;
            if(xsans[ter] >= 10)
            {
                xsans[ter] -= 10;
                bmore = true;
            }
        }

        for (int i = 0; i < acc;i++) // 小数部分四舍五入，并且进位
        {
            ter++;
            if(!bmore)
                break;

            xsans[ter]++;

            if(xsans[ter] >= 10)
            {
                xsans[ter] -= 10;
                bmore = true;
            }
            else
                bmore = false;
        }

        if(xsans[xslen] == 1)
            bmore = true;

        for (int i = 0; i < zslen;i++)
        {
            if(!bmore)
                break;
            zsans[i]++;
            if(zsans[i] >= 10)
            {
                zsans[i] -= 10;
                bmore = true;
            }
            else
                bmore = false;        
        }

        if(bmore)
        {
            zsans[zslen] = 1;
            zslen++;
        }
    }

    for (int i = --zslen; i >= 0; i--)
    {
        cout << zsans[i];
    }
    cout << '.';

    for (int i = --xslen; i >= xslen - acc + 1;i--)
    {
        cout << xsans[i];
    }

    cout << endl;
}

int main()
{
    question();
    return 0;
}