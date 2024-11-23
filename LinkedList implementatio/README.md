Linked List implementation in C

This code implements singly linked list data structure. It has such functions:

1) countNodes() - Simply counts how many nodes in the linked list and their value. Returns **int** amount of nodes.
2) findNodeValue() - Finds a desired value in linked list. It will return a text if the value is not found.
3) createNode() - Creates a new node with allocated memory for it. It will assign the value to the number field, and sets the next pointer to NULL.

Functions (4) and (5) are implemented in (6) but I left it for my personal education.
4) insertNewNodeAtTheBeginning() - Creates a new node at the beginning of list. When you use it, you should update your head by assign function to head.
```
head = insertNewNodeAtTheBeginning(head, 14); //or otherwise, you will lose your new node.
```
5) insertNewNodeAtTheEnd() - Creates a new node at the end of list.
6) insertNewNode() - Creates a new node in user defind location. To insert at the beginning of list, you need to set last value to true and as well as in (4)
assing it to head to update head pointer.
7) deleteNode() - Deletes a node by definding the value of the node. If you delete node at the beginning you as well need to do everything that was said before
about inserting a new node at the beginning.
8) freeList() - Frees all nodes of linked list to prevent memory leaks.
