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

LIST *addArrayToList(int *values, int totalSize)
{
    LIST *list = createList();
    int index;
    for (index = 0; index < totalSize; index++)
    {
        add(list, *(values + index));
    }
    return list;
}

LIST *addArrayToListRecursively(int *values, int currentIndex)
{
    if (currentIndex == 0)
    {
        LIST *list = createList();
        add(list, *(values + currentIndex));
        return list;
    }
    LIST *list = addArrayToListRecursively(values, currentIndex - 1);
    add(list, *(values + currentIndex));
    return list;
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

int main()
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int totalSize = sizeof(numbers) / sizeof(int);
    LIST *list = addArrayToList(numbers, totalSize);
    LIST *recursiveList = addArrayToListRecursively(numbers, totalSize - 1);
    printAll(*list);
    printAll(*recursiveList);
    return 0;
}