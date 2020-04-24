'''
Spiral traversal of a binary tree

Use two stacks to keep track of alternating levels.

This solution runs in O(n) time and O(n) extra space.
'''


class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def spiralTraversal(root):
    # Two stacks
    s1 = []
    s2 = []

    s1.append(root)

    while(len(s1) > 0 or len(s2) > 0):
        while(len(s1) > 0):
            node = s1.pop()
            print(node.data, end=",")
            if node.right:
                s2.append(node.right)
            if node.left:
                s2.append(node.left)
        while(len(s2) > 0):
            node = s2.pop()
            print(node.data, end=",")
            if node.left:
                s1.append(node.left)
            if node.right:
                s1.append(node.right)


# Example input
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(7)
root.left.right = Node(6)
root.right.left = Node(5)
root.right.right = Node(4)
spiralTraversal(root)
