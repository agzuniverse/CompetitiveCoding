'''
The Burst Balloons Problem

Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums.
You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons.

This solution runs in O(n^3) time using bottom-up dynamic programming
'''


def burstBalloons(nums):
    # Add a [1] to left and right so there is no need to treat the extreme left and right balloons as special cases
    # Also remove all balloons with 0 value because popping them does not give any value regardless of when it is popped
    nums = [1]+[x for x in nums if x > 0]+[1]
    n = len(nums)

    memo = [[0]*n for _ in range(n)]

    # Length is the length of subarray to consider
    for length in range(1, n-1):
        for left in range(0, n-1-length):
            # Left is the left end of subarray being considered
            # Right is right end of subarray being considered
            right = left+length+1
            # Now burst each balloon between left and right and see which gives max value
            for i in range(left+1, right):
                memo[left][right] = max(
                    memo[left][right], nums[left]*nums[i]*nums[right]+memo[left][i]+memo[i][right])

    return memo[0][n-1]


# Example input
inp = [3, 1, 5, 8]
print(burstBalloons(inp))
