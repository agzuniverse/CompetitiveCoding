/*
Knapsack problem: There is a knapsack that has max weight capacity W.
We are given n items with a values and weight associated with it.
Find the maximum value of items that we can put into the knapsack without exceeding it's weight limit
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Knapsack {

    static int optimalKnapsack(int n, int vals[], int weights[], int w) {
        int k[][] = new int[n + 1][w + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= w; j++) {
                if (i == 0 || j == 0)
                    k[i][j] = 0;
                else if (weights[i - 1] > j)
                    k[i][j] = k[i - 1][j];
                else
                    k[i][j] = Math.max(vals[i - 1] + k[i - 1][j - weights[i - 1]], k[i - 1][j]);
            }
        }
        return k[n][w];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter number of items");
        String s = br.readLine();
        int n = Integer.parseInt(s);
        System.out.println("Enter array of values of items as space-separated integers");
        s = br.readLine();
        String[] inp = s.split(" ");
        int vals[] = new int[n];
        for (int i = 0; i < n; i++)
            vals[i] = Integer.parseInt(inp[i]);
        System.out.println("Enter array of weights of items as space-separated integers");
        s = br.readLine();
        inp = s.split(" ");
        int weights[] = new int[n];
        for (int i = 0; i < n; i++)
            weights[i] = Integer.parseInt(inp[i]);
        System.out.println("Enter maximum weight capacity of knapsack");
        s = br.readLine();
        int w = Integer.parseInt(s);
        System.out.println("Maximum knapsack value is:" + Integer.toString(optimalKnapsack(n, vals, weights, w)));
    }
}

/*
 * Explanation: For each element, find the maximum value that can be obtained
 * including that element (weight left is reduced by weight of that element) and
 * the maximum value that can be obtained by not including that element, and
 * take the greater of the two. Normal recursive solution runs in O(2^n) time,
 * here we optimize it to O(nw) using dynamic programming.
 */