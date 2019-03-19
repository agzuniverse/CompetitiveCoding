// Given an array of integers, find the smallest integer not in the array

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cout << "Enter length of array: ";
    cin >> n;
    cout << "Enter array: ";
    vector<int> arr;
    for (int i = 0, temp = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    int max = *max_element(arr.begin(), arr.end());
    int hash_arr[max] = {0};
    for (auto i = arr.begin(); i < arr.end(); i++)
        hash_arr[(*i)]++;
    for (int i = 0; i < max; i++)
        if (hash_arr[i] == 0)
        {
            cout << i;
            break;
        }
}