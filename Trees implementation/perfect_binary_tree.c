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

int depthCounter(struct node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftMaxHeight = depthCounter(root->left);
    int rightMaxHeight = depthCounter(root->right);

    return ((leftMaxHeight > rightMaxHeight) ? leftMaxHeight : rightMaxHeight) + 1;
}

int isBinaryTreePerfect(struct node* root, int depth, int layer)
{
    if (root == NULL)
    {
        return 1;
    }

    /*A little bit of debugging, just printing the depth and current layer
    for better understanding how this function works >w<*/
    printf("INFO: depth: %d --- layer: %d\n", depth, layer + 1); 
    
    if (root->left == NULL && root->right == NULL)
    {
        return depth == layer + 1; //Checking if left and right leafs are on the same level
    }

    if (root->left == NULL || root->right == NULL)
    {
        return 0; // The tree is imperfect because this node has only one child
    }
    
    return (isBinaryTreePerfect(root->left, depth, layer + 1) && 
            isBinaryTreePerfect(root->right, depth, layer + 1));
}

void preorderPrint(struct node* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d", root->value);
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main()
{
    struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Perfect binary tree? (0 is false, 1 is true) \n--->(%d)\n\n", isBinaryTreePerfect(root, depthCounter(root), 0));
    root->left->left->left = createNode(8);
    printf("Perfect binary tree? (0 is false, 1 is true) \n--->(%d)\n\n", isBinaryTreePerfect(root, depthCounter(root), 0));

    printf("Preorder: ");
    preorderPrint(root);

    return 0;
}