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

void rebalanceAfterInsert(TREE *tree)
{
    NODE *ancestral = NULL;
    NODE *node = findFirstAncestral(tree->root, &ancestral);
    calculateBalanceFactor(tree->root);
    if (!isUnbalanced(tree->root))
        return;
    NODE *ancestralChild = ancestral->left;
    if (node->value >= ancestral->value)
        ancestralChild = ancestral->right;

    if (isPositive(ancestral->balanceFactor) && isPositive(ancestralChild->balanceFactor))
    {
        // Rotação simples para a esquerda
    }
    else if (isNegative(ancestral->balanceFactor) && isNegative(ancestralChild->balanceFactor))
    {
        // Rotação simples para a direita
    }
    else if (isPositive(ancestral->balanceFactor) && isNegative(ancestralChild->balanceFactor))
    {
        // Rotação dupla para a esquerda
    }
    else if (isNegative(ancestral->balanceFactor) && isPositive(ancestralChild->balanceFactor))
    {
        // Rotação dupla para a direita
    }
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

int main()
{
    TREE *tree = createTree();
    insert(tree, tree->root, 15);
    insert(tree, tree->root, 10);
    insert(tree, tree->root, 20);
    insert(tree, tree->root, 60);
    insert(tree, tree->root, 50);
    printAll(tree->root, 0);
    return 0;
}