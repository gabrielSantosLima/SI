#include <stdio.h>

int main()
{
    int k = 0, i = 0;
    int v[] = {1, 3, 5, 10, 25, 50, 100};
    scanf("%d", &k);
    while (i < 7 && v[i] - k < 0)
        i++;
    printf("Top %d\n", v[i]);
    return 0;
}