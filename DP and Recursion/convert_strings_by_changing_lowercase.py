'''
Given two strings a and b, where b is in all uppercase and length of a greater than b,
Check if a can be converted to b by using the following operations only:
1) Convert a lowercase character in a to it's uppercase
2) Delete a lowercase character in a
'''


def abbreviation(a, b):
    n = len(a)
    m = len(b)
    memo = [[False]*(m+1) for _ in range(n+1)]

    # When both strings are empty it is true
    memo[0][0] = True

    # When b is empty, we can remove all leading characters of a as long as they are lowercase.
    # Hence, set these to true
    for i in range(n):
        if a[i].islower():
            memo[i+1][0] = True
        else:
            break

    for i in range(1, n+1):
        for j in range(1, m+1):
            if a[i-1] == b[j-1]:
                memo[i][j] = memo[i-1][j-1]
            # If conversion to uppercase is a match, we can either convert, or we can delete.
            elif a[i-1].islower and a[i-1].upper() == b[j-1]:
                memo[i][j] = memo[i-1][j-1] or memo[i-1][j]
            # If it is lowercase and conversion is not a match, we can only delete
            elif a[i-1].islower():
                memo[i][j] = memo[i-1][j]

    if memo[n][m]:
        return "YES"
    return "NO"


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        a = input()

        b = input()

        result = abbreviation(a, b)

        fptr.write(result + '\n')

    fptr.close()
