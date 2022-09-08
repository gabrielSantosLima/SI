#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int value;
    struct NODE *leftNode;
    struct NODE *rightNode;
} NODE;

typedef struct TREE
{
    int length;
    NODE *root;
} TREE;

TREE *createTree()
{
    TREE *newTree = (TREE *)malloc(sizeof(TREE));
    newTree->length = 0;
    newTree->root = NULL;
    return newTree;
}

NODE *createNode(int value)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->value = value;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;
    return newNode;
}

void insert(TREE *tree, NODE *root, int value)
{
    if (root == NULL)
    {
        NODE *newNode = createNode(value);
        tree->root = newNode;
        tree->length++;
        return;
    }
    if (value < root->value)
    {
        if (root->leftNode != NULL)
            return insert(tree, root->leftNode, value);
        NODE *newNode = createNode(value);
        root->leftNode = newNode;
        tree->length++;
    }
    else if (value >= root->value)
    {
        if (root->rightNode != NULL)
            return insert(tree, root->rightNode, value);
        NODE *newNode = createNode(value);
        root->rightNode = newNode;
        tree->length++;
    }
}

NODE *find(NODE *root, int value)
{
    if (root == NULL)
        return NULL;
    if (root->value == value)
        return root;
    if (value > root->value)
        return find(root->rightNode, value);
    return find(root->leftNode, value);
}

void remove(TREE *tree, NODE *root, int value)
{
    // TODO
}

void printAll(NODE *root)
{
    if (root == NULL)
    {
        printf("empty.\n");
        return;
    }
    printf("> %d\n", root->value);
    printf("=> Left of: %d\n", root->value);
    printAll(root->leftNode);
    printf("=> Right of: %d\n", root->value);
    printAll(root->rightNode);
}

int main()
{
    TREE *tree = createTree();
    insert(tree, tree->root, 15);
    insert(tree, tree->root, 8);
    insert(tree, tree->root, 23);
    insert(tree, tree->root, 2);
    insert(tree, tree->root, 12);
    insert(tree, tree->root, 20);
    insert(tree, tree->root, 30);
    insert(tree, tree->root, 10);
    printAll(tree->root);

    NODE *node = find(tree->root, 10);
    if (node == NULL)
    {
        printf("Valor não foi encontrado");
    }
    else
    {
        printf("Valor foi encontrado.");
    }
    return 0;
}