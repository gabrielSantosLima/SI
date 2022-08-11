#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int value;
    struct NODE *nextNode;
} NODE;

typedef struct LIST
{
    int size;
    NODE *nodes;
} LIST;

LIST *createList()
{
    LIST *newList = (LIST *)malloc(sizeof(LIST));
    newList->size = 0;
    newList->nodes = NULL;
    return newList;
}

NODE *createNode(int value)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->value = value;
    newNode->nextNode = NULL;
    return newNode;
}

void add(LIST *list, int value)
{
    NODE *newNode = createNode(value);
    if (list->size == 0)
    {
        list->nodes = newNode;
        list->size++;
        return;
    }

    NODE *firstNode = list->nodes;

    while (list->nodes->nextNode != NULL)
    {
        list->nodes = list->nodes->nextNode;
    }

    list->nodes->nextNode = newNode;
    list->size++;
    list->nodes = firstNode;
}

void printAll(LIST list)
{
    printf("\n=========== LISTA ===========\n");
    if (list.size == 0)
    {
        printf("Lista vazia");
        return;
    }
    while (list.nodes != NULL)
    {
        printf("%d ", list.nodes->value);
        list.nodes = list.nodes->nextNode;
    }
}

int getSizeOf(LIST list)
{
    int size = 0;
    while (list.nodes != NULL)
    {
        size++;
        list.nodes = list.nodes->nextNode;
    }
    return size;
}

int main()
{
    LIST *list = createList();
    add(list, 1);
    add(list, 2);
    add(list, 3);
    add(list, 4);

    printAll(*list);
    printf("\nPossui %d elemento(s).", getSizeOf(*list));
    return 0;
}