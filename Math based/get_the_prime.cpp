// This one could start with a story or ..whatever

// Bruce,Nat and Clint are playing a game, the game of primes. The game is like: In rotational fashion, the two players will write some number on a piece of paper and the third one has to find the positive number that is to be added to the product of other two such that the resulting sum is prime. Bruce and Nat have written the numbers on a piece of paper and its Clint's turn to find the third number. If there are multiple answers possible, print the minimum one. Being a Kind person, Help him out!

// Input Format

// The first line consists of the number of testcases n. Each of the following T lines consists of two numbers A and B.

// Constraints

// n<=40000

// A,B<=40000

// Output Format

// For each test case , print the answer in seperate lines.

// Sample Input 0

// 1
// 2 6
// Sample Output 0

// 1
// Explanation 0

// The product of 2 and 6 is 12. To make the sum prime, we can add 1 to it (It becomes 13 which is a prime).

// Contest ends in 6 days
// Submissions: 1
// Max Score: 30
// Difficulty: Easy
// Rate This Challenge:

#include <bits/stdc++.h>

using namespace std;

bool isPrime(long n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t, count, a, b;
    long prod;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;
        prod = a * b;
        count = 0;
        while (!isPrime(prod + count))
            count++;
        cout << count << endl;
    }
}

// Solution in Python3
// def isprime(n):
//     if(n<=1):
//         return False
//     elif(n<=3):
//         return True
//     elif(n%2==0 or n%3==0):
//         return False

//     i=5
//     while(i*i<=n):
//         if(n%i==0 or n%(i+2)==0):
//             return False
//         i=i+6
//     return True

// a = int(input().rstrip())
// for j in range(a):
//     count = 0
//     x = [int(x) for x in input().rstrip().split()]
//     prod = x[0]*x[1]
//     while(isprime(prod+count) is not True):
//         count=count+1
//     print(count)