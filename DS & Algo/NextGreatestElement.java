/*
Next greatest element is defined as the next element on the right of an element in an array that is greater than that element.
Given an array, print all their next greatest elements. If none is present, print -1.

This is a solution that runs in O(n) time using a stack.
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class NextGreatestElement {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter number of elements in the array");
        int n = Integer.parseInt(br.readLine());
        System.out.println("Enter the array");
        int arr[] = new int[n];
        String elems[] = br.readLine().split(" ");
        for (int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(elems[i]);

        Stack<Integer> s = new Stack<>();
        s.push(arr[0]);
        for (int i = 1; i < n; i++) {
            while (!s.empty() && s.peek() < arr[i]) {
                System.out.print(Integer.toString(s.pop()) + " -> " + Integer.toString(arr[i]) + "\n");
            }
            s.push(arr[i]);
        }
        while (!s.empty())
            System.out.print(Integer.toString(s.pop()) + " -> -1\n");
    }
}