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
    for (int i = 2; i <= n;)
    {
        if (n % i == 0)
        {
            f.push_back(i);
            n /= i;
            continue;
        }
        i++;
    }
    for (auto e : f)
        cout << e << " ";
}

int main()
{
    primes(24);
}