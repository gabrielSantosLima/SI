#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MC_K 10

int find_MC_array(int *array, int size, int k, int a)
{
    for (int index = 0; index < k; index++)
    {
        int current_index = rand() % size;
        printf("Tentativa %d: %d\n", index + 1, current_index);
        int item = array[current_index];
        if (item == a)
            return current_index;
    }
    return -1;
}

int main()
{
    time_t t;
    srand((unsigned)time(&t));
    int array[] = {1, 2, 3, 4, 5, 6, 19};
    int size = sizeof(array) / sizeof(array[0]);

    int number = 19;
    int index = find_MC_array(array, size, MC_K, number);

    printf("\nÍndice de %d: %d", number, index);

    return 0;
}