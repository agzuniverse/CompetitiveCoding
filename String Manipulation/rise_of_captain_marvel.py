# So we all saw Nick Fury sending that message to Captain Marvel.To be sure he has encrypted it in a special way.

# “Hello” is encrypted as “Idnjr”

# “Avengers” is encrypted as “Bugljbvo”

# “Bucky” is encrypted as “Cteib”

# Your mission is to find how it is encrypted and decipher the message.

# Input Format

# No of inputs i

# String 1

# String 2

# ……………..

# String i

# Constraints

# 1 < i < 10^6

# Output Format

# Decrypted message 1

# Decrypted message 2

# …………………………………..

# Decrypted message i

# Sample Input 0

# 2
# Avengers
# Assemble
# Sample Output 0

# Bugljbvo
# Brucpypa
# Explanation 0

# Come on..You are smart enough to figure it out.

n = int(input())
reflower = list(
    'abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz')
refupper = list(
    'ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ')
for i in range(n):
    s = list(input().rstrip())
    counter = 1
    result = ''
    for c in s:
        if(c.isupper()):
            result = result + refupper[refupper[26:52].index(c)+counter]
        else:
            result = result + reflower[reflower[26:52].index(c)+counter]
        if(counter > 0):
            counter = counter*-1
        else:
            counter = counter*-1+1
    print(result)
