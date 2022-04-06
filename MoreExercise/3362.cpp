#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class v{
    public:
        long long x = 0;
        long long y = -10;
        long long z = 0;
};

void question()
{
    int n;
    cin >> n;
    v vec;
    while(n--)
    {
        int x1, y1, z1;
        cin >> x1 >> y1 >> z1;
        vec.x += x1;
        vec.y += y1;
        vec.z += z1;
    }
    if(vec.x != 0)
    {
        cout << "YES" << endl;
        return;
    }
    if(vec.y != 0)
    {
        cout << "YES" << endl;
        return;
    }
    if(vec.z != 0)
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int main()
{
    question();
    return 0;
}