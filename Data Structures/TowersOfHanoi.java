import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class TowersOfHanoi {
    static void solve(int n, String source, String destination, String buffer) {
        if (n <= 0)
            return; // Base case
        solve(n - 1, source, buffer, destination); // Move the top n-1 disks from source to buffer
        // Move nth disk to destination
        System.out.println("Move disk " + Integer.toString(n) + " from " + source + " to " + destination);
        solve(n - 1, buffer, destination, source); // Move the n-1 disks from buffer to destination
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter number of disks");
        int n = Integer.parseInt(br.readLine());
        solve(n, "1", "3", "2");
    }
}