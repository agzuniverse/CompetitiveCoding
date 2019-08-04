import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
 * Given two sorted arrays A and B such that A has enough space left to hold B,
 * Merge B into A.
 * 
 * The below solution compares largest elements of A and B first to avoid
 * shifting of elements of A. Solution runs in O(n) time.
 */

class MergeSortedArrays {
    public static void mergeStrings(int A[], int B[], int lenA, int lenB) {
        int indexA = lenA - 1;
        int indexB = lenB - 1;
        int totalIndex = lenA + lenB - 1;
        while (indexB >= 0) {
            if (indexA >= 0 && A[indexA] > B[indexB]) {
                A[totalIndex] = A[indexA];
                indexA--;
            } else {
                A[totalIndex] = B[indexB];
                indexB--;
            }
            totalIndex--;
        }
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter length of array A and B followed by the arrays");
        int lenA = Integer.parseInt(br.readLine());
        int lenB = Integer.parseInt(br.readLine());
        int A[] = new int[lenA + lenB];
        int B[] = new int[lenB];
        String inp[] = br.readLine().split(" ");
        for (int i = 0; i < lenA; i++) {
            A[i] = Integer.parseInt(inp[i]);
        }
        String inp2[] = br.readLine().split(" ");
        for (int i = 0; i < lenB; i++) {
            B[i] = Integer.parseInt(inp2[i]);
        }
        mergeStrings(A, B, lenA, lenB);
        for (int i = 0; i < lenA + lenB; i++) {
            System.out.println(A[i]);
        }
    }
}