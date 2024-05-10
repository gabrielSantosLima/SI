#include <stdio.h>

int main()
{
    char m[][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int x;
    scanf("%d", &x);
    printf("%s\n", m[x - 1]);
    return 0;
}