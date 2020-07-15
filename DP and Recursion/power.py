"""
Implement power(x,y) function that runs in O(logn) time
"""


def power(x, y):
    if y == 0:
        return 1
    temp = power(x, y//2)
    if y & 1 == 0:
        return temp*temp  # If y is even
    return x*temp*temp   # If y is odd


print(power(2, 10))
print(power(3, 9))
