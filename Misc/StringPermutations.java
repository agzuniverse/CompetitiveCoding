/*
Given a string and an integer k, print all combinations of k characters from the string such that the characters are in increasing order.

This solution runs in O(n^k) time
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

class Node {
    public Node left;
    public Node right;
    public int data;

    Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

public class StringPermutations {
    static void printPermutations(char ch[], int k, int depth, String curr) {
        for (int i = 0; i < ch.length; i++) {
            if (depth == k - 1) {
                if (curr.charAt(curr.length() - 1) < ch[i])
                    System.out.println(curr + ch[i]);
            } else {
                if (curr.equals("")) {
                    String temp = curr + ch[i];
                    printPermutations(ch, k, depth + 1, temp);
                }
                if (!curr.equals("") && curr.charAt(curr.length() - 1) < ch[i]) {
                    String temp = curr + ch[i];
                    printPermutations(ch, k, depth + 1, temp);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int k = Integer.parseInt(br.readLine());
        char ch[] = s.toCharArray();
        Arrays.sort(ch);
        String curr = new String("");
        printPermutations(ch, k, 0, curr);
    }
}