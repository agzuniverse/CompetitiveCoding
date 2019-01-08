// Hey..I am Philip J Coulson from Shield and I am here to talk about the Avengers initiative.(If you think I am still dead then sorry to say you haven’t heard the full story.)

// As we know we are facing a major threat and earth needs more of its fighters – the best of them. So come with me .We have a war to win.

// Just to familiarise you with how it works.

// Your first challenge is to print the frequency of a letter(k) in the few(n) given strings.Always remember that you don’t need to ask for inputs like “Enter the string”, “Enter the letter” etc.

// Input Format

// No of strings n

// String 1

// String 2

// ………….

// String n

// letter to be searched k

// Constraints

// 1 < n <10^4

// Output Format

// Frequeny of k in String 1

// Frequeny of k in String 2

// ……………………………………

// Frequeny of k in String n

// Sample Input 0

// 2
// avengersassemble
// hello world
// s
// Sample Output 0

// 3
// 0
// Explanation 0

// Frequency of "s" in the first string is 3 and second string is 0.

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, count = 0;
    vector<string> strs;
    string z;
    char k;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        getline(cin, z);
        strs.push_back(z);
    }
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < strs[i].size(); j++)
        {
            if (strs[i][j] == k)
                count++;
        }
        cout << count << endl;
        count = 0;
    }
}