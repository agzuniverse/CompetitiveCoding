// You are given an array of size n. Find out how many subarrays exist, such that the first and last element of the subarray is the same, with at least 2 elements in each subarray.

// Repeating elements in a subarray are considering distinct at distinct positions. That is, if the subarray [1,2,1] comes twice in an array, it is to be counted distinctly.

// Input
// First line will contain n, the size of the array.
// The next line will contain n space separated integers a, denoting each element in the array.

// Output
// Single line containing the number of possible subarrays.

// SAMPLE INPUT
// 6
// 2 2 3 3 2 2

#include <bits/stdc++.h>
using namespace std;
unordered_map<long int, long int> hm;
void countFreq(long long int a[], long long int n)
{
    for (long long int i = 0; i < n; i++)
        hm[a[i]]++;
}
long int query(long long int x)
{
    return hm[x];
}
int main()
{
    long long int n, result = 0, temp;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    countFreq(a, n);
    for (auto i : hm)
    {
        temp = i.second - 1;
        result += (temp) * (temp + 1) / 2;
    }
    cout << result;
    return 0;
}