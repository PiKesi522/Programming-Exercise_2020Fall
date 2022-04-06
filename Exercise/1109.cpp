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

int main()
{
    double d;
    cin>>d;
    int c = sizeof(d);
    unsigned char *p = (unsigned char *)&d;
    p+=(c-1);
    while (c-->1)
        printf("%02X-", *p--);
    printf("%02X", *p--);
    printf("\n");
    return 0;
}