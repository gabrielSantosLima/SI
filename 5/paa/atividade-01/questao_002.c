#include <stdio.h>
#include <stdlib.h>

int *evenArray(int *array, int size, int *even)
{
    int evenSize = 0;                          // 1
    for (int index = 0; index < size; index++) // 2n + 2
    {
        if (array[index] % 2 == 0) // 2n
            evenSize++;            // n
    }
    int *out = (int *)malloc(evenSize * sizeof(int)); // 1
    int currentIndex = 0;                             // 1
    for (int index = 0; index < size; index++)        // 2n + 2
    {
        if (array[index] % 2 == 0) // 2n
        {
            out[currentIndex] = array[index]; // n
            currentIndex++;                   // n
        }
    }
    *even = evenSize; // 1
    return out;       // 1

    // T(n) = 11n + 9
}

int main()
{
    int array[] = {-100, 2, 3, -400, 5, 6, 77, 8, 9};
    int size = sizeof(array) / sizeof(array[0]);

    int evenSize = 0;
    int *out = evenArray(array, size, &evenSize);

    printf("quantidade de pares: %d\n", evenSize);
    for (int index = 0; index < evenSize; index++)
        printf("%d ", out[index]);

    return 0;
}