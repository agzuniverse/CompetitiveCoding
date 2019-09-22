
/* Given a boolean expression consisting of the operands &, | and ^, find the number of ways it can
be parenthesized such that it evaluates to true.
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class BooleanParenthasization {

    static HashMap<String, HashMap<Boolean, Integer>> h = new HashMap<>();

    static int countWays(String s, boolean bool) {
        if (s.length() == 0)
            return 0;
        if (s.length() == 1) {
            if (s.charAt(0) == '1' && bool == true)
                return 1;
            if (s.charAt(0) == '0' && bool == true)
                return 0;
            if (s.charAt(0) == '1' && bool == false)
                return 0;
            if (s.charAt(0) == '0' && bool == false)
                return 1;
        }
        int ways = 0;
        if (h.containsKey(s) && h.get(s).containsKey(bool))
            return h.get(s).get(bool);
        for (int i = 1; i < s.length(); i += 2) {
            String left = s.substring(0, i);
            String right = s.substring(i + 1);
            int totalWays = (countWays(left, true) + countWays(left, false))
                    * (countWays(right, true) + countWays(right, false));
            int waysToTrue = 0;
            if (s.charAt(i) == '&') {
                waysToTrue = countWays(left, true) * countWays(right, true);
            } else if (s.charAt(i) == '|') {
                waysToTrue = (countWays(left, true) * countWays(right, true))
                        + (countWays(left, false) * countWays(right, true))
                        + (countWays(left, true) * countWays(right, false));
            } else if (s.charAt(i) == '^') {
                waysToTrue = (countWays(left, true) * countWays(right, false))
                        + (countWays(left, false) * countWays(right, true));
            }
            ways += bool ? waysToTrue : totalWays - waysToTrue;
        }
        if (!h.containsKey(s)) {
            HashMap<Boolean, Integer> temp = new HashMap<>();
            temp.put(bool, ways);
            h.put(s, temp);
        } else {
            h.get(s).put(bool, ways);
        }
        return ways;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter boolean string, using only &, | and ^ and with 1 for true and 0 for false.");
        String s = br.readLine();
        int n = countWays(s, true);
        System.out.println(
                "Number of ways the expression can be parenthesized to evaluate to true is:" + Integer.toString(n));
    }
}