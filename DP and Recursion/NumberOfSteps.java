
/*
A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time.
Implement a method to count how many possible ways the child can run up the stairs.

This solution runs in O(n) time and space
*/

import java.util.Scanner;

public class NumberOfSteps {
    static int steps(int i, int memo[]) {
        if (i == 1)
            return 1;
        if (i == 2)
            return 2;
        if (i == 3)
            return 4;
        if (memo[i] == 0)
            memo[i] = steps(i - 1, memo) + steps(i - 2, memo) + steps(i - 3, memo);
        return memo[i];
    }

    public static void main(String args[]) {
        System.out.println("Enter number of steps");
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        System.out.println(steps(n, new int[n + 1]));
        in.close();
    }
}