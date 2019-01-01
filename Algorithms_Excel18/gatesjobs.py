# Gates and Jobs are fierce rivals. Gates want to release a newer version of Windows titled Windows X where X is a string. Jobs argues that he has the copyright for the brand name Y which is a substring of X and Gates cannot use it.

# Gates has already issued printing orders for the name X. So he decides to replace some characters with $ such that Y is no more a substring of X. Your task in hand is to find the minimum no: of characters that he should replace ?

# Input Format

# First line contains the string X.
# The second line contains the substring Y.
# Constraints

# 1 <= len(X) <= 5 * 10^5
# 1 <= len(Y) <= 50
# Output Format

# You're to print the minimum no: of characters that he should replace

# Sample Input 0

# abcabcabczabcabcabcz
# cab
# Sample Output 0

# 4

x = input()
y = input()
x.split(y)
print(x.split(y))
