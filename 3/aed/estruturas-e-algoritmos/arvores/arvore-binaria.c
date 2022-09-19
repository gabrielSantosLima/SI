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
            root = root->leftNode;
        else
            root = root->rightNode;
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
void removeNode(TREE *tree, int value)
{
    NODE *node = NULL, *parent = NULL, *substituteNode = NULL, *substituteNodeParent = NULL;
    node = findNodeWithParent(tree->root, value, &parent);
    if (node == NULL) // Verifica se elemento que quero remover existe.
        return;
    if (node->leftNode == NULL || node->rightNode == NULL) // Possui 1 ou nenhum filho.
    {
        if (node->leftNode == NULL)
            substituteNode = node->rightNode;
        else if (node->rightNode == NULL)
            substituteNode = node->leftNode;
    }
    else // Possui os dois filhos.
    {
        substituteNodeParent = node;
        substituteNode = node->leftNode;
        while (substituteNode->rightNode != NULL) // Busca nó substituto mais a direita na sub-árvore da esquerda.
        {
            substituteNodeParent = substituteNode;
            substituteNode = substituteNode->rightNode;
        }

        /* Quando pai do substituto é igual ao elemento que eu quero remover, quer dizer que o elemento que
        quero remover (node) possui apenas um filho à esquerda (não entrou no loop para buscar elementos a direita
        pois substituteNode->rightNode == NULL). Por conta disso, nós alteramos o valor a esquerda do nó substituto apenas
        quando substituteNodeParent != node. Caso contrário, ficará em loop infinito visto que o elemento substituto é
        o próprio node->leftNode.
        */
        if (substituteNodeParent != node)
        {
            /* Pai do substituto adota filho do nó substituto que irá sair de sua posição atual. Como o nó substituto
            é o elemento mais a direita, o elemento que seu pai irá adotar será, logicamente, o filho da esquerda (pois
            ele já é o elemento mais a direita).
            */
            substituteNodeParent->rightNode = substituteNode->leftNode;
            substituteNode->leftNode = node->leftNode; // Muda filho da esquerda do nó substituto.
        }
        substituteNode->rightNode = node->rightNode; // Muda filho da direita do nó substituto.
    }

    if (parent == NULL) // Verifica se nó que quer remover é a raiz.
    {
        tree->root = substituteNode; // Elemento substituto vira a nova raiz.
        free(node);
        return;
    }

    if (value < parent->value) // Altera referência do pai do elemento que quero remover para o nó substituto.
        parent->leftNode = substituteNode;
    else
        parent->rightNode = substituteNode;
    free(node);
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
    removeNode(tree, 15);
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