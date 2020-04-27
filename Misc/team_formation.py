"""
https://www.hackerrank.com/challenges/team-formation/problem
"""

from collections import Counter


def largestSmall(inp):
    d = Counter(inp)
    sizes = []
    for e in inp:
        if d[e] == 0:
            continue
        temp = e
        arr = [temp]
        while(d[temp+1] != 0 and d[temp+1] >= d[temp]):
            arr.append(temp+1)
            temp += 1
        for elem in arr:
            d[elem] -= 1
        sizes.append(len(arr))
    return min(sizes)


t = int(input())
for _ in range(t):
    inp = [int(x) for x in input().split(' ')]
    if inp[0] == 0:
        print(0)
        continue
    inp = sorted(inp[1:])
    print(largestSmall(inp))

"""
The key to the solution is to count the number of occurances of each number.
One should always include the next number in the current array if it's count is greater than or equal to the current number
But should stop when next number's count is lower than the current number (This is the greedy algorithm required).

Example:
1 1 2 2 2 3 3

Arrays are: 1 2, 1 2 3, 2 3 (and length of smallest array is 2 so solution is 2)

First array is 1 2 because count of 2(which is 3) is greater than count of 1(which is 2).
3 is not included because it's count is less than count of 2.

Then the counts are updated and the process is repeated.
"""
