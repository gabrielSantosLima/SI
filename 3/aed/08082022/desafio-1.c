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

void swap(NODE *nodes, int startIndex, int endIndex)
{
    int currentIndex = 0;
    NODE *first = NULL;
    NODE *end = NULL;
    while (nodes != NULL)
    {
        if (currentIndex + 1 == (startIndex - 1))
        {
            first = nodes;
        }
        if (currentIndex + 1 == (endIndex - 1))
        {
            end = nodes;
        }
        currentIndex++;
        nodes = nodes->nextNode;
    }
    NODE *preNode = first;
    NODE *node = first->nextNode;
    NODE *posNode = first->nextNode->nextNode;

    NODE *preEndNode = end;
    NODE *endNode = end->nextNode;
    NODE *posEndNode = end->nextNode->nextNode;

    preNode->nextNode = endNode;
    node->nextNode = posEndNode;
    preEndNode->nextNode = node;
    endNode->nextNode = posNode;
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

    getAll(nodes);
    swap(nodes, 2, 5);
    getAll(nodes);

    return 0;
}