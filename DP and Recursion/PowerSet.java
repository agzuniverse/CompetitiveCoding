
/*
Given an input set, print the powerset.

This solution works by cloning all the existing subsets, adding the next element to all those subsets, and adding them back to the powerset.
The base case is an empty set. Solution can be implemeneted recursively or iteratively.
This is a bottom-up recursive approach.
Time complexity is O(n2^n) for an input set of length n.
This is the best possible runtime because We have to go through n elements, and the powerset will have 2^n subsets.

Another approach is to take the number 2^n in binary form, and iterate from 0 to that number.
For each iteration, the elements from the original set having index = the positions in the binary number that have 1s
can be put together into one subset. This also runs in O(n2^n) time.
*/

import java.util.ArrayList;
import java.util.Scanner;

public class PowerSet {
    static ArrayList<ArrayList<Integer>> powerSet(ArrayList<Integer> set, int index) {
        ArrayList<ArrayList<Integer>> subsets;
        if (set.size() == index) {
            // Base case, adding empty subset
            subsets = new ArrayList<ArrayList<Integer>>();
            subsets.add(new ArrayList<Integer>());
            return subsets;
        }
        subsets = powerSet(set, index + 1);
        Integer elem = set.get(index);
        ArrayList<ArrayList<Integer>> newSubsets = new ArrayList<ArrayList<Integer>>();
        for (ArrayList<Integer> subset : subsets) {
            ArrayList<Integer> newSubset = new ArrayList<>();
            newSubset.addAll(subset);
            newSubset.add(elem);
            newSubsets.add(newSubset);
        }
        subsets.addAll(newSubsets);
        return subsets;
    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter number of elements");
        int n = in.nextInt();
        System.out.println("Enter the elements");
        ArrayList<Integer> set = new ArrayList<>();
        for (int i = 0; i < n; i++)
            set.add(in.nextInt());
        System.out.println(powerSet(set, 0));
        in.close();
    }
}