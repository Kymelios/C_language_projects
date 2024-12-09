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

int amountOfNodes(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftMaxHeight = amountOfNodes(root->left);
    int rightMaxHeight = amountOfNodes(root->right);

    return leftMaxHeight + rightMaxHeight + 1;
}

int isBinaryTreeComplete(struct node *root, int index, int amountOfNodes)
{
    if (root == NULL)
    {
        return 1;
    }

    if (index >= amountOfNodes)
    {
        printf("ERROR: Current index: %d, Total nodes: %d\n", index, amountOfNodes);
        return 0;
    }

    return isBinaryTreeComplete(root->left, 2 * index + 1, amountOfNodes) 
        && isBinaryTreeComplete(root->right, 2 * index + 2, amountOfNodes);
}

int main()
{
    struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);

    printf("Complete binary tree (0 is false, 1 is true) \n--->(%d)\n\n", isBinaryTreeComplete(root, 0, amountOfNodes(root)));

    root->left->left->left = createNode(5);

    printf("Complete binary tree (0 is false, 1 is true) \n--->(%d)\n\n", isBinaryTreeComplete(root, 0, amountOfNodes(root)));

    return 0;
}