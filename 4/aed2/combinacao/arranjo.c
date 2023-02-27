#include "arranjo.h"

int arranjo(int n, int p)
{
    if (p <= 1)
        return n;
    return n * arranjo(n - 1, p - 1);
}

string *arranjo_string(string text, int p)
{
}