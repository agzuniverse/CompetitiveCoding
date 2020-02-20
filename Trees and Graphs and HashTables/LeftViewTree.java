import java.util.HashMap;

/*
Given a binary tree, print it's left view.
*/

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

class LeftViewTree {
    public static HashMap<Integer, Boolean> hm = new HashMap<>();

    public static void leftView(Node root, int level) {
        if (root == null)
            return;
        if (!hm.getOrDefault(level, false)) {
            System.out.println(root.data);
            hm.put(level, true);
        }
        leftView(root.left, level + 1);
        leftView(root.right, level + 1);
    }

    public static void main(String[] args) {
        // Sample Tree
        Node root = new Node(12);
        root.left = new Node(10);
        root.right = new Node(30);
        root.right.left = new Node(25);
        root.right.right = new Node(40);

        leftView(root, 0);
    }
}

/*
 * Explanation:
 * 
 * Do a DFS traversal. Print the first nodes at each level. The HashMap is used
 * to store if a node has been printed for a given level or not.
 * 
 * For Right view, do DFS but go to the right child first then the left child.
 */