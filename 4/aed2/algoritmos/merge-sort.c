#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define false 0
#define true 1

typedef int bool;

typedef struct ARRAY
{
    int lenght;
    int maxLength;
    long *data;
} ARRAY;

ARRAY *newArray(int maxLength)
{
    ARRAY *newArray = (ARRAY *)malloc(sizeof(ARRAY));
    newArray->lenght = 0;
    newArray->maxLength = maxLength;
    newArray->data = (long *)malloc(sizeof(long) * maxLength);
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

void add(ARRAY *array, long value)
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
        printf("%lu ", array->data[index]);
}

void merge(ARRAY *array, int start, int middle, int end)
{
    int leftSize = middle - start + 1;
    int rightSize = end - middle;
    ARRAY *left = newArray(leftSize);
    ARRAY *right = newArray(rightSize);

    for (int index = 0; index < leftSize; index++)
        add(left, array->data[start + index]);

    for (int index = 0; index < rightSize; index++)
        add(right, array->data[middle + 1 + index]);

    int i = 0;
    int j = 0;
    int index = start;
    while (i < leftSize && j < rightSize)
    {
        if (left->data[i] <= right->data[j])
        {
            array->data[index] = left->data[i];
            i++;
        }
        else
        {
            array->data[index] = right->data[j];
            j++;
        }
        index++;
    }

    while (i < leftSize)
    {
        array->data[index] = left->data[i];
        i++;
        index++;
    }

    while (j < rightSize)
    {
        array->data[index] = right->data[j];
        j++;
        index++;
    }
    free(left);
    free(right);
}

/* ==================== Merge-Sort ====================
- Divide-and-conquer algorithm

Steps:
    - Split the array in two parts (D&C)
    - Sort the arrays and merge on the whole
*/
void mergeSort(ARRAY *array, int start, int end)
{
    if (isEmpty(array) || start >= end)
        return;
    int size = end - start;
    int middle = start + size / 2;
    mergeSort(array, start, middle);
    mergeSort(array, middle + 1, end);
    merge(array, start, middle, end);
}
// =====================================================

void test1000(){
    ARRAY *array = newArray(1000);
    srand(time(NULL));
    for(int index = 0; index < 1000; index++){
        long number = rand() % 1000;
        add(array, number);
    }
    mergeSort(array, 0, array->lenght - 1);
    printArray(array);
}

int main()
{
    test1000();
    return 0;
}