/*
Question: Given a parent array of all nodes in a binary tree (that is guaranteed to be a valid binary tree),
Create the tree. Node with value 0 is created initially as root node.
*/

import java.util.HashMap;

class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class Solution {

    static void createTree(Node root, int n, int parent[]) {
        // Store the nodes created so far in a hashmap
        HashMap<Integer, Node> hm = new HashMap<>();
        hm.put(0, root);

        for (int i = 0; i < parent.length; i++) {
            Node curr = hm.get(parent[i]);
            Node temp = new Node(i + 1);
            if (curr.left == null)
                curr.left = temp;
            else
                curr.right = temp;
            hm.put(i + 1, temp);
        }

    }

    static void preorder(Node root) {
        if (root == null)
            return;
        System.out.print(Integer.toString(root.data) + " ");
        preorder(root.left);
        preorder(root.right);
    }

    public static void main(String[] args) {
        // Sample input
        int n = 6;
        // The value of parent of node with value (i+1) is parent[i]
        int parent[] = { 0, 0, 1, 2, 3, 1 };

        // Create a root node with value 0
        Node root = new Node(0);
        createTree(root, n, parent);

        // Preorder traversal
        preorder(root);
    }
}