'''
Given an array of zeroes and non-zeroes, move all zeroes to the end of the array.
The order of non-zero elements in array must not change.

This must be done in O(n) time and constant space.
'''


def moveZeroes(arr, l):
    counter = 0
    for i in range(l):
        if arr[i] != 0:
            temp = arr[counter]
            arr[counter] = arr[i]
            arr[i] = temp
            counter += 1


inp = [2, 3, 0, 0, 4, 0, 5, 0, 8, 9]  # Example input
l = len(inp)

moveZeroes(inp, l)

print(inp)

'''
Explanation:
Keep a variable called counter that points to the last swappable location.
Initially this is the same as the first index of the array and elements swap with themselves.
When a zero is encountered, counter is not incremented.

So when the next non-zero element is encountered, it swaps to the location pointed to by counter,
which is a zero element, and then counter is incremented.
'''
