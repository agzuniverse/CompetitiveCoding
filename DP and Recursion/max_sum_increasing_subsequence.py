"""
Maximum sum increasing subsequence
Assume all elements in the array are positive.
"""


def maxSumSequence(arr):
    maxsum = [0]*len(arr)
    for i, v in enumerate(arr):
        maxsum[i] = v

    for i in range(1, len(maxsum)):
        for j in range(i):
            if arr[j] < arr[i] and maxsum[i] < maxsum[j]+arr[i]:
                maxsum[i] = maxsum[j]+arr[i]
    return max(maxsum)


arr = [1, 101, 2, 3, 100, 4, 5]
print(maxSumSequence(arr))
