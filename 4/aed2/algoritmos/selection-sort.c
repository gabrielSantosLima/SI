#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define true 1
#define false 0

typedef int bool;

// ====================== ARRAY ======================
typedef struct ARRAY
{
    int length;
    int size;
    int *data;
} ARRAY;

ARRAY *new_array(int size)
{
    ARRAY *narray = (ARRAY *)malloc(sizeof(ARRAY));
    narray->length = 0;
    narray->size = size;
    narray->data = (int *)malloc(size * sizeof(int));
    return narray;
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
// ============================================================

// ====================== Selection Sort ======================
void swap(ARRAY *array, int from, int to)
{
    if (array == NULL || (array != NULL && (from >= array->length || to >= array->length || from == to)))
        return;
    int tmp_value = array->data[from];
    array->data[from] = array->data[to];
    array->data[to] = tmp_value;
}

void selection_sort(ARRAY *array)
{
    for (int i = 0; i < array->length - 1; i++)
    {
        int min_value_index = i;
        for (int j = i + 1; j < array->length; j++)
            if (array->data[j] < array->data[min_value_index])
                min_value_index = j;
        swap(array, i, min_value_index);
    }
}
// ============================================================
void test_1000()
{
    ARRAY *array = new_array(1000);
    srand(time(NULL));
    for (int index = 0; index < 1000; index++)
    {
        long number = rand() % 1000;
        add(array, number);
    }
    selection_sort(array);
    print_array(array);
}

int main()
{
    test_1000();
    return 0;
}