#include <iostream>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data) : data{data}, left{nullptr}, right{nullptr} {}
};

void preorder(Node *root)
{
    if (!root)
        return;
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

void preorderIterative(Node *root)
{
    // Print node, then push right and left children onto stack.
    // Push right first so the left child is accessed first when popping from the stack.
    if (!root)
        return;
    stack<Node *> s;
    s.push(root);
    Node *temp;
    while (!s.empty())
    {
        temp = s.top();
        cout << temp->data;
        s.pop();
        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

void inorderIterative(Node *root)
{
    // As long as root is not null, push root onto the stack and set root as it's left child.
    // once root becomes null, pop the top element from the stack, print it, and set root as it's right child.
    // then the internal loop will push that onto the stack (if it's not null) and continue the process.

    // The breaking condition of the outer loop also requires checking if root is not null, because after it reaches the point where the
    // tree's actual root element is printed, the stack is empty but there can be a right node for that element.
    if (!root)
        return;
    stack<Node *> s;
    Node *temp;
    do
    {
        do
        {
            if (root)
            {
                s.push(root);
                root = root->left;
            }
        } while (root);
        temp = s.top();
        s.pop();
        cout << temp->data;
        root = temp->right;
    } while (!s.empty() || root);
}

void postorder(Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

void postorderIterative(Node *root)
{
    if (!root)
        return;
    stack<Node *> s;
    Node *temp;
    do
    {
        // Push each element's right node first, then that element itself is pushed.
        // Then go to the left node.
        while (root)
        {
            if (root->right)
                s.push(root->right);
            s.push(root);
            root = root->left;
        }
        // If the 2nd element in the stack is the right child of the 1st element,
        // take the 2nd element out and set it as root.
        temp = s.top();
        s.pop();
        if (!s.empty() && temp->right == s.top())
        {
            root = s.top();
            s.pop();
            s.push(temp);
        }
        // If the 2nd element in the stack is not the right child of the 1st element, print the 1st element.

        // This is done because after printing the left and right subtrees of a node that is now on the top of the stack,
        // the 2nd element of the stack will not be that node's right child (since we have already printed it) so we know to print
        // that node directly.
        else
            cout << temp->data;

    } while (!s.empty());
}

int main()
{
    /*

5
| \
4    1
|\   /
| \ 7
3  2

*/
    Node *root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(1);
    root->right->left = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(2);

    cout << "Preorder recursive: ";
    preorder(root);
    cout << "\nPreorder iterative: ";
    preorderIterative(root);
    cout << "\nInorder recursive: ";
    inorder(root);
    cout << "\nInorder iterative: ";
    inorderIterative(root);
    cout << "\nPostorder recursive: ";
    postorder(root);
    cout << "\nPostorder iterative: ";
    postorderIterative(root);
}
