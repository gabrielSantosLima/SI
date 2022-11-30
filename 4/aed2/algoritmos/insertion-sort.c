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
    int *data;
} ARRAY;

ARRAY *newArray(int maxLength)
{
    ARRAY *newArray = (ARRAY *)malloc(sizeof(ARRAY));
    newArray->lenght = 0;
    newArray->maxLength = maxLength;
    newArray->data = (int *)malloc(sizeof(int) * maxLength);
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

void add(ARRAY *array, int value)
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
        printf("%d ", array->data[index]);
}

/* ==================== Insertion-Sort ==================== */
void insertionSort(ARRAY *array)
{
    if(isEmpty(array) || (!isEmpty(array) && array->lenght == 1)) return;
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

void test1000(){
    ARRAY *array = newArray(1000);
    srand(time(NULL));
    for(int index = 0; index < 1000; index++){
        int number = rand() % 1000;
        add(array, number);
    }
    insertionSort(array);
    printArray(array);
}

int main()
{
    test1000();
    return 0;
}