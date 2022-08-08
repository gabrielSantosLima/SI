#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ITEM
{
    char *name;
    struct ITEM *nextItem;
} ITEM;

typedef struct LIST
{
    int size;
    struct ITEM *item;
} LIST;

LIST *createList()
{
    LIST *newList = (LIST *)malloc(sizeof(LIST));
    newList->size = 0;
    newList->item = NULL;
    return newList;
}

ITEM *createItem(char *name)
{
    ITEM *newItem = (ITEM *)malloc(sizeof(ITEM));
    newItem->name = name;
    newItem->nextItem = NULL;
    return newItem;
}

void add(LIST *list, char *name)
{
    ITEM *newItem = createItem(name);
    if (list->size == 0)
    {
        list->item = newItem;
        list->size++;
        return;
    }

    ITEM *firstItem = list->item;
    while (list->item->nextItem != NULL)
    {
        list->item = list->item->nextItem;
    }
    list->item->nextItem = newItem;
    list->size++;
    list->item = firstItem;
}

void printAll(LIST *list)
{
    if (list->size == 0)
    {
        printf("Lista vazia");
        return;
    }
    while (list->item != NULL)
    {
        printf("%s ", list->item->name);
        list->item = list->item->nextItem;
    }
}

int main()
{
    LIST *list = createList();
    add(list, (char *)"Gabriel Lima");
    add(list, (char *)"Guilherme Lima");
    add(list, (char *)"Jonas Lima");
    add(list, (char *)"Quevelin Lima");
    add(list, (char *)"Nara Lima");
    add(list, (char *)"Presopopeu Lima");
    add(list, (char *)"Ermanoteu Lima");
    printAll(list);
    return 0;
}