#include <stdio.h>
#include "combinacao.h"
#include "arranjo.h"
#include "permutacao.h"
#include "string.h"

int main()
{
    char palavra[] = "ola";
    permutacao_string(palavra);
    int numeros[] = {1, 2, 3, 4, 5};
    int n = sizeof(numeros) / sizeof(numeros[0]);
    int p = 3;
    combinacao_int(numeros, n, p);
    return 0;
}