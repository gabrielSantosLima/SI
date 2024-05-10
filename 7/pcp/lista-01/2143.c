#include <stdio.h>

int main()
{
    int t = 0, i = 0, n = 0, aux = 0, tmp = 0;
    while (scanf("%d", &t) != EOF && t != 0)
    {
        for (i = 0; i < t; i++)
        {
            scanf("%d", &n);
            tmp = (n - 1);
            if (tmp % 2 == 0)
                aux = 1 + 2 * tmp;
            else
                aux = 2 + 2 * (tmp - 1);
            printf("%d\n", aux);
        }
    }
    return 0;
}