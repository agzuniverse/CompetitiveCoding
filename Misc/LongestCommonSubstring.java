import java.util.ArrayList;
import java.util.Scanner;

public class LongestCommonSubstring {
    static int lengthOfLongestCommonSubstring(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();
        int subs[][] = new int[n + 1][m + 1];
        int res = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0)
                    subs[i][j] = 0;
                else if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    subs[i][j] = subs[i - 1][j - 1] + 1;
                    res = Math.max(subs[i][j], res);
                } else
                    subs[i][j] = 0;
            }
        }
        return res;
    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter 2 strings");
        String s1 = in.nextLine();
        String s2 = in.nextLine();
        System.out.println(lengthOfLongestCommonSubstring(s1, s2));
        in.close();
    }
}