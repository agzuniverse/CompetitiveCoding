// The Coin Change Problem requires us to find the number of ways we can form a value n given an array containing the denominations of coins we have (in infinite supply). This question requires a dynamic programming approach to compute the solution efficiently.

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the getWays function below.
long getWays(long n, vector<long> c)
{
    vector<long> ways;
    ways.resize(n + 1);
    fill(ways.begin(), ways.end(), 0);
    ways[0] = 1;
    for (long i : c)
        for (long j = 0; j < n + 1; j++)
            if (j >= i)
                ways[j] += ways[j - i];
    return (ways[n]);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<long> c(m);

    for (int i = 0; i < m; i++)
    {
        long c_item = stol(c_temp[i]);

        c[i] = c_item;
    }

    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'

    long ways = getWays(n, c);
    fout << ways;
    fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
