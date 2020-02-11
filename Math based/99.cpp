// Solution to Project Euler question 99

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, b, e, k;
    unordered_map<double, string> vals;
    vector<double> results;
    cin >> n;
    double temp;
    for (int i = 0; i < n; i++)
    {
        cin >> b >> e;
        temp = e * log(b);
        results.push_back(temp);
        vals[temp] = to_string(b) + " " + to_string(e);
    }
    cin >> k;
    nth_element(results.begin(), results.begin() + k - 1, results.end());
    cout << vals[results[k - 1]];
    return 0;
}
