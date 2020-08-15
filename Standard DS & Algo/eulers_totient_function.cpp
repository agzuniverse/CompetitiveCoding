/*
Euler's totient function to find amount of numbers that are coprime to n between 1 and n
Runs in O(sqrt(n)) time.

Euler's totient function gives that:
the number of coprimes to n between 1 and n = n* (1-1/p) for every prime factor p of n.
*/
#include <iostream>
#include <vector>

using namespace std;

int phi(int n)
{
    int ans = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            ans -= ans / i;
        }
    }
    // It is possible for a number n to have a single prime factor greater than sqrt(n)
    // In that case, this condition is triggered.
    if (n > 1)
        ans -= ans / n;
    return ans;
}

int main()
{
    cout << phi(10);
}