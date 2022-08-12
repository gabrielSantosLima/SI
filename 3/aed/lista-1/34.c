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

bool compare(NODE *node1, NODE *node2)
{
    if (node1 == NULL && node2 == NULL)
        return true;
    while (node1 != NULL && node2 != NULL)
    {
        if (node1->value != node2->value)
            return false;
        node1 = node1->nextNode;
        node2 = node2->nextNode;
    }
    if (node1 != NULL || node2 != NULL)
        return false;
    return true;
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

    NODE *otherNodes = NULL;
    add(&otherNodes, 1);
    add(&otherNodes, 2);
    add(&otherNodes, 3);
    add(&otherNodes, 4);
    add(&otherNodes, 5);
    printAll(otherNodes);

    printf("\n");

    if (compare(nodes, otherNodes))
    {
        printf("Listas são iguais");
    }
    else
    {
        printf("Listas são diferentes");
    }

    return 0;
}