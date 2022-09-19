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
    if (node == NULL) // Verifica se elemento que quero remover existe.
        return;
    if (node->left == NULL || node->right == NULL) // Possui 1 ou nenhum filho.
    {
        if (node->left == NULL)
            substituteNode = node->right;
        else if (node->right == NULL)
            substituteNode = node->left;
    }
    else // Possui os dois filhos.
    {
        substituteNodeParent = node;
        substituteNode = node->left;
        while (substituteNode->right != NULL) // Busca nó substituto mais a direita na sub-árvore da esquerda.
        {
            substituteNodeParent = substituteNode;
            substituteNode = substituteNode->right;
        }

        /* Quando pai do substituto é igual ao elemento que eu quero remover, quer dizer que o elemento que
        quero remover (node) possui apenas um filho à esquerda (não entrou no loop para buscar elementos a direita
        pois substituteNode->right == NULL). Por conta disso, nós alteramos o valor a esquerda do nó substituto apenas
        quando substituteNodeParent != node. Caso contrário, ficará em loop infinito visto que o elemento substituto é
        o próprio node->left.
        */
        if (substituteNodeParent != node)
        {
            /* Pai do substituto adota filho do nó substituto que irá sair de sua posição atual. Como o nó substituto
            é o elemento mais a direita, o elemento que seu pai irá adotar será, logicamente, o filho da esquerda (pois
            ele já é o elemento mais a direita).
            */
            substituteNodeParent->right = substituteNode->left;
            substituteNode->left = node->left; // Muda filho da esquerda do nó substituto.
        }
        substituteNode->right = node->right; // Muda filho da direita do nó substituto.
    }

    if (parent == NULL) // Verifica se nó que quer remover é a raiz.
    {
        tree->root = substituteNode; // Elemento substituto vira a nova raiz.
        free(node);
        return;
    }

    if (value < parent->value) // Altera referência do pai do elemento que quero remover para o nó substituto.
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
    insertNode(tree, tree->root, 9);
    insertNode(tree, tree->root, 3);
    insertNode(tree, tree->root, 13);
    insertNode(tree, tree->root, 11);
    insertNode(tree, tree->root, 14);
    insertNode(tree, tree->root, 1);
    insertNode(tree, tree->root, 2);
    printAll(tree->root);
    printf("\nRemovendo 9: \n");
    removeNode(tree, 9);
    printAll(tree->root);
    return 0;
}