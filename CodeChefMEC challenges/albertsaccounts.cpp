// [ Problem by E Vishnu Bhagyanath, CS-5B ]

// Albert is the accounts head of a company in a fictitious land with a unique currency which has notes of every denomination upto . Recently, he’s been having trouble with his accounts because of the large sums of money coming into his company and the different notes available.

// The CEO of the company has asked him to get a grip on the situation by sorting the money inflow to make accounting easier.

// Given an odd integer , and an array of size , your task is to sort the array and find the middle element of the sorted array.

// Input Format

// First line will be , the number of test cases. Each test case will have  as the first line with the next line containing  space separated integers .

// Constraints

// Output Format

// Print exactly  lines with the result of the corresponding test case.

// Sample Input 0

// 2
// 5
// 4 4 4 4 1
// 9
// 9 8 7 6 5 4 3 2 1
// Sample Output 0

// 4
// 5

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, len, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        cin >> len;
        for (int j = 0; j < len; j++)
        {
            cin >> a;
            v.push_back(a);
        }
        int k = len / 2;
        nth_element(v.begin(), v.begin() + k, v.end());
        cout << v[k] << "\n";
    }
    return 0;
}
