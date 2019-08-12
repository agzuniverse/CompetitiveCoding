
/* Print the number of trailing zeroes in the factorial of a number */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class TrailingFactorialZeroes {
    static void printTrailingZeroesInFactorial(int a) {
        int count = 0;
        for (int i = 5; a / i > 0; i *= 5)
            count += a / i;
        System.out.println(count);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter number");
        int a = Integer.parseInt(br.readLine());
        printTrailingZeroesInFactorial(a);
    }
    /*
     * Explanation: One trailing zero is present for every pair of multiple of 5 and
     * 2. Since multiples of 2 is always greater than multiples of 5, we just have
     * to count multiples of 5. 25 counts as 2 multiples of 5, 125 as 3 multiples
     * etc
     */
}