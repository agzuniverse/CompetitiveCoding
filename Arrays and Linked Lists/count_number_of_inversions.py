'''
Count the number of inversions in an array faster than O(n^2) time.

An inversion exists when there is a arr[i]>arr[j] with i<j

This solution runs in O(nlogn) time and O(n) space using mergesort.
'''


def mergesort(arr, l, u):
    if l >= u:
        return
    mid = (l+u)//2
    mergesort(arr, l, mid)
    mergesort(arr, mid+1, u)
    mergeWithInversionsCount(arr, l, mid, u)


def mergeWithInversionsCount(arr, l, mid, u):
    global inversions
    temp = []
    lower = l
    upper = mid+1
    while lower <= mid and upper <= u:
        if arr[lower] <= arr[upper]:
            temp.append(arr[lower])
            lower += 1
        else:
            temp.append(arr[upper])
            # The number of inversions is equal to number of elements left in the left array when we pick element from right array
            inversions += mid-lower+1
            print(inversions)
            upper += 1
    while lower <= mid:
        temp.append(arr[lower])
        lower += 1
    while upper <= u:
        temp.append(arr[upper])
        upper += 1
    for e in temp:
        arr[l] = e
        l += 1


# Sample input
arr = [5, 4, 3, 2, 1]
inversions = 0
mergesort(arr, 0, len(arr)-1)
print(inversions)
