#include <stdio.h>

int main()
{
    int n = 0, i = 0, f = 0, j = 0, k = 0, aux = 0, aux2 = 0;
    scanf("%d %d %d", &n, &i, &f);
    int x[n];
    for (j = 0; j < n; j++)
        scanf("%d", &x[j]);
    for (j = 0; j < n; j++)
    {
        for (k = n - 1; k > j; k--)
        {
            aux = x[j] + x[k];
            if (aux >= i && aux <= f)
                aux2++;
        }
    }
    printf("%d\n", aux2);
    return 0;
}