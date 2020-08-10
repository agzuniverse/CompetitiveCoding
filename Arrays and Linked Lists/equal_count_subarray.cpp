/*
Given an array of letters and numbers, find the longest subarray with equal number of letters and numbers.

Time complexity required: O(n)
*/

#include <iostream>
#include <unordered_map>

using namespace std;

bool isLetter(char c)
{
    return (c >= 'a' && c <= 'z') ? true : false;
}

int solve(char arr[], int n)
{
    int countOfLetters[n] = {0};
    int countOfNumbers[n] = {0};
    if (isLetter(arr[0]))
        countOfLetters[0] = 1;
    else
        countOfNumbers[0] = 1;
    int diff[n] = {0};
    for (int i = 1; i < n; i++)
    {
        if (isLetter(arr[i]))
        {
            countOfLetters[i] = countOfLetters[i - 1] + 1;
            countOfNumbers[i] = countOfNumbers[i - 1];
        }
        else
        {
            countOfNumbers[i] = countOfNumbers[i - 1] + 1;
            countOfLetters[i] = countOfLetters[i - 1];
        }
    }
    // Get the difference between the cumulative count of letters and numbers.
    // The idea is that when the differences are the same at two points, there is an equal number
    // of letters and numbers in between those two points.
    for (int i = 0; i < n; i++)
        diff[i] = countOfLetters[i] - countOfNumbers[i];

    // Find the largest subarray in diff that has the same value at the beginning and the end
    // i.e, subarray between the points with same value in diff will have same number of letters and numbers.
    unordered_map<int, int> hm;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (hm.find(diff[i]) != hm.end())
            ans = max(ans, i - hm[diff[i]]);
        else
            hm[diff[i]] = i;
    }
    return ans;
}

int main()
{
    char arr[] = {'a', 'a', 'a', 'a', '1', '1', 'a', '1', '1', 'a', 'a', '1', 'a', 'a', '1', 'a', 'a', 'a', 'a', 'a'};
    cout << solve(arr, sizeof(arr) / sizeof(arr[0]));
}