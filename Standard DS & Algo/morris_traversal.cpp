/*
Find Kth smallest node in a BST in O(1) space, O(n) time.
*/

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data)
    {
        left = nullptr;
        right = nullptr;
    }
};

void morrisTraversal(Node *root, int k)
{
    if (root == nullptr)
        return;
    Node *curr = root, *temp;
    int count = 0, minElement;
    while (curr != nullptr)
    {
        // If left element is null increment counter (print for normal traversal) and go to right
        if (curr->left == nullptr)
        {
            count++;
            if (count == k)
                minElement = curr->data;
            curr = curr->right;
        }
        else
        {
            // Find the rightmost element of the left subtree
            temp = curr->left;
            while (temp->right != nullptr && temp->right != curr)
                temp = temp->right;
            if (temp->right == nullptr)
            {
                // Connect to inorder successor
                temp->right = curr;
                curr = curr->left;
            }
            else if (temp->right == curr)
            {
                // Restore the tree
                temp->right == nullptr;
                count++;
                if (count == k)
                    minElement = curr->data;
                curr = curr->right;
            }
        }
    }
    cout << minElement << endl;
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right = new Node(70);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    morrisTraversal(root, 3);
}

/*
Explanation:

The solution is to use Morris traversal.
Normal inorder traversal uses O(h) space (where h is tree height) for the recursion stack.
Morris traversal allows inorder and preorder traversal with O(1) space.

Morris traversal works by creating a link from the right most node of the left subtree of a node to the node.
i.e, it creates a link from each node to it's inorder successor.
*/