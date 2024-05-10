#include <stdio.h>

int main()
{
    char q[] = "LIFE IS NOT A PROBLEM TO BE SOLVED";
    int n = 0, i = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        printf("%c", q[i]);
    printf("\n");
    return 0;
}