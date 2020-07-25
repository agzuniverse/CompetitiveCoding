"""
Given 2 input strings, print the longest common subsequence.

Done in O(n^2) time.
"""

a = "AGGTAB"
b = "GXTXAXB"

n = len(a)
m = len(b)

dp = [[0]*(m+1) for _ in range(n+1)]

for i in range(n+1):
    for j in range(m+1):
        if i == 0 or j == 0:
            dp[i][j] = 0
            continue
        if a[i-1] == b[j-1]:
            dp[i][j] = 1+dp[i-1][j-1]
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])
print("Length of longest common subsequence: ", dp[n][m])

i = n
j = m
ans = ""
while i > 0 and j > 0:
    if a[i-1] == b[j-1]:
        ans += a[i-1]
        i -= 1
        j -= 1
        continue
    if dp[i-1][j] > dp[i][j-1]:
        i -= 1
    else:
        j -= 1
print("Longest common subsequence is: ", ans[::-1])
