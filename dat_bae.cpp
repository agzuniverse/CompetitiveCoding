/*
Interactive problem:
There are N machine of which B are broken. Each machine stores one bit
and sends them back. We can make upto F queries.

For each query we send N bits which are stored in the machines (index 0 based)
Then the bits are read back and given to us. The broken machines don't return anything
Which means we get back N-B bits.

Identify and print the indices of the broken machines.

Constrant: B<(min(15,N-1))
There will be T testcases.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, b, f;
    cin >> t;
    for (int z = 0; z < t; z++)
    {
        cin >> n >> b >> f;
    }
}