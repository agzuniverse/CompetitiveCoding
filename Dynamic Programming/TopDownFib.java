
/*
Implementation to find nth fibonacci number using top-down dynamic programming.
Note that this has a higher space use than the traditional bottom-up approach ( O(n) vs O(1) ).
The time complexity is O(n).
*/

import java.util.Scanner;

public class TopDownFib {
    static int fib(int n, int memo[]) {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else if (memo[n] == 0)
            memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
        return memo[n];
    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        System.out.println(fib(n, new int[n + 1]));
        in.close();
    }
}