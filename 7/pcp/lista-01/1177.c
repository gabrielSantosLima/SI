#include <stdio.h>

int main()
{
    int t = 0, i = 0;
    scanf("%d", &t);
    for (i = 0; i < 1000; i++)
        printf("N[%d] = %d\n", i, i % t);
    return 0;
}