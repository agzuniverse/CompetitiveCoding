'''
Calculate minimum edit distance between 2 strings
This is also called Levenshtein distance.

The edit distance increases by 1 each time the following operations are performed:

1) Insert a character
2) Remove a character
3) Replace a character with another one

This solution runs in O(n*m) time where n and m are the lengths of the two strings.
'''

# The loop goes through the strings back to front


def findMinEditDistance(a, b, m, n):
    memo = [[0]*(n+1) for x in range(m+1)]

    for i in range(m+1):
        for j in range(n+1):
            # If one of the strings gets over all characters in the other string has to be deleted
            if i == 0:
                memo[i][j] = j
            elif j == 0:
                memo[i][j] = i

            # No edit required if characters are the same
            elif a[i-1] == b[j-1]:
                memo[i][j] = memo[i-1][j-1]

            # Else perform one edit and find the the minimum edit distance for the 3 ways we can edit the string
            else:
                memo[i][j] = 1 + min(memo[i-1][j-1],
                                     memo[i-1][j], memo[i][j-1])

    return memo[m][n]


a = input("Enter first string: ")
b = input("Enter second string: ")
print(findMinEditDistance(a, b, len(a), len(b)))
