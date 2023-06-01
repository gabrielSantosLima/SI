#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_las_vegas_array(int *array, int size, int a)
{
    int index = -1;
    int tries = 0;
    while (index < 0)
    {
        int current_index = rand() % size;
        tries++;
        printf("Tentativa %d: %d\n", tries, current_index);
        if (array[current_index] == a)
            return current_index;
    }
    return index;
}

int main()
{
    time_t t;
    srand((unsigned)time(&t));
    int array[] = {1, 2, 3, 4, 5, 6, 19};
    int size = sizeof(array) / sizeof(array[0]);

    int number = 2;
    int index = find_las_vegas_array(array, size, number);

    printf("\nÍndice de %d: %d", number, index);

    return 0;
}