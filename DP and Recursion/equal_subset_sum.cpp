/*
Given an input array, check if it can split into two arrays having equal sums.
*/

#include <iostream>
#include <vector>

using namespace std;

bool hasEqualSubset(vector<int> inp)
{
    int n = inp.size();
    int S = 0;
    for (auto i : inp)
        S += i;
    if (S & 1 == 1)
        return false; // If total sum is odd, it is not possible to have 2 subsets having same sum
    S /= 2;
    vector<vector<bool>> memo(n, vector<bool>(S + 1));

    // Sum of 0 is always possible by picking no elements
    for (int i = 0; i < n; i++)
        memo[i][0] = true;

    // The first row (Corresponding to picking the first element only) is true only for the
    // sum value same as it's value
    for (int i = 0; i < S; i++)
        memo[0][i] = (inp[0] == i ? true : false);

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= S; j++)
        {
            if (memo[i - 1][j])
                memo[i][j] = true; // If we can get the sum without including this element
            else if (inp[i] <= j)
                memo[i][j] = memo[i - 1][j - inp[i]];
        }
    }

    return memo[n - 1][S];
}

int main()
{
    vector<int> inp = {5, 7, 21, 9};
    cout << hasEqualSubset(inp) << endl;
}

/*
Explanation:
Calculate the sum of the array S.
The problem then reduces to finding a subset of the array that sums to S/2.
If such a subset exists, the remaining elements must also sum to S/2, thus solving the problem.

Finding a subset of the array that sums to a particular number is a dp problem following
the pattern of the 0/1 Knapsack problem, with the sum S as the columns and number of elements n as rows.

Time complexity of the solution is O(n*S)
*/