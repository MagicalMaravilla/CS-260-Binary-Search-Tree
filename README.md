# CS-260-Binary-Search-Tree
will brainstorm, write a few tests, and then attempt code this project based on the information.

Design Phase
Node Structure: Each node in the BST will have three attributes:

value: to store the data value.
left: a reference to the left child node if it exists, or null if there is no left child.
right: a reference to the right child node if it exists, or null if there is no right child.
BST Properties: The BST will maintain the property that for any given node, all values in the left subtree are less than or equal to the node's value, and all values in the right subtree are greater.

Core Functions:

add(value): Inserts a new value into the BST, preserving the BST property. Start from the root and navigate down the tree to find the correct position for the new value.
remove(value): Finds and removes a node with the given value. If the node to be removed has two children, it will be replaced with its in-order successor (the smallest value in its right subtree) or predecessor (the largest value in its left subtree).
find(value): Searches for a value in the BST, returning true if the value exists and false otherwise.
Traversal Functions:

inOrderTraversal(): Visits all nodes in ascending order of value. This is useful for getting a sorted list of all elements in the tree.
preOrderTraversal(): Visits the root node first, then recursively visits the left subtree and the right subtree. Useful for creating a copy of the tree.
postOrderTraversal(): Recursively visits the left subtree and the right subtree before visiting the root node. Useful for deleting the tree.
breadthFirstTraversal(): Visits all nodes at the current depth before moving to the nodes at the next depth level. Useful for level order traversal.
Complexity Analysis: Compare the time complexity of insert and search operations in a BST with those in an unordered binary tree. Generally, for a balanced BST, both operations have a time complexity of O(log n), whereas, for an unordered tree, the complexity can degrade to O(n).


Test Plan
Add Function Tests:

Add values in a manner that requires traversal to both left and right children.
Add values that are equal to existing values to test the handling of duplicates.
Remove Function Tests:

Remove a leaf node (node with no children).
Remove a node with one child.
Remove a node with two children.
Remove a node that doesn't exist.
Traversal Function Tests:

Ensure in-order traversal returns a sorted list of all elements.
Verify pre-order, post-order, and breadth-first traversals return the expected order based on their definitions.
Find Function Test:

Find existing and non-existing values to ensure the function correctly identifies the presence or absence of values.
Complexity Analysis Test:

Measure the time it takes to perform insert and search operations as the tree size increases and compare these times to the theoretical complexities.

