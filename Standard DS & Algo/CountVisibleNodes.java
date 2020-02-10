/* Count all visible nodes in a binary tree.
A node is said to be visible if it has the greatest value from the path from root to that node.

This implementation uses DFS to traverse the tree keeping track of the maximum value seen for each path and returning the count required.
Time complexity is O(n).
*/
class Node {
    public Node left;
    public Node right;
    public int data;

    Node(int data) {
        this.data = data;
    }
}

public class CountVisibleNodes {
    static int dfs(Node root, int max) {
        if (root == null)
            return 0;
        if (root.data > max) {
            max = root.data;
            return dfs(root.left, max) + dfs(root.right, max) + 1;
        }
        return dfs(root.left, max) + dfs(root.right, max);
    }

    public static void main(String[] args) {
        Node root = new Node(5);
        root.left = new Node(3);
        root.right = new Node(10);
        root.left.left = new Node(20);
        root.left.right = new Node(21);
        root.right.left = new Node(1);

        System.out.println(Integer.toString(dfs(root, 0)));
    }
}