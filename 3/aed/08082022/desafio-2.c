#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NO
{
    int content;
    struct NO *nextNode;
} NODE;

NODE *createNode(int content)
{
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->content = content;
    node->nextNode = NULL;
    return node;
}

void insert(NODE **nodes, int content)
{
    NODE *initialNode = *nodes;

    if ((*nodes) == NULL)
    {
        NODE *newNode = createNode(content);
        (*nodes) = newNode;
        return;
    }

    while ((*nodes)->nextNode != NULL)
    {
        (*nodes) = (*nodes)->nextNode;
    }

    NODE *newNode = createNode(content);
    (*nodes)->nextNode = newNode;
    (*nodes) = initialNode;
}

int getSize(NODE *nodes)
{
    int size = 0;

    while (nodes != NULL)
    {
        size++;
        nodes = nodes->nextNode;
    }
    return size;
}

bool isEmpty(NODE *nodes)
{
    return getSize(nodes) == 0;
}

NODE *removeLast(NODE *nodes)
{
    if (nodes == NULL)
    {
        return NULL;
    }

    if (getSize(nodes) == 1)
    {
        free(nodes);
        return NULL;
    }

    NODE *initialNode = nodes;

    while (nodes->nextNode->nextNode != NULL)
    {
        nodes = nodes->nextNode;
    }

    free(nodes->nextNode);
    nodes->nextNode = NULL;
    return initialNode;
}

void getAll(NODE *nodes)
{
    printf("======== LISTA COMPLETA ========\n");
    if (isEmpty(nodes))
    {
        printf("Lista Vazia");
    }
    while (nodes != NULL && !isEmpty(nodes))
    {
        printf("%d ", nodes->content);
        nodes = nodes->nextNode;
    }
    printf("\n================================\n");
}

void swapOddAndEven(NODE **nodes)
{
    if (getSize(*nodes) == 1)
    {
        return;
    }
    NODE *startNode = (*nodes)->nextNode;
    NODE *aux = NULL;
    while (*nodes != NULL && (*nodes)->nextNode != NULL)
    {
        NODE *currentNode = *nodes;
        NODE *nextNode = currentNode->nextNode;
        NODE *nextNextNode = nextNode->nextNode;

        currentNode->nextNode = nextNextNode;
        nextNode->nextNode = currentNode;
        if (aux != NULL)
        {
            aux->nextNode = nextNode;
        }
        aux = currentNode;
        (*nodes) = currentNode->nextNode;
    }
    (*nodes) = startNode;
}

int main()
{
    NODE *nodes = NULL;

    insert(&nodes, 4);
    insert(&nodes, 5);
    insert(&nodes, 2);
    insert(&nodes, 3);
    insert(&nodes, 1);
    insert(&nodes, 6);
    insert(&nodes, 7);

    getAll(nodes);
    swapOddAndEven(&nodes);
    getAll(nodes);

    return 0;
}
// strcmp