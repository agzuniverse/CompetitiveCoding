
/*
Given an array of n integers which represent sides of triangles, print 
the 3 sides which can be used to form a non-degenerate triangle with maximum perimeter.

This solution runs in O(nlogn)
The array is sorted in descending order. After this, for every i starting from 0,
if arr[i]<arr[i+1]+arr[i+2], that will be the 3 sides forming the max perimeter.
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class MaximumPerimeter {
    static void maximumPerimeter(int arr[], int n) {
        sortDescending(arr, n);
        for (int i = 0; i < n - 2; i++) {
            if (arr[i] < arr[i + 1] + arr[i + 2]) {
                System.out.println(Integer.toString(arr[i]) + " " + Integer.toString(arr[i + 1]) + " "
                        + Integer.toString(arr[i + 2]));
                return;
            }
        }
        System.out.println("-1");
    }

    static void sortDescending(int arr[], int n) {
        Arrays.sort(arr, 0, n);
        for (int i = 0, j = n - 1; i < n / 2; i++, j--) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    public static void main(String args[]) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter length of array");
        int n = 0;
        try {
            n = Integer.parseInt(br.readLine());
            int arr[] = new int[n];
            String inp[] = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inp[i]);
            }
            maximumPerimeter(arr, n);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}