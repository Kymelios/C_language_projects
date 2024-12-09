# Trees Implementation in C

File binary_tree.c contains a simple implementation of a tree data structures and algorithms in C. It has such commands:
1. createNode() - Creates a new node with allocated memory for it. It will assign the value to the number field, and sets the **left** and **right** pointers to NULL.

## Printing all nodes values (Tree Traversal).

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

## full_binary_tree.c

In this tree data structre we do the same as we did before, but this time we check if the tree is full.
1. isBinaryTreeFull() - In this function we have to check if there is a root node, then check if each node has 2 children or 0, and if at least one of the nodes does not meet this condition then the tree is considered not to be a full binary tree.

## perfect_binary_tree.c

In this tree data structre we should implement the depth check and the perfect binary tree check.
1. depthCounter() - In this function we find the maximum depth of left and right subtree, then we compare their depths to determine if one is deeper than the other.
2. isBinaryTreePerfect() - In this function, we check if all leaf nodes of the tree are located on the same level. If any of them are at a different level,
then it is not a perfect binary tree.

## complete_binary_tree.c

1. amountOfNodes() - Similar to the depth counter, here we sum up the total number of nodes by recursively adding the counts from left and right subtrees and then adding +1 for the current node to get the exact amout of nodes.
2. isBinaryTreeComplete() -  In this function, we check if the tree fills from left-to-right order. If any node is not located in this order (for example, nodes are placed like 1, 2, 3, and you add another node at position 5 while position 4 is empty), the tree won't be complete because it doesn't follow the left-to-right filling rule.
