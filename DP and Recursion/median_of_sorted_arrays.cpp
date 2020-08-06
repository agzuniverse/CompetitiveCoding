/*
Given two sorted arrays, return the median of both the arrays in O(log(min(n,m)) time and O(1) space.
*/

#include <iostream>

using namespace std;

float findMedianOfSingleArray(int arr[], int n)
{
    if (n % 2 == 0)
        return (float)(arr[n / 2] + arr[n / 2 - 1]) / 2;
    else
        return (float)arr[n / 2];
}

float findMedianOf2(int a, int b)
{
    return (a + b) / 2.0;
}

float findMedianOf3(int a, int b, int c)
{
    return a + b + c - max(a, max(b, c)) - min(a, min(b, c));
}

float findMedianOf4(int a, int b, int c, int d)
{
    int Max = max(a, max(b, max(c, d)));
    int Min = min(a, min(b, min(c, d)));
    return (a + b + c + d - Max - Min) / 2.0;
}

float findMedian(int arr1[], int n, int arr2[], int m)
{
    // If the smaller array becomes empty
    if (n == 0)
        return findMedianOfSingleArray(arr2, m);
    // If the smaller array has one element
    if (n == 1)
    {
        // If the larger array also has one element
        if (m == 1)
            return findMedianOf2(arr1[0], arr2[0]);
        // If the larger array has odd number of elements
        if (m & 1)
            return findMedianOf2(arr2[m / 2], findMedianOf3(arr2[m / 2 - 1], arr2[m / 2 + 1], arr1[0]));
        // If the larger array has even number of elements
        return findMedianOf3(arr1[0], arr2[m / 2], arr2[m / 2 - 1]);
    }
    // If the smaller array has 2 elements
    if (n == 2)
    {
        // If the larger array also has 2 elements
        if (m == 2)
            return findMedianOf4(arr1[0], arr1[1], arr2[0], arr2[1]);
        // If the larger array has odd number of elements
        if (m & 1)
            return findMedianOf3(arr2[m / 2], min(arr2[m / 2 + 1], arr1[1]), max(arr2[m / 2 - 1], arr1[0]));
        // If the larger array has even number of elements
        return findMedianOf4(arr2[m / 2], arr2[m / 2 - 1], min(arr2[m / 2 + 1], arr1[1]), max(arr2[m / 2 - 2], arr1[0]));
    }
    int indexA = (n - 1) / 2;
    int indexB = (m - 1) / 2;
    if (arr1[indexA] <= arr2[indexB])
        return findMedian(arr1 + indexA, n / 2 + 1, arr2, m - indexA);
    return findMedian(arr1, n / 2 + 1, arr2 + indexA, m - indexA);
}

int main()
{
    int arr1[] = {-5, 3, 6, 12, 15};
    int arr2[] = {-12, -10, -6, -3, 4, 10};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    float ans;
    if (n < m)
        ans = findMedian(arr1, n, arr2, m);
    else
        ans = findMedian(arr2, m, arr1, n);
    cout << ans << endl;
}
