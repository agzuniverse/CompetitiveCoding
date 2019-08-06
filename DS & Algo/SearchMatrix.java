import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
Given a MxN matrix where each row and column is sorted in ascending order, create a function to 
find a given element within the matrix.

Time complexity of this solution is O(n) as we are eliminating a whole row or column with each step.
*/

class SearchMatrix {
    static void searchMat(int mat[][], int e, int M, int N) {
        int col = N - 1;
        int row = 0;
        while (col >= 0 && row < M) {
            if (mat[row][col] == e) {
                System.out.println("Element found at " + Integer.toString(row + 1) + "," + Integer.toString(col + 1));
                return;
            }
            if (mat[row][col] > e)
                col--;
            if (mat[row][col] < e)
                row++;
        }
        System.out.println("Not found");
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter M and N followed by N space separated elements M times.");
        int M = Integer.parseInt(br.readLine());
        int N = Integer.parseInt(br.readLine());
        int mat[][] = new int[M][N];
        for (int i = 0; i < M; i++) {
            String inp[] = br.readLine().split(" ");
            for (int j = 0; j < inp.length; j++) {
                mat[i][j] = Integer.parseInt(inp[j]);
            }
        }
        System.out.println("Enter element to search");
        int e = Integer.parseInt(br.readLine());
        searchMat(mat, e, M, N);

    }
}