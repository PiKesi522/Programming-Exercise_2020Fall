#include <iostream>
#include <string>

/*简单的数学题*/
/*需要提高精度*/

using namespace std;

int main()
{
    long long d,ki;
    int n,si;
    cin >> d >> n;

    double temp,time = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> ki >> si;

        if(ki > d)
            continue;

        temp = (d - ki) / si;

        if(time < temp)
            time = temp;
    }

    printf("%.6f",d/time);

    return 0;
}