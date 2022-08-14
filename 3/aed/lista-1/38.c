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

NODE *at(NODE *nodes, int index)
{
    if (index < 0)
        return NULL;
    int currentIndex = 0;
    while (nodes != NULL)
    {
        if (currentIndex == index)
        {
            return nodes;
        }
        currentIndex++;
        nodes = nodes->nextNode;
    }
    return NULL;
}

void switchPosition(NODE **nodes, int startIndex, int endIndex)
{
    if (*nodes == NULL || startIndex < 0 || endIndex < 0 || startIndex == endIndex)
        return;
    NODE *preNode = at(*nodes, startIndex - 1);
    NODE *node = at(*nodes, startIndex);
    NODE *endNode;
    if (startIndex > endIndex)
    {
        endNode = at(*nodes, endIndex - 1);
    }
    else
    {
        endNode = at(*nodes, endIndex);
    }
    if (node == NULL || (endNode == NULL && endIndex != 0 && startIndex > endIndex))
        return;
    if (preNode == NULL)
    {
        *nodes = node->nextNode;
    }
    else
    {
        preNode->nextNode = node->nextNode;
    }
    if (endNode != NULL)
    {
        node->nextNode = endNode->nextNode;
        endNode->nextNode = node;
    }
    else
    {
        node->nextNode = *nodes;
        *nodes = node;
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
    switchPosition(&nodes, 3, 1);
    printAll(nodes); // Result: 10 2 34 4 1
    return 0;
}