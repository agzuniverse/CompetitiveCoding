# Peter is back at Queens..(Oh..please don't ask me how he got out of the snap.Just wait for "The Endgame"). Bored ,he came up with an infinite sequence consisting of bits. The sequence is constructed in the following way: It begins with zero and then the following steps are repeated infinitely: 1)copy the entire sequence by replacing every zero with one and vice versa. 2) append the copy to original sequence. The first few iterations would result in the following sequences. 01, 0110, 01101001, 0110100110010110 Being the coder you are, help Harry to find an easy way to answer the following question, how many one's are present in the sequence between L and U inclusive?

# Input Format

# The first line of input contains the lower bound L and second line contains the upper bound U, both of them integers.

# Constraints

# L and U will be between 0 and 10^7, inclusive, L<=U

# Output Format

# One line of output displaying the number of one's between the inputted lower and upper bound

# Sample Input 0

# 5
# 15
# Sample Output 0

# 5
# Explanation 0

# The interval [5, 15] covers the digits 01101[00110010110]1001011001101001. This subsequence contains 5 ones, so the correct answer is 5.

l = int(input().rstrip())
u = int(input().rstrip())

a = [0]

while(len(a) < u):
    b = a.copy()
    for i in range(len(b)):
        if(b[i] == 0):
            b[i] = 1
        else:
            b[i] = 0
    a = a+b

count = 0
for i in a[l:u+1]:
    if(a[i] == 1):
        count = count+1
print(count)
