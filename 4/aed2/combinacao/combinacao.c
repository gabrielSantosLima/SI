#include "combinacao.h"

int combinacao(int n, int p)
{
    return arranjo(n, p) / fat(p);
}

void combine_int(int array[], int data[], int start, int end, int index, int p)
{
    int i, j;

    if (index == p)
    {
        for (j = 0; j < p; j++)
            printf("%d ", data[j]);
        printf("\n");
        return;
    }

    for (i = start; i <= end && end - i + 1 >= p - index; i++)
    {
        data[index] = array[i];
        combine_int(array, data, i + 1, end, index + 1, p);
    }
}

void combinacao_int(int array[], int n, int p)
{
    int data[p];
    combine_int(array, data, 0, n - 1, 0, p);
}