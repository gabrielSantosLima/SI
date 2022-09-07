#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int indexOf(int numbers[], int size, int number)
{
    int end = size - 1;
    int start = 0;

    while (start <= end)
    {
        int middle = (start + end) / 2;
        if (numbers[middle] == number)
        {
            return middle;
        }
        if (numbers[middle] < number)
        {
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
    }

    return -1;
}

void bubbleSort(int numbers[], int size)
{
    int i = 0, j = 0;
    bool swapped = false;
    for (i = 0; i < (size - 1); i++)
    {
        for (j = 0; j < (size - 1 - i); j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                int auxNumber = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = auxNumber;
                swapped = true;
            }
        }
        if (!swapped)
            return;
    }
}

void printAll(int numbers[], int size)
{
    int index = 0;
    printf("=================\n");
    if (size == 0)
    {
        printf("Lista vazia");
        return;
    }
    for (index = 0; index < size; index++)
    {
        printf("%d ", numbers[index]);
    }
    printf("\n=================\n");
}

int main()
{
    int numbers[] = {1, 29, 3, 34, 15};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    printAll(numbers, size);
    bubbleSort(numbers, size);
    printAll(numbers, size);
    int index = indexOf(numbers, size, 15);
    if (index >= 0)
    {
        printf("Item encontrado - Indice: %d", index);
    }
    else
    {
        printf("Item não encontrado");
    }
    return 0;
}