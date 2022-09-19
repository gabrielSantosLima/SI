#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

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
    newNode->right = NULL;
    newNode->left = NULL;
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
        return;
    }
    if (root->right != NULL)
        return insertNode(tree, root->right, value);
    NODE *newNode = createNode(value);
    root->right = newNode;
}

void printAll(NODE *root)
{
    if (root == NULL)
        return;
    printf("%d (", root->value);
    printAll(root->left);
    printAll(root->right);
    printf(")");
}

bool isValid(NODE *root)
{
    if (root == NULL)
        return true;
    if ((root->left && root->value < root->left->value) ||
        (root->right && root->value > root->right->value))
        return false;
    if (!isValid(root->left) || !isValid(root->right))
        return false;
    return true;
}

int main()
{
    TREE *tree = createTree();
    insertNode(tree, tree->root, 9);
    insertNode(tree, tree->root, 3);
    insertNode(tree, tree->root, 13);
    insertNode(tree, tree->root, 11);
    insertNode(tree, tree->root, 14);
    insertNode(tree, tree->root, 1);
    insertNode(tree, tree->root, 10);
    insertNode(tree, tree->root, 12);
    printAll(tree->root);

    bool valid = isValid(tree->root);
    if (valid)
        printf("\nÁrvore é válida.");
    else
        printf("\nÁrvore não é válida.");
    return 0;
}