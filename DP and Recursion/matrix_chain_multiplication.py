'''
Matrix Chain Multiplication problem

Given the dimensions of the matrix in an array P[0..n], calculate the minimum number of calculations required
to perform the multiplication of the matrices.

This solution runs in O(n^3) time.

The solution uses the fact that matrix multiplication is associative but the number of operations
can differ significantly depending on the order in which the multiplication is performed.
'''

import sys


def matrixChainMultiplication(p, n):
    memo = [[sys.maxsize]*n for _ in range(n)]

    # Cost is 0 when considering one matrix
    for i in range(n):
        memo[i][i] = 0

    # z is the matrix chain length
    for z in range(2, n):
        # i and j are start and end points, with k varying with condition i<=k<j
        for i in range(1, n-z+1):
            j = i+z-1
            for k in range(i, j):
                currMin = memo[i][k] + memo[k+1][j] + p[i-1]*p[k]*p[j]
                memo[i][j] = min(memo[i][j], currMin)

    # The upper triangle elements are filled
    return memo[1][n-1]


# Example input
p = [1, 2, 3, 4]
n = len(p)
print(matrixChainMultiplication(p, n))
