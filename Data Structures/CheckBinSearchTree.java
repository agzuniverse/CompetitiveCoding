/*
Check if a given binary tree is a binary search tree.
*/

class TreeNode {
    int data;
    TreeNode left;
    TreeNode right;

    TreeNode(int data) {
        this.data = data;
    }
}

public class CheckBinSearchTree {

    /*
     * For a BST, every element to the left of a node should be between -infinity
     * and node.data every node on the right should be between node.data and
     * +infinity.
     * 
     * This solution assumes the data is integer values, and in case of equal value
     * to a node, it can be inserted to the left of the node.
     */
    static boolean checkBST(TreeNode n, int min, int max) {
        if (n == null)
            return true;
        if (n.data >= min && n.data < max)
            return checkBST(n.left, min, n.data) && checkBST(n.right, n.data, max);
        else
            return false;
    }

    public static void main(String args[]) {
        TreeNode root = new TreeNode(5);
        root.left = new TreeNode(3);
        root.right = new TreeNode(7);
        root.left.right = new TreeNode(4);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(9);
        root.right.right.left = new TreeNode(8);

        boolean res = checkBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
        System.out.println(Boolean.toString(res));
    }
}