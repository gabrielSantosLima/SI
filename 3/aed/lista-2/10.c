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

void insertTreeWithMaxHeight(TREE *tree)
{
    int index = 1;
    for (index = 1; index <= 17; index++)
        insertNode(tree, tree->root, index);
}

void insertTreeWithMinHeight(TREE *tree, int start, int end)
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    int middle = (start + end) / 2;
    if (start > end)
        return;
    insertNode(tree, tree->root, numbers[middle]);
    insertTreeWithMinHeight(tree, start, middle - 1);
    insertTreeWithMinHeight(tree, middle + 1, end);
}

void printAll(NODE *root, int level)
{
    if (root == NULL)
        return;

    for (int index = 0; index < level; index++)
        printf("   ");
    printf("%d\n", root->value);
    printAll(root->left, level + 1);
    printAll(root->right, level + 1);
}

int main()
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    TREE *treeMinHeight = createTree();
    TREE *treeMaxHeight = createTree();

    insertTreeWithMaxHeight(treeMaxHeight);
    insertTreeWithMinHeight(treeMinHeight, 0, 16);

    printf("MAX HEIGHT: ");
    printAll(treeMaxHeight->root, 0);
    printf("\n");
    printf("MIN HEIGHT: ");
    printf("\n");
    printAll(treeMinHeight->root, 0);
    return 0;
}