/* Print top view of a tree */

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    void topView(Node *root)
    {
        map<int, Node *> h;
        queue<pair<Node *, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty())
        {
            pair<Node *, int> e = q.front();
            q.pop();
            if (e.first->left != NULL)
                q.push(make_pair(e.first->left, e.second - 1));
            if (e.first->right != NULL)
                q.push(make_pair(e.first->right, e.second + 1));
            if (!h[e.second])
            {
                h[e.second] = e.first;
            }
        }
        for (auto &i : h)
        {
            cout << i.second->data << " ";
        }
    }
};

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    cin >> t;

    while (t-- > 0)
    {
        cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.topView(root);

    return 0;
}

/* Explanation:
Hash the the node to it's horizontal distance. If a node is already hashed into a distance, do not replace it.

For left and right views, do the same except hash the node using it's vertical distance as the key.
 */