#include <stdio.h>

int main()
{
    int t = 0, i = 0, j = 0, m = 0, n = 0, aux = -1;
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        aux = -1;
        scanf("%d %d", &n, &m);
        int v[n];
        for (j = 0; j < n; j++)
            v[j] = 0;
        for (j = 0; j < m; j++)
        {
            int x = 0;
            scanf("%d", &x);
            v[x - 1]++;
        }
        j = 0;
        while (j < n && aux == -1)
        {
            if ((float)v[j] / (float)m > 0.5)
                aux = j + 1;
            j++;
        }
        if (aux != -1)
            printf("%d\n", aux);
        else
            printf("-1\n");
    }
    return 0;
}