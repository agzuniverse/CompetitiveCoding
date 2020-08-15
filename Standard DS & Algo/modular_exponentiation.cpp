/*
Modular exponentiation:
Finding (x^y)%m in O(log(y)) time.
*/
#include <iostream>

using namespace std;

long long int pow(long long x, long long y, long long m)
{
    long long ans = 1;
    x = x % m;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y % 2 != 0)
            ans = (ans * x) % m;
        x = (x * x) % m;
        y /= 2;
    }
    return ans;
}

int main()
{
    cout << pow(2, 32, 1000000009);
}