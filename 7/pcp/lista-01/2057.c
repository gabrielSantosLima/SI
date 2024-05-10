#include <stdio.h>

int main()
{
    int s = 0, t = 0, f = 0;
    scanf("%d %d %d", &s, &t, &f);
    if (s == 0)
        s = 24;
    printf("%d\n", (s + t + f) % 24);
    return 0;
}