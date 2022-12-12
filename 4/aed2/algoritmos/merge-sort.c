#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define false 0
#define true 1

typedef int bool;

typedef struct ARRAY
{
    int lenght;
    int size;
    long *data;
} ARRAY;

ARRAY *new_array(int size)
{
    ARRAY *narray = (ARRAY *)malloc(sizeof(ARRAY));
    narray->lenght = 0;
    narray->size = size;
    narray->data = (long *)malloc(sizeof(long) * size);
    return narray;
}

bool is_empty(ARRAY *array)
{
    return array == NULL ||
           (array != NULL && array->lenght == 0);
}

bool is_full(ARRAY *array)
{
    return array == NULL ||
           (array != NULL && array->lenght == array->size);
}

void add(ARRAY *array, long value)
{
    if (is_full(array))
        return;
    array->data[array->lenght] = value;
    array->lenght++;
}

void print_array(ARRAY *array)
{
    if (is_empty(array))
        return;
    for (int index = 0; index < array->lenght; index++)
        printf("%lu ", array->data[index]);
}

void merge(ARRAY *array, int start, int middle, int end)
{
    int left_size = middle - start + 1;
    int right_size = end - middle;
    ARRAY *left = new_array(left_size);
    ARRAY *right = new_array(right_size);

    for (int index = 0; index < left_size; index++)
        add(left, array->data[start + index]);

    for (int index = 0; index < right_size; index++)
        add(right, array->data[middle + 1 + index]);

    int i = 0;
    int j = 0;
    int index = start;
    while (i < left_size && j < right_size)
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

    while (i < left_size)
    {
        array->data[index] = left->data[i];
        i++;
        index++;
    }

    while (j < right_size)
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
void merge_sort(ARRAY *array, int start, int end)
{
    if (is_empty(array) || start >= end)
        return;
    int size = end - start;
    int middle = start + size / 2;
    merge_sort(array, start, middle);
    merge_sort(array, middle + 1, end);
    merge(array, start, middle, end);
}
// =====================================================

void test_1000()
{
    ARRAY *array = new_array(1000);
    srand(time(NULL));
    for (int index = 0; index < 1000; index++)
    {
        long number = rand() % 1000;
        add(array, number);
    }
    merge_sort(array, 0, array->lenght - 1);
    print_array(array);
}

int main()
{
    test_1000();
    return 0;
}