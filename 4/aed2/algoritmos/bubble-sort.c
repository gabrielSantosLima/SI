#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define true 1
#define false 0

typedef int bool;

// ==================== Array ====================

typedef struct ARRAY
{
    int *data;
    int length;
    int size;
} ARRAY;

ARRAY *new_array(int size)
{
    ARRAY *array = (ARRAY *)malloc(sizeof(ARRAY));
    array->data = (int *)malloc(size * sizeof(int));
    array->size = size;
    array->length = 0;
    return array;
}

bool is_empty(ARRAY *array)
{
    return array != NULL && array->length == 0;
}

bool is_full(ARRAY *array)
{
    return array != NULL && array->length == array->size;
}

void add(ARRAY *array, int value)
{
    if (array == NULL || is_full(array))
        return;
    array->data[array->length] = value;
    array->length++;
}

void print_array(ARRAY *array)
{
    if (array == NULL || is_empty(array))
        return;
    for (int index = 0; index < array->length; index++)
        printf("%d ", array->data[index]);
    printf("\n");
}
// ===============================================
// ==================== Bubble Sort ====================

void swap(ARRAY *array, int from, int to)
{
    if (array == NULL || is_empty(array) || array->length <= from || array->length <= to)
        return;
    int tmp_value = array->data[from];
    array->data[from] = array->data[to];
    array->data[to] = tmp_value;
}

void bubble_sort(ARRAY *array)
{
    if (array == NULL || is_empty(array))
        return;
    bool swapped = false;
    for (int i = 0; i < array->length - 1; i++)
    {
        for (int j = 0; j < array->length - i - 1; j++)
        {
            if (array->data[j] > array->data[j + 1])
            {
                swap(array, j, j + 1);
                swapped = true;
            }
        }
        if (!swapped)
            return;
    }
}
// ===============================================

void test1000()
{
    ARRAY *array = new_array(1000);
    srand(time(NULL));
    for (int index = 0; index < 1000; index++)
    {
        long number = rand() % 1000;
        add(array, number);
    }
    bubble_sort(array);
    print_array(array);
}

int main()
{
    test1000();
    return 0;
}
