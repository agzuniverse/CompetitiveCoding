/*
Rabin Karp algorithm is used for substring matching with O(n+m) average case and O(nm) worst case running time, where
n is length of haystack and m is length of needle.
It uses hashing and checks individual characters only if the hash of the haystack piece matches the hash of the needle.
*/

#include <bits/stdc++.h>
#define d 256 //No of possible characters
#define q 101 //Sufficiently large prime number

using namespace std;

int main()
{
    string haystack;
    string needle;
    //Enter haystack
    cin >> haystack;
    //Enter needle
    cin >> needle;
    int n = haystack.length();
    int m = needle.length();
    int h = (int)(pow((double)d, (double)m - 1)) % q;

    int p = 0; //Hash value of pattern
    int t = 0; //Hash value of window

    for (int i = 0; i < m; i++)
    {
        p = (d * p + needle[i]) % q;
        t = (d * t + haystack[i]) % q;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
                if (haystack[i + j] != needle[j])
                {
                    flag = false;
                    break;
                }
            if (flag)
                cout << i;
        }
        if (i < n - m)
        {
            t = (d * (t - haystack[i] * h) + haystack[i + m]) % q;
            if (t < 0)
                t = t + q;
        }
    }
}