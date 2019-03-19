/*
https://www.hackerrank.com/contests/ccmec-practice1/challenges/jack-largest-island/problem

Print the side of the largest square of '1's in a square matrix that can contain either 1 or 0.

First line of input is n, the length of side of the matrix.
This is followed by n lines each representing a row of the matrix.

For example:

Input:
4
0 0 0 0
0 1 1 0
0 1 1 0
0 0 0 1

Output:
2
*/

#include <bits/stdc++.h>

using namespace std;

int n, result;
vector<vector<int>> mat;
vector<vector<bool>> calculated;

int find_maximum_submatrix(int i, int j)
{
    if (i >= n || j >= n)
        return 0;
    if (!calculated[i][j])
    {
        if (mat[i][j] == 0)
        {
            find_maximum_submatrix(i + 1, j);
            find_maximum_submatrix(i + 1, j + 1);
            find_maximum_submatrix(i, j + 1);
        }
        else
        {
            mat[i][j] = 1 + min({find_maximum_submatrix(i + 1, j), find_maximum_submatrix(i + 1, j + 1), find_maximum_submatrix(i, j + 1)});
            if (result < mat[i][j])
                result = mat[i][j];
        }
        calculated[i][j] = true;
    }
    return mat[i][j];
}

int main()
{
    cin >> n;
    mat.resize(n);
    calculated.resize(n);
    for (int i = 0; i < n; i++)
    {
        mat[i].resize(n);
        calculated[i].resize(n);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
            calculated[i][j] = false;
        }
    }
    find_maximum_submatrix(0, 0);
    cout << result;
}