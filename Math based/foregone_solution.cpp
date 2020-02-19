/*
Question from the qualification round of Google Code Jam 2019

For t testcases, a number n that contains at least one digit as 4 is given.

1<n<10^9

The solution must express the number n as sum of two numbers a and b
such that neither a nor b contains the digit 4.
*/

#include <bits/stdc++.h>

using namespace std;

int getDigitPos(long long n)
{
    int pos = 0;
    while (n)
    {
        if (n % 10 == 4)
            return pos;
        n /= 10;
        pos++;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t, temp;
    long long n, a, b, temp2;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        a = n;
        b = 0;
        do
        {
            temp = getDigitPos(a);
            if (temp != -1)
            {

                temp2 = pow(10, temp);
                b += temp2;
                a -= temp2;
            }
        } while (temp != -1);
        cout << "Case #" << i + 1 << ": " << a << " " << b << "\n";
    }
}