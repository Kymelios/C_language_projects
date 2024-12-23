#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

//This function creates a new node and allocate memory for it
struct node *createNode(int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

//This functions prints tree in preorder traversal
void preorderPrint(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("-%d-", root->value);
    preorderPrint(root->left);
    preorderPrint(root->right);
}

//This function calculates a height of the tree
int treeHeight(struct node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    
    int result = ((leftHeight > rightHeight) ? leftHeight : rightHeight) + 1;
    return result;
}

//This function calculates real amount of nodes in tree
int amountOfNodes(struct  node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftNodes = amountOfNodes(root->left);
    int rightNodes = amountOfNodes(root->right);

    return (leftNodes + rightNodes) + 1;
}

//This function finds a needed value in the tree
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

    printf("Tree height: %d\n", treeHeight(root));
    printf("Amount of nodes: %d\n", amountOfNodes(root));

    printf("Preorder: ");
    preorderPrint(root);

    return 0;
}
