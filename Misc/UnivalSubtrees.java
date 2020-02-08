/*
Given a binary tree, print the number of unival subtrees.

Unival tree is a tree whose root element, right subtree and left subtree all hold the same value.
*/

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

public class UnivalSubtrees {
    public static void main(String[] args) {
        Node root = new Node(0);
        root.left = new Node(1);
        root.right = new Node(0);
        root.right.left = new Node(1);
        root.right.right = new Node(0);
        root.right.left.left = new Node(1);
        root.right.left.right = new Node(1);
        count=0;
        countUnivalTrees(root);
        System.out.println(count);
    }

    static int count;

    public static boolean countUnivalTrees(Node root) {
        if (root.left == null && root.right == null){
            count++;
            return true;
        }
        if (countUnivalTrees(root.left) && countUnivalTrees(root.right) && root.left.data == root.data && root.right.data == root.data){
            count++;
            return true;
        }
        return false;
    }
}