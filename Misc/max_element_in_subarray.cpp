// Given a set of arrays of size n and an integer k, you have to find the maximum integer for each and every contiguous subarray of size k for each of the given arrays.

// Input Format

// First line of input will contain the number of test cases T. For each test case, you will be given the size of array N and the size of subarray to be used K. This will be followed by the elements of the array A.

// Output Format

// For each of the contiguous subarrays of size k of each array, you have to print the maximum integer.

// Sample Input
// 2
// 5 2
// 3 4 6 3 4
// 7 4
// 3 4 5 8 1 4 10

// Sample Output
// 4 6 6 4
// 8 8 8 10
// Explanation

// For the first case, the contiguous subarrays of size 2 are {3,4},{4,6},{6,3} and {3,4}. The 4 maximum elements of subarray of size 2 are: 4 6 6 4.

// For the second case,the contiguous subarrays of size 4 are {3,4,5,8},{4,5,8,1},{5,8,1,4} and {8,1,4,10}. The 4 maximum element of subarray of size 4 are: 8 8 8 10.

//This solution using dequeue runs in O(n) time.
#include <bits/stdc++.h>

using namespace std;

void printKMax(int arr[], int n, int k)
{
    deque<int> q;
    for (int i = 0; i < k; i++)
    {
        // The indices are stored instead of the elements themseles and this comparison is >= instead of > to deal with duplicate elements.
        while ((!q.empty()) && arr[i] >= arr[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    for (int i = k; i < n; i++)
    {
        cout << arr[q.front()] << " ";

        while ((!q.empty()) && q.front() <= i - k)
            q.pop_front();
        while ((!q.empty()) && arr[i] >= arr[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    cout << arr[q.front()] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t > 0)
    {
        int n, k;
        cin >> n >> k;
        int i;
        int arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
}