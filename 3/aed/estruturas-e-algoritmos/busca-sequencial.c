#include <stdio.h>
#include <stdlib.h>

int indexOf(int numbers[], int size, int number)
{
    int index = 0;
    for (index = 0; index < size; index++)
    {
        if (numbers[index] == number)
            return index;
    }
    return -1;
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
    int index = indexOf(numbers, size, 3);
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