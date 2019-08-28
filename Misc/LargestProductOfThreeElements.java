
/*
Given an array of integers, print the largest possible product using 3 integers from the array
This solution runs in O(n) time.
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class LargestProductOfThreeElements {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter length of the array");
        int n = Integer.parseInt(br.readLine());
        System.out.println("Enter the array as space separated integers");
        String[] vals = br.readLine().split(" ");
        int[] inp = new int[n];
        for (int i = 0; i < n; i++)
            inp[i] = Integer.parseInt(vals[i]);

        int h3 = inp[0] * inp[1] * inp[2], h2 = inp[0] * inp[1], l2 = inp[0] * inp[1], h1 = Math.max(inp[0], inp[1]),
                l1 = Math.min(inp[0], inp[1]);
        for (int i = 2; i < n; i++) {
            h3 = Math.max(Math.max(inp[i] * h2, inp[i] * l2), h3);
            h2 = Math.max(Math.max(inp[i] * h1, inp[i] * l1), h2);
            l2 = Math.min(Math.min(inp[i] * h1, inp[i] * l1), l2);
            h1 = Math.max(h1, inp[i]);
            l1 = Math.min(l1, inp[i]);
        }
        System.out.println(Integer.toString(h3));
    }
}

/*
 * Explanation: Since negative numbers become positive when multiplied with
 * another negative number, we have to keep track of lowest as well as highest
 * single number and product of two numbers. These values are then updated as
 * shown in the loop so h3 is always the highest number.
 */