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

int *addListToArray(LIST list)
{
    int *newValues = (int *)malloc(sizeof(int) * list.size);
    int currentIndex = 0;
    while (list.nodes != NULL)
    {
        newValues[currentIndex] = list.nodes->value;
        currentIndex++;
        list.nodes = list.nodes->nextNode;
    }
    return newValues;
}

int *addListToArrayRecursively(LIST list, int currentIndex)
{
    if (currentIndex == 0)
    {
        int *values = (int *)malloc(sizeof(int) * list.size);
        values[0] = list.nodes->value;
        return values;
    }
    int *values = addListToArrayRecursively(list, currentIndex - 1);
    int listIndex = 0;
    for (listIndex = 0; listIndex < currentIndex; listIndex++)
    {
        list.nodes = list.nodes->nextNode;
    }
    values[currentIndex] = list.nodes->value;
    return values;
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

void printAllArray(int *values, int size)
{
    printf("\n=========== VETOR ===========\n");
    if (size == 0)
    {
        printf("Lista vazia");
        return;
    }
    int index = 0;
    for (index = 0; index < size; index++)
    {
        printf("%d ", *(values + index));
    }
}

int main()
{
    LIST *list = createList();
    add(list, 1);
    add(list, 2);
    add(list, 3);
    add(list, 4);
    add(list, 5);
    add(list, 8);
    add(list, 9);
    add(list, 54);

    printAll(*list);
    int *numbersRecursively = addListToArrayRecursively(*list, list->size - 1);
    printAllArray(numbersRecursively, list->size);

    int *numbers = addListToArray(*list);
    printAllArray(numbers, list->size);

    return 0;
}