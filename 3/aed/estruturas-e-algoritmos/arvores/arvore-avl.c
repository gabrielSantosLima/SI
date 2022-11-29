#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

typedef int bool;

typedef struct NODE
{
    int value;
    int balanceFactor;
    struct NODE *left;
    struct NODE *right;
    struct NODE *parent;
} NODE;

typedef struct TREE
{
    NODE *root;
} TREE;

NODE *createNode(int value)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->value = value;
    newNode->balanceFactor = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
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

NODE *findFirstAncestral(NODE *node)
{
    while (node != NULL && node->balanceFactor == 0)
        node = node->parent;
    return node;
}

void rotateLeft(NODE *a, NODE *b)
{
    int aValue = a->value;
    a->value = b->value;
    b->value = aValue;

    // Operações de rotação
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

    // Operações de rotação
    a->left = b->left;
    b->left = b->right;
    b->right = a->right;
    a->right = b;
}

void rebalance(TREE *tree, NODE *node)
{
    NODE *a = NULL;
    a = findFirstAncestral(node);
    calculateBalanceFactor(tree->root);
    if (!isUnbalanced(tree->root) || a == NULL)
        return;
    NODE *b = a->left;
    if (node->value >= a->value)
        b = a->right;
    if (b == NULL)
        return;
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
        node->parent = root;
        rebalance(tree, node);
    }
    else
    {
        if (root->right != NULL)
            return insert(tree, root->right, value);
        NODE *node = createNode(value);
        root->right = node;
        node->parent = root;
        rebalance(tree, node);
    }
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

NODE *findNode(NODE *root, int value)
{
    if (root == NULL)
        return NULL;
    if (root->value == value)
        return root;
    if (value < root->value)
        return findNode(root->left, value);
    return findNode(root->right, value);
}

void rebalanceAfterRemoveNode(TREE *tree, NODE *node)
{
    while (isUnbalanced(tree->root))
        rebalance(tree, node);
}

void removeNode(TREE *tree, int value)
{
    NODE *node = NULL, *parent = NULL, *substituteNode = NULL, *substituteNodeParent = NULL;
    node = findNode(tree->root, value);
    if (node == NULL)
        return;
    parent = node->parent;
    if (node->left == NULL || node->right == NULL)
    {
        if (node->left == NULL)
            substituteNode = node->right;
        else if (node->right == NULL)
            substituteNode = node->left;

        if (substituteNode != NULL && substituteNode->left != NULL)
            substituteNode->left->parent = substituteNode->parent;
        if (substituteNode != NULL && substituteNode->right != NULL)
            substituteNode->right->parent = substituteNode->parent;
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

        if (substituteNode->left != NULL)
            substituteNode->left->parent = substituteNode->parent;
        if (substituteNode->right != NULL)
            substituteNode->right->parent = substituteNode->parent;

        if (substituteNodeParent != node)
        {
            substituteNodeParent->right = substituteNode->left;
            substituteNode->left = node->left;
        }
        substituteNode->right = node->right;
    }

    if (node->left != NULL)
        node->left->parent = substituteNode;
    if (node->right != NULL)
        node->right->parent = substituteNode;

    if (parent == NULL)
    {
        substituteNode->parent = NULL;
        tree->root = substituteNode;
        rebalanceAfterRemoveNode(tree, node);
        free(node);
        return;
    }

    if (value < parent->value)
        parent->left = substituteNode;
    else
        parent->right = substituteNode;
    rebalanceAfterRemoveNode(tree, node);
    free(node);
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
    removeNode(tree, 15);
    printAll(tree->root, 0);
    return 0;
}