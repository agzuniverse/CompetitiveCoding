/*
Given a complete binary tree, find the number of nodes in the tree in better than O(n) time.

This answer runs in O(log(n)^2) time.
*/

#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *new_node(int data)
{
    struct Node *temp = new Node();
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

int findLeftHeight(Node *root)
{
    if (root == nullptr)
        return 0;
    return 1 + findLeftHeight(root->left);
}

int findRightHeight(Node *root)
{
    if (root == nullptr)
        return 0;
    return 1 + findRightHeight(root->right);
}

int count(Node *root)
{
    int left = findLeftHeight(root);
    int right = findRightHeight(root);
    if (left == right)
        return (1 << left) - 1;
    return 1 + count(root->left) + count(root->right);
}

int main()
{
    struct Node *root = new_node(10);
    root->left = new_node(8);
    root->left->left = new_node(5);
    root->left->right = new_node(9);
    root->right = new_node(15);
    root->right->left = new_node(13);

    cout << count(root);
}

/*
Explanation:

If left most and rightmost paths have the same height, the tree is complete and number of nodes is 2^height-1.

If not, recurse for left and right subtrees.
Since in complete binary trees only last level is not filled and it is filled left to right, at each recursion
half the tree is discarded.
For each recursion there is a complexity of O(h) to find the height of left and right subtrees.
So total complexity is O(h^2) and since h=log(n), complexity is O(log(n)^2).
*/