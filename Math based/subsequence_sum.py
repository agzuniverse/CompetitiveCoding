"""
Given a very large integer, find the sum of all of it's subsequences.
Print the answer modulo 10^9+7

For eg: input=123
1+2+3+12+13+23+123 = 177 is the answer
"""

mod = 1000000007

# Modular exponentiation function, same as Python's built in mod(x,y,p)
def power(x,y):
    ans = 1
    while(y):
        if y&1 == 1:
            ans = (ans*x)%mod
        x=(x*x)%mod
        y = y>>1
    return ans

def solve(s):
    res=0
    n = len(s)
    for i in range(n):
        res += pow(2,i,mod)*pow(11,n-i-1,mod)*int(s[i])%mod
    return res%mod

s=input()
print(solve(s))

"""
Explanation
For a number 'abc', the solution is sum of
100*a + 10*b + c
10*b + c
10*a + b
10*a + c
a
b
c

Which is
121*a  +  22*b + 4*c
And these numbers can be calculated as
2^0 * 11^2 * a  =  121 a
2^1 * 11^1 * b =   22 b
2^2 * 11^ 0 * c= 4 c

So for a general case, for the ith digit in a number with n digits,
the factor to multiply that digit will be given by (i starts from 0)
2^i * 11^(n-i-1) * digit
"""