/*
Given an array of stock prices and value k, find the maximum amount of money that can be made by k transactions.

One transaction includes buying stock and selling it at a later day.
New stock cannot be bought while old stock is still held, or on the same day old stock was sold.
*/
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int findMaxProfit(vector<int> a, int k)
{
    // Array should at least have 2 elements in it
    if (a.size() <= 1)
        return 0;

    int dp[k + 1][a.size()];

    // All values for 0 transactions and only 1st element is 0
    for (int i = 0; i < k + 1; i++)
        dp[i][0] = 0;
    for (int i = 0; i < a.size(); i++)
        dp[0][i] = 0;

    int maxprofit;
    for (int i = 1; i < k + 1; i++)
    {
        // maxprofit holds the maximum value that can we can have by selling in the previous transaction
        // and buying stock anywhere before current value of j
        maxprofit = numeric_limits<int>::min();
        for (int j = 1; j < a.size(); j++)
        {
            maxprofit = max(maxprofit, dp[i - 1][j - 1] - a[j - 1]);
            dp[i][j] = max(dp[i][j - 1], maxprofit + a[j]);
        }
    }
    return dp[k][a.size() - 1];
}

int main()
{
    // Sample inputs
    vector<int> prices{5, 11, 3, 50, 60, 90};
    int k = 2;

    int maxProfit = findMaxProfit(prices, k);
    cout << maxProfit << endl;
}