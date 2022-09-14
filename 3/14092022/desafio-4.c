#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int value;
    struct NODE *left;
    struct NODE *right;
} NODE;

NODE *createNode(int value)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->value = value;
    return newNode;
}

void insert(NODE **root, NODE *currentRoot, int value)
{
    if (currentRoot == NULL)
    {
        NODE *newNode = createNode(value);
        *root = newNode;
        return;
    }
    if (value < currentRoot->value)
    {
        if (currentRoot->left != NULL)
            return insert(root, currentRoot->left, value);
        NODE *newNode = createNode(value);
        currentRoot->left = newNode;
    }
    else
    {
        if (currentRoot->right != NULL)
            return insert(root, currentRoot->right, value);
        NODE *newNode = createNode(value);
        currentRoot->right = newNode;
    }
}

void printAll(NODE *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->value);
    printAll(root->left);
    printAll(root->right);
}

void printInternalNodes(NODE *root)
{
    if (root == NULL)
        return;
    printInternalNodes(root->left);
    if (root->left != NULL || root->right != NULL)
        printf("%d ", root->value);
    printInternalNodes(root->right);
}

void maior_menor_arvore(NODE *raiz, int *maior, int *menor)
{
    if (raiz == NULL)
        return;
    if (raiz->value > *maior)
        *maior = raiz->value;
    if (raiz->value < *menor)
        *menor = raiz->value;
    maior_menor_arvore(raiz->left, maior, menor);
    maior_menor_arvore(raiz->right, maior, menor);
}

int main()
{
    NODE *root = NULL;
    insert(&root, root, 15);
    insert(&root, root, 10);
    insert(&root, root, 22);
    insert(&root, root, 2);
    insert(&root, root, 12);
    insert(&root, root, 40);
    int maior = root->value;
    int menor = root->value;

    maior_menor_arvore(root, &maior, &menor);
    printf("MAIOR: %d\n", maior);
    printf("MENOR: %d", menor);
    // printInternalNodes(root);
    return 0;
}