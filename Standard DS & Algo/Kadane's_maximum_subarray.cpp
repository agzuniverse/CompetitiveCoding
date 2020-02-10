// Kadane's maximum subarray algorithm finds the max contigous subarray in O(n) time,
// which is more efficient than the divider and conquer (O(nlogn))
// and brute force algorithm (O(n^2))

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    vector<int> a;
    int n, input;
    //Enter number of elements in the array
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        a.push_back(input);
    }
    int max_subarray_sum, max_this_round;
    max_subarray_sum = max_this_round = *a.begin();
    for (auto i = a.begin(); i < a.end(); i++)
    {
        max_this_round = max((*i), ((*i) + max_this_round));
        max_subarray_sum = max(max_subarray_sum, max_this_round);
    }
    cout << max_subarray_sum;
}