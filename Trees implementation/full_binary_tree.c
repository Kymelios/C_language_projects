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

int isBinaryTreeFull(struct node* root)
{
    if (root == NULL)
    {
        printf("Tree is empty!\n");
        return 1;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1; //It will return 1 (true) if it doesn't have any childs (leafs) in the node 
    }
    //If node has a left and right children, it will recursively check if both subtrees are full binary trees
    if (root->left && root->right) 
    {
        return isBinaryTreeFull(root->left) && isBinaryTreeFull(root->right);
    }
    
    return 0;
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

int main()
{
    struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    
    printf("Full binary tree? (0 is false, 1 is true) \n--->(%d)\n\n", isBinaryTreeFull(root));

    root->right->right = createNode(7);

    printf("Full binary tree? (0 is false, 1 is true) \n--->(%d)\n\n", isBinaryTreeFull(root));

    printf("Preorder: ");
    preorderPrint(root);

    return 0;
}