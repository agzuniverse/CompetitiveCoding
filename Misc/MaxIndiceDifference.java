/*
For a given array, find the maximum value of j-i such that arr[j]>=arr[i]

This solution has a time complexity of O(n).
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class MaxIndiceDifference {

    static int findMaxDiff(int vals[], int n) {
        int minSoFar[] = new int[n];
        int maxSoFar[] = new int[n];
        minSoFar[0] = vals[0];
        for (int i = 1; i < n; i++)
            minSoFar[i] = Math.min(vals[i], minSoFar[i - 1]);
        maxSoFar[n - 1] = vals[n - 1];
        for (int i = n - 2; i >= 0; i--)
            maxSoFar[i] = Math.max(vals[i], maxSoFar[i + 1]);

        int maxDiff = -1;
        int i = 0, j = 0;
        while (i < n && j < n) {
            if (minSoFar[i] < maxSoFar[j]) {
                maxDiff = Math.max(maxDiff, j - i);
                j++;
            } else
                i++;
        }
        return maxDiff;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter number of elements");
        String s = br.readLine();
        int n = Integer.parseInt(s);
        System.out.println("Enter array as space separated integers.");
        s = br.readLine();
        String[] inp = s.split(" ");
        int vals[] = new int[n];
        for (int i = 0; i < n; i++)
            vals[i] = Integer.parseInt(inp[i]);
        System.out.println(findMaxDiff(vals, n));
    }
}

/*
 * Explanation:
 * https://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-
 * that-arrj-arri/
 */