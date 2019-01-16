// Bucket sort is used usually for inputs in the range [0,1) as they cannot be used as indices in counting sort.
// They run in O(n) time if we assume sorting each bucket runs in O(1) time.
// It has O(n) time complexity for a uniformly distributed input.

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    float input;
    cin >> n;
    vector<vector<float>> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        b[(int)(input * n)].push_back(input);
    }
    for (int i = 0; i < n; i++)
    {
        sort(b[i].begin(), b[i].end());
    }
    vector<float> c;
    for (int i = 0; i < n; i++)
        for (auto j = b[i].begin(); j < b[i].end(); j++)
            c.push_back(*j);

    for (auto i = c.begin(); i < c.end(); i++)
    {
        cout << *i << endl;
    }
}