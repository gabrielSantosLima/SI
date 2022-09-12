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

void insertNode(TREE *tree, NODE *root, int value)
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
            return insertNode(tree, root->leftNode, value);
        NODE *newNode = createNode(value);
        root->leftNode = newNode;
        tree->length++;
    }
    else if (value >= root->value)
    {
        if (root->rightNode != NULL)
            return insertNode(tree, root->rightNode, value);
        NODE *newNode = createNode(value);
        root->rightNode = newNode;
        tree->length++;
    }
}

NODE *findNode(NODE *root, int value)
{
    if (root == NULL)
        return NULL;
    if (root->value == value)
        return root;
    if (value > root->value)
        return findNode(root->rightNode, value);
    return findNode(root->leftNode, value);
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
        {
            root = root->leftNode;
        }
        else
        {
            root = root->rightNode;
        }
    }
    return NULL;
}

/*
    Para remover um elemento precisamos:
    1. Buscar o elemento a ser removido juntamente de seu pai
    2. Achar o nó substituto e seu pai:
        I. Se, o elemento a ser removido possuir 1 filho, atribuímos a este nó o nó substituto
        Caso contrário, precisamos encontrar o nó mais a direita da sub-árvore da esquerda
        (ou o nó mais a esquerda da sub-árvore da direita)
    3. Por fim verificamos se o elemento a ser removido é a raiz. Caso verdadeiro, atribuímos o valor de raíz
    para o nó substituto
    4. Caso contrário, fazemos o pai do elemento a ser removido apontar para o nó substituto, eliminando
    o nó de interesse.
*/
void removeNode(TREE *tree, NODE *root, int value)
{
    if (tree->root == NULL || tree->length == 0)
        return;

    NODE *node = NULL;
    NODE *nodeParent = NULL;
    NODE *substituteNode = NULL;
    NODE *substituteNodeParent = NULL;

    node = findNodeWithParent(root, value, &nodeParent);

    if (node->rightNode == NULL || node->leftNode == NULL)
    {
        if (node->leftNode == NULL)
            substituteNode = node->rightNode;
        else if (node->rightNode == NULL)
            substituteNode = node->leftNode;
    }
    else
    {
        substituteNodeParent = node;
        substituteNode = node->leftNode;
        while (substituteNode->rightNode != NULL)
        {
            substituteNodeParent = substituteNode;
            substituteNode = substituteNode->rightNode;
        }

        if (substituteNodeParent != node)
        {
            substituteNodeParent->rightNode = substituteNode->rightNode;
            substituteNode->leftNode = node->leftNode;
        }
        substituteNode->rightNode = node->rightNode;
    }

    if (nodeParent == NULL)
    {
        free(node);
        tree->root = substituteNode;
        return;
    }

    if (value < nodeParent->value)
    {
        nodeParent->leftNode = substituteNode;
    }
    else
    {
        nodeParent->rightNode = substituteNode;
    }
    free(node);
    tree->root = root;
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
    insertNode(tree, tree->root, 15);
    insertNode(tree, tree->root, 8);
    insertNode(tree, tree->root, 23);
    insertNode(tree, tree->root, 2);
    insertNode(tree, tree->root, 12);
    insertNode(tree, tree->root, 20);
    insertNode(tree, tree->root, 30);
    insertNode(tree, tree->root, 10);

    printAll(tree->root);
    removeNode(tree, tree->root, 15);
    printAll(tree->root);

    // NODE *node = findNode(tree->root, 10);
    // if (node == NULL)
    // {
    //     printf("Valor não foi encontrado");
    // }
    // else
    // {
    //     printf("Valor foi encontrado.");
    // }
    return 0;
}