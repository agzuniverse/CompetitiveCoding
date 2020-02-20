
/* Given two nodes in a binary tree, find the lowest common ancestor using constant space.*/
import java.io.IOException;
import java.util.ArrayList;

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

class LowestCommonAncestor {

    public static Node findCommonAncestor(Node root, int n1, int n2) {
        if (root == null)
            return null;
        if (root.data == n1 || root.data == n2)
            return root;
        Node fromLeftSubtree = findCommonAncestor(root.left, n1, n2);
        Node fromRightSubtree = findCommonAncestor(root.right, n1, n2);
        if (fromLeftSubtree != null && fromRightSubtree != null)
            return root;
        if (fromLeftSubtree != null)
            return fromLeftSubtree;
        return fromRightSubtree;
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);

        Node result = findCommonAncestor(root, 4, 5);
        System.out.println(result.data);
    }
}

/*
 * Explanation:
 * 
 * While traversing, if a node we need is found, return that node.
 * 
 * If not, check for the node in the left and right subtrees. If one node is
 * found in left subtree and the other on the right subtree, the node we are
 * currently on is the lowest common ancestor, so return this node.
 * 
 * Else, return what is returned by whichever subtree that has returned a
 * non-null value. If both subtrees have returned null, return null.
 */

/*
 * Old solution that uses O(n) space: Save paths to both the nodes in 2 separate
 * arrays, then compare the arrays to find the first common node.
 * 
 * 
 * public class LowestCommonAncestor {
 * 
 * static ArrayList<Integer> path1 = new ArrayList<>(); static
 * ArrayList<Integer> path2 = new ArrayList<>();
 * 
 * static boolean findPathToA(Node root, int a) { if (root == null) return
 * false; if (root.data == a) { path1.add(root.data); return true; } if
 * (findPathToA(root.left, a)) { path1.add(root.data); return true; } if
 * (findPathToA(root.right, a)) { path1.add(root.data); return true; } return
 * false; }
 * 
 * static boolean findPathToB(Node root, int a) { if (root == null) return
 * false; if (root.data == a) { path2.add(root.data); return true; } if
 * (findPathToB(root.left, a)) { path2.add(root.data); return true; } if
 * (findPathToB(root.right, a)) { path2.add(root.data); return true; } return
 * false; }
 * 
 * static int findCommonAncestor(Node root, int a, int b) { findPathToA(root,
 * a); findPathToB(root, b); int i = path1.size() - 1; int j = path2.size() - 1;
 * int lca = -1; while (i >= 0 && j >= 0) { if (path1.get(i) == path2.get(j))
 * lca = path1.get(i); else break; i--; j--; } return lca; }
 * 
 * public static void main(String[] args) throws IOException { Node root = new
 * Node(1); root.left = new Node(2); root.right = new Node(3); root.left.left =
 * new Node(4); root.left.right = new Node(5); root.right.left = new Node(6);
 * root.right.right = new Node(7);
 * 
 * System.out.println(findCommonAncestor(root, 4, 2)); } }
 */