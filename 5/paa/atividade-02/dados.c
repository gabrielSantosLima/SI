#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MC_K 10

int find_MC_array(int *array, int size, int k, int a)
{
    for (int index = 0; index < k; index++)
    {
        int current_index = rand() % size;
        printf("Lançamento %d: dado com a face '%d'\n", index + 1, current_index + 1);
        int item = array[current_index];
        if (item == a)
            return index + 1;
    }
    return -1;
}

int main()
{
    time_t t;
    srand((unsigned)time(&t));
    int array[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(array) / sizeof(array[0]);

    int number = 6;
    int tries = find_MC_array(array, size, MC_K, number);

    printf("\nQuantidade de lançamentos para cair '%d': %d tentativa(s)", number, tries);

    return 0;
}