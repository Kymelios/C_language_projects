Trees Implementation in C

File binary_tree.c contains a simple implementation of a tree data structures and algorithms in C. It has such commands:
1. createNode() - Creates a new node with allocated memory for it. It will assign the value to the number field, and sets the **left** and **right** pointers to NULL.
##Printing all nodes values (Tree Traversal).
2. inorderPrint():
   - Visit all nodes in the left subtree.
   - Visit the root node.
   - Visit all nodes in the right subtree.
3. preorderPrint():
   - Visit the root node first.
   - Visit all nodes in the left subtree.
   - Finish by visiting all nodes in the right subtree.
4. postorderPrint():
   - Visit all nodes in the left subtree.
   - Visit all nodes in the right subtree.
   - Finish by visiting the root node.
