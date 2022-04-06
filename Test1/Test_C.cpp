#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    while(b^=a^=b^=a%=b);
    return a;
}

void question()
{
    int n;
    long long s;
    cin >> n >> s;
    //int table[100001];
    int *height = (int *)malloc(sizeof(int) * 1000001);
    for(int i = 0; i < 1000001; i++)
        height[i] = n;
    for(int i = 0; i < n ;i++)
    {
        int temp;
        cin >> temp;
        for(int j = 0; j < temp; j++)
        {
            height[j] -= 1;
            //cout << height[j];
        }
    }

    int h = 0;
    for(h = 0;;h++)
    {
        if(s < height[h])
            break;
        s = s - height[h];
    }
    int kkk = 0;
    if(s!=0 && h==0)
        kkk = 1;
    else
        cout << h;

    if(s != 0)
    {
        if(h != 0)
            cout << '+';
        int t = gcd(s,height[h]);
        s = s / t;
        height[h] = height[h] / t;
        cout << s << '/' << height[h];
    }
    free(height);

}

int main()
{
    question();
    return 0;
}
