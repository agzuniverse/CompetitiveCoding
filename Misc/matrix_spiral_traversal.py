"""
Given a Matrix print it's clockwise spiral traversal
"""


def spiralTraversal(mat):
    n = len(mat)  # No. of rows
    m = len(mat[0])  # No. of columns
    nIsOdd = n & 1
    mIsOdd = m & 1  # Required because the stopping condition is different for even/odd number of rows/columns
    i = 0  # Current row being printed
    j = 0  # Current column being printed

    while ((nIsOdd and n-i >= 0) or (not nIsOdd and n-i > 1)) and ((mIsOdd and m-j >= 0) or (not mIsOdd and m-j > 1)):
        # Print top row left to right
        for k in range(j, m):
            print(mat[i][k])
        i += 1
        # Print right column top to bottom
        for k in range(i, n):
            print(mat[k][m-1])
        m -= 1
        # Print bottom row right to left
        for k in range(m-1, j-1, -1):
            print(mat[n-1][k])
        n -= 1
        # Print left column bottom to top
        for k in range(n-1, i-1, -1):
            print(mat[k][j])
        j += 1


# mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
mat = [[1,  2,  3,  4,  5],
       [6,  7,  8,  9,  10],
       [11, 12, 13, 14, 15],
       [16, 17, 18, 19, 20]]
spiralTraversal(mat)
"""
Explanation:
Alternate between printing rows and columns while reducing n and m and increasing i and j
"""
