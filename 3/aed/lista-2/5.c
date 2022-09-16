#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

typedef int bool;

typedef struct NODE
{
    int value;
    struct NODE *left;
    struct NODE *right;
} NODE;

typedef struct TREE
{
    NODE *root;
} TREE;

TREE *createTree()
{
    TREE *newTree = (TREE *)malloc(sizeof(TREE));
    newTree->root = NULL;
    return newTree;
}

NODE *createNode(int value)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(TREE *tree, NODE *root, int value)
{
    if (tree->root == NULL)
    {
        NODE *newNode = createNode(value);
        tree->root = newNode;
        return;
    }
    if (value < root->value)
    {
        if (root->left != NULL)
            return insert(tree, root->left, value);
        NODE *newNode = createNode(value);
        root->left = newNode;
    }
    else
    {
        if (root->right != NULL)
            return insert(tree, root->right, value);
        NODE *newNode = createNode(value);
        root->right = newNode;
    }
}

void printAll(NODE *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->value);
    printf("(");
    printAll(root->left);
    printAll(root->right);
    printf(")");
}

int main()
{
    TREE *tree = createTree();
    bool isRunning = true;
    while (isRunning)
    {
        int value;
        scanf("%d", &value);
        if (value != 0)
            insert(tree, tree->root, value);
        else
            isRunning = false;
    }
    printAll(tree->root);
    return 0;
}