#include <stdio.h>
#include <stdlib.h>

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

void insertNode(TREE *tree, NODE *root, int value)
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
            return insertNode(tree, root->left, value);
        NODE *newNode = createNode(value);
        root->left = newNode;
    }
    else
    {
        if (root->right != NULL)
            return insertNode(tree, root->right, value);
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

int getLastElementInPreOrder(NODE *root)
{
    if (root == NULL)
        return -1;
    if (root->right == NULL)
        return root->value;
    return getLastElementInPreOrder(root->right);
}

int main()
{
    TREE *tree = createTree();
    insertNode(tree, tree->root, 10);
    insertNode(tree, tree->root, 3);
    insertNode(tree, tree->root, 23);
    insertNode(tree, tree->root, 27);
    insertNode(tree, tree->root, 7);
    insertNode(tree, tree->root, 1);
    insertNode(tree, tree->root, 9);
    insertNode(tree, tree->root, 99);
    insertNode(tree, tree->root, 109);
    printAll(tree->root);
    printf("\nLAST: %d", getLastElementInPreOrder(tree->root));
    return 0;
}