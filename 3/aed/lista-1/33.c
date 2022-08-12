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
    int currentIndex = 0;
    NODE *newNode = createNode(value);
    if (*nodes == NULL)
        return;

    NODE *firstNode = *nodes;
    NODE *lastCurrentNode = NULL;
    while ((*nodes) != NULL)
    {

        if (currentIndex == index && lastCurrentNode == NULL)
        {
            newNode->nextNode = *nodes;
            *nodes = newNode;
            return;
        }
        else if (currentIndex == index && (*nodes)->nextNode == NULL)
        {
            newNode->nextNode = *nodes;
            lastCurrentNode->nextNode = newNode;
            *nodes = firstNode;
            return;
        }
        else if (currentIndex == index)
        {
            lastCurrentNode->nextNode = newNode;
            newNode->nextNode = *nodes;
            *nodes = firstNode;
            return;
        }
        currentIndex++;
        lastCurrentNode = *nodes;
        *nodes = (*nodes)->nextNode;
    }
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

int main()
{
    NODE *nodes = NULL;
    add(&nodes, 1);
    add(&nodes, 2);
    add(&nodes, 3);
    add(&nodes, 4);
    add(&nodes, 5);

    addAt(&nodes, 6, 1);
    printAll(nodes); // Result: 1 6 2 3 4 5
    return 0;
}