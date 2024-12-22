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

int findValue(struct node *root, int targetValue)
{
    if (root == NULL)
    {
        return 0; //Value was not found! -_-
    }
    if (root->value == targetValue)
    {
        return 1; //Value was found! >w<
    }

    return findValue(root->left, targetValue) || findValue(root->right, targetValue);
}

int main()
{
    struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Was value found? (0 is false, 1 is true) \n--->(%d)\n\n", findValue(root, 1));
    printf("Was value found? (0 is false, 1 is true) \n--->(%d)\n\n", findValue(root, 32));

    printf("Preorder: ");
    preorderPrint(root);

    return 0;
}