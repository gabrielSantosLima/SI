#include <stdio.h>

int main()
{
    int h = 0, e = 0, a = 0, o = 0, w = 0, x = 0;
    scanf("%d %d %d %d %d %d", &h, &e, &a, &o, &w, &x);
    int s = h + e + a, s2 = o + w;
    if (s > s2)
        printf("Middle-earth is safe.\n");
    else if (s + x > s2)
        printf("Middle-earth is safe.\n");
    else
        printf("Sauron has returned.\n");
    return 0;
}