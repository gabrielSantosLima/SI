#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
    int value;
    struct NO *next;
} NODE;

NODE *createNode(int value)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void push(NODE **nodes, NODE *newNode)
{
    if ((*nodes) == NULL)
    {
        newNode->next = NULL;
        (*nodes) = newNode;
    }
    else
    {
        newNode->next = *nodes;
        (*nodes) = newNode;
    }
}

NODE *pop(NODE **nodes)
{
    if ((*nodes) == NULL)
    {
        return NULL;
    }
    if ((*nodes)->next == NULL)
    {
        NODE *pastNode = (*nodes);
        *nodes = NULL;
        return pastNode;
    }
    else
    {
        NODE *pastNode = (*nodes);
        *nodes = pastNode->next;
        return pastNode;
    }
}

void printAll(NODE *nodes)
{
    while (nodes != NULL)
    {
        printf("%d ", nodes->value);
        nodes = nodes->next;
    }
}

int main()
{
    NODE *nodes = NULL;
    push(&nodes, createNode(2));
    push(&nodes, createNode(5));
    push(&nodes, createNode(4));
    push(&nodes, createNode(3));

    printf("=== ANTES ===\n");
    printAll(nodes);
    printf("\n=== DEPOIS ===\n");

    NODE *newNode = NULL;
    while (nodes != NULL)
    {
        NODE *pastNode = pop(&nodes);
        printf("%d ", pastNode->value);
        push(&newNode, pastNode);
    }

    printf("\n=== DE VOLTA... ===\n");
    while (newNode != NULL)
    {
        NODE *pastNode = pop(&newNode);
        push(&nodes, pastNode);
    }

    printAll(nodes);

    return 0;
}