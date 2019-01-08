# When Scott Lang escaped from the Quantum Realm and reached his home , Cassie was playing (Let's hope she has not turned to dust).And she wanted Scott to play with him too. Well the game is simple. He has to compare few words character by character, and count how many times the characters in a given position are the same. You are given i Strings and you have to return an integer K indicating the score (as defined above) of how closely the two match.

# Input Format

# First line of input contains an integer i denoting the number of Strings.Remaining lines contain the respective Strings.

# Constraints

# 1 < i < 50

# Output Format

# Output should be a single line with an integer containing the no of matching cases

# Sample Input 0

# 2
# Tick
# Tock
# Sample Output 0

# 3
# Explanation 0

# The letters in the words match at position 0,2 and 3.Hence no of matching cases is 3.

n = int(input().rstrip())
x = []
smallest = -1
for j in range(n):
    z = input().rstrip()
    x.append(z)
    if(smallest == -1):
        smallest = len(z)
    elif(len(z) < smallest):
        smallest = len(z)

score = 0
for i in range(smallest):
    flag = True
    for k in range(n):
        if(x[k][i] != x[0][i]):
            flag = False
            break
    if(flag):
        score = score+1

print(score)
