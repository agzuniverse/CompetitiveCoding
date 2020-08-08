"""
Segment Tree

Make a segment tree to perform sum of a range and update a given element operations on an array in O(logn) time.
It takes O(n) time to construct the tree from given input array. Further operations are all O(logn).
"""

import math


def getMiddleElement(start, end):
    return (end-start)//2 + start


def updateValue(st, start, end, changedIndex, si, change):
    # If the current range is outside the changedIndex
    if changedIndex < start or changedIndex > end:
        return
    # If the current range includes the changedIndex
    st[si] += change
    if start != end:
        mid = getMiddleElement(start, end)
        updateValue(st, start, mid, changedIndex, 2*si+1, change)
        updateValue(st, mid+1, end, changedIndex, 2*si+2, change)


def getSum(st, start, end, rangeStart, rangeEnd, si):
    # If current segment of the array is outside the range we want
    if start > rangeEnd or end < rangeStart:
        return 0
    # If current segment is within given range, return sum of the segment
    if start >= rangeStart and end <= rangeEnd:
        return st[si]

    mid = getMiddleElement(start, end)
    return getSum(st, start, mid, rangeStart, rangeEnd, 2*si+1)+getSum(st, mid+1, end, rangeStart, rangeEnd, 2*si+2)

# Start and end indices correspond to the main array,
# si is the index in the array representing the ST


def constructST(inp, start, end, st, si):
    if start == end:
        st[si] = inp[start]
        return inp[start]
    mid = getMiddleElement(start, end)
    st[si] = constructST(inp, start, mid, st, 2*si+1) + \
        constructST(inp, mid+1, end, st, 2*si+2)
    return st[si]


def main():
    inp = [1, 3, 5, 7, 9, 11]

    # Size of ST is 2*(smallest power of 2 greater than len(inp)) - 1
    size = 2*(2**(int(math.ceil(math.log2(len(inp))))))-1

    st = [0]*size
    constructST(inp, 0, len(inp)-1, st, 0)
    print(st)

    # Get sum of values in a range
    print(getSum(st, 0, len(inp)-1, 1, 3, 0))

    # Update a value
    temp = inp[1]
    inp[1] = 10
    # This change has to be added to every node representing a segment of which inp[1] is a part of
    change = inp[1]-temp
    updateValue(st, 0, len(inp)-1, 1, 0, change)

    # Updated sum of the same range
    print(getSum(st, 0, len(inp)-1, 1, 3, 0))


main()
