#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct NO
{
    int value;
    struct NO *last;
    struct NO *next;
} NODE;

NODE *createNode(int value)
{
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->value = value;
    node->next = NULL;
    node->last = NULL;
    return node;
}

void insert(NODE **nodes, int value)
{
    if (*nodes == NULL)
    {
        NODE *newNode = createNode(value);
        newNode->last = newNode;
        newNode->next = newNode;
        *nodes = newNode;
        return;
    }
    NODE *firstNode = *nodes;
    NODE *newNode = createNode(value);

    while ((*nodes)->next != firstNode)
    {
        (*nodes) = (*nodes)->next;
    }

    (*nodes)->next = newNode;
    firstNode->last = newNode;
    newNode->next = firstNode;
    newNode->last = *nodes;

    *nodes = firstNode;
}

int size(NODE *nodes)
{
    if (nodes == NULL)
    {
        return 0;
    }
    if (nodes->next == nodes)
    {
        return 1;
    }
    NODE *firstNode = nodes;
    int size = 0;
    while (nodes->next != firstNode)
    {
        size++;
        nodes = nodes->next;
    }
    size++;
    return size;
}

bool isEmpty(NODE *nodes)
{
    return size(nodes) == 0;
}

void printAll(NODE *nodes)
{
    NODE *firstNode = nodes;
    printf("> LISTA COMPLETA\n");

    if (isEmpty(nodes))
    {
        printf("\nLista vazia!");
        return;
    }

    while (nodes->next != firstNode)
    {
        printf("%d ", nodes->value);
        nodes = nodes->next;
    }
    printf("%d\n", nodes->value);
}

void printAllReverse(NODE *nodes)
{
    NODE *firstNode = nodes;
    printf("> LISTA COMPLETA REVERSA\n");

    if (isEmpty(nodes))
    {
        printf("\nLista vazia!");
        return;
    }

    while (nodes->last != firstNode)
    {
        nodes = nodes->last;
        printf("%d ", nodes->value);
    }
    printf("%d ", nodes->last->value);
}

void removeLast(NODE **nodes)
{
    if (isEmpty(*nodes))
        return;

    if ((*nodes)->next == *nodes)
    {
        free(*nodes);
        *nodes = NULL;
        return;
    }

    NODE *firstNode = *nodes;
    NODE *removedNode = firstNode->last;

    removedNode->last->next = firstNode;
    firstNode->last = removedNode->last;
    free(removedNode);
}

NODE *find(NODE *nodes, int value)
{
    NODE *firstNode = nodes;
    if (isEmpty(nodes))
    {
        return NULL;
    }
    if (nodes->next == nodes)
    {
        if (nodes->value == value)
        {
            return nodes;
        }
        return NULL;
    }
    while (nodes->next != firstNode)
    {
        if (nodes->value == value)
        {
            return nodes;
        }
        nodes = nodes->next;
    }
    if (nodes->value == value)
    {
        return nodes;
    }
    return NULL;
}

int main()
{
    NODE *nodes = NULL;
    insert(&nodes, 20);
    insert(&nodes, 30);
    insert(&nodes, 40);
    insert(&nodes, 7);
    insert(&nodes, 60);
    insert(&nodes, 80);

    printAll(nodes);
    removeLast(&nodes);
    printAll(nodes);
    printAllReverse(nodes);

    int number = 70;
    printf("\nBuscando elemento: %d", number);
    NODE *node = find(nodes, number);
    if (node != NULL)
    {
        printf("\nElemento encontrado!");
    }
    else
    {
        printf("\nElemento não existe!");
    }

    if (isEmpty(nodes))
    {
        printf("\nEstá vazio");
    }

    printf("\nTamanho total: %d", size(nodes));
    return 0;
}