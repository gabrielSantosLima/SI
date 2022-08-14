#include <stdio.h>
#include <stdlib.h>

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

void addAt(NODE **nodes, int value, int index)
{
    if (*nodes == NULL || index < 0)
    {
        add(nodes, value);
        return;
    }
    int currentIndex = 0;
    NODE *firstNode = *nodes;
    NODE *lastNode = NULL;
    while (*nodes != NULL && currentIndex != index)
    {
        currentIndex++;
        lastNode = *nodes;
        *nodes = (*nodes)->nextNode;
    }
    if (*nodes == NULL)
    {
        *nodes = firstNode;
        add(nodes, value);
        return;
    }
    NODE *newNode = createNode(value);
    if (lastNode == NULL)
    {
        newNode->nextNode = firstNode;
        *nodes = newNode;
        return;
    }
    newNode->nextNode = lastNode->nextNode;
    lastNode->nextNode = newNode;
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

NODE *removeAt(NODE **nodes, int index)
{
    if (*nodes == NULL || index < 0)
        return NULL;
    int currentIndex = 0;
    NODE *firstNode = *nodes;
    NODE *lastNode = NULL;
    while (*nodes != NULL && currentIndex != index)
    {
        lastNode = *nodes;
        currentIndex++;
        *nodes = (*nodes)->nextNode;
    }
    if (*nodes == NULL)
    {
        *nodes = firstNode;
        return NULL;
    }
    if (lastNode == NULL)
    {
        NODE *currentNode = *nodes;
        *nodes = currentNode->nextNode;
        currentNode->nextNode = NULL;
        return currentNode;
    }
    NODE *currentNode = *nodes;
    lastNode->nextNode = currentNode->nextNode;
    *nodes = firstNode;
    currentNode->nextNode = NULL;
    return currentNode;
}

void switchPosition(NODE **nodes, int startIndex, int endIndex)
{
    NODE *removedNode = removeAt(nodes, startIndex);
    if (removedNode != NULL)
    {
        addAt(nodes, removedNode->value, endIndex);
        free(removedNode);
    }
}

int main()
{
    NODE *nodes = NULL;
    add(&nodes, 10);
    add(&nodes, 2);
    add(&nodes, 34);
    add(&nodes, 4);
    add(&nodes, 1);
    printAll(nodes);
    switchPosition(&nodes, 1, 3);
    printAll(nodes); // Result: 10 34 4 2 1
    return 0;
}