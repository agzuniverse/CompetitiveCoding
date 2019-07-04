import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;

/*
 * Given an array of positive or negative integer elements and a sum value, find
 * the number of contiguous subarrays that add up to that value.
 */

//Helper class for reading inputs faster
class FastScanner {
    BufferedReader br;
    StringTokenizer st;

    FastScanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }
}

public class SubarraysWithSum {
    public static void main(String args[]) {
        FastScanner in = new FastScanner();
        ArrayList<Integer> inp = new ArrayList<>();
        int n = in.nextInt(); // Number of elements in the array
        for (int i = 0; i < n; i++)
            inp.add(in.nextInt());
        int sum = in.nextInt(); // The value contiguous subarrays should add up to

        int currSum = 0;
        int ans = 0;
        HashMap<Integer, Integer> hm = new HashMap<>();
        for (int i : inp) {
            currSum += i;
            if (currSum == sum)
                ans++;
            ans += hm.getOrDefault(currSum - sum, 0);
            hm.put(currSum, hm.getOrDefault(currSum, 0) + 1);
        }
        System.out.println(ans);

        /*
         * Explanation: The cumulative sum is calculated at each stage and the number of
         * times a cumulative sum appears is recorded in a hash table. If the curent
         * cumulative sum is equal to the required sum, result is incremented. Then
         * result is incremented by the number of times current sum - required sum
         * appears in the hash table. This runs in O(n) time.
         */
    }
}