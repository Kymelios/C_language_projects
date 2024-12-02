#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

struct node *createNode(int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/* Also implemented 3 methods to traverse a tree:
1) In the first method (Inorder traversal), we visit all nodes in the left subtree,
   then we visit the root node, and finally, we visit all nodes in the right subtree.

2) In the second method (Preorder traversal), we start with the root node,
   then visit all nodes in the left subtree, and finish by visiting all nodes in the right subtree.

3) In the last method (Postorder traversal), we first visit all nodes in the left subtree,
   then all nodes in the right subtree, and finish by coming back to the root node.
*/

void inorderPrint(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderPrint(root->left);
    printf("%d", root->value);
    inorderPrint(root->right);
}

void preorderPrint(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d", root->value);
    preorderPrint(root->left);
    preorderPrint(root->right);
}

void postorderPrint(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderPrint(root->left);
    postorderPrint(root->right);
    printf("%d", root->value);
}

int main()
{
    struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Inorder: ");
    inorderPrint(root);
    printf("\nPreorder: ");
    preorderPrint(root);
    printf("\nPostorder: ");
    postorderPrint(root);
    printf("\n");

    return 0;
}