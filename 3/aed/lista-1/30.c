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

LIST *concat(LIST list1, LIST list2)
{
    LIST *list = createList();
    while (list1.nodes != NULL)
    {
        add(list, list1.nodes->value);
        list1.nodes = list1.nodes->nextNode;
    }
    while (list2.nodes != NULL)
    {
        add(list, list2.nodes->value);
        list2.nodes = list2.nodes->nextNode;
    }
    return list;
}

int main()
{
    LIST *list1 = createList();
    add(list1, 1);
    add(list1, 2);
    add(list1, 3);
    add(list1, 4);
    LIST *list2 = createList();
    add(list2, 6);
    add(list2, 7);

    printAll(*list1);
    printAll(*list2);

    LIST *list = concat(*list1, *list2);
    printAll(*list);
    return 0;
}