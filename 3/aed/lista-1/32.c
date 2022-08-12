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

void removeAt(NODE **nodes, int index)
{
    int currentIndex = 0;
    if (*nodes == NULL)
        return;
    NODE *firstNode = *nodes;
    NODE *lastCurrentNode = NULL;
    while (*nodes != NULL)
    {
        if (currentIndex == index && lastCurrentNode == NULL)
        {
            NODE *currentNode = *nodes;
            *nodes = currentNode->nextNode;
            free(currentNode);
            return;
        }
        else if (currentIndex == index && (*nodes)->nextNode == NULL)
        {
            NODE *currentNode = *nodes;
            lastCurrentNode->nextNode = NULL;
            *nodes = firstNode;
            free(currentNode);
            return;
        }
        else if (currentIndex == index)
        {
            NODE *currentNode = *nodes;
            lastCurrentNode->nextNode = currentNode->nextNode;
            *nodes = firstNode;
            free(currentNode);
            return;
        }
        lastCurrentNode = *nodes;
        currentIndex++;
        *nodes = (*nodes)->nextNode;
    }
    *nodes = firstNode;
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

    removeAt(&nodes, 2);
    printAll(nodes);
    return 0;
}