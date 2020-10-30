

/*Write a program to find whether a given number is a power of 2 or not.

Input format:
The first line of the input contains the number n for which you have to find whether it is a power of 2 or not.

Output Format:
Print 'YES' or 'NO' accordingly without quotes.

Example:

Input:
32

Output:
YES

Input:
26

Output:
NO

Explanation:
In the first example, 32 is actually  so the answer is YES.
The second number is not a power of 2 hence the answer is NO. */

The Code-

import math
n=int(input())
def log2(n):
  l=math.log10(n)/math.log10(2)
  return(l)
def isPower(n): 
    return (math.ceil(log2(n)) == math.floor(log2(n)))
if(isPower(n)): 
    print("YES", end="")
else: 
    print("NO", end="")