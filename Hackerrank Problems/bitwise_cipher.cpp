#include <bits/stdc++.h>

using namespace std;

string cipher(int n, int k, string s)
{
    char ans[n];
    int x = 0;
    for (int i = 0; i < k - 1; i++)
    {
        ans[i] = (s[i] - '0' ^ x) + '0';
        x ^= ans[i] - '0';
    }
    for (int i = k - 1; i < n; i++)
    {
        ans[i] = (s[i] - '0' ^ x) + '0';
        x ^= ans[i] - '0';
        x ^= ans[i - k + 1] - '0';
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string result = cipher(n, k, s);
    cout << result;
    return 0;
}
