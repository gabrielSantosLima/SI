#include <stdio.h>
#include <stdlib.h>

void maxMinArray(int *array, int size, int *max, int *min)
{
    if (size == 0) // 1
        return;
    *max = array[0];                           // 1
    *min = array[0];                           // 1
    for (int index = 0; index < size; index++) // 1 + n + 1 + n = 2n + 2
    {
        if (array[index] > *max) // n
            *max = array[index]; // n
        if (array[index] < *min) // n
            *min = array[index]; // n
    }

    // T(n) = 1 + 2n + 2 + 4n = 6n + 3
}

int main()
{
    int array[] = {-100, 2, 3, -400, 5, 6, 77, 8, 9};
    int size = sizeof(array) / sizeof(array[0]);

    int *max = (int *)malloc(sizeof(int));
    int *min = (int *)malloc(sizeof(int));

    maxMinArray(array, size, max, min);
    if (max && min)
    {
        printf("Menor número: %d\n", *min);
        printf("Maior número: %d", *max);
    }

    return 0;
}
