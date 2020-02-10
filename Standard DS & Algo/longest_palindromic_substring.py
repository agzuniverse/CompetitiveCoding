# Given a string, find the longest palindromic substring.
inp = input("Enter string")

maxLen = 0
startIndex = 0
strLen = len(inp)
low = 0
high = 0


def expandString(low, high):
    global startIndex
    global maxLen
    while low >= 0 and high < strLen and inp[low] == inp[high]:
        if high-low+1 > maxLen:
            maxLen = high-low+1
            startIndex = low
        low -= 1
        high += 1


for i in range(1, strLen):
    # Generate all even length substrings around this point until
    # a point is hit where the string is not a palindrome
    low = i-1
    high = i
    expandString(low, high)
    # Do the same, but now for strings of odd length
    low = i-1
    high = i+1
    # Here inp[i] is the center of the palindromic substring currently being considered
    expandString(low, high)

print("Length of longest palindromic substring: ", maxLen)
print("Longest palindromic substring is: ", inp[startIndex:startIndex+maxLen])

# This solution runs in O(n^2) time and O(1) space
# The DP solution takes up O(n^2) space
# The most efficient solution however is the Manacher's algorithm which does it in O(n) time.
