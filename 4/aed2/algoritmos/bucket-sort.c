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
    int size;
    double *data;
} ARRAY;

ARRAY *new_array(int size)
{
    ARRAY *narray = (ARRAY *)malloc(sizeof(ARRAY));
    narray->lenght = 0;
    narray->size = size;
    narray->data = (double *)malloc(sizeof(double) * size);
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

void add(ARRAY *array, double value)
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
        printf("%.2f ", array->data[index]);
}

ARRAY *concat(ARRAY *arrays[], int size)
{
    ARRAY *array = new_array(size);
    for (int index = 0; index < size; index++)
        for (int elementIndex = 0; elementIndex < arrays[index]->lenght; elementIndex++)
            add(array, arrays[index]->data[elementIndex]);
    return array;
}
// =====================================================

// ==================== Linked List ====================
typedef struct NODE
{
    double value;
    struct NODE *next_node;
} NODE;

typedef struct LIST
{
    int length;
    NODE *data;
} LIST;

LIST *new_list()
{
    LIST *nlist = (LIST *)malloc(sizeof(LIST));
    nlist->data = NULL;
    nlist->length = 0;
    return nlist;
}

NODE *create_node(double value)
{
    NODE *nnode = (NODE *)malloc(sizeof(NODE));
    nnode->value = value;
    nnode->next_node = NULL;
    return nnode;
}

void push(LIST *list, double value)
{
    if (list == NULL)
        return;
    if (list->length == 0)
    {
        list->data = create_node(value);
        list->length++;
        return;
    }
    NODE *aux_node = list->data;
    while (aux_node->next_node != NULL)
        aux_node = aux_node->next_node;
    aux_node->next_node = create_node(value);
    list->length++;
}

void print_list(LIST *list)
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
        node = node->next_node;
    }
}

// =====================================================

/* ==================== Bucket Sort ==================== */
void print_buckets(LIST *buckets[], int length)
{
    for (int index = 0; index < length; index++)
    {
        printf("Bucket %d: ", index);
        print_list(buckets[index]);
        printf("\n");
    }
}

ARRAY *list_2_array(LIST *list)
{
    if (list == NULL)
        return NULL;
    ARRAY *array = new_array(list->length);
    NODE *aux_node = list->data;
    while (aux_node != NULL)
    {
        add(array, aux_node->value);
        aux_node = aux_node->next_node;
    }
    return array;
}

void insertion_sort(ARRAY *array)
{
    if (is_empty(array) || (!is_empty(array) && array->lenght == 1))
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

void bucket_sort(ARRAY *array)
{
    if (array == NULL || is_empty(array))
        return;
    int size = array->size;
    LIST *buckets[size];
    for (int index = 0; index < size; index++)
        buckets[index] = new_list();
    for (int index = 0; index < size; index++)
    {
        int position = floor(size * array->data[index]);
        push(buckets[position], array->data[index]);
    }
    print_buckets(buckets, size);
    ARRAY *buckets_as_array[size];
    for (int index = 0; index < size; index++)
    {
        ARRAY *bucketAsArray = list_2_array(buckets[index]);
        insertion_sort(bucketAsArray);
        buckets_as_array[index] = bucketAsArray;
    }
    ARRAY *sorted_array = concat(buckets_as_array, size);
    for (int index = 0; index < sorted_array->lenght; index++)
        array->data[index] = sorted_array->data[index];
}
// =====================================================

void test_1000()
{
    ARRAY *array = new_array(1000);
    srand(time(NULL));
    for (int index = 0; index < 1000; index++)
    {
        double number = (rand() % 100);
        number /= 100;
        add(array, number);
    }
    bucket_sort(array);
    print_array(array);
}

int main()
{
    test_1000();
    return 0;
}