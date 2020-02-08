# Count the maximum sum of subsequence of an array consisting only of non-adjacent elements.
# This solution runs in O(n) time and constant space.

arr = [2, 4, 6, 2, 5]  # Sample input

incl = 0  # Maximum sum including the current element
excl = 0  # Maximum sum excluding the current element

for i in arr:
    temp = max(incl, excl)
    if i > 0:
        # Max sum including the current element is equal to current element + max sum excluding the previous element when current element is not negative
        incl = excl+i
    # Max sum exluding the current element is max of max sum including and max sum excluding the previous element.
    excl = temp

print(max(incl, excl))
