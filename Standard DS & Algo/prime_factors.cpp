/*
Print all prime factors of a number, with each prime factor occuring the same number
of times it would occur as in it's prime factorisation.

Example: primes(24) = 2,2,2,3 because 24 = 2^3 * 3
*/

#include <bits/stdc++.h>

using namespace std;

void primes(int n)
{
    vector<int> f;
    while (n % 2 == 0)
    {
        f.push_back(2);
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            f.push_back(i);
            n /= i;
        }
    }
    // It is possible for a number n to have a single prime factor greater than sqrt(n)
    // In that case, this condition is triggered.
    if (n > 2)
        f.push_back(n);
    for (auto e : f)
        cout << e << " ";
}

int main()
{
    primes(24);
}