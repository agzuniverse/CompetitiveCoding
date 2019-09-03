/*
Check if a binary tree is balanced.

For a binary tree to be balanced, it must have:
- Balanced left subtree
- Balanced right subtree
- Difference in height between left and right subtree 1 or 0
*/

class Node {
    int data;
    Node left = null, right = null;

    Node(int data) {
        this.data = data;
    }
}

public class CheckBinTreeBalanced {

    static int findHeight(Node root) {
        if (root == null)
            return 0;
        return findHeight(root.left) + findHeight(root.right) + 1;
    }

    static boolean isBalanced(Node root) {
        if (root == null)
            return true;
        boolean leftBalanced = isBalanced(root.left);
        boolean rightBalanced = isBalanced(root.right);
        int leftHeight = findHeight(root.left);
        int rightHeight = findHeight(root.right);
        return leftBalanced && rightBalanced && (Math.abs(leftHeight - rightHeight) <= 1);

    }

    public static void main(String[] args) {
        Node root = null;

        root = new Node(15);
        root.left = new Node(10);
        root.right = new Node(20);
        root.left.left = new Node(8);
        root.left.right = new Node(12);
        root.right.left = new Node(16);
        root.right.right = new Node(25);
        boolean res = isBalanced(root);
        if (res)
            System.out.println("Tree is balanced");
        else
            System.out.println("Tree is not balanced");
    }
}