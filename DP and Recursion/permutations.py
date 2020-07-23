"""
Write a program to print all permutations of an array.

An array of N elements will have N! permutations, and hence this algorithm runs in O(n!) time.
"""


def permute(arr, l, n):
    if l == n:
        print(arr)
    for i in range(l, n+1):
        arr[i], arr[l] = arr[l], arr[i]
        permute(arr, l+1, n)
        arr[i], arr[l] = arr[l], arr[i]


arr = [1, 2, 3, 4, 5]
permute(arr, 0, len(arr)-1)
