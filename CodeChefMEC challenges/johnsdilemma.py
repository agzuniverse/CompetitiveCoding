# [ Problem by Kuriakose Eldho, CS-5A ]

# John is a travel blogger making a trip around the globe. He has a bad habit of keeping all his travel pics in a single huge folder on his computer. All the pictures are named with consecutive numbers starting with 1.

# One day he discovers that some of his pictures from Egypt have gone corrupt. After further inspection it is found that only the images with a perfect square for a name have gone corrupt. If the pictures from Egypt start from  and end with , then help John count how many of his travel pictures have gone corrupt.

# Input Format

# First line will be , the number of test cases. Each line that follows is a test case with two integers  and separated by a space.

# Constraints

# Output Format

# Output exactly  lines, each a single integer which is the result of each test case.

# Sample Input 0

# 2
# 1 100
# 300 401
# Sample Output 0

# 10
# 3

n = int(input().rstrip())
for i in range(n):
    a = [int(x) for x in input().rstrip().split(' ')]
    counter = 0
    # lower = int(a[0]**0.5)+1
    # lower = 1 if lower == 2 else lower
    lower = 1
    while(lower**2 < a[0]):
        lower += 1
    while(lower**2 <= a[1]):
        counter += 1
        lower += 1
    print(counter)
