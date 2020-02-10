// Counting sort sorts in O(n) time.
// The range of the input values have to known before hand and this has to be a relatively small value to avoid very large space complexity.

#include <bits/stdc++.h>
#define RANGE 100

using namespace std;

int main()
{
    int n, input;
    vector<int> a, count(RANGE);
    fill(count.begin(), count.end(), 0); //Fastest way to set all elements in a vector to 0
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        a.push_back(input);
    }
    for (auto i = a.begin(); i < a.end(); i++)
    {
        count[*i]++;
    }
    for (int i = 1; i < RANGE; i++)
    {
        count[i] += count[i - 1];
    }
    for (auto i = a.end() - 1; i >= a.begin(); i--)
    {
        // This is a reverse loop to maintain stability
        // i.e elements that had the same value in the original array will appear in the same order they did in the original array
        b[count[*i] - 1] = *i;
        count[*i]--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << endl;
    }
}

// Counting sort done on each digit of inputs which each contain d digits starting from the least significant digit
// to the most significant digit is called radix sort of requires d iterations of counting sort, and hence
// runs in O(d(n)) time.