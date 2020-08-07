/*
Convert a binary tree with n elements into a circular doubly linked list using no extra space and O(n) time
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

// Given the heads of two circular linked lists, concatenate right to the end of left and return left
struct Node *concatenate(struct Node *left, struct Node *right)
{
    if (left == nullptr)
        return right;
    if (right == nullptr)
        return left;

    struct Node *leftLast = left->left;
    struct Node *rightLast = right->left;

    leftLast->right = right;
    right->left = leftLast;

    left->left = rightLast;
    rightLast->right = left;

    return left;
}

struct Node *convertToLL(struct Node *root)
{
    if (root == nullptr)
        return nullptr;
    struct Node *left = convertToLL(root->left);
    struct Node *right = convertToLL(root->right);

    // Convert root node into a circular linked list by making left and right point to itself
    root->left = root->right = root;

    // This determines if the order of elements in the linked list is in inorder, postorder or preorder.
    // Here it is left->root->right, so it is inorder
    return concatenate(concatenate(left, root), right);
}

int main()
{
    struct Node *root = new_node(10);
    root->left = new_node(8);
    root->left->left = new_node(5);
    root->left->right = new_node(9);
    root->right = new_node(15);
    root->right->left = new_node(13);

    Node *head = convertToLL(root);

    // Print the linked list
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->right;
    } while (temp != head);
}