#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NODE
{
    int value;
    struct NODE *nextNode;
} NODE;

NODE *createNode(int value)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->value = value;
    newNode->nextNode = NULL;
    return newNode;
}

void add(NODE **nodes, int value)
{
    NODE *newNode = createNode(value);
    if (*nodes == NULL)
    {
        *nodes = newNode;
        return;
    }
    NODE *firstNode = *nodes;
    while ((*nodes)->nextNode != NULL)
    {
        *nodes = (*nodes)->nextNode;
    }
    (*nodes)->nextNode = newNode;
    *nodes = firstNode;
}

void printAll(NODE *nodes)
{
    printf("\n=== LISTA ===\n");
    if (nodes == NULL)
    {
        printf("Lista vazia.");
        return;
    }
    while (nodes != NULL)
    {
        printf("%d ", nodes->value);
        nodes = nodes->nextNode;
    }
}

void removeLast(NODE **nodes)
{
    if ((*nodes) == NULL)
        return;
    if ((*nodes)->nextNode == NULL)
    {
        free(*nodes);
        *nodes = NULL;
        return;
    }
    NODE *firstNode = *nodes;

    while ((*nodes)->nextNode->nextNode != NULL)
    {
        (*nodes) = (*nodes)->nextNode;
    }
    free((*nodes)->nextNode);
    (*nodes)->nextNode = NULL;
    *nodes = firstNode;
}

void reset(NODE **nodes)
{
    if (*nodes == NULL)
        return;
    removeLast(nodes);
    return reset(nodes);
}

int main()
{
    NODE *nodes = NULL;
    add(&nodes, 1);
    add(&nodes, 2);
    add(&nodes, 3);
    add(&nodes, 4);
    add(&nodes, 5);
    printAll(nodes);
    reset(&nodes);
    printAll(nodes);
    return 0;
}