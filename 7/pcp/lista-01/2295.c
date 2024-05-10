#include <stdio.h>

int main()
{
    float a = 0.0, g = 0.0, ra = 0.0, rg = 0.0;
    int i = 0;
    scanf("%f %f %f %f", &a, &g, &ra, &rg);
    if ((ra * (1 / a)) <= (1 * (rg / g)))
        i = 1;
    if (i)
        printf("G\n");
    else
        printf("A\n");
    return 0;
}