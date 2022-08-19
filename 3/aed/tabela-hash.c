#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int powToInt(int base, int exponent)
{
    int result = 1;
    int index = 0;
    for (index = 0; index < exponent; index++)
    {
        result *= base;
    }
    return result;
}

int hash(char *key)
{
    int length = strlen(key);
    int index = 0;
    int hashKey = 0;
    for (index = 0; index < length; index++)
    {
        int result = (int)key[index] * powToInt(128, length - 1 - index);
        printf("%d\n", powToInt(128, length - 1 - index));
        hashKey += result;
    }
    return hashKey;
}

int main()
{
    int key = hash("Hash");
    printf("KEY: %d\n", key);
    return 0;
}