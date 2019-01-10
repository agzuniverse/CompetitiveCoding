# In a far away land there lived a king named Suhpesoj. Suhpesoj was a tyrannical ruler who hated his subjects. One day, he had gone off crazier than usual and decide that he wanted one and only one person to live in his kingdom other than himself, while all the others were banished.

# Suhpesoj, however, admired brainy people, and wanted his favorite and most wittiest subject, Julius, to be the one to survive. Fearing an uprising amongst the people if he were to unfairly choose Julius, Suhpesoj devised a game in which everyone could participate and the final person remaining would be victorious. He knew Julius was clever enough to solve this puzzle himself and this would undoubtedly make Julius the only one to survive.

# Suhpesoj gathered his people and told them - “I will place n chairs in front of you in a circle and each of you will have to choose a seat. Then, I will start counting in a circular fashion from chair 1 and of all the people currently sitting down, every k-th person will stand up. This will continue till only one person is sitting down. This person will be banished from my kingdom, and I will keep doing this with one less chair each time in the same order as you first sat down until only one person is remaining and he shall remain in my kingdom”

# Julius, upon hearing this, calculated where he should sit for him to be victorious.

# Where did Julius sit in a circle of n chairs, if every k-th person was chosen in each step?

# Input
# First line will be t, the number of test cases. Following t lines will be each 2 space separated integers denoting n and k

# Output
# Enter the position where Julius should sit, with 1-based indexing.


def f(n, k):
    if n == 1:
        return 0
    if n < k:
        return (f(n-1, k) + k) % n
    m = n - n//k
    return k * ((f(m, k) - n % k) % m) // (k-1)


t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    numb = [i for i in range(1, n+1)]

    while(len(numb) > 1):
        index = f(n, k)
        del numb[index]
        n -= 1
    print(numb[0])
