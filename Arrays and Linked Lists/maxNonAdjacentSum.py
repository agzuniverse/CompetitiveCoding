"""
Given an array of positive integers, find the maximum sum without adding two adjacent elements.
Solution in O(n) time and O(1) space.
"""


def maxNonAdjacentSum(arr):
    incl = 0  # Max including previous element
    excl = 0  # Max excluding previous element
    for i in arr:
        temp = incl
        incl = excl+i
        excl = max(excl, temp)
    return max(excl, incl)


arr = [5, 5, 10, 100, 10, 5]
print(maxNonAdjacentSum(arr))

"""
Explanation:
From the next element's perspective, the greatest sum including the previous element is
previous element + (greatest sum excluding the previous element) for the previous element.

Again from the perspective of the next element, greatest sum not including the previous element is
the max of incl and excl for the previous element.
"""
