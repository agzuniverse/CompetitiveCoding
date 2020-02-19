# Kurian likes to play with numbers. He takes some integer number y, writes it down on the board, and then performs with it n−1 operations of the two kinds:

# Divide the number y by 3 (y must be divisible by 3) Multiply the number y by 2.

# You are given an array of n numbers, your task in hand is to rearrange these numbers such that it fits into the two operations of the game.

# Input Format

# The input contains an integer n, denoting the size of the array and n space separated integers denoting the elements of the array on a new line.

# Constraints

# 2 ≤ n ≤ 150

# 1 ≤ arr[i] ≤ 2*10^18

# Output Format

# You're to print the rearranged array.

# Sample Input 0

# 6
# 4 8 6 3 12 9
# Sample Output 0

# 9 3 6 12 4 8

n = int(input())
a = input().rstrip().split(' ')
b = [a[0]]
a.remove(a[0])


def insert():
    for e in a:
        l = int(e)
        x = int(b[-1])
        y = int(b[0])
        if x / 3 == l or x*2 == l:
            b.append(e)
            a.remove(e)
            insert()
        elif l / 3 == y or l*2 == y:
            b.insert(0, e)
            a.remove(e)
            insert()


insert()

print(' '.join(b))
