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

NODE *findNodeAndParent(NODE *root, int value, NODE **parent)
{
    parent = NULL;
    while (root != NULL)
    {
        if (root->value == value)
            return root;
        *parent = root;
        if (value < root->value)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

void removeNode(TREE *tree, int value)
{
    NODE *node = NULL, *parent = NULL, *substituteNode = NULL, *substituteNodeParent = NULL;
    node = findNodeAndParent(tree->root, value, &parent);
    if (node == NULL)
        return;
    if (node->left == NULL || node->right == NULL)
    {
        if (node->left == NULL)
            substituteNode = node->right;
        else if (node->right == NULL)
            substituteNode = node->left;
    }
    else
    {
        substituteNodeParent = node;
        substituteNode = node->left;
        while (substituteNode->right != NULL)
        {
            substituteNodeParent = substituteNode;
            substituteNode = substituteNode->right;
        }
        if (substituteNodeParent != node)
        {
            substituteNodeParent->right = substituteNode->left;
            substituteNode->left = node->left;
        }
        substituteNode->right = node->right;
    }

    if (parent == NULL)
    {
        tree->root = substituteNode;
        free(node);
        return;
    }

    if (value < parent->value)
        parent->left = substituteNode;
    else
        parent->right = substituteNode;
    free(node);
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

int main()
{
    TREE *tree = createTree();
    insertNode(tree, tree->root, 20);
    insertNode(tree, tree->root, 25);
    insertNode(tree, tree->root, 10);
    insertNode(tree, tree->root, 5);
    insertNode(tree, tree->root, 12);
    insertNode(tree, tree->root, 22);
    insertNode(tree, tree->root, 23);
    printAll(tree->root);

    /*
        Árvore:
        20
            10E
                5E
                12D
            25D
                22E
                    23D
        Como nó substituto, podemos escolher o elemento mais a
            - Direita na sub-árvore da esquerda;
            - Esquerda na sub-árvore da direita.

        Neste caso, podem ser os elementos 12 ou 22. No código
        substituímos pelo elemento mais a direita na sub-árvore
        da esquerda.
    */

    printf("\nRemovendo 20: \n");
    removeNode(tree, 20);
    printAll(tree->root);
    return 0;
}