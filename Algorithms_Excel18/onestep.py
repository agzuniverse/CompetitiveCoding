# Pranav has a matrix of size n * m with him. He want to traverse it in a zig zag fashion such that first he'll go one step forward in both x and y directions and then he goes 1 step backward in x direction and 1 step forward in y direction. After this he does the same with 2, 3, ... upto k steps, until he reaches the end of the matrix. Your task in hand is to print the traversal of the matrix.

# Input Format

# You're given two integers n and m denoting the rows and columns of the matrix. The next n lines contains m space separated integers denoting the elements of the matrix.

# Constraints

# 1 <= m,n <= 5000

# 1 <= mat[i][j] <= 10^18

# Output Format

# You're to output x space separated integers denoting the traversal of the matrix.

# Sample Input 0

# 4 4
# 1 2 3 4
# 5 6 7 8
# 9 10 11 12
# 13 14 15 16
# Sample Output 0

# 1 6 9 14

z = input().rstrip().split(' ')
n = int(z[0])
m = int(z[1])
a = []
for i in range(n):
    a.append(input().rstrip().split(' '))
xpos = 0
ypos = 0
print(a[ypos][xpos], end=' ')
try:
    for i in range(int(n/2)):
        xpos += 1
        ypos += 1
        print(a[ypos][xpos], end=' ')
        xpos -= 1
        ypos += 1
        print(a[ypos][xpos], end=' ')
except:
    exit()
