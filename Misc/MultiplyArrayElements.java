import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/*
  Given an array, create an array where the value of each indice is the product of all elements of the input array except that index.
  Division cannot be used, and the solution must be in O(n)
*/

public class MultiplyArrayElements {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter number of elements in the array");
        int n = Integer.parseInt(br.readLine());
        System.out.println("Enter the array as space separated integers");
        String[] vals = br.readLine().split(" ");
        int[] arr = new int[n];
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(vals[i]);
        }
        int temp = 1;
        Arrays.fill(ans, 1);
        for (int i = 0; i < n; i++) {
            ans[i] *= temp;
            temp *= arr[i];
        }
        temp = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= temp;
            temp *= arr[i];
        }
        for (int i : ans)
            System.out.print(Integer.toString(i) + " ");
    }
}

/*
 * Explanation: Multiply all elements to the left of an element in one loop,
 * multiply all elements to the right of an element in another loop.
 */