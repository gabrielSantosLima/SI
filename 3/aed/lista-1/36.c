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

void swap(NODE **nodes, int from, int to)
{
    if (to <= from)
        return;
    NODE *preNode1 = at(*nodes, from - 1);
    NODE *node1 = at(*nodes, from);
    NODE *posNode1 = at(*nodes, from + 1);

    NODE *preNode2 = at(*nodes, to - 1);
    NODE *node2 = at(*nodes, to);
    NODE *posNode2 = at(*nodes, to + 1);

    if (preNode1 != NULL)
    {
        preNode1->nextNode = node2;
    }
    else
    {
        *nodes = node2;
    }

    if (to - from == 1)
    {
        node2->nextNode = node1;
    }
    else
    {
        node2->nextNode = posNode1;
    }

    if (preNode2 != NULL && to - from != 1)
    {
        preNode2->nextNode = node1;
    }
    node1->nextNode = posNode2;
}

void swapAll(NODE **nodes)
{
    int size = getSize(*nodes);
    int from = 0;
    int to = size - 1;
    while (from < to)
    {
        swap(nodes, from, to);
        from++;
        to--;
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
    swapAll(&nodes);
    printAll(nodes); // Result: 1 4 34 2 10
    return 0;
}