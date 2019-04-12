/* Program to divide an array with into n+1 contiguous parts (given input array and a value n), such that each part has an equal sum, if it is possible
Print 'IMPOSSIBLE' if such a partition is not possible.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr, cpy_array;
    int size, n, partition_at;
    cout << "Enter length of array\n";
    cin >> size;
    arr.resize(size);
    cout << "Enter array\n";
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cpy_array = arr;
    cout << "Enter the value of n\n";
    cin >> n;
    /* SAMPLE INPUT
    7
    3 7 6 2 2 0 10
    2
    */

    // Build array that has cumulative sum of all elements
    for (int i = 1; i < size; i++)
        arr[i] += arr[i - 1];

    if (arr[size - 1] % (n + 1) == 0)
        partition_at = arr[size - 1] / (n + 1); // This should be the sum of each partition
    else
        cout << "IMPOSSIBLE\n";

    vector<int> partitions;
    int num = n, i = size - 1;
    while (num)
    {
        if (arr[i] == partition_at * num)
        {
            partitions.push_back(i);
            num--;
        }
        if (i <= 0)
            break;
        i--;
    }
    if (partitions.size() != n) // Check if we were able to get the required number of partitions.
        cout << "IMPOSSIBLE\n";
    else
    {
        for (int i = 0; i < size; i++)
        {
            cout << cpy_array[i] << " ";
            if (i == partitions.back())
            {
                cout << "| ";
                partitions.pop_back();
            }
        }
    }
}