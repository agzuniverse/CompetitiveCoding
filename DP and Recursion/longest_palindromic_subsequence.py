'''
Given an input string, find the length of the longest palindromic subsequence
'''


def longestPalindromicSubstring(inp, n):
    memo = [[0]*n for _ in range(n)]

    for i in range(n):
        memo[i][i] = 1

    # The traversal is done diagonally, filling in the upper diagonal elements
    # l is length of substring currently being considered
    for l in range(2, n+1):
        for i in range(n-l+1):
            j = i+l-1
            if inp[i] == inp[j] and l == 2:
                memo[i][j] = 2
            elif inp[i] == inp[j]:
                memo[i][j] = memo[i+1][j-1]+2
            else:
                memo[i][j] = max(memo[i+1][j], memo[i][j-1])

    return memo[0][n-1]


inp = input("Enter string: ")
strLen = len(inp)
print(longestPalindromicSubstring(inp, strLen))
