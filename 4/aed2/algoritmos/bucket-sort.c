#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define false 0
#define true 1

typedef int bool;

// ==================== Array ====================
typedef struct ARRAY
{
    int lenght;
    int maxLength;
    double *data;
} ARRAY;

ARRAY *newArray(int maxLength)
{
    ARRAY *newArray = (ARRAY *)malloc(sizeof(ARRAY));
    newArray->lenght = 0;
    newArray->maxLength = maxLength;
    newArray->data = (double *)malloc(sizeof(double) * maxLength);
    return newArray;
}

bool isEmpty(ARRAY *array)
{
    return array == NULL ||
           (array != NULL && array->lenght == 0);
}

bool isFull(ARRAY *array)
{
    return array == NULL ||
           (array != NULL && array->lenght == array->maxLength);
}

void add(ARRAY *array, double value)
{
    if (isFull(array))
        return;
    array->data[array->lenght] = value;
    array->lenght++;
}

void printArray(ARRAY *array)
{
    if (isEmpty(array))
        return;
    for (int index = 0; index < array->lenght; index++)
        printf("%.2f ", array->data[index]);
}

ARRAY *concat(ARRAY *arrays[], int maxLength)
{
    ARRAY *array = newArray(maxLength);
    for (int index = 0; index < maxLength; index++)
    {
        for (int elementIndex = 0; elementIndex < arrays[index]->lenght; elementIndex++)
        {
            add(array, arrays[index]->data[elementIndex]);
        }
    }
    return array;
}
// =====================================================

// ==================== Linked List ====================
typedef struct NODE
{
    double value;
    struct NODE *nextNode;
} NODE;

typedef struct LIST
{
    int length;
    NODE *data;
} LIST;

LIST *newList()
{
    LIST *newList = (LIST *)malloc(sizeof(LIST));
    newList->data = NULL;
    newList->length = 0;
    return newList;
}

NODE *createNode(double value)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->value = value;
    newNode->nextNode = NULL;
    return newNode;
}

void push(LIST *list, double value)
{
    if (list == NULL)
        return;
    if (list->length == 0)
    {
        list->data = createNode(value);
        list->length++;
        return;
    }
    NODE *auxNode = list->data;
    while (auxNode->nextNode != NULL)
        auxNode = auxNode->nextNode;
    auxNode->nextNode = createNode(value);
    list->length++;
}

void printList(LIST *list)
{
    if (list == NULL || (list != NULL && list->length == 0))
    {
        printf("Lista vazia");
        return;
    }
    NODE *node = list->data;
    while (node != NULL)
    {
        printf("%.2f ", node->value);
        node = node->nextNode;
    }
}

// =====================================================

/* ==================== Bucket Sort ==================== */
void printBuckets(LIST *buckets[], int length)
{
    for (int index = 0; index < length; index++)
    {
        printf("Bucket %d: ", index);
        printList(buckets[index]);
        printf("\n");
    }
}

ARRAY *listToArray(LIST *list)
{
    if (list == NULL)
        return NULL;
    ARRAY *array = newArray(list->length);
    NODE *auxNode = list->data;
    while (auxNode != NULL)
    {
        add(array, auxNode->value);
        auxNode = auxNode->nextNode;
    }
    return array;
}

void insertionSort(ARRAY *array)
{
    if (isEmpty(array) || (!isEmpty(array) && array->lenght == 1))
        return;
    for (int index = 1; index < array->lenght; index++)
    {
        double key = array->data[index];
        int i = index - 1;
        while (i >= 0 && array->data[i] > key)
        {
            array->data[i + 1] = array->data[i];
            i = i - 1;
        }
        array->data[i + 1] = key;
    }
}

void bucketSort(ARRAY *array, int maxLength)
{
    LIST *buckets[maxLength];
    for (int index = 0; index < maxLength; index++)
    {
        buckets[index] = newList();
    }
    for (int index = 0; index < maxLength; index++)
    {
        int position = floor(maxLength * array->data[index]);
        push(buckets[position], array->data[index]);
    }
    printBuckets(buckets, maxLength);
    ARRAY *bucketsAsArray[maxLength];
    for (int index = 0; index < maxLength; index++)
    {
        ARRAY *bucketAsArray = listToArray(buckets[index]);
        insertionSort(bucketAsArray);
        bucketsAsArray[index] = bucketAsArray;
    }
    ARRAY *sortedArray = concat(bucketsAsArray, maxLength);
    for (int index = 0; index < sortedArray->lenght; index++)
    {
        array->data[index] = sortedArray->data[index];
    }
}
// =====================================================

void test1000()
{
    ARRAY *array = newArray(1000);
    srand(time(NULL));
    for (int index = 0; index < 1000; index++)
    {
        double number = (rand() % 100);
        number /= 100;
        add(array, number);
    }
    bucketSort(array, 1000);
    printArray(array);
}

int main()
{
    test1000();
    return 0;
}