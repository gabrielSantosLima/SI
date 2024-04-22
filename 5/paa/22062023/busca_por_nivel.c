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
    int length;
} TREE;

TREE *create_tree()
{
    TREE *ntree = (TREE *)malloc(sizeof(TREE));
    ntree->length = 0;
    ntree->root = NULL;
    return ntree;
}

NODE *create_node(int value)
{
    NODE *nnode = (NODE *)malloc(sizeof(NODE));
    nnode->left = NULL;
    nnode->right = NULL;
    nnode->value = value;
    return nnode;
}

void add(TREE *tree, NODE *root, int value)
{
    if (tree->root == NULL)
    {
        tree->length++;
        tree->root = create_node(value);
        return;
    }

    if (root->value > value)
    {
        if (root->left != NULL)
            return add(tree, root->left, value);
        root->left = create_node(value);
        tree->length++;
        return;
    }
    if (root->right != NULL)
        return add(tree, root->right, value);
    root->right = create_node(value);
    tree->length++;
    return;
}

void print_tree(NODE *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->value);
    print_tree(root->left);
    print_tree(root->right);
}

void print_tree_by_level(NODE *root, int value)
{
}

int main()
{
    TREE *tree = create_tree();
    add(tree, tree->root, 10);
    add(tree, tree->root, 5);
    add(tree, tree->root, 6);
    add(tree, tree->root, 3);
    add(tree, tree->root, 11);
    add(tree, tree->root, 12);
    printf("Pré ordem:\n");
    print_tree(tree->root);
    printf("\n");
    printf("Por nível:\n");
    print_tree_by_level(tree->root, 0);
    return 0;
}