#include <stdio.h>
#include <stdlib.h>
#define false 0
#define true 1

typedef int bool;

void swap(int *array, int size, int from, int to)
{
    int aux = array[to];     // 1
    array[to] = array[from]; // 1
    array[from] = aux;       // 1
}

void bubbleSort(int *array, int size)
{
    if (size <= 1) // 1
        return;
    bool swapped = false;              // 1
    for (int i = 0; i < size - 1; i++) // 2n + 1
    {
        for (int j = 0; j < size - i - 1; j++) // 1 + n + n - 1
        {
            if (array[j] > array[j + 1])
            {
                swap(array, size, j, j + 1);
                swapped = true;
            }
        }
        if (!swapped) // n
            return;
    }
}

int main()
{
    int array[] = {-100, 2, 3, -400, 5, 6, 77, 8, 9};
    int size = sizeof(array) / sizeof(array[0]);

    for (int index = 0; index < size; index++)
        printf("%d ", array[index]);

    printf("\n");

    bubbleSort(array, size);

    for (int index = 0; index < size; index++)
        printf("%d ", array[index]);
    return 0;
}