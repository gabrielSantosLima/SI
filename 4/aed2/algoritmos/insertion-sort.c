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
    int *data;
} ARRAY;

ARRAY *new_array(int maxLength)
{
    ARRAY *newArray = (ARRAY *)malloc(sizeof(ARRAY));
    newArray->lenght = 0;
    newArray->size = maxLength;
    newArray->data = (int *)malloc(sizeof(int) * maxLength);
    return newArray;
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

void add(ARRAY *array, int value)
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
        printf("%d ", array->data[index]);
}

/* ==================== Insertion-Sort ==================== */
void insertion_sort(ARRAY *array)
{
    if(is_empty(array) || (!is_empty(array) && array->lenght == 1)) return;
    for(int index = 1; index < array->lenght; index++){
        int key = array->data[index];
        int i = index - 1;
        while(i >= 0 && array->data[i] > key){
            array->data[i + 1] = array->data[i];
            i = i - 1;
        }
        array->data[i + 1] = key;
    }
}
// =====================================================

void test_1000(){
    ARRAY *array = new_array(1000);
    srand(time(NULL));
    for(int index = 0; index < 1000; index++){
        int number = rand() % 1000;
        add(array, number);
    }
    insertion_sort(array);
    print_array(array);
}

int main()
{
    test_1000();
    return 0;
}