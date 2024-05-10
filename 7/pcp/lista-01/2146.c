#include <stdio.h>

int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)
        printf("%d\n", n - 1);
    return 0;
}