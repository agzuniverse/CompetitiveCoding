/*  
Given a string which consists of both uppercase and lowercase latin alphabets,
count the total number of occurances of vowels in all the substrings of the string
*/

#include <bits/stdc++.h>

using namespace std;

int calc(string s)
{
    int n = s.length();
    vector<int> arr;

    arr.push_back(n);
    for (int i = 1; i < n; i++)
        arr.push_back((n - i) + arr[i - 1] - i);

    int sum = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            sum += arr[i];
    return sum;
}

int main()
{
    string s;
    cin >> s;
    cout << vowel(s) << endl;
}

/*
Explanation:
The first character is present in n substrings (where n is length of string)
The ith character from then on is present in (n-i) substrings as the starting character, and it is also included in all the substrings that
includes the previous character. It is not included in the first i substrings.
Hence (n-i)+arr[i-1]-i gives us the number of occurances of the character in all substrings.
*/