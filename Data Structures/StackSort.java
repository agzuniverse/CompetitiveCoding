
/*
Given a stack of integers, sort it. The only data structure you are allowed to use is another stack.
This solution runs in O(n^2) time and O(n) space.
*/

import java.util.*;

public class StackSort {
    public static void main(String args[]) {
        Stack<Integer> stack = new Stack<>();
        Stack<Integer> res = new Stack<>();
        stack.push(1);
        stack.push(3);
        stack.push(6);
        stack.push(5);
        stack.push(9);
        stack.push(8);
        stack.push(7);
        while (!stack.isEmpty()) {
            if (res.isEmpty())
                res.push(stack.pop());
            else {
                while (!stack.isEmpty() && res.peek() >= stack.peek()) {
                    res.push(stack.pop());
                }
                if (!stack.isEmpty()) {
                    int temp = stack.pop();
                    while (!res.isEmpty())
                        stack.push(res.pop());
                    res.push(temp);
                }
            }
        }
        System.out.println(res.toString());
    }
}