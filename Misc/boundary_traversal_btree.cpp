// Print boundary traversal of a binary tree in the anticlockwise direction

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->right = temp->left = NULL;
    return temp;
}

void printLeftBoundary(struct node *root)
{
    if (root)
    {
        if (root->left)
        {
            cout << root->data << " ";
            printLeftBoundary(root->left);
        }
        else if (root->right)
        {
            cout << root->data << " ";
            printLeftBoundary(root->right);
        }
    }
}

void printRightBoundary(struct node *root)
{
    if (root)
    {
        if (root->right)
        {
            printRightBoundary(root->right);
            cout << root->data << " ";
        }
        else if (root->left)
        {
            printRightBoundary(root->right);
            cout << root->data << " ";
        }
    }
}

void printLeaves(struct node *root)
{
    if (root)
    {
        printLeaves(root->left);
        if (root->left == NULL && root->right == NULL)
            cout << root->data << " ";
        printLeaves(root->right);
    }
}

void printBoundaryTraversal(struct node *root)
{
    cout << root->data << " ";
    printLeftBoundary(root->left);
    printLeaves(root);
    printRightBoundary(root->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    // Sample binary tree for testing this code
    struct node *root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
    // Expected output is 20 8 4 10 14 25 22 for this tree

    printBoundaryTraversal(root);
}