# Miller Rabin primality test is a probabilistic method of determining primality
# The higher the value of k, more accurate it is
# It runs in O(klog^3(n)) time

import random


def check(a, s, d, n):
    x = pow(a, d, n)
    print("x="+str(x)+" a="+str(a)+" d="+str(d)+" n="+str(n))
    if x == 1:
        return True
    for i in range(s - 1):
        if x == n - 1:
            return True
        x = pow(x, 2, n)
    return x == n - 1


def isPrime(n, k=10):
    if n == 2:
        return True
    if not n & 1:
        return False

    s = 0
    d = n - 1

    while d % 2 == 0:
        d = d // 2
        s += 1

    for i in range(k):
        a = random.randint(2, n - 1)
        if not check(a, s, d, n):
            return False
    return True


n = int(input())
if(isPrime(n)):
    print("is prime")
else:
    print("not prime")
