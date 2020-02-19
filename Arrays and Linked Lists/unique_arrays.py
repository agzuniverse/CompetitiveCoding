# Navaneeth loves playing with arrays, today he is trying to generate an unique array, such that each element occurs exactly twice and distance between the identical elements is equal to the element itself.

# Input Format

# You have an integer n denoting the largest number in the array.

# Constraints

# 1 <= n < 200

# Output Format

# For each test case you're to output the array, if it's possible to generate an array or -1 if it's impossible to generate the unique array

# Sample Input 0

# 3
# Sample Output 0

# 3 1 2 1 3 2

n = int(input())
a = [0]*n*2
fin_ans = 1
for i in range(n, 0, -1):
    c = 0
    flag = 0
    while a[c] != 0 or a[c+i+1] != 0:
        c += 1
        if c+i+1 >= len(a):
            flag = 1
            break
    if flag == 0:
        a[c] = i
        a[c+i+1] = i
    else:
        indices = []
        loc = 0
        flag_swap = 0
        while 0 in a[loc:]:
            indices.append(a.index(0, loc))
            loc = indices[-1]+1
        for k in indices:
            for m in range(len(a)):
                if k+a[m]+1 < len(a) and a[k+a[m]+1] == a[m]:
                    a[k], a[m] = a[m], a[k]
                    flag_swap = 1
                elif k+a[m]+1 > len(a) and a[k-a[m]-1] == a[m]:
                    a[k], a[m] = a[m], a[k]
                    flag_swap = 1
        if flag_swap == 1:
            for o in range(n, 0, -1):
                c = 0
                flag = 0
                while a[c] != 0 or a[c+o+1] != 0:
                    c += 1
                    if c+o+1 >= len(a):
                        flag = 1
                        break
                if flag == 0:
                    a[c] = o
                    a[c+o+1] = o
        else:
            print(-1)
            fin_ans = 0
            break

if fin_ans == 1:
    print(' '.join(str(i) for i in a))
