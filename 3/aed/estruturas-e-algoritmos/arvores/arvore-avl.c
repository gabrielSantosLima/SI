#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1
#define DEFAULT_BF 3

typedef int bool;

typedef struct NODE
{
    int value;
    int balanceFactor;
    struct NODE *left;
    struct NODE *right;
} NODE;

typedef struct TREE
{
    NODE *root;
} TREE;

NODE *createNode(int value)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->value = value;
    newNode->balanceFactor = DEFAULT_BF;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TREE *createTree()
{
    TREE *newTree = (TREE *)malloc(sizeof(TREE));
    newTree->root = NULL;
    return newTree;
}

bool isPositive(int number)
{
    return number >= 0;
}

bool isNegative(int number)
{
    return number < 0;
}

int heightOf(NODE *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    int heightOfLeft = heightOf(root->left);
    int heightOfRight = heightOf(root->right);
    if (heightOfLeft > heightOfRight)
        return 1 + heightOfLeft;
    return 1 + heightOfRight;
}

int balanceFactorOf(NODE *root)
{
    if (root == NULL || root->left == NULL && root->right == NULL)
        return 0;
    return heightOf(root->right) - heightOf(root->left);
}

void calculateBalanceFactor(NODE *root)
{
    if (root == NULL)
        return;
    root->balanceFactor = balanceFactorOf(root);
    calculateBalanceFactor(root->left);
    calculateBalanceFactor(root->right);
}

bool isUnbalanced(NODE *root)
{
    if (root == NULL)
        return false;
    if (root->balanceFactor == 2 || root->balanceFactor == -2)
        return true;
    if (isUnbalanced(root->left) || isUnbalanced(root->right))
        return true;
    return false;
}

NODE *findFirstAncestral(NODE *root, NODE **ancestral)
{
    if (root == NULL)
        return NULL;
    if (root->balanceFactor == DEFAULT_BF)
        return root;
    if (root->balanceFactor != 0)
        *ancestral = root;
    NODE *left = findFirstAncestral(root->left, ancestral);
    if (left != NULL)
        return left;
    NODE *right = findFirstAncestral(root->right, ancestral);
    return right;
}

void rotateLeft(NODE *a, NODE *b)
{
    int aValue = a->value;
    a->value = b->value;
    b->value = aValue;

    a->right = b->right;
    b->right = b->left;
    b->left = a->left;
    a->left = b;
}

void rotateRight(NODE *a, NODE *b)
{
    int aValue = a->value;
    a->value = b->value;
    b->value = aValue;

    a->left = b->left;
    b->left = b->right;
    b->right = a->right;
    a->right = b;
}

void rebalanceAfterInsert(TREE *tree)
{
    NODE *a = NULL;
    NODE *node = findFirstAncestral(tree->root, &a);
    calculateBalanceFactor(tree->root);
    if (!isUnbalanced(tree->root))
        return;
    NODE *b = a->left;
    if (node->value >= a->value)
        b = a->right;

    if (isPositive(a->balanceFactor) && isPositive(b->balanceFactor))
    {
        // Rotação simples para a esquerda
        rotateLeft(a, b);
    }
    else if (isNegative(a->balanceFactor) && isNegative(b->balanceFactor))
    {
        // Rotação simples para a direita
        rotateRight(a, b);
    }
    else if (isPositive(a->balanceFactor) && isNegative(b->balanceFactor))
    {
        NODE *c = b->left;
        if (node->value >= b->value)
            c = b->right;
        // Rotação dupla para a esquerda
        rotateRight(b, c);
        rotateLeft(a, b);
    }
    else if (isNegative(a->balanceFactor) && isPositive(b->balanceFactor))
    {
        NODE *c = b->left;
        if (node->value >= b->value)
            c = b->right;
        // Rotação dupla para a direita
        rotateLeft(b, c);
        rotateRight(a, b);
    }
    calculateBalanceFactor(tree->root);
}

void insert(TREE *tree, NODE *root, int value)
{
    if (tree->root == NULL)
    {
        NODE *node = createNode(value);
        tree->root = node;
        calculateBalanceFactor(tree->root);
        return;
    }
    if (value < root->value)
    {
        if (root->left != NULL)
            return insert(tree, root->left, value);
        NODE *node = createNode(value);
        root->left = node;
    }
    else
    {
        if (root->right != NULL)
            return insert(tree, root->right, value);
        NODE *node = createNode(value);
        root->right = node;
    }
    rebalanceAfterInsert(tree);
}

void printAll(NODE *root, int level)
{
    if (root == NULL)
        return;
    for (int index = 0; index < level; index++)
        printf("  ");
    printf("%d [bf=%d]\n", root->value, root->balanceFactor);
    printAll(root->left, level + 1);
    printAll(root->right, level + 1);
}

NODE *findNodeWithParent(NODE *root, int value, NODE **parent)
{
    if (root == NULL)
        return NULL;
    *parent = NULL;
    while (root != NULL)
    {
        if (value == root->value)
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
    node = findNodeWithParent(tree->root, value, &parent);
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
        calculateBalanceFactor(tree->root);
        return;
    }

    if (value < parent->value)
        parent->left = substituteNode;
    else
        parent->right = substituteNode;
    free(node);
    calculateBalanceFactor(tree->root);
}

void rebalanceAfterRemoveNode(TREE *tree)
{
    while (isUnbalanced(tree->root))
    {
        NODE *a = NULL;
        NODE *b = NULL;
        NODE *node = NULL; // Elemento que foi removido

        // Buscar primeiro ancestral com BF diferente de 0 e seu filho (no sentido inverso do elemento que foi removido)

        if (isPositive(a->balanceFactor) && isPositive(b->balanceFactor))
            rotateLeft(a, b);
        else if (isNegative(a->balanceFactor) && isNegative(b->balanceFactor))
            rotateRight(a, b);
        else if (isPositive(a->balanceFactor) && isNegative(b->balanceFactor))
        {
            NODE *c = b->left;
            if (node->value >= b->value)
                c = b->right;
            rotateRight(b, c);
            rotateLeft(a, b);
        }
        else if (isNegative(a->balanceFactor) && isPositive(b->balanceFactor))
        {
            NODE *c = b->left;
            if (node->value >= b->value)
                c = b->right;
            rotateLeft(b, c);
            rotateRight(a, b);
        }
        calculateBalanceFactor(tree->root);
    }
}

int main()
{
    TREE *tree = createTree();
    insert(tree, tree->root, 10);
    insert(tree, tree->root, 20);
    insert(tree, tree->root, 15);
    insert(tree, tree->root, 60);
    insert(tree, tree->root, 50);
    insert(tree, tree->root, 5);
    insert(tree, tree->root, 3);
    insert(tree, tree->root, 4);
    insert(tree, tree->root, 82);
    insert(tree, tree->root, 100);
    insert(tree, tree->root, 115);
    insert(tree, tree->root, 111);
    insert(tree, tree->root, 99);
    insert(tree, tree->root, 30);
    insert(tree, tree->root, 90);
    removeNode(tree, 10);
    printAll(tree->root, 0);
    return 0;
}