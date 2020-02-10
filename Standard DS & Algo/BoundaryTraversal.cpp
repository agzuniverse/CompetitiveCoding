/* Print the boundary traversal of a binary tree */

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void printLeftBoundary(Node *n)
{
    if (n == NULL)
        return;
    if (n->left)
    {
        cout << n->data << " ";
        printLeftBoundary(n->left);
    }
    else if (n->right)
    {
        cout << n->data << " ";
        printLeftBoundary(n->right);
    }
}

void printRightBoundary(Node *n)
{
    if (n == NULL)
        return;
    if (n->right)
    {
        printRightBoundary(n->right);
        cout << n->data << " ";
    }
    else if (n->left)
    {
        printRightBoundary(n->left);
        cout << n->data << " ";
    }
}

void printLeaves(Node *n)
{
    if (n == NULL)
        return;
    printLeaves(n->left);
    if (n->right == NULL && n->left == NULL)
        cout << n->data << " ";
    printLeaves(n->right);
}

void printBoundary(Node *n)
{
    if (n == NULL)
        return;
    cout << n->data << " ";
    printLeftBoundary(n->left);
    printLeaves(n->left);
    printLeaves(n->right);
    printRightBoundary(n->right);
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
    root->right->right = new Node(25);

    printBoundary(root);
}

/*
Print the root node data
Then print left subtree except leaf nodes top to bottom
Then print left subtree leaf nodes left to right
Then print right subtree leaf nodes left to right
Then print right subtree bottom to top
*/