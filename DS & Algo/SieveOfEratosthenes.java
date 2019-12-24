zimport java.util.ArrayList;
import java.util.Scanner;

public class SieveOfEratosthenes {
    static ArrayList<Integer> generatePrimes(int max) {
        boolean flags[] = new boolean[max + 1];
        flags[0] = false;
        flags[1] = false;
        for (int i = 2; i <= max; i++)
            flags[i] = true;
        int curr = 2;
        while (curr < Math.sqrt(max)) {
            if (flags[curr])
                for (int i = curr * curr; i <= max; i += curr)
                    flags[i] = false;
            curr++;
        }
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i <= max; i++)
            if (flags[i])
                ans.add(i);
        return ans;
    }

    public static void main(String args[]) {
        System.out.println("Enter limit till which to generate primes");
        Scanner in = new Scanner(System.in);
        int max = in.nextInt();
        ArrayList<Integer> primes = generatePrimes(max);
        System.out.println(primes.toString());
    }
}