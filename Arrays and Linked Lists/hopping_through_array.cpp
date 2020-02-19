/*
Given an array of integers where each element represents the max number of steps that can be made forward from that element.
Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element).
If an element is 0, then cannot move through that element.

Example
Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3 (1-> 3 -> 8 ->9)

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int counter = 1, steps_left = arr[0], max_reach = arr[0];

    for (int i = 1; i < n - 1; i++)
    {
        if ((i + arr[i]) > max_reach)
            max_reach = i + arr[i];
        steps_left--;
        if (!steps_left)
        {
            counter++;
            steps_left = max_reach - i;
        }
    }
    cout << counter;
}