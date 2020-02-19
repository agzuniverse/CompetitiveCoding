/*
Question from the qualification round of Google Code Jam 2019

We start at the north-west corner of a matrix. We can either go one cell south or one cell east.
Our goal is to get to the south east cell.

A person has already gone through the matrix, and the path they followed is given to us.
We must find a path such that we do not make any move same as the move made by that person.
(It is okay to land on the same cell as the person, we just cannot make the same move that person made from that cell.)
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t, n;
    string path, ans;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cin >> path;
        for (int j = 0; j < (2 * n - 2); j++)
        {
            if (path[j] == 'S')
                ans += 'E';
            else
                ans += 'S';
        }
        cout << "Case #" << i + 1 << ": " << ans << "\n";
        ans = "";
    }
}