/*
Output Format

Print YES if string

is valid, otherwise, print NO.

Sample Input 0

aabbcd

Sample Output 0

NO

Explanation 0

Given
, we would need to remove two characters, both c and d aabb or a and b abcd, to make it valid. We are limited to removing only one character, so

is invalid.

Sample Input 1

aabbccddeefghi

Sample Output 1

NO

Explanation 1

Frequency counts for the letters are as follows:

{'a': 2, 'b': 2, 'c': 2, 'd': 2, 'e': 2, 'f': 1, 'g': 1, 'h': 1, 'i': 1}

There are two ways to make the valid string:

    Remove 

characters with a frequency of :
.
Remove
characters of frequency :

    .

Neither of these is an option.

Sample Input 2

abcdefghhgfedecba

Sample Output 2

YES

Explanation 2

All characters occur twice except for e
which occurs times. We can delete one instance of e to have a valid string.
*/


#include <bits/stdc++.h>

using namespace std;

string isValid(string s)
{
    map<char, int> h;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        h[s[i]]++;
    }
    int count = 0, flag = 0;
    if (h.begin()->second == next(h.begin(), 1)->second)
        count = h.begin()->second;
    else if (next(h.begin(), 1)->second == next(h.begin(), 2)->second)
        count = next(h.begin(), 1)->second;
    else if (h.begin()->second == next(h.begin(), 2)->second)
        count = h.begin()->second;
    else
        return ("NO");
    map<char, int>::iterator it;
    for (auto &it : h)
    {
        if ((it.second) != count && (it.second) != count + 1)
        {
            if (it.second == 1)
            {
                flag++;
                if (flag >= 2)
                    return ("NO");
                continue;
            }
            return ("NO");
        }
        else if ((it.second) == count + 1)
        {
            flag++;
            if (flag >= 2)
                return ("NO");
        }
    }
    return ("YES");
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
