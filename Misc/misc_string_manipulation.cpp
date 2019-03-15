/*
Given an input like 2[3[b]2[ab]], print the output as bbbabababbbbababab
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    stack<char> chars;
    stack<int> nums;
    cin >> s;
    string numstr;
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
            numstr += s[i];
        else if (s[i] == '[')
        {
            nums.push(stoi(numstr));
            numstr = "";
            chars.push('[');
        }
        else if (s[i] == ']')
        {
            string curr;
            char c;
            do
            {
                c = chars.top();
                curr += c;
                chars.pop();
            } while (c != '[');
            int repeats = nums.top();
            nums.pop();
            reverse(curr.begin(), curr.end());
            for (int x = 0; x < repeats; x++)
                for (int y = 0; y < curr.length(); y++)
                    if (curr[y] != '[')
                        chars.push(curr[y]);
        }
        else
            chars.push(s[i]);
    }
    string result;
    while (!chars.empty())
    {
        result += chars.top();
        chars.pop();
    }
    reverse(result.begin(), result.end());
    cout << result;
}