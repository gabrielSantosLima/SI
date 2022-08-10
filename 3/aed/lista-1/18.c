#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

    if (list->size == 1)
    {
        int order = strcmp(name, list->item->name);
        if (order == 0 || order > 0)
        {
            list->item->nextItem = newItem;
        }
        else
        {
            newItem->nextItem = list->item;
            list->item = newItem;
        }
        list->size++;
        return;
    }

    ITEM *firstItem = list->item;
    ITEM *lastItem = NULL;
    while (list->item != NULL)
    {
        ITEM *currentItem = list->item;
        int order = strcmp(name, currentItem->name);
        if (order == 0)
        {
            newItem->nextItem = currentItem->nextItem;
            currentItem->nextItem = newItem;
            list->size++;
            list->item = firstItem;
            return;
        }
        else if (order < 0)
        {
            if (lastItem == NULL)
            {
                list->item = newItem;
                newItem->nextItem = currentItem;
            }
            else
            {
                newItem->nextItem = currentItem;
                lastItem->nextItem = newItem;
                list->item = firstItem;
            }
            list->size++;
            return;
        }
        lastItem = list->item;
        list->item = list->item->nextItem;
    }
    lastItem->nextItem = newItem;
    list->size++;
    list->item = firstItem;
}

void printAll(LIST list)
{
    if (list.size == 0)
    {
        printf("Lista vazia");
        return;
    }
    printf("\n====================\n");
    while (list.item != NULL)
    {
        printf("%s ", list.item->name);
        list.item = list.item->nextItem;
    }
}

int main()
{
    LIST *list = createList();
    add(list, (char *)"Gabriel");
    add(list, (char *)"Guilherme");
    add(list, (char *)"Jonas");
    add(list, (char *)"Quevelin");
    add(list, (char *)"Nara");
    add(list, (char *)"Arara");
    add(list, (char *)"Presopopeu");
    add(list, (char *)"Ermanoteu");
    printAll(*list);
    return 0;
}