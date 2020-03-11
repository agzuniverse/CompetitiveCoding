'''
The KMP Algorithm for pattern matching

More efficient than Rabin Karp algorithm because it has a worst case of O(n+m)
compared to Rabin Karip algorithm's worst case of O((n+m)*n). But KMP algorithm
does require O(m) extra space.

n is the length of the haystack and m is the length of the needle.

KMP algorithm works by constructing an auxillary "LPS" array and using it to
avoid matching characters that we already know will match.
'''


def KMPsearch(haystack, needle):
    n = len(haystack)
    m = len(needle)
    lps = [0]*m
    computeLPSarray(needle, lps, m)
    i = 0
    j = 0
    while i < n:
        if i < n and haystack[i] == needle[j]:
            i += 1
            j += 1
        if j == m:
            print("Pattern found at index " + str(i-j))
            j = lps[j-1]

        elif i < n and haystack[i] != needle[j]:
            # Use the LPS array to skip matching the characters we already know will match
            if j != 0:
                j = lps[j-1]
            else:
                i += 1

# For each character needle[0..i] find the longest prefix that is also a suffix


def computeLPSarray(needle, lps, m):
    lps[0] = 0  # For a single character there can be no proper prefix
    currLen = 0  # Length of the previous longest proper prefix that is also a suffix
    i = 1
    while i < m:
        if needle[i] == needle[currLen]:
            currLen += 1
            lps[i] = currLen
            i += 1
        else:
            if currLen != 0:
                currLen = lps[currLen-1]
            else:
                lps[i] = 0
                i += 1


# Example inputs
haystack = "ABABDABACDABABCABABABCABAB"
needle = "ABABCABAB"
KMPsearch(haystack, needle)
