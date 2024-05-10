#include <stdio.h>

int main()
{
    int n = 0, i = 0, j = 1, sum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        int x = 0;
        scanf("%d", &x);
        sum = 0;
        j = 1;
        while (j < x)
        {
            if (x % j == 0)
                sum += j;
            j++;
        }
        if (sum == x)
            printf("%d eh perfeito\n", x);
        else
            printf("%d nao eh perfeito\n", x);
    }
    return 0;
}